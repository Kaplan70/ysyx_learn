// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpre_encode83.h"
#include "Vpre_encode83__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vpre_encode83::Vpre_encode83(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpre_encode83__Syms(contextp(), _vcname__, this)}
    , en{vlSymsp->TOP.en}
    , x{vlSymsp->TOP.x}
    , t{vlSymsp->TOP.t}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpre_encode83::Vpre_encode83(const char* _vcname__)
    : Vpre_encode83(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpre_encode83::~Vpre_encode83() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpre_encode83___024root___eval_debug_assertions(Vpre_encode83___024root* vlSelf);
#endif  // VL_DEBUG
void Vpre_encode83___024root___eval_static(Vpre_encode83___024root* vlSelf);
void Vpre_encode83___024root___eval_initial(Vpre_encode83___024root* vlSelf);
void Vpre_encode83___024root___eval_settle(Vpre_encode83___024root* vlSelf);
void Vpre_encode83___024root___eval(Vpre_encode83___024root* vlSelf);

void Vpre_encode83::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpre_encode83::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpre_encode83___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpre_encode83___024root___eval_static(&(vlSymsp->TOP));
        Vpre_encode83___024root___eval_initial(&(vlSymsp->TOP));
        Vpre_encode83___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpre_encode83___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vpre_encode83::eventsPending() { return false; }

uint64_t Vpre_encode83::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vpre_encode83::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpre_encode83___024root___eval_final(Vpre_encode83___024root* vlSelf);

VL_ATTR_COLD void Vpre_encode83::final() {
    Vpre_encode83___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpre_encode83::hierName() const { return vlSymsp->name(); }
const char* Vpre_encode83::modelName() const { return "Vpre_encode83"; }
unsigned Vpre_encode83::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vpre_encode83::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vpre_encode83___024root__trace_init_top(Vpre_encode83___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vpre_encode83___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpre_encode83___024root*>(voidSelf);
    Vpre_encode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vpre_encode83___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vpre_encode83___024root__trace_register(Vpre_encode83___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpre_encode83::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vpre_encode83::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vpre_encode83___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
