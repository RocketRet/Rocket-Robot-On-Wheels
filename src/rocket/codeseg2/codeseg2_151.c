#include <include_asm.h>
#include <ultra64.h>
#include <PR/sched.h>
#include <types.h>

struct unk800473F0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};

extern struct GfxContext D_800A5DA8; // 0x10 bytes
extern struct unk800473F0 D_800A5DB8; // 0x04 bytes
extern struct GfxTask* D_800A5DBC; // 0x04 bytes

extern u32* D_800AAF7C;
extern u32 D_800AAF84;
extern OSMesgQueue *gSchedMesgQueue;

extern u8 _binary_bin_rspboot_code_bin_start[];
extern u8 _binary_bin_rspboot_code_bin_end[];

extern u8 _binary_bin_f3dex2_code_bin_start[];
extern u8 _binary_bin_f3dex2_data_bin_start[];

extern u64 D_800D1770[];
extern u64 D_800E4820[];

extern u64 D_800C0460[SP_DRAM_STACK_SIZE64];
extern u64 D_800C0860[OS_YIELD_DATA_SIZE];


extern OSMesgQueue D_80017DE4;


// void schedule_gfx_task()
// {
//     struct unk800473F0 sp10;
//     struct unk800473F0 sp18;
//     struct unk800473F0 sp20;
//     struct GfxTask *ctx = D_800A5DBC;
//     OSScTask *curTask = &ctx->schedTask;
//     gDPFullSync(D_800A5DA8.dlHead++);
//     gSPEndDisplayList(D_800A5DA8.dlHead++);


//     if ((D_800A5DB8.unk0 & 0xF) )
//     {
//         if ((D_800A5DB8.unk0 & 0xF0) && (D_800A5DB8.unk1) && (D_800A5DB8.unk2))
//             sp10 = D_800A5DB8;
//     }

// // /* 480CC 800474CC 24020005 */  addiu      $v0, $zero, 5
// // /* 480D0 800474D0 14820003 */  bne        $a0, $v0, .L800474E0
// // /* 480D4 800474D4 24020003 */   addiu     $v0, $zero, 3
// // /* 480D8 800474D8 08011D4E */  j          .L80047538
// // /* 480DC 800474DC 24030007 */   addiu     $v1, $zero, 7
// // .L800474E0:
// // /* 480E0 800474E0 14820003 */  bne        $a0, $v0, .L800474F0
// // /* 480E4 800474E4 24020004 */   addiu     $v0, $zero, 4
// // /* 480E8 800474E8 08011D4E */  j          .L80047538
// // /* 480EC 800474EC 24030005 */   addiu     $v1, $zero, 5
// // .L800474F0:
// // /* 480F0 800474F0 14820003 */  bne        $a0, $v0, .L80047500
// // /* 480F4 800474F4 24030020 */   addiu     $v1, $zero, 0x20
// // /* 480F8 800474F8 08011D4E */  j          .L80047538
// // /* 480FC 800474FC 24030006 */   addiu     $v1, $zero, 6
// // .L80047500:
// // /* 48100 80047500 93A20020 */  lbu        $v0, 0x20($sp)
// // /* 48104 80047504 304200F0 */  andi       $v0, $v0, 0xf0
// // /* 48108 80047508 14430003 */  bne        $v0, $v1, .L80047518
// // /* 4810C 8004750C 24020002 */   addiu     $v0, $zero, 2
// // /* 48110 80047510 08011D4E */  j          .L80047538
// // /* 48114 80047514 24030004 */   addiu     $v1, $zero, 4
// // .L80047518:
// // /* 48118 80047518 14820003 */  bne        $a0, $v0, .L80047528
// // /* 4811C 8004751C 24030002 */   addiu     $v1, $zero, 2
// // /* 48120 80047520 08011D4E */  j          .L80047538
// // /* 48124 80047524 24030003 */   addiu     $v1, $zero, 3
// // .L80047528:
// // /* 48128 80047528 93A20021 */  lbu        $v0, 0x21($sp)
// // /* 4812C 8004752C 10430002 */  beq        $v0, $v1, .L80047538
// // /* 48130 80047530 38820001 */   xori      $v0, $a0, 1
// // /* 48134 80047534 2C430001 */  sltiu      $v1, $v0, 1
// // .L80047538:

//     curTask->list.t.type = M_GFXTASK;
//     curTask->list.t.flags = 0;
//     curTask->list.t.ucode_boot = _binary_bin_rspboot_code_bin_start;
//     curTask->list.t.ucode_boot_size = _binary_bin_rspboot_code_bin_end - _binary_bin_rspboot_code_bin_start;
//     curTask->list.t.ucode = _binary_bin_f3dex2_code_bin_start;
//     curTask->list.t.ucode_data = _binary_bin_f3dex2_data_bin_start;
//     curTask->list.t.output_buff = D_800D1770;
//     curTask->list.t.output_buff_size = D_800E4820;
//     curTask->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
//     curTask->list.t.dram_stack = D_800C0460;
//     curTask->list.t.dram_stack_size = SP_DRAM_STACK_SIZE8;
//     curTask->list.t.data_ptr = &ctx->unk14;
//     curTask->list.t.data_size = (uintptr_t)D_800A5DA8.dlHead - (uintptr_t)D_800A5DA8.dlStart;
//     curTask->list.t.yield_data_ptr = D_800C0860;
//     curTask->list.t.yield_data_size = OS_YIELD_DATA_SIZE;
//     // curTask->next = NULL;
//     curTask->flags = OS_SC_NEEDS_RDP | OS_SC_NEEDS_RSP | OS_SC_LAST_TASK | OS_SC_SWAPBUFFER;
//     curTask->msgQ = &D_80017DE4;
//     curTask->msg = ctx->unk124;
//     curTask->framebuffer = ctx->framebuffer;
//     osWritebackDCache(ctx, sizeof(struct GfxTask));
//     osWritebackDCache(D_800A5DA8.dlStart, (uintptr_t)D_800A5DA8.dlHead - (uintptr_t)D_800A5DA8.dlStart);
//     osWritebackDCache(D_800A5DA8.unkC, (uintptr_t)D_800A5DA8.dlStart + (uintptr_t)D_800A5DA8.unk0 - (uintptr_t)D_800A5DA8.unkC);
//     osWritebackDCache(D_800AAF7C, D_800AAF84);
//     osSendMesg(gSchedMesgQueue, curTask, OS_MESG_BLOCK);
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_151", schedule_gfx_task);
