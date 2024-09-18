// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd_sub_32.h for the primary calling header

#ifndef VERILATED_VADD_SUB_32___024ROOT_H_
#define VERILATED_VADD_SUB_32___024ROOT_H_  // guard

#include "verilated.h"

class Vadd_sub_32__Syms;

class Vadd_sub_32___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(select,0,0);
    VL_OUT8(c,0,0);
    VL_OUT8(overflow,0,0);
    VL_OUT8(zero,0,0);
    CData/*0:0*/ __VactContinue;
    VL_IN(a,31,0);
    VL_IN(b,31,0);
    VL_OUT(result,31,0);
    IData/*31:0*/ add_sub_32__DOT__bs;
    IData/*31:0*/ add_sub_32__DOT__resultb;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd_sub_32__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd_sub_32___024root(Vadd_sub_32__Syms* symsp, const char* v__name);
    ~Vadd_sub_32___024root();
    VL_UNCOPYABLE(Vadd_sub_32___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
