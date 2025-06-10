#include <klib.h>
#include <klib-macros.h>


/*
修改AM中的优化等级为O0
+CFLAGS   += -O0 -MMD -Wall -Werror $(INCFLAGS) \

-->(0x8000000c):  call  [_trm_init@0x800000d8]
-->(0x800000e8):    call  [main@0x80000080]
-->(0x80000098):      call  [add@0x80000010]
-->(0x80000044):      ret   [main@0x8000009c]
-->(0x800000a8):      call  [sub@0x80000048]
-->(0x8000007c):      ret   [main@0x800000ac]
-->(0x800000d4):    ret   [_trm_init@0x800000ec]
*/

int add(int a, int b) {
	int c = a + b;
	return c;
}

int sub(int a, int b) {
  int c = a -b;
  return c;
}

int main() {
  int a = add(1, 3);
  int b = sub(a, 1);
  int c = a + b;
  return 0;
}
