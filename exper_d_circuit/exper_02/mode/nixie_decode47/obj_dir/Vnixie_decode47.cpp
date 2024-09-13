// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vnixie_decode47.h"
#include "Vnixie_decode47__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vnixie_decode47::Vnixie_decode47(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vnixie_decode47__Syms(contextp(), _vcname__, this)}
    , x{vlSymsp->TOP.x}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vnixie_decode47::Vnixie_decode47(const char* _vcname__)
    : Vnixie_decode47(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vnixie_decode47::~Vnixie_decode47() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vnixie_decode47___024root___eval_debug_assertions(Vnixie_decode47___024root* vlSelf);
#endif  // VL_DEBUG
void Vnixie_decode47___024root___eval_static(Vnixie_decode47___024root* vlSelf);
void Vnixie_decode47___024root___eval_initial(Vnixie_decode47___024root* vlSelf);
void Vnixie_decode47___024root___eval_settle(Vnixie_decode47___024root* vlSelf);
void Vnixie_decode47___024root___eval(Vnixie_decode47___024root* vlSelf);

void Vnixie_decode47::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vnixie_decode47::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vnixie_decode47___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vnixie_decode47___024root___eval_static(&(vlSymsp->TOP));
        Vnixie_decode47___024root___eval_initial(&(vlSymsp->TOP));
        Vnixie_decode47___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vnixie_decode47___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vnixie_decode47::eventsPending() { return false; }

uint64_t Vnixie_decode47::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vnixie_decode47::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vnixie_decode47___024root___eval_final(Vnixie_decode47___024root* vlSelf);

VL_ATTR_COLD void Vnixie_decode47::final() {
    Vnixie_decode47___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vnixie_decode47::hierName() const { return vlSymsp->name(); }
const char* Vnixie_decode47::modelName() const { return "Vnixie_decode47"; }
unsigned Vnixie_decode47::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vnixie_decode47::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vnixie_decode47___024root__trace_init_top(Vnixie_decode47___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vnixie_decode47___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnixie_decode47___024root*>(voidSelf);
    Vnixie_decode47__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vnixie_decode47___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vnixie_decode47___024root__trace_register(Vnixie_decode47___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vnixie_decode47::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vnixie_decode47::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vnixie_decode47___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
