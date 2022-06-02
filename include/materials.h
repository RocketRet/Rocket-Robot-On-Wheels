#ifndef __MATERIALS_H__
#define __MATERIALS_H__

#include <types.h>

static inline struct TexturedMaterial *get_material_data(struct MaterialGfx *materialGfx) {
    struct TexturedMaterial *ret;
    if (IS_K0_ADDRESS(materialGfx->materialData)) {
        ret = (struct TexturedMaterial*)materialGfx->materialData;
    } else {
        ret = load_textured_material(materialGfx);
    }
    return ret;
}

#endif
