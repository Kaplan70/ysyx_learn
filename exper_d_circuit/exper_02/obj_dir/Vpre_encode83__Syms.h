// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPRE_ENCODE83__SYMS_H_
#define VERILATED_VPRE_ENCODE83__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vpre_encode83.h"

// INCLUDE MODULE CLASSES
#include "Vpre_encode83___024root.h"

// SYMS CLASS (contains all model state)
class Vpre_encode83__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vpre_encode83* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vpre_encode83___024root        TOP;

    // CONSTRUCTORS
    Vpre_encode83__Syms(VerilatedContext* contextp, const char* namep, Vpre_encode83* modelp);
    ~Vpre_encode83__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
