// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdouble_switch.h"
#include "Vdouble_switch__Syms.h"

//============================================================
// Constructors

Vdouble_switch::Vdouble_switch(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdouble_switch__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , f{vlSymsp->TOP.f}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdouble_switch::Vdouble_switch(const char* _vcname__)
    : Vdouble_switch(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdouble_switch::~Vdouble_switch() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdouble_switch___024root___eval_debug_assertions(Vdouble_switch___024root* vlSelf);
#endif  // VL_DEBUG
void Vdouble_switch___024root___eval_static(Vdouble_switch___024root* vlSelf);
void Vdouble_switch___024root___eval_initial(Vdouble_switch___024root* vlSelf);
void Vdouble_switch___024root___eval_settle(Vdouble_switch___024root* vlSelf);
void Vdouble_switch___024root___eval(Vdouble_switch___024root* vlSelf);

void Vdouble_switch::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdouble_switch::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdouble_switch___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdouble_switch___024root___eval_static(&(vlSymsp->TOP));
        Vdouble_switch___024root___eval_initial(&(vlSymsp->TOP));
        Vdouble_switch___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdouble_switch___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdouble_switch::eventsPending() { return false; }

uint64_t Vdouble_switch::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdouble_switch::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdouble_switch___024root___eval_final(Vdouble_switch___024root* vlSelf);

VL_ATTR_COLD void Vdouble_switch::final() {
    Vdouble_switch___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdouble_switch::hierName() const { return vlSymsp->name(); }
const char* Vdouble_switch::modelName() const { return "Vdouble_switch"; }
unsigned Vdouble_switch::threads() const { return 1; }
