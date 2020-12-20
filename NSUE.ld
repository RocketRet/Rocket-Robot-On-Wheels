#ifndef SPLAT_BEGIN_SEG
#ifndef SHIFT
#define SPLAT_BEGIN_SEG(name, start, vram, subalign) \
    . = start;\
    name##_ROM_START = .;\
    name##_VRAM = ADDR(.name);\
    .name vram : AT(name##_ROM_START) subalign {
#else
#define SPLAT_BEGIN_SEG(name, start, vram, subalign) \
    name##_ROM_START = .;\
    name##_VRAM = ADDR(.name);\
    .name vram : AT(name##_ROM_START) subalign {
#endif
#endif

#ifndef SPLAT_END_SEG
#ifndef SHIFT
#define SPLAT_END_SEG(name, end) \
    } \
    . = end;\
    name##_ROM_END = .;
#else
#define SPLAT_END_SEG(name, end) \
    } \
    name##_ROM_END = .;
#endif
#endif

SECTIONS
{
    SPLAT_BEGIN_SEG(header, 0x0, 0x0, )
        BUILD_DIR/asm/header.s.o(.data);
    SPLAT_END_SEG(header, 0x40)
    
    SPLAT_BEGIN_SEG(code_boot, 0x40, 0xA4000040, )
        BUILD_DIR/asm/boot.s.o(.text);
    SPLAT_END_SEG(code_boot, 0x1000)
    
    SPLAT_BEGIN_SEG(code_app, 0x1000, 0x80000400, )
        BUILD_DIR/bin/entry.bin.o(.data);
        BUILD_DIR/bin/f3dex2_code.bin.o(.data);
        BUILD_DIR/bin/app_4150.bin.o(.data);
        BUILD_DIR/bin/f3dex2_data.bin.o(.data);
        BUILD_DIR/bin/app_19390.bin.o(.data);
    SPLAT_END_SEG(code_app, 0xC00000)
}
