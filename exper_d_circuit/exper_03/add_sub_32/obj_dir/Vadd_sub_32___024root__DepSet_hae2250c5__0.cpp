// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_sub_32.h for the primary calling header

#include "verilated.h"

#include "Vadd_sub_32___024root.h"

VL_INLINE_OPT void Vadd_sub_32___024root___ico_sequent__TOP__0(Vadd_sub_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub_32___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->add_sub_32__DOT__bs = ((IData)(vlSelf->select)
                                    ? ((IData)(1U) 
                                       + (~ vlSelf->b))
                                    : vlSelf->b);
    vlSelf->c = (1U & (IData)((1ULL & (((QData)((IData)(vlSelf->a)) 
                                        + (QData)((IData)(vlSelf->add_sub_32__DOT__bs))) 
                                       >> 0x20U))));
    vlSelf->add_sub_32__DOT__resultb = (vlSelf->a + vlSelf->add_sub_32__DOT__bs);
    vlSelf->overflow = (((vlSelf->a >> 0x1fU) == (vlSelf->add_sub_32__DOT__bs 
                                                  >> 0x1fU)) 
                        & ((vlSelf->add_sub_32__DOT__resultb 
                            >> 0x1fU) != (vlSelf->a 
                                          >> 0x1fU)));
    vlSelf->result = ((vlSelf->add_sub_32__DOT__resultb 
                       >> 0x1fU) ? ((IData)(1U) + (~ vlSelf->add_sub_32__DOT__resultb))
                       : vlSelf->add_sub_32__DOT__resultb);
    vlSelf->zero = (1U & (~ (IData)((0U != vlSelf->result))));
}

void Vadd_sub_32___024root___eval_ico(Vadd_sub_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub_32___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vadd_sub_32___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vadd_sub_32___024root___eval_act(Vadd_sub_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub_32___024root___eval_act\n"); );
}

void Vadd_sub_32___024root___eval_nba(Vadd_sub_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub_32___024root___eval_nba\n"); );
}

void Vadd_sub_32___024root___eval_triggers__ico(Vadd_sub_32___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_sub_32___024root___dump_triggers__ico(Vadd_sub_32___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd_sub_32___024root___eval_triggers__act(Vadd_sub_32___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_sub_32___024root___dump_triggers__act(Vadd_sub_32___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_sub_32___024root___dump_triggers__nba(Vadd_sub_32___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd_sub_32___024root___eval(Vadd_sub_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub_32___024root___eval\n"); );
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
        Vadd_sub_32___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vadd_sub_32___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("add_sub_32.v", 5, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vadd_sub_32___024root___eval_ico(vlSelf);
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
            Vadd_sub_32___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vadd_sub_32___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("add_sub_32.v", 5, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vadd_sub_32___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vadd_sub_32___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("add_sub_32.v", 5, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vadd_sub_32___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vadd_sub_32___024root___eval_debug_assertions(Vadd_sub_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub_32___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->select & 0xfeU))) {
        Verilated::overWidthError("select");}
}
#endif  // VL_DEBUG
