#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


extern u32 D_800E4824;
extern OSMesgQueue D_800A63A8;
extern u32 D_800A6378;
extern u32 D_800A637C;

INCLUDE_ASM(s32, "codeseg2/codeseg2_169", func_8004E4E0);

void func_8004E548(u32 arg0)
{
    D_800A637C |= arg0;
    func_8004E5A4();
}

void func_8004E574(s32 arg0)
{
    D_800A637C &= ~arg0;
    func_8004E5A4();
}

extern struct ControllerData D_800A6380;

void func_8004E5A4()
{
    if ((D_800A637C & 0x01) == 0)
    {
        D_800A6378 = 0;
    }
    else if (D_800A637C & 0x02)
    {
        D_800A6378 = 4;
    }
    else if (D_800A637C & 0x04)
    {
        D_800A6378 = 8;
    }
    else if (D_800A637C & 0x08)
    {
        D_800A6378 = 4;
    }
    else
    {
        D_800A6378 = 7;
    }
}

s32 func_8004E60C()
{
    s32 ret = D_800E4824;
    if (ret == 0)
    {
        osContStartReadData(&D_800A63A8);
        ret = 1;
        D_800E4824 = 1;
    }
    return ret;
}

void func_8004E64C()
{
    if (D_800E4824)
    {
        if (osRecvMesg(&D_800A63A8, NULL, OS_MESG_NOBLOCK) == 0)
        {
            func_8004E6D4();
        }
    }
}

void func_8004E694()
{
    if (D_800E4824)
    {
        osRecvMesg(&D_800A63A8, NULL, OS_MESG_BLOCK);
        func_8004E6D4();
    }
}

struct unkD_800A5FC4
{
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

extern struct unkD_800A5FC4 D_800A5FC4[MAXCONTROLLERS];

// TODO finish this
// void func_8004E6D4()
// {
//     OSContPad pads[MAXCONTROLLERS];
    
//     osContGetReadData(pads);
//     D_800E4824 = 0;
//     if (pads[0].errno == 0)
//     {
//         s32 i;
//         for (i = 0; i < MAXCONTROLLERS; i++)
//         {
//             f32 scaledX = pads[i].stick_x * D_800A5FC4[i].unk0;
//             f32 scaledY = pads[i].stick_y * D_800A5FC4[i].unk4;
//             f32 mag = scaledX + scaledY;
//             if (mag < 0)
//             {
//                 if (mag > D_800A5FC4[i].unkC)
//                 {
//                     D_800A5FC4[i].unkC = mag;
//                 }
//             }
//             else
//             {
//                 if (mag < D_800A5FC4[i].unk8)
//                 {
//                     D_800A5FC4[i].unk8 = mag;
//                 }
//             }
//         }
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_169", func_8004E6D4);

void clear_buttons_pressed(struct ControllerData *contData, u32 buttons)
{
    contData->buttonPressed &= ~buttons;
}

extern u32 D_800A63C8;

void func_8004E92C()
{
    D_800A63C8 = 0;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_169", func_8004E938);
