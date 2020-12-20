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
        BUILD_DIR/asm/entry.s.o(.text);
        BUILD_DIR/bin/app_1100.bin.o(.data);
        BUILD_DIR/asm/code1.s.o(.text);
        BUILD_DIR/asm/code2.s.o(.text);
        BUILD_DIR/bin/app_2090.bin.o(.data);
        BUILD_DIR/bin/f3dex2_code.bin.o(.data);
        BUILD_DIR/asm/code3.s.o(.text);
        BUILD_DIR/asm/code4.s.o(.text);
        BUILD_DIR/asm/code5.s.o(.text);
        BUILD_DIR/asm/code6.s.o(.text);
        BUILD_DIR/asm/code7.s.o(.text);
        BUILD_DIR/asm/code8.s.o(.text);
        BUILD_DIR/asm/code9.s.o(.text);
        BUILD_DIR/asm/code10.s.o(.text);
        BUILD_DIR/asm/code11.s.o(.text);
        BUILD_DIR/asm/code12.s.o(.text);
        BUILD_DIR/asm/code13.s.o(.text);
        BUILD_DIR/asm/code14.s.o(.text);
        BUILD_DIR/asm/code15.s.o(.text);
        BUILD_DIR/asm/code16.s.o(.text);
        BUILD_DIR/asm/code17.s.o(.text);
        BUILD_DIR/asm/code18.s.o(.text);
        BUILD_DIR/asm/code19.s.o(.text);
        BUILD_DIR/asm/code20.s.o(.text);
        BUILD_DIR/asm/code21.s.o(.text);
        BUILD_DIR/asm/code22.s.o(.text);
        BUILD_DIR/asm/code23.s.o(.text);
        BUILD_DIR/asm/code24.s.o(.text);
        BUILD_DIR/asm/code25.s.o(.text);
        BUILD_DIR/asm/code26.s.o(.text);
        BUILD_DIR/asm/code27.s.o(.text);
        BUILD_DIR/asm/code28.s.o(.text);
        BUILD_DIR/asm/code29.s.o(.text);
        BUILD_DIR/asm/code31.s.o(.text);
        BUILD_DIR/asm/code32.s.o(.text);
        BUILD_DIR/asm/code33.s.o(.text);
        BUILD_DIR/asm/code34.s.o(.text);
        BUILD_DIR/asm/code35.s.o(.text);
        BUILD_DIR/asm/code36.s.o(.text);
        BUILD_DIR/asm/code37.s.o(.text);
        BUILD_DIR/asm/code38.s.o(.text);
        BUILD_DIR/asm/code39.s.o(.text);
        BUILD_DIR/asm/code40.s.o(.text);
        BUILD_DIR/asm/code41.s.o(.text);
        BUILD_DIR/asm/code42.s.o(.text);
        BUILD_DIR/asm/code43.s.o(.text);
        BUILD_DIR/asm/code44.s.o(.text);
        BUILD_DIR/asm/code45.s.o(.text);
        BUILD_DIR/asm/code46.s.o(.text);
        BUILD_DIR/asm/code47.s.o(.text);
        BUILD_DIR/asm/code48.s.o(.text);
        BUILD_DIR/asm/code49.s.o(.text);
        BUILD_DIR/asm/code50.s.o(.text);
        BUILD_DIR/asm/code51.s.o(.text);
        BUILD_DIR/asm/code52.s.o(.text);
        BUILD_DIR/asm/code53.s.o(.text);
        BUILD_DIR/asm/code54.s.o(.text);
        BUILD_DIR/asm/code55.s.o(.text);
        BUILD_DIR/asm/code56.s.o(.text);
        BUILD_DIR/asm/code57.s.o(.text);
        BUILD_DIR/asm/code58.s.o(.text);
        BUILD_DIR/asm/code59.s.o(.text);
        BUILD_DIR/asm/code60.s.o(.text);
        BUILD_DIR/asm/code61.s.o(.text);
        BUILD_DIR/asm/code62.s.o(.text);
        BUILD_DIR/asm/code63.s.o(.text);
        BUILD_DIR/asm/code64.s.o(.text);
        BUILD_DIR/asm/code65.s.o(.text);
        BUILD_DIR/asm/code66.s.o(.text);
        BUILD_DIR/asm/code67.s.o(.text);
        BUILD_DIR/asm/code68.s.o(.text);
        BUILD_DIR/asm/code69.s.o(.text);
        BUILD_DIR/asm/code70.s.o(.text);
        BUILD_DIR/asm/code71.s.o(.text);
        BUILD_DIR/asm/code72.s.o(.text);
        BUILD_DIR/asm/code73.s.o(.text);
        BUILD_DIR/asm/code74.s.o(.text);
        BUILD_DIR/asm/code75.s.o(.text);
        BUILD_DIR/asm/code76.s.o(.text);
        BUILD_DIR/asm/code77.s.o(.text);
        BUILD_DIR/asm/code78.s.o(.text);
        BUILD_DIR/asm/code79.s.o(.text);
        BUILD_DIR/asm/code80.s.o(.text);
        BUILD_DIR/asm/code81.s.o(.text);
        BUILD_DIR/asm/code82.s.o(.text);
        BUILD_DIR/asm/code83.s.o(.text);
        BUILD_DIR/asm/code84.s.o(.text);
        BUILD_DIR/asm/code85.s.o(.text);
        BUILD_DIR/asm/code86.s.o(.text);
        BUILD_DIR/asm/code87.s.o(.text);
        BUILD_DIR/asm/code88.s.o(.text);
        BUILD_DIR/asm/code89.s.o(.text);
        BUILD_DIR/asm/code90.s.o(.text);
        BUILD_DIR/asm/code91.s.o(.text);
        BUILD_DIR/asm/code92.s.o(.text);
        BUILD_DIR/asm/code93.s.o(.text);
        BUILD_DIR/asm/code94.s.o(.text);
        BUILD_DIR/asm/code95.s.o(.text);
        BUILD_DIR/asm/code96.s.o(.text);
        BUILD_DIR/asm/code97.s.o(.text);
        BUILD_DIR/asm/code98.s.o(.text);
        BUILD_DIR/asm/code99.s.o(.text);
        BUILD_DIR/asm/code100.s.o(.text);
        BUILD_DIR/asm/code101.s.o(.text);
        BUILD_DIR/asm/code102.s.o(.text);
        BUILD_DIR/asm/code103.s.o(.text);
        BUILD_DIR/asm/code104.s.o(.text);
        BUILD_DIR/asm/code105.s.o(.text);
        BUILD_DIR/asm/code106.s.o(.text);
        BUILD_DIR/asm/code107.s.o(.text);
        BUILD_DIR/asm/code108.s.o(.text);
        BUILD_DIR/bin/app_189E0.bin.o(.data);
        BUILD_DIR/bin/f3dex2_data.bin.o(.data);
        BUILD_DIR/bin/app_19390.bin.o(.data);
        BUILD_DIR/asm/code.s.o(.text);
        BUILD_DIR/bin/app_9FC70.bin.o(.data);
    SPLAT_END_SEG(code_app, 0xC00000)
}
