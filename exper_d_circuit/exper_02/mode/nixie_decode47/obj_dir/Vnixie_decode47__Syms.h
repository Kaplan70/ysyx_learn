// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VNIXIE_DECODE47__SYMS_H_
#define VERILATED_VNIXIE_DECODE47__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vnixie_decode47.h"

// INCLUDE MODULE CLASSES
#include "Vnixie_decode47___024root.h"

// SYMS CLASS (contains all model state)
class Vnixie_decode47__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vnixie_decode47* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vnixie_decode47___024root      TOP;

    // CONSTRUCTORS
    Vnixie_decode47__Syms(VerilatedContext* contextp, const char* namep, Vnixie_decode47* modelp);
    ~Vnixie_decode47__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
