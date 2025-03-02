import argparse
import os
from pyocd.core.helpers import ConnectHelper
from pyocd.flash.loader import FlashLoader

def flash_firmware(elf_file, pack_path, target_type):
    # 设置环境变量以指定pack文件路径
    os.environ['CMSIS_PACK_PATH'] = pack_path

    # 创建会话并连接到设备
    session = ConnectHelper.session_with_chosen_probe(
        target_override=target_type,
        options={"pack": pack_path}
    )
    with session:
        # 创建FlashLoader实例
        loader = FlashLoader(session)
        
        # 加载ELF文件
        loader.add_file(elf_file)
        
        # 编程Flash
        loader.program()
        print(f"Successfully flashed {elf_file} using pack {pack_path} to {target_type}")

if __name__ == "__main__":
    # 设置命令行参数解析
    parser = argparse.ArgumentParser(description='Flash ELF file to device using pyOCD.')
    parser.add_argument('elf_file', type=str, help='Path to the ELF file to be flashed')
    parser.add_argument('--pack', type=str, required=True, help='Path to the CMSIS pack file')
    parser.add_argument('--target', type=str, default='py32f030', help='Target device type')
    
    # 解析命令行参数
    args = parser.parse_args()
    
    import argparse
import os
from pyocd.core.helpers import ConnectHelper
from pyocd.flash.loader import FlashLoader

def flash_firmware(elf_file, pack_path, target_type):
    # 设置环境变量以指定pack文件路径
    os.environ['CMSIS_PACK_PATH'] = pack_path

    # 创建会话并连接到设备
    session = ConnectHelper.session_with_chosen_probe(
        target_override=target_type,
        options={"pack": pack_path}
    )
    with session:
        # 创建FlashLoader实例
        loader = FlashLoader(session)
        
        # 加载ELF文件
        loader.add_file(elf_file)
        
        # 编程Flash
        loader.program()
        print(f"Successfully flashed {elf_file} using pack {pack_path} to {target_type}")

if __name__ == "__main__":
    # 设置命令行参数解析
    # parser = argparse.ArgumentParser(description='Flash ELF file to device using pyOCD.')
    # parser.add_argument('elf_file', type=str, help='Path to the ELF file to be flashed')
    # parser.add_argument('--pack', type=str, required=True, help='Path to the CMSIS pack file')
    # parser.add_argument('--target', type=str, default='py32f030', help='Target device type')
    
    # # 解析命令行参数
    # args = parser.parse_args()
    
    f = "C:\\Users\\bai\\Desktop\\PY32F030\\demo\\build\\firmware.elf"
    p = "C:\\Users\\bai\\Desktop\\PY32F030\\demo\\tools"

    # 烧录固件
    flash_firmware(f, p, "py32f030")

    # 烧录固件
    # flash_firmware(args.elf_file, args.pack, args.target)
