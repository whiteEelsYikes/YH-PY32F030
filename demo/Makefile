# 定义工具链
AS = arm-none-eabi-as.exe
CC = arm-none-eabi-gcc.exe
LD = arm-none-eabi-ld.exe
OBJCOPY = arm-none-eabi-objcopy.exe
OBJDUMP = arm-none-eabi-objdump.exe
GDB = arm-none-eabi-gdb

# 定义编译和链接选项
ASFLAGS := -mthumb -mcpu=cortex-m0plus -Wall -g
CFLAGS := -mthumb -mcpu=cortex-m0plus -march=armv6-m -c -Wall -g 
LDFLAGS := -T link.ld

# 一些额外的配置
DEVICE := py32f003x8
KEIL_UVISION = E:\keil_v5\Core\UV4\UV4.exe  # 确保这是Keil uVision的正确路径
PROJECT_FILE = ARM-MDK\demo.uvprojx  # Keil工程文件路径

# 定义目标文件和中间文件路径
BUILD_DIR := Build
OBJ_DIR := $(BUILD_DIR)/obj

TARGET = $(BUILD_DIR)/demo
DISFILE := $(TARGET).elf

SOURCES := $(wildcard *.s) $(wildcard *.c)
OBJECTS := $(patsubst %.s,$(OBJ_DIR)/%.o,$(wildcard *.s)) $(patsubst %.c,$(OBJ_DIR)/%.o,$(wildcard *.c))

LDFLAGS += -Map=$(TARGET).map

# 默认目标
all: cleanbuild $(TARGET).bin $(TARGET).hex $(DISFILE).dis

# 创建编译目录
$(OBJ_DIR):
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi

# 编译汇编文件
$(OBJ_DIR)/%.o: %.s | $(OBJ_DIR)
	$(AS) $(ASFLAGS) -o $@ $<

# 编译C文件
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $<

# 链接目标文件
$(TARGET).elf: $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

# 生成二进制文件
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# 生成十六进制文件
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

# 生成内存映射文件
$(TARGET).map: $(TARGET).elf
	$(OBJDUMP) -h $< > $@

# 生成反汇编文件
$(DISFILE).dis: $(TARGET).elf
	$(OBJDUMP)  -a -x -d -S -s -t $^ >> $@

# 反汇编目标文件
disasm: $(TARGET).elf
	$(OBJDUMP) -D $(TARGET).elf > $(TARGET).lst

# 清理生成的文件，但不清除obj目录
clean_files:
	@if [ -d $(BUILD_DIR) ]; then \
		rm -f $(BUILD_DIR)/*.elf $(BUILD_DIR)/*.bin $(BUILD_DIR)/*.hex $(BUILD_DIR)/*.map; \
	fi

# 清理build目录下的所有文件
cleanbuild:
	@if [ -d $(BUILD_DIR) ]; then \
		find $(BUILD_DIR) -type f -exec rm -f {} \; ; \
	fi

# 清理build/obj目录下的所有文件
cleanobj:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -f $(OBJ_DIR)/*; \
	fi

# 清理整个build目录并删除build目录
clean:
	make cleanobj
	make cleanbuild
	@if [ -d $(BUILD_DIR) ]; then \
		rm -r $(BUILD_DIR)/; \
	fi

# 烧录固件
flash: $(TARGET).elf
	@echo "Flashing $^ to target"
	pyocd flash -t $(DEVICE) $^

# 启动调试服务器
debug: $(TARGET).elf
	@echo "Starting pyOCD GDB server"
	pyocd gdbserver

# 连接GDB客户端
gdb: $(TARGET).elf
	@echo "Connecting GDB client $^"
	$(GDB) $^ -ex "target remote localhost:3333"

# 启动Keil uVision进行调试
keil:
	@echo "Starting Keil uVision for debugging"
	$(KEIL_UVISION) -d $(PROJECT_FILE)


.PHONY: all clean_files cleanbuild cleanobj clean disasm flash debug gdb


# 以下伪目标未经验证
# 谨慎使用

set_pyocd:

set_build_path:

.PHONY: set_pyocd set_build_path
