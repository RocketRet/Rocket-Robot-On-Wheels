#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


extern void *D_800E48A0;
extern void *D_800E48A4;
extern void *D_800E48A8;
extern void *D_800E48AC;
extern s32 D_800E48B0;
extern s32 D_800E48B8;
extern s32 D_800E48C0[];

extern void *D_800AAF74;

void func_80061440()
{
    D_800E48A0 = D_800AAF74 + 0x39800;
    D_800E48A4 = D_800E48A8 = D_800E48AC = D_800E48A0;
}

void *main_alloc_nozero(s32 size)
{
    if (size == 0)
    {
        return NULL;
    }
    else
    {
        void *addr = D_800E48AC;
        D_800E48AC = (void*)((uintptr_t)addr + ALIGN(size,8));
        return addr;
    }
}

void clear_main_pool()
{
    D_800E48AC = D_800E48A8;
}

void memcpy(u8 *, u8 *, s32);

void *main_alloc_copy(s32 size, u8 *src)
{
    void *addr;
    if (size == 0)
    {
        addr = NULL;
    }
    else
    {
        void *tmpAddr = D_800E48AC;
        D_800E48AC = (void*)((uintptr_t)tmpAddr + ALIGN(size,8));
        addr = tmpAddr;
    }
    memcpy(addr, src, size);
    return addr;
}

void *main_alloc_bzero(s32 size)
{
    void *addr;
    if (size == 0)
    {
        addr = NULL;
    }
    else
    {
        void *tmpAddr = D_800E48AC;
        D_800E48AC = (void*)((uintptr_t)tmpAddr + ALIGN(size, 8));
        addr = tmpAddr;
    }
    bzero(addr, size);
    return addr;
}

void func_80061574()
{
    D_800E48C0[++D_800E48B8] = D_800E48B0;
}

s32 func_800615A4(s32 arg0)
{
    if (arg0 == 0)
    {
        return 0;
    }
    else
    {
        D_800E48B0 -= ALIGN(arg0, 8); 
        return D_800E48B0;
    }
}

void func_800615D4()
{
    D_800E48B0 = D_800E48C0[D_800E48B8--];
}

// TODO regalloc
// void memcpy(u8 *dst, u8 *src, s32 count)
// {
//     if (count >= 100 && ((uintptr_t)src & 3) == ((uintptr_t)dst & 3))
//     {
//         s32 byteCopies = (4 - ((uintptr_t)src & 3)) & 3;
//         s32 dwordCopies = (u32)(count - byteCopies) / 8;
//         s32 byteCopies2 = (count - byteCopies) & 7;
//         for (;--byteCopies >= 0;)
//         {
//             *dst++ = *src++;
//         }
//         for (;--dwordCopies >= 0;)
//         {
//             *(u64*)dst = *(u64*)src;
//             dst += 8;
//             src += 8;
//         }
//         for (; --byteCopies2 >= 0;)
//         {
//             *dst++ = *src++;
//         }
//     }
//     else
//     {
//         while (--count >= 0)
//         {
//             *dst++ = *src++;
//         }
//     }
// }

INCLUDE_ASM(void, "codeseg2/codeseg2_223", memcpy, u8*, u8*, s32);

void memmove(u8 *dst, u8 *src, s32 count)
{
    if (src < dst)
    {
        dst += count;
        src += count;
        while (--count >= 0)
        {
            *--dst = *--src;
        }
    }
    else
    {
        while (--count >= 0)
        {
            *dst++ = *src++;
        }
    }
}
