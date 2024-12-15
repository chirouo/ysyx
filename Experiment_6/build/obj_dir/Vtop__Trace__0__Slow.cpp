// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+13,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+14,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+15,"btn",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+16,"sw",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->declBit(c+17,"ps2_clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+18,"ps2_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+19,"uart_rx",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+20,"uart_tx",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+21,"ledr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->declBit(c+22,"VGA_CLK",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"VGA_HSYNC",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"VGA_VSYNC",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"VGA_BLANK_N",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+26,"VGA_R",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+27,"VGA_G",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+28,"VGA_B",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+29,"seg0",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+30,"seg1",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+31,"seg2",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+32,"seg3",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+33,"seg4",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+34,"seg5",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+35,"seg6",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+36,"seg7",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+13,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+14,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+15,"btn",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+16,"sw",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->declBit(c+17,"ps2_clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+18,"ps2_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+19,"uart_rx",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+20,"uart_tx",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+21,"ledr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->declBit(c+22,"VGA_CLK",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"VGA_HSYNC",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"VGA_VSYNC",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"VGA_BLANK_N",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+26,"VGA_R",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+27,"VGA_G",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+28,"VGA_B",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+29,"seg0",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+30,"seg1",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+31,"seg2",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+32,"seg3",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+33,"seg4",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+34,"seg5",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+35,"seg6",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+36,"seg7",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+1,"h_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 9,0);
    tracep->declBus(c+2,"v_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 9,0);
    tracep->declBus(c+3,"vga_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 23,0);
    tracep->pushNamePrefix("my_keyboard ");
    tracep->declBit(c+13,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+37,"resetn",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+17,"ps2_clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+18,"ps2_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+4,"buffer",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 9,0);
    tracep->declBus(c+5,"count",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 3,0);
    tracep->declBus(c+6,"ps2_clk_sync",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
    tracep->declBit(c+7,"sampling",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_uart ");
    tracep->declBit(c+20,"tx",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+19,"rx",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_vga_ctrl ");
    tracep->declBit(c+13,"pclk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+14,"reset",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+3,"vga_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 23,0);
    tracep->declBus(c+1,"h_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 9,0);
    tracep->declBus(c+2,"v_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 9,0);
    tracep->declBit(c+23,"hsync",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"vsync",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+26,"vga_r",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+27,"vga_g",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+28,"vga_b",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+44,"h_frontporch",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+45,"h_active",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+46,"h_backporch",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+47,"h_total",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+48,"v_frontporch",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+49,"v_active",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+50,"v_backporch",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+51,"v_total",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+8,"x_cnt",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 9,0);
    tracep->declBus(c+9,"y_cnt",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 9,0);
    tracep->declBit(c+10,"h_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+11,"v_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_vmem ");
    tracep->declBus(c+1,"h_addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 9,0);
    tracep->declBus(c+12,"v_addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 8,0);
    tracep->declBus(c+3,"vga_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 23,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mybsf ");
    tracep->declBus(c+38,"in_x",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+39,"shamt",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBit(c+40,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+41,"L_R",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+42,"A_L",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+43,"out_s",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__h_valid)
                              ? (0x3ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt) 
                                           - (IData)(0x91U)))
                              : 0U)),10);
    bufp->fullSData(oldp+2,(((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__v_valid)
                              ? (0x3ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt) 
                                           - (IData)(0x24U)))
                              : 0U)),10);
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__vga_data),24);
    bufp->fullSData(oldp+4,(vlSelf->top__DOT__my_keyboard__DOT__buffer),10);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__my_keyboard__DOT__count),4);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync),3);
    bufp->fullBit(oldp+7,((IData)((4U == (6U & (IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync))))));
    bufp->fullSData(oldp+8,(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt),10);
    bufp->fullSData(oldp+9,(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt),10);
    bufp->fullBit(oldp+10,(vlSelf->top__DOT__my_vga_ctrl__DOT__h_valid));
    bufp->fullBit(oldp+11,(vlSelf->top__DOT__my_vga_ctrl__DOT__v_valid));
    bufp->fullSData(oldp+12,(((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__v_valid)
                               ? (0x1ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt) 
                                            - (IData)(0x24U)))
                               : 0U)),9);
    bufp->fullBit(oldp+13,(vlSelf->clk));
    bufp->fullBit(oldp+14,(vlSelf->rst));
    bufp->fullCData(oldp+15,(vlSelf->btn),5);
    bufp->fullSData(oldp+16,(vlSelf->sw),16);
    bufp->fullBit(oldp+17,(vlSelf->ps2_clk));
    bufp->fullBit(oldp+18,(vlSelf->ps2_data));
    bufp->fullBit(oldp+19,(vlSelf->uart_rx));
    bufp->fullBit(oldp+20,(vlSelf->uart_tx));
    bufp->fullSData(oldp+21,(vlSelf->ledr),16);
    bufp->fullBit(oldp+22,(vlSelf->VGA_CLK));
    bufp->fullBit(oldp+23,(vlSelf->VGA_HSYNC));
    bufp->fullBit(oldp+24,(vlSelf->VGA_VSYNC));
    bufp->fullBit(oldp+25,(vlSelf->VGA_BLANK_N));
    bufp->fullCData(oldp+26,(vlSelf->VGA_R),8);
    bufp->fullCData(oldp+27,(vlSelf->VGA_G),8);
    bufp->fullCData(oldp+28,(vlSelf->VGA_B),8);
    bufp->fullCData(oldp+29,(vlSelf->seg0),8);
    bufp->fullCData(oldp+30,(vlSelf->seg1),8);
    bufp->fullCData(oldp+31,(vlSelf->seg2),8);
    bufp->fullCData(oldp+32,(vlSelf->seg3),8);
    bufp->fullCData(oldp+33,(vlSelf->seg4),8);
    bufp->fullCData(oldp+34,(vlSelf->seg5),8);
    bufp->fullCData(oldp+35,(vlSelf->seg6),8);
    bufp->fullCData(oldp+36,(vlSelf->seg7),8);
    bufp->fullBit(oldp+37,((1U & (~ (IData)(vlSelf->rst)))));
    bufp->fullCData(oldp+38,((0xffU & (IData)(vlSelf->sw))),8);
    bufp->fullCData(oldp+39,((7U & ((IData)(vlSelf->sw) 
                                    >> 8U))),3);
    bufp->fullBit(oldp+40,(vlSelf->top__DOT____Vcellinp__mybsf__clk));
    bufp->fullBit(oldp+41,((1U & ((IData)(vlSelf->sw) 
                                  >> 0xcU))));
    bufp->fullBit(oldp+42,((1U & ((IData)(vlSelf->sw) 
                                  >> 0xbU))));
    bufp->fullCData(oldp+43,(vlSelf->top__DOT____Vcellout__mybsf__out_s),8);
    bufp->fullIData(oldp+44,(0x60U),32);
    bufp->fullIData(oldp+45,(0x90U),32);
    bufp->fullIData(oldp+46,(0x310U),32);
    bufp->fullIData(oldp+47,(0x320U),32);
    bufp->fullIData(oldp+48,(2U),32);
    bufp->fullIData(oldp+49,(0x23U),32);
    bufp->fullIData(oldp+50,(0x203U),32);
    bufp->fullIData(oldp+51,(0x20dU),32);
}
