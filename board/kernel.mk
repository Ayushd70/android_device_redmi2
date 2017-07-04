# Kernel
BOARD_KERNEL_CMDLINE += androidboot.selinux=permissive
KERNEL_TOOLCHAIN := $(ANDROID_BUILD_TOP)/prebuilts/gcc/$(HOST_OS)-x86/arm/arm-eabi-4.8/bin
TARGET_KERNEL_CONFIG := wt88047_defconfig
TARGET_KERNEL_CROSS_COMPILE_PREFIX := arm-eabi-
TARGET_KERNEL_SOURCE := kernel/wingtech/msm8916
