//*****************************************************************************
//
// cmsis_ccs.h - Include file containing #defines necessary to build the CMSIS
// dsp libraries using compiler intrinsics for the TMS470 compiler.
//
// Copyright (c) 2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 8542 of the CMSIS DSP Application Note.
//
//*****************************************************************************

#ifndef CMSIS_CCS_H_
#define CMSIS_CCS_H_


//
//     v5e, v6, Cortex-M3, Cortex-M4, Cortex-R4, and Cortex-A8 compiler intrinsics
//
#define __CLZ         _norm
#define __SXTB        _sxtb
#define __SXTH        _sxth
#define __UXTB        _uxtb
#define __UXTH        _uxth
//  CCS supports intrinsics to take advantage of the shift operand left/right
//      before saturation extension of SSAT, but CMSIS does not take advantage
//      of those, so tell the compiler to use a sat & shift left with a shift
//      value of 0 whenever it encounters an SSAT
#define __SSAT(VAL, BITPOS) \
    _ssatl(VAL , 0, BITPOS)

//
//  Only define M4 based intrinsics if we're not using an M4
//
#if defined (__TI_TMS470_V7M4__)
#define __ROR          __ror
#define __SXTB16(src1)     _sxtb16(src1,0) // The TI ARM compiler rotamt (2nd)
// argument set to zero, as not in the ARM compiler intrinsic
//
//    V5E, V6, Cortex-M4, Cortex-R4, and Cortex-A8 compiler intrinsics
//
#define __QADD        _sadd
#define __QDADD        _sdadd
#define __QDSUB        _sdsub
#define    __SMLABB    _smlabb
#define    __SMLABT    _smlabt
#define __SMLALBB    _smlalbb
#define __SMLALBT    _smlalbt
#define __SMLALTB    _smlaltb
#define __SMLALTT    _smlaltt
#define __SMLATB    _smlatb
#define __SMLATT    _smlatt
#define __SMLAWB    _smlawb
#define __SMLAWT    _smlawt

#define __SMULBB    _smulbb
#define __SMULBT    _smulbt
#define __SMULTB    _smultb
#define __SMULTT    _smultt
#define __SMULWB    _smulwb
#define __SMULWT    _smulwt
#define __QSUB        _ssub
#define __SUBC        _subc

//
//    v6, Cortex-M4, Cortex-R4, and Cortex-A8 compiler intrinsics
//
#define __SHASX        _shaddsubx
#define __SHSAX        _shsubaddx
#define __PKHBT        _pkhbt
#define __PKHTB        _pkhtb
#define __QADD16    _qadd16
#define __QADD8        _qadd8
#define __QSUB16    _qsub16
#define __QSUB8        _qsub8
#define __QASX        _saddsubx
#define __QSAX        _qsubaddx
#define __SADD16    _sadd16
#define __SADD8        _sadd8
#define __SASX        _saddsubx
#define __SEL        _sel
#define __SHADD16    _shadd16
#define __SHADD8    _shadd8
#define __SHSUB16    _shsub16
#define __SHSUB8    _shsub8
#define __SMLAD        _smlad
#define __SMLADX    _smladx
#define __SMLALD    _smlald
#define __SMLALDX    _smlaldx
#define __SMLSD        _smlsd
#define __SMLSDX    _smlsdx
#define __SMLSLD    _smlsld
#define __SMLSLDX    _smlsldx
#define __SMMLA        _smmla
#define __SMMLAR    _smmlar
#define __SMMLS        _smmls
#define __SMMLSR    _smmlsr
#define __SMMUL        _smmul
#define __SMMULR    _smmulr
#define __SMUAD        _smuad
#define __SMUADX    _smuadx
#define __SMUSD        _smusd
#define __SMUSDX    _smusd
#define __SSAT16    _ssat16
#define __SSUB16    _ssub16
#define __SSUB8        _ssub8
#define __SSAX        _ssubaddx
#define __SXTAB        _sxtab
#define __SXTAB16    _sxtab16
#define __SXTAH        _sxtah
#define __UMAAL        _umaal
#define __UADD16    _uadd16
#define __UADD8        _uadd8
#define __UHADD16    _uhadd16
#define __UHADD8    _uhadd8
#define __UASX        _uaddsubx
#define __UHSUB16    _uhsub16
#define __UHSUB8    _uhsub8
#define __UQADD16    _uqadd16
#define __UQADD8    _uqadd8
#define __UQASX        _uqaddsubx
#define __UQSUB16    _uqsub16
#define __UQSUB8    _uqsub8
#define __UQSAX        _uqsubaddx
#define __USAD8        _usad8
#define __USAT16    _usat16
#define __USUB16    _usub16
#define __USUB8        _usub8
#define __USAX        _usubaddx
#define __UXTAB        _uxtab
#define __UXTAB16    _uxtab16
#define __UXTAH        _uxtah
#define __UXTB16    _uxtb16
#endif /*__TI_TMS470_V7M4__*/

#endif /*CMSIS_CCS_H_*/
