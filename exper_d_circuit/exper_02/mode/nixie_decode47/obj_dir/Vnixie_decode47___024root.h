// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vnixie_decode47.h for the primary calling header

#ifndef VERILATED_VNIXIE_DECODE47___024ROOT_H_
#define VERILATED_VNIXIE_DECODE47___024ROOT_H_  // guard

#include "verilated.h"

class Vnixie_decode47__Syms;

class Vnixie_decode47___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(x,3,0);
    VL_OUT8(y,6,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vnixie_decode47__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vnixie_decode47___024root(Vnixie_decode47__Syms* symsp, const char* v__name);
    ~Vnixie_decode47___024root();
    VL_UNCOPYABLE(Vnixie_decode47___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
