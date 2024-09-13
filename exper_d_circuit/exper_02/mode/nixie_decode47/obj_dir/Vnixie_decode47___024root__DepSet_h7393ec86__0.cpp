// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnixie_decode47.h for the primary calling header

#include "verilated.h"

#include "Vnixie_decode47___024root.h"

extern const VlUnpacked<CData/*6:0*/, 16> Vnixie_decode47__ConstPool__TABLE_h91d99e03_0;

VL_INLINE_OPT void Vnixie_decode47___024root___ico_sequent__TOP__0(Vnixie_decode47___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = vlSelf->x;
    vlSelf->y = Vnixie_decode47__ConstPool__TABLE_h91d99e03_0
        [__Vtableidx1];
}

void Vnixie_decode47___024root___eval_ico(Vnixie_decode47___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vnixie_decode47___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vnixie_decode47___024root___eval_act(Vnixie_decode47___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root___eval_act\n"); );
}

void Vnixie_decode47___024root___eval_nba(Vnixie_decode47___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root___eval_nba\n"); );
}

void Vnixie_decode47___024root___eval_triggers__ico(Vnixie_decode47___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vnixie_decode47___024root___dump_triggers__ico(Vnixie_decode47___024root* vlSelf);
#endif  // VL_DEBUG
void Vnixie_decode47___024root___eval_triggers__act(Vnixie_decode47___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vnixie_decode47___024root___dump_triggers__act(Vnixie_decode47___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vnixie_decode47___024root___dump_triggers__nba(Vnixie_decode47___024root* vlSelf);
#endif  // VL_DEBUG

void Vnixie_decode47___024root___eval(Vnixie_decode47___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vnixie_decode47___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vnixie_decode47___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("nixie_decode47.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vnixie_decode47___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vnixie_decode47___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vnixie_decode47___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("nixie_decode47.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vnixie_decode47___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vnixie_decode47___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("nixie_decode47.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vnixie_decode47___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vnixie_decode47___024root___eval_debug_assertions(Vnixie_decode47___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->x & 0xf0U))) {
        Verilated::overWidthError("x");}
}
#endif  // VL_DEBUG
