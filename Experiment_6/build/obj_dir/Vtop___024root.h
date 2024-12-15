// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*0:0*/ top__DOT____Vcellinp__mybsf__clk;
    VL_IN8(rst,0,0);
    VL_IN8(btn,4,0);
    VL_IN8(ps2_clk,0,0);
    VL_IN8(ps2_data,0,0);
    VL_IN8(uart_rx,0,0);
    VL_OUT8(uart_tx,0,0);
    VL_OUT8(VGA_CLK,0,0);
    VL_OUT8(VGA_HSYNC,0,0);
    VL_OUT8(VGA_VSYNC,0,0);
    VL_OUT8(VGA_BLANK_N,0,0);
    VL_OUT8(VGA_R,7,0);
    VL_OUT8(VGA_G,7,0);
    VL_OUT8(VGA_B,7,0);
    VL_OUT8(seg0,7,0);
    VL_OUT8(seg1,7,0);
    VL_OUT8(seg2,7,0);
    VL_OUT8(seg3,7,0);
    VL_OUT8(seg4,7,0);
    VL_OUT8(seg5,7,0);
    VL_OUT8(seg6,7,0);
    VL_OUT8(seg7,7,0);
    CData/*7:0*/ top__DOT____Vcellout__mybsf__out_s;
    CData/*0:0*/ top__DOT__my_vga_ctrl__DOT__h_valid;
    CData/*0:0*/ top__DOT__my_vga_ctrl__DOT__v_valid;
    CData/*3:0*/ top__DOT__my_keyboard__DOT__count;
    CData/*2:0*/ top__DOT__my_keyboard__DOT__ps2_clk_sync;
    CData/*0:0*/ top__DOT__my_keyboard__DOT____Vlvbound_h1a91ade8__0;
    CData/*0:0*/ __Vtrigrprev__TOP__top__DOT____Vcellinp__mybsf__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN16(sw,15,0);
    VL_OUT16(ledr,15,0);
    SData/*9:0*/ top__DOT__my_vga_ctrl__DOT__x_cnt;
    SData/*9:0*/ top__DOT__my_vga_ctrl__DOT__y_cnt;
    SData/*9:0*/ top__DOT__my_keyboard__DOT__buffer;
    IData/*23:0*/ top__DOT__vga_data;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*23:0*/, 524288> top__DOT__my_vmem__DOT__vga_mem;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
