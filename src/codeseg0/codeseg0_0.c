#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg0/codeseg0_0", func_80000DD0);

INCLUDE_ASM(s32, "codeseg0/codeseg0_0", func_80000E64);

INCLUDE_ASM(s32, "codeseg0/codeseg0_0", func_80000F38);

INCLUDE_ASM(s32, "codeseg0/codeseg0_0", func_80000FC4);

void func_8001DE00(void);
void func_80041908(void);
void func_800638EC(s32);
void osSendMesg(void *, void *, s32);
void osRecvMesg(void *, void *, s32);
void func_800954FC(void);
void func_8008FC1C(void);

void func_80061C18(void);
void func_80099A34(void);

void func_8004E64C(void);
void func_80046CBC(void);
void func_80037E60(void *, s32);
void func_8007F22C(void *);

void func_80075100(f32);
void func_80074ADC(void *, f32);
void func_8004ED04(void);
void func_8004E60C(void);

extern u32 D_80017DE4; // OSMesgQueue
extern u32 D_800180A0; // OSMesgQueue
extern u32 D_800A638C;
extern u32 D_8009FE10;
extern u32 D_8009F094;
extern u32 D_800AB9C8;


extern f32 D_80000500; // 1.0f / 6.0f

struct unkD_800A6380 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u16 unkC;
};

extern struct unkD_800A6380 D_800A6380;

// TODO different compiler
// 
// void func_80001248(void *arg0)
// {
//     f32 f20;
//     s16 sp10[2];
//     s32 *sp18; // OSMesg

//     func_8001DE00();
//     func_80041908();
//     func_800638EC(0);
//     sp10[0] = 0xFF;
//     osSendMesg(&D_80017DE4, &sp10, 1); // OS_MESG_BLOCK
//     f20 = D_80000500;
//     while (1)
//     {
//         osRecvMesg(&D_800180A0, &sp18, 1); // OS_MESG_BLOCK
//         if (sp18[0] != 0)
//         {
//             if (sp18[0] == 1)
//             {
//                 func_800954FC();
//             }
//         }
//         else
//         {
//             func_8008FC1C();
//             if (D_800A6380.unkC)
//             {
//                 func_80099A34();
//             }
//             func_80061C18();
//             if (sp18[2] == 0)
//             {
//                 func_8004E64C();
//                 func_80046CBC();
//                 func_80037E60(&D_8009FE10, sp18[1]);
//                 func_8007F22C(&D_8009F094);
//             }
//             func_80075100(sp18[1] * f20);
//             func_80074ADC(&D_800AB9C8, sp18[1] * f20);
//             func_8004ED04();
//             func_8004E60C();
//         }
//         sp10[0] = 0xFF;
//         osSendMesg(&D_80017DE4, &sp10, 1); // OS_MESG_BLOCK
//     }
//     return;
// }

INCLUDE_ASM(s32, "codeseg0/codeseg0_0", func_80001248);
