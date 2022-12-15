#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <audio.h>

extern void *D_800E48A0;
extern void *D_800E48A4;
extern void *D_800E48A8;
extern void *D_800E48AC;
extern void *D_800E48B0;
extern s32 D_800E48B8;
extern void *D_800E48C0[];

void func_80061440()
{
    D_800E48A0 = gAudioHeapPtr + AUDIO_HEAP_SIZE;
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

void custom_memcpy(void *, void *, s32);

void *main_alloc_copy(s32 size, u8 *src)
{
    u8 *addr;
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
    custom_memcpy(addr, src, size);
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

void push_second_heap_state()
{
    D_800E48C0[++D_800E48B8] = D_800E48B0;
}

void *alloc_second_heap(u32 len)
{
    if (len == 0)
    {
        return 0;
    }
    else
    {
        D_800E48B0 = (void*)((uintptr_t)D_800E48B0 - ALIGN(len, 8));
        return D_800E48B0;
    }
}

void pop_second_heap_state()
{
    D_800E48B0 = D_800E48C0[D_800E48B8--];
}

// Minor regalloc
#ifdef NON_MATCHING
void custom_memcpy(void *dst, void *src, s32 count)
{
    u8* dst8 = (u8*)dst;
    u8* src8 = (u8*)src;
    if (count >= 100 && ((uintptr_t)src8 & 3) == ((uintptr_t)dst8 & 3))
    {
        s32 byteCopies = (4 - ((uintptr_t)src8 & 3)) & 3;
        s32 dwordCopies = (u32)(count - byteCopies) / 8;
        s32 byteCopies2 = (count - byteCopies) & 7;
        u64* dst64;
        u64* src64;
        while (--byteCopies >= 0)
        {
            *dst8++ = *src8++;
        }
        dst64 = (u64*)dst8;
        src64 = (u64*)src8;
        while (--dwordCopies >= 0)
        {
            *dst64++ = *src64++;
        }
        dst8 = (u8*)dst64;
        src8 = (u8*)src64;
        while (--byteCopies2 >= 0)
        {
            *dst8++ = *src8++;
        }
    }
    else
    {
        while (--count >= 0)
        {
            *dst8++ = *src8++;
        }
    }
}
#else
INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_223", custom_memcpy, void*, void*, s32);
#endif

void custom_memmove(u8 *dst, u8 *src, s32 count)
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
