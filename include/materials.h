#ifndef __MATERIALS_H__
#define __MATERIALS_H__

#include <types.h>

#define MATERIAL_FLAG_TWO_SIDED         0x01
#define MATERIAL_FLAG_POINT_FILTERED    0x02
#define MATERIAL_FLAG_MIPMAPPED         0x40
#define MATERIAL_FLAG_MULTITEXTURE_MIX  0x80

#define	gDPSetCombineLERP_custom(pkt, a0, b0, c0, d0, Aa0, Ab0, Ac0, Ad0,	\
		a1, b1, c1, d1,	Aa1, Ab1, Ac1, Ad1)			\
{									\
	Gfx *_g = (Gfx *)(pkt);						\
									\
	_g->words.w0 =	_SHIFTL(G_SETCOMBINE, 24, 8) |			\
			_SHIFTL(GCCc0w0(a0, c0,	\
				       Aa0, Ac0) |	\
			       GCCc1w0(a1, c1), 	\
			       0, 24);					\
	_g->words.w1 =	(unsigned int)(GCCc0w1(b0, 		\
					       d0,		\
					       Ab0, 		\
					       Ad0) |		\
				       GCCc1w1(b1, 		\
					       Aa1,		\
					       Ac1, 		\
					       d1,		\
					       Ab1, 		\
					       Ad1));		\
}

struct unkfunc_800926B8 {
    s32 pad0;
    s32 pad4;
    Gfx *unk8;
};

typedef struct CombinerParams_s {
    u8 color[4];
    u8 alpha[4];
} CombinerParams;

typedef union RGBA32_u {
    struct {
        u8 r;
        u8 g;
        u8 b;
        u8 a;
    } colors;
    u32 rgba32;
} RGBA32;

typedef union RGBA32_pad8_u {
    struct {
        u8 r;
        u8 g;
        u8 b;
        u8 a;
    } colors;
    u32 rgba32;
    u8 pad[8];
} RGBA32_pad8;

static inline struct TexturedMaterial *get_material_data(struct MaterialGfx *materialGfx) {
    struct TexturedMaterial *ret;
    if (IS_K0_ADDRESS(materialGfx->materialData.raw)) {
        ret = materialGfx->materialData.texturedMaterial;
    } else {
        ret = load_textured_material(materialGfx);
    }
    return ret;
}

#endif
