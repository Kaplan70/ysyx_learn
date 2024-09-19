// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_sub__Syms.h"


void Vadd_sub___024root__trace_chg_sub_0(Vadd_sub___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd_sub___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub___024root__trace_chg_top_0\n"); );
    // Init
    Vadd_sub___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_sub___024root*>(voidSelf);
    Vadd_sub__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd_sub___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd_sub___024root__trace_chg_sub_0(Vadd_sub___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->a),8);
    bufp->chgCData(oldp+1,(vlSelf->b),8);
    bufp->chgBit(oldp+2,(vlSelf->select));
    bufp->chgCData(oldp+3,(vlSelf->result),8);
    bufp->chgBit(oldp+4,(vlSelf->carry));
    bufp->chgBit(oldp+5,(vlSelf->overflow));
    bufp->chgBit(oldp+6,(vlSelf->zero));
    bufp->chgCData(oldp+7,((0xffU & vlSelf->__VdfgTmp_h88aeb86a__0)),8);
}

void Vadd_sub___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub___024root__trace_cleanup\n"); );
    // Init
    Vadd_sub___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_sub___024root*>(voidSelf);
    Vadd_sub__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
