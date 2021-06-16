#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>

// regalloc
// void decompress(struct DecompressionParams *arg0, u32 compressedSize, u8 *src, u32 uncompressedSize, u8 *dst)
// {
//     u8 bVar2;
//     s32 uVar5;
//     u8 *srcEnd;
//     u8 *dstEnd;
//     u8 layoutBits;

//     srcEnd = src + compressedSize;
//     dstEnd = dst + uncompressedSize;
//     do
//     {
//         if (src >= srcEnd)
//             return;
//         uVar5 = 7;
//         layoutBits = *src++;
//         while (1)
//         {
//             if (uVar5 < 0 || src >= srcEnd || dst >= dstEnd)
//             {
//                 break;
//             }
//             if ((u32)layoutBits & (1U << (uVar5)))
//             {
//                 s32 firstByte = *src++;
//                 s32 secondByte = *src++;
//                 u16 bytes = firstByte << 8 | secondByte;
//                 u8 *curByte;
//                 u8 *lastByte;
//                 u16 offset = (bytes >> arg0->shift);
//                 u16 length = (bytes & arg0->mask) + arg0->lengthOffset - 1;
//                 curByte = dst - offset;
//                 lastByte = curByte + length;
//                 while (lastByte > curByte)
//                 {
//                     *dst++ = *curByte++;
//                 }
//             }
//             else
//             {
//                 *dst++ = *src++;
//             }
//             uVar5 = uVar5 - 1;
//         }
//     } while (1);
// }

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_427", decompress, struct DecompressionParams *, u32, u8 *, u32, u8 *);
