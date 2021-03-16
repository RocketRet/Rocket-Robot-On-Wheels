#include <include_asm.h>
#include <ultra64.h>
#include <PR/n_libaudio.h>


INCLUDE_ASM(s32, "lib/codeseg1/codeseg1_111", CustomSynNew);
#define AL_MAX_AUX_BUS_SOURCES       8
#define AL_MAX_AUX_BUS_FX	     1

typedef struct ALParam_s {
    struct ALParam_s    *next;
    s32                 delta;
    s16                 type;
    union {
        f32             f;
        s32             i;
    } data;
    union {
        f32             f;
        s32             i;
    } moredata;
    union {
        f32             f;
        s32             i;
    } stillmoredata;
    union {
        f32             f;
        s32             i;
    } yetstillmoredata;
} ALParam;

typedef struct {
    struct ALParam_s            *next;
    s32                         delta;
    s16                         type;
    s16                         unity;  /* disable resampler */
    f32                         pitch;
    s16                         volume;
    ALPan                       pan;
    u8                          fxMix;
    s32                         samples;
    struct ALWaveTable_s        *wave;
} ALStartParamAlt;

typedef struct {
    struct ALParam_s            *next;
    s32                         delta;
    s16                         type;
    s16                         unity;  /* disable resampler */
    struct ALWaveTable_s        *wave;
} ALStartParam;

typedef struct {
    struct ALParam_s    *next;
    s32                 delta;
    s16                 type;
    struct PVoice_s     *pvoice;
} ALFreeParam;

typedef Acmd *(*ALCmdHandler)(void *, s16 *, s32, s32, Acmd *);
typedef s32   (*ALSetParam)(void *, s32, void *);

typedef struct ALFilter_s {
    struct ALFilter_s   *source;
    ALCmdHandler        handler;
    ALSetParam          setParam;
    s16                 inp;
    s16                 outp;
    s32                 type;
} ALFilter;

typedef struct {
    ALFilter                    filter;
    ADPCM_STATE                 *state;
    ADPCM_STATE                 *lstate;
    ALRawLoop                   loop;
    struct ALWaveTable_s        *table;
    s32                         bookSize;
    ALDMAproc                   dma;
    void                        *dmaState;
    s32                         sample;
    s32                         lastsam;
    s32                         first;
    s32                         memin; 
} ALLoadFilter;

typedef struct ALResampler_s {
    ALFilter            filter;
    RESAMPLE_STATE      *state;
    f32                 ratio;
    s32			upitch;
    f32		        delta;
    s32			first;
    ALParam		*ctrlList;
    ALParam		*ctrlTail;
    s32                 motion;
} ALResampler;

typedef struct {
    s16		        fc;
    s16		        fgain;
    union {
        s16		fccoef[16];
        s64             force_aligned;
    } fcvec;
    POLEF_STATE		*fstate;
    s32			first;
} ALLowPass;

typedef struct {
    u32		input;
    u32		output;
    s16		ffcoef;
    s16		fbcoef;
    s16		gain;
    f32		rsinc;
    f32		rsval;
    s32		rsdelta;
    f32		rsgain;
    ALLowPass	*lp;
    ALResampler	*rs;
} ALDelay;

typedef s32   (*ALSetFXParam)(void *, s32, void *);
typedef struct {
    struct ALFilter_s   filter;
    s16			*base;
    s16			*input;
    u32			length;
    ALDelay		*delay;
    u8			section_count;
    ALSetFXParam        paramHdl;
} ALFx;

typedef struct N_PVoice_s {
    ALLink               node;
    struct N_ALVoice_s    *vvoice;
/** ALLoadFilter *********************************/
    ADPCM_STATE                 *dc_state;
    ADPCM_STATE                 *dc_lstate;
    ALRawLoop                   dc_loop;
    struct ALWaveTable_s        *dc_table;
    s32                         dc_bookSize;
    ALDMAproc                   dc_dma;
    void                        *dc_dmaState;
    s32                         dc_sample;
    s32                         dc_lastsam;
    s32                         dc_first;
    s32                         dc_memin; 
/** ALResampler *********************************/
    RESAMPLE_STATE      *rs_state;
    f32                 rs_ratio;
    s32			rs_upitch;
    f32		        rs_delta;
    s32			rs_first;
/** ALEnvMixer *********************************/
    ENVMIX_STATE	*em_state;
    s16		        em_pan;
    s16		        em_volume;
    s16		        em_cvolL;
    s16		        em_cvolR;
    s16		        em_dryamt;
    s16		        em_wetamt;
    u16                 em_lratl;
    s16                 em_lratm;
    s16                 em_ltgt;
    u16                 em_rratl;
    s16                 em_rratm;
    s16                 em_rtgt;
    s32                 em_delta;
    s32                 em_segEnd;
    s32			em_first;
    ALParam		*em_ctrlList;
    ALParam		*em_ctrlTail;
    s32                 em_motion;
    s32                 offset;
} N_PVoice;

typedef struct N_ALAuxBus_s {
    ALFilter            filter;
    s32                 sourceCount;
    s32                 maxSources;
    N_PVoice           **sources;
    ALFx                *fx;
    ALFx		*fx_array[AL_MAX_AUX_BUS_SOURCES];
} N_ALAuxBus;

extern N_ALSynth *D_80019934;

#define n_syn D_80019934

void CustomFxNew();

// TODO different compiler, index[array]
// ALFxRef CustomAllocFX(s16 bus, ALSynConfig *c, ALHeap *hp)
// {
//     CustomFxNew(&n_syn->auxBus->fx_array[bus], c, hp);
//     return(n_syn->auxBus->fx_array[bus]);
// }

INCLUDE_ASM(s32, "lib/codeseg1/codeseg1_111", CustomAllocFX);
