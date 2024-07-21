# AbstractMachine kernels

CONTACTS

Bug reports and suggestions go to Yanyan Jiang (jyy@nju.edu.cn) and Zihao 
Yu (yuzihao@ict.ac.cn).

am-kernels子项目用于收录一些可以在AM上运行的测试集和简单程序:

```bash
├── benchmarks                  # 可用于衡量性能的基准测试程序
│   ├── coremark
│   ├── dhrystone
│   └── microbench
├── kernels                     # 可展示的应用程序
│   ├── hello
│   ├── litenes                 # 简单的NES模拟器
│   ├── nemu                    # NEMU
│   ├── slider                  # 简易图片浏览器
│   ├── thread-os               # 内核线程操作系统
│   └── typing-game             # 打字小游戏
└── tests                       # 一些具有针对性的测试集
    ├── am-tests                # 针对AM API实现的测试集
    └── cpu-tests               # 针对CPU指令实现的测试集
```

## cpu-tests

```bash
make ARCH=$ISA-nemu ALL=xxx gdb
make ARCH=$ISA-nemu ALL=xxx run
```

for example:
```bash
make ARCH=riscv32-nemu ALL=dummy run
```
