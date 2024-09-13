// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vnixie_decode47__Syms.h"


VL_ATTR_COLD void Vnixie_decode47___024root__trace_init_sub__TOP__0(Vnixie_decode47___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"x", false,-1, 3,0);
    tracep->declBus(c+2,"y", false,-1, 6,0);
    tracep->pushNamePrefix("nixie_decode47 ");
    tracep->declBus(c+1,"x", false,-1, 3,0);
    tracep->declBus(c+2,"y", false,-1, 6,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vnixie_decode47___024root__trace_init_top(Vnixie_decode47___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root__trace_init_top\n"); );
    // Body
    Vnixie_decode47___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vnixie_decode47___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vnixie_decode47___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vnixie_decode47___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vnixie_decode47___024root__trace_register(Vnixie_decode47___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vnixie_decode47___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vnixie_decode47___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vnixie_decode47___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vnixie_decode47___024root__trace_full_sub_0(Vnixie_decode47___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vnixie_decode47___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root__trace_full_top_0\n"); );
    // Init
    Vnixie_decode47___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnixie_decode47___024root*>(voidSelf);
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vnixie_decode47___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vnixie_decode47___024root__trace_full_sub_0(Vnixie_decode47___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnixie_decode47___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->x),4);
    bufp->fullCData(oldp+2,(vlSelf->y),7);
}
