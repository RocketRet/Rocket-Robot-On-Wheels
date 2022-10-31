#include <include_asm.h>
#include <ultra64.h>


struct unkD_800E4DD0 {
    u32 romAddr;
    u32 ramAddr;
    u32 size;
    u32 *unkC;
};

void func_80061A58();

extern struct unkD_800E4DD0 D_800E4DD0[];
extern s32 D_800AAF60;
extern s32 D_800AAF64;
extern OSMesgQueue D_80017DFC;

void func_80061B90(u32 romAddr,u32 ramAddr,u32 size,u32 *arg3)
{
    s32 index = D_800AAF64;
    s32 bVar1;

    D_800E4DD0[index].romAddr = romAddr;
    D_800E4DD0[index].ramAddr = ramAddr;
    D_800E4DD0[index].size = size;
    D_800E4DD0[index].unkC = arg3;
    bVar1 = D_800AAF60 == index;
    D_800AAF64 = (index + 1) % 5;
    *arg3 = 0;
    if (bVar1)
    {
        func_80061A58();
    }
}

void func_80061C18()
{
    OSMesg mesg;
  
    if (D_800E4DD0[D_800AAF60].unkC) {
        if (osRecvMesg(&D_80017DFC, &mesg, OS_MESG_NOBLOCK) == 0) {
            *D_800E4DD0[D_800AAF60].unkC = D_800E4DD0[D_800AAF60].ramAddr;
            D_800E4DD0[D_800AAF60].unkC = NULL;
            D_800AAF60 = (D_800AAF60 + 1) % 5;
        }
    }
    func_80061A58();
}
