#!/usr/bin/env bash
set -euo pipefail
cd -- "$(dirname -- "$0")"

kernel="${1:-../linux-3.18.6/arch/x86/boot/bzImage}"
if [ ! -f "$kernel" ]; then
    echo '未找到内核镜像，请指定上周编译的 bzImage：'
    echo 'bash 运行测试.sh ~/LinuxKernel/linux-3.18.6/arch/x86/boot/bzImage'
    exit 1
fi

if command -v qemu-system-i386 >/dev/null 2>&1; then
    qemu=qemu-system-i386
elif command -v qemu >/dev/null 2>&1; then
    qemu=qemu
else
    echo '未找到 QEMU，请先安装 qemu-system-x86。'
    exit 1
fi

make -C menu rootfs
exec "$qemu" -kernel "$kernel" -initrd rootfs.img \
    -append 'console=ttyS0' -nographic
