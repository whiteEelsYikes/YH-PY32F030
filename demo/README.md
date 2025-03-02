

# demo介绍

一个跑在py32f030单片机上的简单汇编裸机程序，使用gnu和make实现

> 这只是一个简单的demo
>
> 代码很垃圾也没什么参考价值，也就适合做一个简单的实例
>
> **项目中相关代码有大量的没有什么用的代码，只是单纯懒得去处理这些代码，因为这是一个demo，所以demo不配**

## 效果展示



## 项目结构

```shell
demo
│  link.ld  # demo 链接脚本
│  main.c   # 一个简单的c程序（用于混合编程）
│  Makefile  # make 固件配置文件（脚本）
│  README.md  # 一个简单的文档
│  start copy  # 不知道什么时候备份的start.s文件
│  start.s  # 启动文件（裸机汇编）
│
├─ARM-MDK  # 这个目录是给keil5存放工程的，因为使用keil调试会使用到
│  │  demo.uvguix.bai  # 自己去学keil5相关的
│  │  demo.uvoptx  # 自己去学keil5相关的
│  │  demo.uvprojx  # 自己去学keil5相关的
│  │  EventRecorderStub.scvd  # 自己去学keil5相关的
│  │
│  ├─DebugConfig  # 自己去学keil5相关的
│  │      Target_1_PY32F030x8.dbgconf  # 自己去学keil5相关的
│  │
│  ├─Listings  # 自己去学keil5相关的
│  │      start.lst  # 自己去学keil5相关的
│  │
│  └─Objects  # 自己去学keil5相关的
│          demo.build_log.htm
│          demo_Target 1.dep
│
├─Build  # 该命令是编译结果和编译时产生的一些中间文件存放的位置
│  │  demo.bin  # 编译出的bin文件
│  │  demo.elf  # 编译出的elf文件（keil的axf也可以直接使用该文件）
│  │  demo.elf.dis  # demo.elf 的反汇编文件（包含各种必要和不必要信息）
│  │  demo.hex  # 编译出的hex文件
│  │  demo.map  # demo.elf的内存映射表
│  │
│  └─obj  # 一些编译时产生的中间文件 .o文件什么的（虽然也是elf文件）
│          ...
│
└─tools  # 本项目可能会使用到的一些工具（包括在win构建时需要使用的bash的相关命令支持在 tools/Build下）
    │  arm-gnu-toolchain-14.2.rel1-mingw-w64-x86_64-arm-none-eabi.exe
    │  nuclei_riscv_newlibc_prebuilt_win32_2024.06.zip
    │  Puya.PY32F0xx_DFP.1.1.7.pack
    │  pyOCD_py32f030.py
    │  README.md
    │  win32-buildtools-1.2.zip
    │
    └─Build  # 在win使用make构建时，为了尽可能兼容bash shell而使用的一些程序
        ├─bin  # 我使用的是这个，将这个命令加入环境变量就可以了
        │      ...
        └─bin1  # 可以不管这个
                ...
```

# 构建make

> 没啥难度，毕竟不是Linux内核那些项目，也没有复杂的依赖关系链和构建工具链

简单三步构建下载与仿真

`````shell
make
make flash
make keil
make debug
make gdb
`````

构建时可能会报错，可能需要先处理环境和依赖

## makefile 编译依赖

makefile的实现没有在Linux环境进行测试，以下仅针对win11环境：

需要准备的文件：

> **所有需要的依赖程序和文件都在tools\目录下提供**
>
> *适用于win平台的make是没有提供的，可以自行前往make官网下载或者使用工具链中提供的make构建工具*

将**tools\Build**目录加入**系统环境变量PATH**，或者**终端临时环境变量**

然后还需要安装win平台的`arm-gnu-toolchain-14.2.rel1-mingw-w64-x86_64-arm-none-eabi`

可以使用其他版本的**gnu arm 构建工具**，重点是**构建工具的bin目录**也需要加入**系统环境变量path**，或者**终端临时环境变量**

### 使用命令提示符

> 1. 打开 **开始菜单**，搜索并选择 **命令提示符** 或 **cmd**。
> 2. 输入以下命令，将 `./tools/Build` 替换为你的路径：
>    ```cmd
>    set PATH=%PATH%;./tools/Build
>    ```
> 3. 你可以通过运行以下命令来验证新的 `PATH` 环境变量：
>    ```cmd
>    echo %PATH%
>    ```
>

### 使用 PowerShell
> 1. 打开 **开始菜单**，搜索并选择 **PowerShell**。
> 2. 输入以下命令，将 `./tools/Build` 替换为你要添加的路径：
>    ```powershell
>    $env:PATH = "$env:PATH;./tools/Build"
>    ```
> 3. 你可以通过运行以下命令来验证新的 `PATH` 环境变量：
>    ```powershell
>    echo $env:PATH
>    ```
>

当环境变量设置完成以后，你应该可以正常执行基本的编译构建操作了
````shell
make
````



## makefile 下载固件

> 主要是利用`pyocd`来实现
>
> 对此需要先安装pyocd以及pyocd需要的芯片配置：
>
> ````shell
> # 此处 <> 中的内容表示可选
> <python -m> pip install pyocd
> <python -m> pyocd list --targets
> <python -m> pyocd pack find py32f030
> <python -m> pyocd pack install PY32F030x8
> <python -m> pyocd list --targets
> <python -m> pyocd flash -t py32f003x8 firmware.elf
> ````
>
> 然后可以执行下载固件操作
>
> ````shell
> make flash
> ````
>



## makefile 调试依赖

目前支持两种调试方式：**pyocd联合gdb调试**、**keil调试**

### pyocd联合gdb调试

> 如果能正常执行`make` 和 `make flash`目标则不需要进行额外处理，可以直接使用：
>
> 1. 先启动pyocd
>
>    ```shell
>    make debug
>    ```
>
> 2. 在另一个命令行窗口使用gdb开始调试
>
>    ````shell
>    make gdb
>    ````
>

### keil调试

> 需要安装keil5并且修改makefile中keil的位置
>
> 1. 安装keil
>
>    自己网上查去，安装包网上很多
>
> 2. 修改makefile（使用git diff进行比较分析）
>
>    ```shell
>    diff --git a/Makefile b/you-Makefile
>    index 168e09d..060eb0e 100644
>    --- a/Makefile
>    +++ b/you-Makefile
>    @@ -13,8 +13,8 @@ LDFLAGS := -T link.ld
>             
>     # 一些额外的配置
>     DEVICE := py32f003x8
>    -KEIL_UVISION = E:\keil_v5\Core\UV4\UV4.exe  # 确保这是Keil uVision的正确路径
>    -PROJECT_FILE = ARM-MDK\demo.uvprojx  # Keil工程文件路径
>    +KEIL_UVISION = 你的keil IDE位置  # 确保这是Keil uVision的正确路径
>    +PROJECT_FILE = （正常情况这个选项是不需要修改的，因为所有相对路径）本项目的keil工程.uvprojx文件位置  # Keil工程文件路径     
>             
>     # 定义目标文件和中间文件路径
>     BUILD_DIR := Build
>    ```
>    当所有的配置都正确配置后可以执行keil仿真：
>    
>    ````shell
>    make keil
>    ````
>    
>    
>

