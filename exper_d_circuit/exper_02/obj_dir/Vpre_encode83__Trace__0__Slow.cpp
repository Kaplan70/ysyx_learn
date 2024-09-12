// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpre_encode83__Syms.h"


VL_ATTR_COLD void Vpre_encode83___024root__trace_init_sub__TOP__0(Vpre_encode83___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpre_encode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpre_encode83___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"x", false,-1, 7,0);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBit(c+3,"t", false,-1);
    tracep->declBus(c+4,"y", false,-1, 2,0);
    tracep->pushNamePrefix("pre_encode83 ");
    tracep->declBus(c+1,"x", false,-1, 7,0);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBit(c+3,"t", false,-1);
    tracep->declBus(c+4,"y", false,-1, 2,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vpre_encode83___024root__trace_init_top(Vpre_encode83___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpre_encode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpre_encode83___024root__trace_init_top\n"); );
    // Body
    Vpre_encode83___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vpre_encode83___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpre_encode83___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpre_encode83___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vpre_encode83___024root__trace_register(Vpre_encode83___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpre_encode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpre_encode83___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vpre_encode83___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vpre_encode83___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vpre_encode83___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vpre_encode83___024root__trace_full_sub_0(Vpre_encode83___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpre_encode83___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpre_encode83___024root__trace_full_top_0\n"); );
    // Init
    Vpre_encode83___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpre_encode83___024root*>(voidSelf);
    Vpre_encode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpre_encode83___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpre_encode83___024root__trace_full_sub_0(Vpre_encode83___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vpre_encode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpre_encode83___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->x),8);
    bufp->fullBit(oldp+2,(vlSelf->en));
    bufp->fullBit(oldp+3,(vlSelf->t));
    bufp->fullCData(oldp+4,(vlSelf->y),3);
}
