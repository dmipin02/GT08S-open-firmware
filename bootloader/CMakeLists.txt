add_executable(bootloader src/boot.c)
target_compile_options(bootloader INTERFACE "-march armv5te -mtune arm9e -mthumb-interwork -fdata-sections -ffunction-sections -Os -g2")
target_link_options(bootloader INTERFACE "-Wl --gc-sections -T linker.ld")
#add_custom_command(
#    TARGET bootloader
#    POST_BUILD
#    COMMAND "arm-none-eabi-objcopy -S -O binary build/bootloader/bootloader output/INT_BOOTLOADER"
#)
#execute_process(COMMAND "tools/mtk_signed.exe output/INT_BOOTLOADER")
