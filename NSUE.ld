SECTIONS
{
    __romPos = 0x0;
    header_ROM_START = __romPos;
    header_VRAM = ADDR(.header);
    .header : AT(header_ROM_START) SUBALIGN(16)
    {
        header_TEXT_END = .;
        header_DATA_START = .;
        header = .;
        build/us/asm/header.o(.data);
        header_DATA_END = .;
    }
    __romPos += SIZEOF(.header);
    header_ROM_END = __romPos;

    boot_ROM_START = __romPos;
    boot_VRAM = ADDR(.boot);
    .boot 0xA4000040 : AT(boot_ROM_START) SUBALIGN(16)
    {
        boot_TEXT_END = .;
        boot_DATA_START = .;
        boot = .;
        build/us/bin/boot.o(.data);
        boot2 = .;
        build/us/bin/boot2.o(.data);
        boot_DATA_END = .;
    }
    __romPos += SIZEOF(.boot);
    boot_ROM_END = __romPos;

    . = 0x80000400;
    codesegs0_1_ROM_START = __romPos;
    codesegs0_1_VRAM = ADDR(.codesegs0_1);
    .codesegs0_1 : AT(codesegs0_1_ROM_START) SUBALIGN(16)
    {
        codesegs0_1_TEXT_START = .;
        build/us/asm/entry.o(.text);
        build/us/src/rocket/codeseg0/codeseg0.o(.rdata);
        build/us/src/lib/codeseg1/player.o(.rdata);
        build/us/asm/data/lib/sn/floatdisf.rodata.o(.rodata);
        build/us/asm/data/lib/sn/fixunssfdi.rodata.o(.rodata);
        build/us/src/lib/codeseg1/player_fx.o(.rdata);
        build/us/asm/data/lib/sn/udivmoddi4.rodata.o(.rodata);
        build/us/asm/data/lib/sn/floatdidf.rodata.o(.rodata);
        build/us/src/lib/codeseg1/aud_samples.o(.rdata);
        build/us/ultra/src/sched/sched.o(.rodata);
        build/us/ultra/src/gu/perspective.o(.rodata);
        build/us/ultra/src/gu/sinf.o(.rodata);
        codesegs0_1_TEXT_END = .;
        codesegs0_1_DATA_START = .;
        build/us/asm/data/exceptasm_rodata.rodata.o(.rodata);
        build/us/ultra/src/io/devmgr.o(.rodata);
        build/us/ultra/src/io/sirawread.o(.rodata);
        build/us/ultra/src/io/sirawwrite.o(.rodata);
        build/us/ultra/src/io/pirawread.o(.rodata);
        build/us/ultra/src/gu/cosf.o(.rodata);
        build/us/ultra/src/io/sirawdma.o(.rodata);
        build/us/ultra/src/gu/libm_vals.o(.rodata);
        build/us/ultra/src/io/viswapcontext.o(.rodata);
        build/us/ultra/src/io/sprawdma.o(.rodata);
        build/us/ultra/src/io/epirawread.o(.rodata);
        build/us/ultra/src/audio/drvrnew.o(.rodata);
        build/us/ultra/src/audio/reverb.o(.rodata);
        build/us/ultra/src/n_audio/n_drvrnew.o(.rodata);
        build/us/ultra/src/n_audio/n_reverb.o(.rodata);
        build/us/ultra/src/n_audio/n_synthesizer.o(.rodata);
        build/us/ultra/src/n_audio/n_env.o(.rodata);
        build/us/ultra/src/io/aisetfreq.o(.rodata);
        build/us/ultra/src/audio/synthesizer.o(.rodata);
        build/us/ultra/src/audio/env.o(.rodata);
        build/us/ultra/src/audio/resample.o(.rodata);
        build/us/ultra/src/audio/save.o(.rodata);
        build/us/ultra/src/n_audio/n_resample.o(.rodata);
        build/us/src/rocket/codeseg0/codeseg0.o(.text);
        rspboot_code = .;
        build/us/bin/rspboot_code.o(.data);
        n_aspMain_code = .;
        build/us/bin/n_aspMain_code.o(.data);
        f3dex2_code = .;
        build/us/bin/f3dex2_code.o(.data);
        build/us/ultra/src/sched/sched.o(.text);
        build/us/asm/lib/codeseg1/bzero.o(.text);
        build/us/ultra/src/io/pigetstat.o(.text);
        build/us/ultra/src/io/spsetpc.o(.text);
        build/us/ultra/src/os/startthread.o(.text);
        padding = .;
        build/us/bin/padding.o(.data);
        build/us/ultra/src/os/createthread.o(.text);
        build/us/ultra/src/os/setthreadpri.o(.text);
        build/us/asm/lib/codeseg1/writebackdcache.o(.text);
        build/us/ultra/src/io/pimgr.o(.text);
        build/us/ultra/src/os/createmesgqueue.o(.text);
        build/us/src/lib/codeseg1/player.o(.text);
        build/us/ultra/src/io/pirawdma.o(.text);
        build/us/asm/lib/codeseg1/invaldcache.o(.text);
        build/us/ultra/src/os/initialize.o(.text);
        build/us/ultra/src/os/sendmesg.o(.text);
        build/us/ultra/src/os/recvmesg.o(.text);
        build/us/ultra/src/os/gettime.o(.text);
        build/us/ultra/src/gu/mtxutil.o(.text);
        build/us/ultra/src/gu/perspective.o(.text);
        build/us/ultra/src/io/conteepprobe.o(.text);
        build/us/ultra/src/io/conteepwrite.o(.text);
        build/us/ultra/src/io/conteeplongread.o(.text);
        build/us/src/lib/sn/floatdisf.o(.text);
        build/us/ultra/src/io/conteepread.o(.text);
        build/us/ultra/src/io/conteeplongwrite.o(.text);
        build/us/src/lib/sn/cmpdi2.o(.text);
        build/us/ultra/src/gu/mtxcatl.o(.text);
        build/us/ultra/src/gu/translate.o(.text);
        build/us/ultra/src/gu/scale.o(.text);
        build/us/ultra/src/io/visetspecial.o(.text);
        build/us/ultra/src/io/controller.o(.text);
        build/us/ultra/src/io/contreaddata.o(.text);
        build/us/ultra/src/os/seteventmesg.o(.text);
        build/us/ultra/src/gu/random.o(.text);
        build/us/ultra/src/io/pidma.o(.text);
        build/us/src/lib/sn/udivdi3.o(.text);
        build/us/ultra/src/io/motor.o(.text);
        build/us/src/lib/sn/fixunssfdi.o(.text);
        build/us/asm/lib/codeseg1/writebackdcacheall.o(.text);
        build/us/ultra/src/gu/sinf.o(.text);
        build/us/ultra/src/io/vimgr.o(.text);
        build/us/ultra/src/io/visetmode.o(.text);
        build/us/ultra/src/io/viblack.o(.text);
        build/us/ultra/src/io/visetevent.o(.text);
        build/us/asm/lib/codeseg1/setintmask.o(.text);
        build/us/ultra/src/os/assert.o(.text);
        build/us/ultra/src/io/sptaskyielded.o(.text);
        build/us/ultra/src/io/vigetcurrframebuf.o(.text);
        build/us/ultra/src/io/vigetnextframebuf.o(.text);
        build/us/ultra/src/io/viswapbuf.o(.text);
        build/us/ultra/src/io/sptask.o(.text);
        build/us/ultra/src/io/dpsetnextbuf.o(.text);
        build/us/ultra/src/io/sptaskyield.o(.text);
        build/us/asm/lib/codeseg1/interrupt.o(.text);
        build/us/ultra/src/os/thread.o(.text);
        build/us/asm/lib/codeseg1/exceptasm.o(.text);
        build/us/ultra/src/io/cartrominit.o(.text);
        build/us/ultra/src/io/leodiskinit.o(.text);
        build/us/ultra/src/io/piacs.o(.text);
        build/us/ultra/src/os/getthreadpri.o(.text);
        build/us/ultra/src/io/devmgr.o(.text);
        build/us/ultra/src/io/epirawdma.o(.text);
        build/us/src/lib/codeseg1/player_fx.o(.text);
        build/us/src/lib/codeseg1/aud_sched.o(.text);
        build/us/ultra/src/n_audio/n_synsetpan.o(.text);
        build/us/ultra/src/n_audio/n_synsetvol.o(.text);
        build/us/ultra/src/n_audio/n_synaddplayer.o(.text);
        build/us/ultra/src/n_audio/n_synstopvoice.o(.text);
        build/us/src/lib/codeseg1/lib_memory.o(.text);
        build/us/ultra/src/n_audio/n_synallocvoice.o(.text);
        build/us/ultra/src/n_audio/n_synsetfxmix.o(.text);
        build/us/ultra/src/n_audio/n_synstartvoice.o(.text);
        build/us/src/lib/codeseg1/aud_thread.o(.text);
        build/us/ultra/src/n_audio/n_synsetpitch.o(.text);
        build/us/ultra/src/os/virtualtophysical.o(.text);
        build/us/asm/lib/codeseg1/getsr.o(.text);
        build/us/asm/lib/codeseg1/setsr.o(.text);
        build/us/asm/lib/codeseg1/setfpccsr.o(.text);
        build/us/ultra/src/io/sirawread.o(.text);
        build/us/ultra/src/io/sirawwrite.o(.text);
        build/us/asm/lib/codeseg1/invalicache.o(.text);
        build/us/asm/lib/codeseg1/maptlbrdb.o(.text);
        build/us/ultra/src/io/pirawread.o(.text);
        build/us/asm/lib/codeseg1/getcount.o(.text);
        build/us/ultra/src/os/timerintr.o(.text);
        build/us/ultra/src/gu/cosf.o(.text);
        build/us/ultra/src/io/siacs.o(.text);
        build/us/ultra/src/io/sirawdma.o(.text);
        build/us/ultra/src/os/settimer.o(.text);
        build/us/ultra/src/gu/mtxcatf.o(.text);
        build/us/ultra/src/io/vi.o(.text);
        build/us/ultra/src/io/pigetcmdq.o(.text);
        build/us/ultra/src/os/jammesg.o(.text);
        build/us/src/lib/sn/udivmoddi4.o(.text);
        build/us/ultra/src/io/pfsisplug.o(.text);
        build/us/ultra/src/io/crc.o(.text);
        build/us/ultra/src/io/contramwrite.o(.text);
        build/us/ultra/src/io/contramread.o(.text);
        build/us/src/lib/sn/floatdidf.o(.text);
        build/us/ultra/src/io/vigetcurrcontext.o(.text);
        build/us/ultra/src/io/viswapcontext.o(.text);
        build/us/ultra/src/io/spgetstat.o(.text);
        build/us/asm/lib/codeseg1/bcopy.o(.text);
        build/us/ultra/src/io/spsetstat.o(.text);
        build/us/ultra/src/io/sprawdma.o(.text);
        build/us/ultra/src/io/sp.o(.text);
        build/us/ultra/src/io/dp.o(.text);
        build/us/ultra/src/io/leointerrupt.o(.text);
        build/us/ultra/src/os/destroythread.o(.text);
        build/us/ultra/src/os/resetglobalintmask.o(.text);
        build/us/ultra/src/io/epirawwrite.o(.text);
        build/us/ultra/src/io/epirawread.o(.text);
        build/us/ultra/src/os/setglobalintmask.o(.text);
        build/us/ultra/src/os/yieldthread.o(.text);
        build/us/ultra/src/n_audio/n_sl.o(.text);
        build/us/ultra/src/audio/sl.o(.text);
        build/us/ultra/src/audio/drvrnew.o(.text);
        build/us/ultra/src/n_audio/n_auxbus.o(.text);
        build/us/ultra/src/audio/reverb.o(.text);
        build/us/ultra/src/audio/heapalloc.o(.text);
        build/us/ultra/src/n_audio/n_drvrnew.o(.text);
        build/us/ultra/src/n_audio/n_reverb.o(.text);
        build/us/ultra/src/n_audio/n_synthesizer.o(.text);
        build/us/ultra/src/n_audio/n_env.o(.text);
        build/us/ultra/src/audio/heapinit.o(.text);
        build/us/src/lib/codeseg1/aud_dma.o(.text);
        build/us/ultra/src/io/aigetstat.o(.text);
        build/us/ultra/src/io/aisetfreq.o(.text);
        build/us/src/lib/codeseg1/aud_samples.o(.text);
        build/us/ultra/src/io/aisetnextbuf.o(.text);
        build/us/asm/lib/codeseg1/probetlb.o(.text);
        build/us/ultra/src/io/si.o(.text);
        build/us/asm/lib/codeseg1/setcompare.o(.text);
        build/us/ultra/src/io/pfsgetstatus.o(.text);
        build/us/ultra/src/n_audio/n_syndelete.o(.text);
        build/us/ultra/src/audio/synthesizer.o(.text);
        build/us/ultra/src/audio/syndelete.o(.text);
        build/us/ultra/src/audio/filter.o(.text);
        build/us/ultra/src/audio/env.o(.text);
        build/us/ultra/src/audio/load.o(.text);
        build/us/ultra/src/audio/resample.o(.text);
        build/us/ultra/src/audio/auxbus.o(.text);
        build/us/ultra/src/audio/mainbus.o(.text);
        build/us/ultra/src/audio/save.o(.text);
        build/us/ultra/src/n_audio/n_synallocfx.o(.text);
        build/us/ultra/src/n_audio/n_save.o(.text);
        build/us/src/lib/sn/divdi3.o(.text);
        build/us/ultra/src/n_audio/n_load.o(.text);
        build/us/ultra/src/n_audio/n_resample.o(.text);
        build/us/ultra/src/io/epidma.o(.text);
        build/us/ultra/src/io/driverominit.o(.text);
        build/us/ultra/src/io/aigetlen.o(.text);
        build/us/ultra/src/io/ai.o(.text);
        build/us/ultra/src/audio/synallocfx.o(.text);
        build/us/ultra/src/audio/copy.o(.text);
        build/us/ultra/src/n_audio/n_mainbus.o(.text);
        rocket_codeseg0_codeseg0 = .;
        build/us/src/rocket/codeseg0/codeseg0.o(.data);
        n_aspMain_data = .;
        build/us/bin/n_aspMain_data.o(.data);
        f3dex2_data = .;
        build/us/bin/f3dex2_data.o(.data);
        ___ultra_src_sched_sched = .;
        build/us/ultra/src/sched/sched.o(.data);
        ___ultra_src_io_pimgr = .;
        build/us/ultra/src/io/pimgr.o(.data);
        lib_codeseg1_player = .;
        build/us/src/lib/codeseg1/player.o(.data);
        ___ultra_src_os_initialize = .;
        build/us/ultra/src/os/initialize.o(.data);
        ___ultra_src_io_controller = .;
        build/us/ultra/src/io/controller.o(.data);
        ___ultra_src_gu_random = .;
        build/us/ultra/src/gu/random.o(.data);
        ___ultra_src_io_motor = .;
        build/us/ultra/src/io/motor.o(.data);
        ___ultra_src_io_vimgr = .;
        build/us/ultra/src/io/vimgr.o(.data);
        ___ultra_src_io_vitbl = .;
        build/us/ultra/src/io/vitbl.o(.data);
        ___ultra_src_os_thread = .;
        build/us/ultra/src/os/thread.o(.data);
        exceptasm_data = .;
        build/us/asm/data/exceptasm_data.data.o(.data);
        ___ultra_src_io_piacs = .;
        build/us/ultra/src/io/piacs.o(.data);
        lib_codeseg1_player_fx = .;
        build/us/src/lib/codeseg1/player_fx.o(.data);
        lib_codeseg1_aud_sched = .;
        build/us/src/lib/codeseg1/aud_sched.o(.data);
        lib_codeseg1_aud_thread = .;
        build/us/src/lib/codeseg1/aud_thread.o(.data);
        ___ultra_src_os_timerintr = .;
        build/us/ultra/src/os/timerintr.o(.data);
        ___ultra_src_io_siacs = .;
        build/us/ultra/src/io/siacs.o(.data);
        ___ultra_src_io_vi = .;
        build/us/ultra/src/io/vi.o(.data);
        ___ultra_src_n_audio_n_sl = .;
        build/us/ultra/src/n_audio/n_sl.o(.data);
        ___ultra_src_audio_sl = .;
        build/us/ultra/src/audio/sl.o(.data);
        ___ultra_src_audio_drvrnew = .;
        build/us/ultra/src/audio/drvrnew.o(.data);
        _1A6E0 = .;
        build/us/bin/1A6E0.o(.data);
        ___ultra_src_n_audio_n_drvrnew = .;
        build/us/ultra/src/n_audio/n_drvrnew.o(.data);
        ___ultra_src_n_audio_n_reverb = .;
        build/us/ultra/src/n_audio/n_reverb.o(.data);
        ___ultra_src_n_audio_n_env = .;
        build/us/ultra/src/n_audio/n_env.o(.data);
        lib_codeseg1_aud_samples = .;
        build/us/src/lib/codeseg1/aud_samples.o(.data);
        ___ultra_src_io_aisetnextbuf = .;
        build/us/ultra/src/io/aisetnextbuf.o(.data);
        ___ultra_src_io_vimodepallan1 = .;
        build/us/ultra/src/io/vimodepallan1.o(.data);
        ___ultra_src_io_vimodempallan1 = .;
        build/us/ultra/src/io/vimodempallan1.o(.data);
        ___ultra_src_io_vimodentsclan1 = .;
        build/us/ultra/src/io/vimodentsclan1.o(.data);
        ___ultra_src_audio_env = .;
        build/us/ultra/src/audio/env.o(.data);
        codesegs0_1_DATA_END = .;
    }
    __romPos += SIZEOF(.codesegs0_1);
    codesegs0_1_ROM_END = __romPos;

    codeseg2_ROM_START = __romPos;
    codeseg2_VRAM = ADDR(.codeseg2);
    .codeseg2 : AT(codeseg2_ROM_START) SUBALIGN(16)
    {
        build/us/src/rocket/codeseg2/codeseg2_3.o(.rdata);
        build/us/asm/data/rocket/codeseg2/codeseg2_18.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_20.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_23.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_29.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_35.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_37.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_38.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_40.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_42.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_44.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_46.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_53.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_56.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_63.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_66.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_67.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_68.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_69.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_71.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_75.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_76.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_82.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_88.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_90.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_92.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_94.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_96.rodata.o(.rodata);
        build/us/src/rocket/codeseg2/codeseg2_103.o(.rdata);
        build/us/asm/data/rocket/codeseg2/codeseg2_106.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_107.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_109.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_111.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_114.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_115.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_116.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_119.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_133.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_137.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_138.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_140.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_144.rodata.o(.rodata);
        build/us/src/rocket/codeseg2/codeseg2_152.o(.rdata);
        build/us/asm/data/rocket/codeseg2/codeseg2_153.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_154.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_158.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_160.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_164.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_167.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_169.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_173.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_176.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_184.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_185.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_188.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_190.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_192.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_197.rodata.o(.rodata);
        build/us/src/rocket/codeseg2/codeseg2_198.o(.rdata);
        build/us/src/rocket/codeseg2/codeseg2_203.o(.rdata);
        build/us/src/rocket/codeseg2/codeseg2_204.o(.rdata);
        build/us/src/rocket/codeseg2/codeseg2_207.o(.rdata);
        build/us/asm/data/rocket/codeseg2/codeseg2_210.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_214.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_219.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_221.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_227.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_228.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_230.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_233.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_240.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_243.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_244.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_245.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_247.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_249.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_263.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_266.rodata.o(.rodata);
        build/us/src/rocket/codeseg2/codeseg2_267.o(.rdata);
        build/us/asm/data/rocket/codeseg2/codeseg2_270.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_274.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_276.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_279.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_281.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_283.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_285.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_293.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_296.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_299.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_300.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_303.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_304.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_308.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_311.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_312.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_317.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_321.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_322.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_327.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_330.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_331.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_335.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_341.rodata.o(.rodata);
        build/us/src/rocket/codeseg2/codeseg2_343.o(.rdata);
        build/us/asm/data/rocket/codeseg2/codeseg2_346.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_352.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_367.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_368.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_370.rodata.o(.rodata);
        build/us/src/rocket/codeseg2/codeseg2_375.o(.rdata);
        build/us/asm/data/rocket/codeseg2/codeseg2_378.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_380.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_392.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_395.rodata.o(.rodata);
        build/us/src/rocket/codeseg2/codeseg2_396.o(.rdata);
        build/us/asm/data/rocket/codeseg2/codeseg2_405.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_408.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_410.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_413.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_414.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_417.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_420.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_421.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_424.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_428.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_430.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_432.rodata.o(.rodata);
        build/us/src/rocket/codeseg2/codeseg2_433.o(.rdata);
        build/us/asm/data/rocket/codeseg2/codeseg2_435.rodata.o(.rodata);
        build/us/src/rocket/codeseg2/codeseg2_439.o(.rdata);
        build/us/asm/data/rocket/codeseg2/codeseg2_443.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_449.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_451.rodata.o(.rodata);
        build/us/asm/data/rocket/codeseg2/codeseg2_452.rodata.o(.rodata);
        codeseg2_TEXT_START = .;
        build/us/src/rocket/codeseg2/codeseg2_0.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_1.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_2.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_3.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_16.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_17.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_18.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_19.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_20.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_21.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_22.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_23.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_27.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_28.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_29.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_30.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_31.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_32.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_33.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_34.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_35.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_36.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_37.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_38.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_40.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_41.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_42.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_44.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_46.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_53.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_56.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_61.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_62.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_63.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_66.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_67.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_68.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_69.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_70.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_71.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_75.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_76.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_78.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_79.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_80.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_81.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_82.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_88.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_89.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_90.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_92.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_93.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_94.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_96.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_103.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_104.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_105.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_106.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_107.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_108.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_109.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_110.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_111.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_114.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_115.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_116.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_117.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_118.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_119.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_121.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_122.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_123.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_124.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_125.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_126.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_127.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_128.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_129.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_130.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_131.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_132.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_133.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_137.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_138.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_140.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_144.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_145.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_146.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_147.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_148.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_149.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_150.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_151.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_152.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_153.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_154.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_157.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_158.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_160.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_163.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_164.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_167.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_169.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_171.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_172.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_173.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_174.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_175.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_176.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_178.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_179.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_180.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_181.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_182.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_183.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_184.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_185.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_188.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_189.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_190.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_191.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_192.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_195.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_196.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_197.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_198.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_203.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_204.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_207.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_209.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_210.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_214.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_219.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_221.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_222.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_223.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_224.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_225.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_226.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_227.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_228.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_230.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_231.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_232.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_233.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_240.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_243.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_244.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_245.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_247.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_248.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_249.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_261.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_262.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_263.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_266.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_267.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_269.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_270.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_272.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_273.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_274.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_276.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_277.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_278.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_279.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_281.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_282.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_283.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_285.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_293.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_296.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_298.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_299.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_300.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_301.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_302.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_303.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_304.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_308.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_311.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_312.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_317.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_320.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_321.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_322.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_324.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_325.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_326.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_327.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_330.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_331.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_332.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_333.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_334.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_335.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_341.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_343.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_346.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_351.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_352.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_365.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_366.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_367.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_368.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_369.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_370.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_371.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_372.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_373.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_375.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_376.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_377.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_378.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_380.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_382.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_383.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_384.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_385.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_386.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_387.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_388.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_389.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_390.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_391.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_392.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_393.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_394.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_395.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_396.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_404.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_405.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_406.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_407.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_408.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_410.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_411.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_412.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_413.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_414.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_415.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_416.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_417.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_420.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_421.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_422.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_423.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_424.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_426.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_427.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_428.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_429.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_430.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_432.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_433.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_434.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_435.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_436.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_437.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_438.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_439.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_442.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_443.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_446.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_447.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_448.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_449.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_451.o(.text);
        build/us/src/rocket/codeseg2/codeseg2_452.o(.text);
        codeseg2_TEXT_END = .;
        codeseg2_DATA_START = .;
        all_data_data = .;
        build/us/asm/data/all_data.data.o(.data);
        rocket_codeseg2_codeseg2_395 = .;
        build/us/src/rocket/codeseg2/codeseg2_395.o(.data);
        all_data_2_data = .;
        build/us/asm/data/all_data_2.data.o(.data);
        codeseg2_DATA_END = .;
    }
    __romPos += SIZEOF(.codeseg2);
    codeseg2_ROM_END = __romPos;

    codesegs0_1_bss_ROM_START = __romPos;
    codesegs0_1_bss_VRAM = ADDR(.codesegs0_1_bss);
    .codesegs0_1_bss (NOLOAD) : AT(codesegs0_1_bss_ROM_START) SUBALIGN(16)
    {
        codesegs0_1_bss_DATA_END = .;
        codesegs0_1_bss_BSS_START = .;
        build/us/src/rocket/codeseg0/codeseg0.o(.bss);
        build/us/ultra/src/io/pimgr.o(.bss);
        build/us/src/lib/codeseg1/player.o(.bss);
        build/us/ultra/src/os/initialize.o(.bss);
        build/us/ultra/src/io/conteepread.o(.bss);
        build/us/ultra/src/io/controller.o(.bss);
        build/us/ultra/src/os/seteventmesg.o(.bss);
        build/us/ultra/src/io/motor.o(.bss);
        build/us/ultra/src/io/vimgr.o(.bss);
        build/us/ultra/src/io/sptask.o(.bss);
        build/us/ultra/src/io/cartrominit.o(.bss);
        build/us/ultra/src/io/leodiskinit.o(.bss);
        build/us/ultra/src/io/piacs.o(.bss);
        build/us/src/lib/codeseg1/player_fx.o(.bss);
        build/us/src/lib/codeseg1/aud_sched.o(.bss);
        build/us/src/lib/codeseg1/lib_memory.o(.bss);
        build/us/src/lib/codeseg1/aud_thread.o(.bss);
        build/us/ultra/src/os/timerintr.o(.bss);
        build/us/ultra/src/io/siacs.o(.bss);
        build/us/ultra/src/io/pfsisplug.o(.bss);
        build/us/ultra/src/os/kdebugserver.o(.bss);
        build/us/ultra/src/io/leointerrupt.o(.bss);
        build/us/src/lib/codeseg1/aud_dma.o(.bss);
        build/us/src/lib/codeseg1/aud_samples.o(.bss);
        build/us/ultra/src/io/driverominit.o(.bss);
        codesegs0_1_bss_BSS_END = .;
    }
    codeseg2_bss_ROM_START = __romPos;
    codeseg2_bss_VRAM = ADDR(.codeseg2_bss);
    .codeseg2_bss (NOLOAD) : AT(codeseg2_bss_ROM_START) SUBALIGN(16)
    {
        codeseg2_bss_DATA_END = .;
        codeseg2_bss_BSS_START = .;
        build/us/asm/data/rocket/codeseg2/codeseg2_bss.bss.o(.bss);
        codeseg2_bss_BSS_END = .;
    }

    assets_ROM_START = __romPos;
    assets_VRAM = ADDR(.assets);
    .assets : AT(assets_ROM_START) SUBALIGN(16)
    {
        assets_TEXT_END = .;
        assets_DATA_START = .;
        assets = .;
        build/us/bin/assets.o(.data);
        assets_DATA_END = .;
    }
    __romPos += SIZEOF(.assets);
    assets_ROM_END = fxbank_ROM_START;

    fxbank_ROM_START = __romPos;
    fxbank_VRAM = ADDR(.fxbank);
    .fxbank : AT(fxbank_ROM_START) SUBALIGN(16)
    {
        fxbank_TEXT_END = .;
        fxbank_DATA_START = .;
        fxbank = .;
        build/us/bin/fxbank.o(.data);
        fxbank_DATA_END = .;
    }
    __romPos += SIZEOF(.fxbank);
    fxbank_ROM_END = ptrbank_ROM_START;

    ptrbank_ROM_START = __romPos;
    ptrbank_VRAM = ADDR(.ptrbank);
    .ptrbank : AT(ptrbank_ROM_START) SUBALIGN(16)
    {
        ptrbank_TEXT_END = .;
        ptrbank_DATA_START = .;
        ptrbank = .;
        build/us/bin/ptrbank.o(.data);
        ptrbank_DATA_END = .;
    }
    __romPos += SIZEOF(.ptrbank);
    ptrbank_ROM_END = wavebank_ROM_START;

    wavebank_ROM_START = __romPos;
    wavebank_VRAM = ADDR(.wavebank);
    .wavebank : AT(wavebank_ROM_START) SUBALIGN(16)
    {
        wavebank_TEXT_END = .;
        wavebank_DATA_START = .;
        wavebank = .;
        build/us/bin/wavebank.o(.data);
        wavebank_DATA_END = .;
    }
    __romPos += SIZEOF(.wavebank);
    wavebank_ROM_END = song00_ROM_START;

    song00_ROM_START = __romPos;
    song00_VRAM = ADDR(.song00);
    .song00 : AT(song00_ROM_START) SUBALIGN(16)
    {
        song00_TEXT_END = .;
        song00_DATA_START = .;
        song00 = .;
        build/us/bin/song00.o(.data);
        song00_DATA_END = .;
    }
    __romPos += SIZEOF(.song00);
    song00_ROM_END = song01_ROM_START;

    song01_ROM_START = __romPos;
    song01_VRAM = ADDR(.song01);
    .song01 : AT(song01_ROM_START) SUBALIGN(16)
    {
        song01_TEXT_END = .;
        song01_DATA_START = .;
        song01 = .;
        build/us/bin/song01.o(.data);
        song01_DATA_END = .;
    }
    __romPos += SIZEOF(.song01);
    song01_ROM_END = song02_ROM_START;

    song02_ROM_START = __romPos;
    song02_VRAM = ADDR(.song02);
    .song02 : AT(song02_ROM_START) SUBALIGN(16)
    {
        song02_TEXT_END = .;
        song02_DATA_START = .;
        song02 = .;
        build/us/bin/song02.o(.data);
        song02_DATA_END = .;
    }
    __romPos += SIZEOF(.song02);
    song02_ROM_END = song03_ROM_START;

    song03_ROM_START = __romPos;
    song03_VRAM = ADDR(.song03);
    .song03 : AT(song03_ROM_START) SUBALIGN(16)
    {
        song03_TEXT_END = .;
        song03_DATA_START = .;
        song03 = .;
        build/us/bin/song03.o(.data);
        song03_DATA_END = .;
    }
    __romPos += SIZEOF(.song03);
    song03_ROM_END = song04_ROM_START;

    song04_ROM_START = __romPos;
    song04_VRAM = ADDR(.song04);
    .song04 : AT(song04_ROM_START) SUBALIGN(16)
    {
        song04_TEXT_END = .;
        song04_DATA_START = .;
        song04 = .;
        build/us/bin/song04.o(.data);
        song04_DATA_END = .;
    }
    __romPos += SIZEOF(.song04);
    song04_ROM_END = song05_ROM_START;

    song05_ROM_START = __romPos;
    song05_VRAM = ADDR(.song05);
    .song05 : AT(song05_ROM_START) SUBALIGN(16)
    {
        song05_TEXT_END = .;
        song05_DATA_START = .;
        song05 = .;
        build/us/bin/song05.o(.data);
        song05_DATA_END = .;
    }
    __romPos += SIZEOF(.song05);
    song05_ROM_END = song06_ROM_START;

    song06_ROM_START = __romPos;
    song06_VRAM = ADDR(.song06);
    .song06 : AT(song06_ROM_START) SUBALIGN(16)
    {
        song06_TEXT_END = .;
        song06_DATA_START = .;
        song06 = .;
        build/us/bin/song06.o(.data);
        song06_DATA_END = .;
    }
    __romPos += SIZEOF(.song06);
    song06_ROM_END = song07_ROM_START;

    song07_ROM_START = __romPos;
    song07_VRAM = ADDR(.song07);
    .song07 : AT(song07_ROM_START) SUBALIGN(16)
    {
        song07_TEXT_END = .;
        song07_DATA_START = .;
        song07 = .;
        build/us/bin/song07.o(.data);
        song07_DATA_END = .;
    }
    __romPos += SIZEOF(.song07);
    song07_ROM_END = song08_ROM_START;

    song08_ROM_START = __romPos;
    song08_VRAM = ADDR(.song08);
    .song08 : AT(song08_ROM_START) SUBALIGN(16)
    {
        song08_TEXT_END = .;
        song08_DATA_START = .;
        song08 = .;
        build/us/bin/song08.o(.data);
        song08_DATA_END = .;
    }
    __romPos += SIZEOF(.song08);
    song08_ROM_END = song09_ROM_START;

    song09_ROM_START = __romPos;
    song09_VRAM = ADDR(.song09);
    .song09 : AT(song09_ROM_START) SUBALIGN(16)
    {
        song09_TEXT_END = .;
        song09_DATA_START = .;
        song09 = .;
        build/us/bin/song09.o(.data);
        song09_DATA_END = .;
    }
    __romPos += SIZEOF(.song09);
    song09_ROM_END = song0A_ROM_START;

    song0A_ROM_START = __romPos;
    song0A_VRAM = ADDR(.song0A);
    .song0A : AT(song0A_ROM_START) SUBALIGN(16)
    {
        song0A_TEXT_END = .;
        song0A_DATA_START = .;
        song0A = .;
        build/us/bin/song0A.o(.data);
        song0A_DATA_END = .;
    }
    __romPos += SIZEOF(.song0A);
    song0A_ROM_END = song0B_ROM_START;

    song0B_ROM_START = __romPos;
    song0B_VRAM = ADDR(.song0B);
    .song0B : AT(song0B_ROM_START) SUBALIGN(16)
    {
        song0B_TEXT_END = .;
        song0B_DATA_START = .;
        song0B = .;
        build/us/bin/song0B.o(.data);
        song0B_DATA_END = .;
    }
    __romPos += SIZEOF(.song0B);
    song0B_ROM_END = song0C_ROM_START;

    song0C_ROM_START = __romPos;
    song0C_VRAM = ADDR(.song0C);
    .song0C : AT(song0C_ROM_START) SUBALIGN(16)
    {
        song0C_TEXT_END = .;
        song0C_DATA_START = .;
        song0C = .;
        build/us/bin/song0C.o(.data);
        song0C_DATA_END = .;
    }
    __romPos += SIZEOF(.song0C);
    song0C_ROM_END = song0D_ROM_START;

    song0D_ROM_START = __romPos;
    song0D_VRAM = ADDR(.song0D);
    .song0D : AT(song0D_ROM_START) SUBALIGN(16)
    {
        song0D_TEXT_END = .;
        song0D_DATA_START = .;
        song0D = .;
        build/us/bin/song0D.o(.data);
        song0D_DATA_END = .;
    }
    __romPos += SIZEOF(.song0D);
    song0D_ROM_END = song0E_ROM_START;

    song0E_ROM_START = __romPos;
    song0E_VRAM = ADDR(.song0E);
    .song0E : AT(song0E_ROM_START) SUBALIGN(16)
    {
        song0E_TEXT_END = .;
        song0E_DATA_START = .;
        song0E = .;
        build/us/bin/song0E.o(.data);
        song0E_DATA_END = .;
    }
    __romPos += SIZEOF(.song0E);
    song0E_ROM_END = song0F_ROM_START;

    song0F_ROM_START = __romPos;
    song0F_VRAM = ADDR(.song0F);
    .song0F : AT(song0F_ROM_START) SUBALIGN(16)
    {
        song0F_TEXT_END = .;
        song0F_DATA_START = .;
        song0F = .;
        build/us/bin/song0F.o(.data);
        song0F_DATA_END = .;
    }
    __romPos += SIZEOF(.song0F);
    song0F_ROM_END = song10_ROM_START;

    song10_ROM_START = __romPos;
    song10_VRAM = ADDR(.song10);
    .song10 : AT(song10_ROM_START) SUBALIGN(16)
    {
        song10_TEXT_END = .;
        song10_DATA_START = .;
        song10 = .;
        build/us/bin/song10.o(.data);
        song10_DATA_END = .;
    }
    __romPos += SIZEOF(.song10);
    song10_ROM_END = song11_ROM_START;

    song11_ROM_START = __romPos;
    song11_VRAM = ADDR(.song11);
    .song11 : AT(song11_ROM_START) SUBALIGN(16)
    {
        song11_TEXT_END = .;
        song11_DATA_START = .;
        song11 = .;
        build/us/bin/song11.o(.data);
        song11_DATA_END = .;
    }
    __romPos += SIZEOF(.song11);
    song11_ROM_END = song12_ROM_START;

    song12_ROM_START = __romPos;
    song12_VRAM = ADDR(.song12);
    .song12 : AT(song12_ROM_START) SUBALIGN(16)
    {
        song12_TEXT_END = .;
        song12_DATA_START = .;
        song12 = .;
        build/us/bin/song12.o(.data);
        song12_DATA_END = .;
    }
    __romPos += SIZEOF(.song12);
    song12_ROM_END = song13_ROM_START;

    song13_ROM_START = __romPos;
    song13_VRAM = ADDR(.song13);
    .song13 : AT(song13_ROM_START) SUBALIGN(16)
    {
        song13_TEXT_END = .;
        song13_DATA_START = .;
        song13 = .;
        build/us/bin/song13.o(.data);
        song13_DATA_END = .;
    }
    __romPos += SIZEOF(.song13);
    song13_ROM_END = song14_ROM_START;

    song14_ROM_START = __romPos;
    song14_VRAM = ADDR(.song14);
    .song14 : AT(song14_ROM_START) SUBALIGN(16)
    {
        song14_TEXT_END = .;
        song14_DATA_START = .;
        song14 = .;
        build/us/bin/song14.o(.data);
        song14_DATA_END = .;
    }
    __romPos += SIZEOF(.song14);
    song14_ROM_END = song15_ROM_START;

    song15_ROM_START = __romPos;
    song15_VRAM = ADDR(.song15);
    .song15 : AT(song15_ROM_START) SUBALIGN(16)
    {
        song15_TEXT_END = .;
        song15_DATA_START = .;
        song15 = .;
        build/us/bin/song15.o(.data);
        song15_DATA_END = .;
    }
    __romPos += SIZEOF(.song15);
    song15_ROM_END = song16_ROM_START;

    song16_ROM_START = __romPos;
    song16_VRAM = ADDR(.song16);
    .song16 : AT(song16_ROM_START) SUBALIGN(16)
    {
        song16_TEXT_END = .;
        song16_DATA_START = .;
        song16 = .;
        build/us/bin/song16.o(.data);
        song16_DATA_END = .;
    }
    __romPos += SIZEOF(.song16);
    song16_ROM_END = __romPos;

    /DISCARD/ :
    {
        *(*);
    }
}
