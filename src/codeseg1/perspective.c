#include <include_asm.h>
#include <ultra64.h>

// void guMtxIdentF(float (*mf)[4]);
// extern float sinf(float angle);
// extern float cosf(float angle);

// typedef unsigned short u16;
// typedef long Mtx_t[4][4];
// typedef union {
//     Mtx_t m;
//     long long int force_structure_alignment;
// } Mtx;

// void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
// {
// 	float	cot;
// 	int	i, j;

// 	guMtxIdentF(mf);

// 	fovy *= 3.1415926 / 180.0;
// 	cot = cosf (fovy/2) / sinf (fovy/2);

// 	mf[0][0] = cot / aspect;
// 	mf[1][1] = cot;
// 	mf[2][2] = (near + far) / (near - far);
// 	mf[2][3] = -1;
// 	mf[3][2] = (2 * near * far) / (near - far);
// 	mf[3][3] = 0;

// 	for (i=0; i<4; i++)
// 	    for (j=0; j<4; j++)
// 		mf[i][j] *= scale;

// 	if (perspNorm != (u16 *) 0) {
// 	    if (near+far<=2.0) {
// 		*perspNorm = (u16) 0xFFFF;
// 	    } else  {
// 		*perspNorm = (u16) ((2.0*65536.0)/(near+far));
// 		if (*perspNorm<=0) 
// 		    *perspNorm = (u16) 0x0001;
// 	    }
// 	}
// }

// typedef	float	Matrix[4][4];

// void guPerspective(Mtx *m, u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
// {
// 	Matrix	mf;

// 	guPerspectiveF(mf, perspNorm, fovy, aspect, near, far, scale);

// 	guMtxF2L(mf, m);
// }

INCLUDE_ASM(void, "lib/codeseg1/perspective", guPerspectiveF, float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale);

INCLUDE_ASM(void, "lib/codeseg1/perspective", guPerspective, Mtx *m, u16 *perspNorm, float fovy, float aspect, float near, float far, float scale);
