#include <am.h>
#include <klib-macros.h>

#define STACK_SIZE (4096 * 8)
/*
- 当PCB作为栈使用时，`stack[STACK_SIZE]`被使用
- 当PCB存储Context指针时，`cp`字段被使用
- 由于是union，这两种使用方式是互斥的，不会同时使用

这种设计在简单的操作系统内核中很常见，特别是在内存受限的环境中，通过union来复用内存空间，提高内存使用效率。
*/
typedef union {
  uint8_t stack[STACK_SIZE];
  struct { Context *cp; };
} PCB;
static PCB pcb[2], pcb_boot, *current = &pcb_boot;

static void f(void *arg) {
  while (1) {
    putch("?AB"[(uintptr_t)arg > 2 ? 0 : (uintptr_t)arg]);
    for (int volatile i = 0; i < 100000; i++) ;
    yield();
  }
}

static Context *schedule(Event ev, Context *prev) {
  current->cp = prev;
  current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
  return current->cp;
}

int main() {
  cte_init(schedule);
  pcb[0].cp = kcontext((Area) { pcb[0].stack, &pcb[0] + 1 }, f, (void *)1L);
  pcb[1].cp = kcontext((Area) { pcb[1].stack, &pcb[1] + 1 }, f, (void *)2L);
  yield();
  panic("Should not reach here!");
}
