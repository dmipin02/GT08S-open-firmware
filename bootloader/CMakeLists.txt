set(CMAKE_CXX_FLAGS "")
set(CMAKE_C_FLAGS "")
add_executable(bootloader src/boot.c)
target_compile_options(bootloader INTERFACE "-march armv5te -mtune arm9e -mthumb-interwork -fdata-sections -ffunction-sections -Os -g2 -nostdlib --heap=0x0000 -eb_lib=n")
target_link_options(bootloader INTERFACE "-Wl --gc-sections -T linker.ld")
set_target_properties(bootloader PROPERTIES OUTPUT_NAME "bootloader.elf")
set(MAKE_SIGN "${CMAKE_CURRENT_SOURCE_DIR}/tools/mtk_signer")
add_custom_target(INT_BOOTLOADER ALL)
add_dependencies(INT_BOOTLOADER bootloader)
add_custom_command(
   TARGET INT_BOOTLOADER
   POST_BUILD
   COMMAND ${CMAKE_OBJCOPY} -S -O binary bootloader.elf ../output/INT_BL.bin
) 
# TODO: сделать автоподписывание int_bootloader