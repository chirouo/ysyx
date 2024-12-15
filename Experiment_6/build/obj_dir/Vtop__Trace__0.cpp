// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__h_valid)
                                 ? (0x3ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt) 
                                              - (IData)(0x91U)))
                                 : 0U)),10);
        bufp->chgSData(oldp+1,(((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__v_valid)
                                 ? (0x3ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt) 
                                              - (IData)(0x24U)))
                                 : 0U)),10);
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__vga_data),24);
        bufp->chgSData(oldp+3,(vlSelf->top__DOT__my_keyboard__DOT__buffer),10);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__my_keyboard__DOT__count),4);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync),3);
        bufp->chgBit(oldp+6,((IData)((4U == (6U & (IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync))))));
        bufp->chgSData(oldp+7,(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt),10);
        bufp->chgSData(oldp+8,(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt),10);
        bufp->chgBit(oldp+9,(vlSelf->top__DOT__my_vga_ctrl__DOT__h_valid));
        bufp->chgBit(oldp+10,(vlSelf->top__DOT__my_vga_ctrl__DOT__v_valid));
        bufp->chgSData(oldp+11,(((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__v_valid)
                                  ? (0x1ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt) 
                                               - (IData)(0x24U)))
                                  : 0U)),9);
    }
    bufp->chgBit(oldp+12,(vlSelf->clk));
    bufp->chgBit(oldp+13,(vlSelf->rst));
    bufp->chgCData(oldp+14,(vlSelf->btn),5);
    bufp->chgSData(oldp+15,(vlSelf->sw),16);
    bufp->chgBit(oldp+16,(vlSelf->ps2_clk));
    bufp->chgBit(oldp+17,(vlSelf->ps2_data));
    bufp->chgBit(oldp+18,(vlSelf->uart_rx));
    bufp->chgBit(oldp+19,(vlSelf->uart_tx));
    bufp->chgSData(oldp+20,(vlSelf->ledr),16);
    bufp->chgBit(oldp+21,(vlSelf->VGA_CLK));
    bufp->chgBit(oldp+22,(vlSelf->VGA_HSYNC));
    bufp->chgBit(oldp+23,(vlSelf->VGA_VSYNC));
    bufp->chgBit(oldp+24,(vlSelf->VGA_BLANK_N));
    bufp->chgCData(oldp+25,(vlSelf->VGA_R),8);
    bufp->chgCData(oldp+26,(vlSelf->VGA_G),8);
    bufp->chgCData(oldp+27,(vlSelf->VGA_B),8);
    bufp->chgCData(oldp+28,(vlSelf->seg0),8);
    bufp->chgCData(oldp+29,(vlSelf->seg1),8);
    bufp->chgCData(oldp+30,(vlSelf->seg2),8);
    bufp->chgCData(oldp+31,(vlSelf->seg3),8);
    bufp->chgCData(oldp+32,(vlSelf->seg4),8);
    bufp->chgCData(oldp+33,(vlSelf->seg5),8);
    bufp->chgCData(oldp+34,(vlSelf->seg6),8);
    bufp->chgCData(oldp+35,(vlSelf->seg7),8);
    bufp->chgBit(oldp+36,((1U & (~ (IData)(vlSelf->rst)))));
    bufp->chgCData(oldp+37,((0xffU & (IData)(vlSelf->sw))),8);
    bufp->chgCData(oldp+38,((7U & ((IData)(vlSelf->sw) 
                                   >> 8U))),3);
    bufp->chgBit(oldp+39,(vlSelf->top__DOT____Vcellinp__mybsf__clk));
    bufp->chgBit(oldp+40,((1U & ((IData)(vlSelf->sw) 
                                 >> 0xcU))));
    bufp->chgBit(oldp+41,((1U & ((IData)(vlSelf->sw) 
                                 >> 0xbU))));
    bufp->chgCData(oldp+42,(vlSelf->top__DOT____Vcellout__mybsf__out_s),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
