// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_sub__Syms.h"


VL_ATTR_COLD void Vadd_sub___024root__trace_init_sub__TOP__0(Vadd_sub___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"a", false,-1, 7,0);
    tracep->declBus(c+2,"b", false,-1, 7,0);
    tracep->declBit(c+3,"select", false,-1);
    tracep->declBus(c+4,"result", false,-1, 7,0);
    tracep->declBit(c+5,"carry", false,-1);
    tracep->declBit(c+6,"overflow", false,-1);
    tracep->declBit(c+7,"zero", false,-1);
    tracep->pushNamePrefix("add_sub ");
    tracep->declBus(c+9,"n", false,-1, 31,0);
    tracep->declBus(c+1,"a", false,-1, 7,0);
    tracep->declBus(c+2,"b", false,-1, 7,0);
    tracep->declBit(c+3,"select", false,-1);
    tracep->declBus(c+4,"result", false,-1, 7,0);
    tracep->declBit(c+5,"carry", false,-1);
    tracep->declBit(c+6,"overflow", false,-1);
    tracep->declBit(c+7,"zero", false,-1);
    tracep->declBus(c+8,"bs", false,-1, 7,0);
    tracep->pushNamePrefix("u_add ");
    tracep->declBus(c+9,"n", false,-1, 31,0);
    tracep->declBus(c+1,"a", false,-1, 7,0);
    tracep->declBus(c+8,"b", false,-1, 7,0);
    tracep->declBus(c+4,"result", false,-1, 7,0);
    tracep->declBit(c+5,"carry", false,-1);
    tracep->declBit(c+6,"overflow", false,-1);
    tracep->declBit(c+7,"zero", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vadd_sub___024root__trace_init_top(Vadd_sub___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub___024root__trace_init_top\n"); );
    // Body
    Vadd_sub___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd_sub___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_sub___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_sub___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd_sub___024root__trace_register(Vadd_sub___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vadd_sub___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vadd_sub___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vadd_sub___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd_sub___024root__trace_full_sub_0(Vadd_sub___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd_sub___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub___024root__trace_full_top_0\n"); );
    // Init
    Vadd_sub___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_sub___024root*>(voidSelf);
    Vadd_sub__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd_sub___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd_sub___024root__trace_full_sub_0(Vadd_sub___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_sub__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_sub___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->a),8);
    bufp->fullCData(oldp+2,(vlSelf->b),8);
    bufp->fullBit(oldp+3,(vlSelf->select));
    bufp->fullCData(oldp+4,(vlSelf->result),8);
    bufp->fullBit(oldp+5,(vlSelf->carry));
    bufp->fullBit(oldp+6,(vlSelf->overflow));
    bufp->fullBit(oldp+7,(vlSelf->zero));
    bufp->fullCData(oldp+8,((0xffU & vlSelf->__VdfgTmp_h88aeb86a__0)),8);
    bufp->fullIData(oldp+9,(8U),32);
}
