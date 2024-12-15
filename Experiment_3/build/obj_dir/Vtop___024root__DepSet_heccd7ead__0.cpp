// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ top__DOT__alu__DOT__t;
    top__DOT__alu__DOT__t = 0;
    CData/*3:0*/ top__DOT__alu__DOT__t_s;
    top__DOT__alu__DOT__t_s = 0;
    CData/*0:0*/ top__DOT__alu__DOT__t_w;
    top__DOT__alu__DOT__t_w = 0;
    // Body
    vlSelf->VGA_CLK = vlSelf->clk;
    vlSelf->uart_tx = vlSelf->uart_rx;
    top__DOT__alu__DOT__t_w = 0U;
    top__DOT__alu__DOT__t_s = 0U;
    top__DOT__alu__DOT__t = 0U;
    if ((4U & (IData)(vlSelf->btn))) {
        if ((2U & (IData)(vlSelf->btn))) {
            if ((1U & (IData)(vlSelf->btn))) {
                top__DOT__alu__DOT__t = (0xfU & ((IData)(1U) 
                                                 + 
                                                 (~ (IData)(vlSelf->sw))));
                vlSelf->top__DOT____Vcellout__alu__out_c 
                    = (1U & ((((0xfU & ((IData)(vlSelf->sw) 
                                        >> 0xcU)) + (IData)(top__DOT__alu__DOT__t)) 
                              + (1U & ((IData)(vlSelf->sw) 
                                       >> 4U))) >> 4U));
                top__DOT__alu__DOT__t_s = (0xfU & (
                                                   (((IData)(vlSelf->sw) 
                                                     >> 0xcU) 
                                                    + (IData)(top__DOT__alu__DOT__t)) 
                                                   + 
                                                   (1U 
                                                    & ((IData)(vlSelf->sw) 
                                                       >> 4U))));
                vlSelf->top__DOT____Vcellout__alu__out_s 
                    = (1U & (~ (IData)((0U != (IData)(top__DOT__alu__DOT__t_s)))));
            } else {
                top__DOT__alu__DOT__t = (0xfU & ((IData)(1U) 
                                                 + 
                                                 (~ (IData)(vlSelf->sw))));
                vlSelf->top__DOT____Vcellout__alu__out_c 
                    = (1U & ((((0xfU & ((IData)(vlSelf->sw) 
                                        >> 0xcU)) + (IData)(top__DOT__alu__DOT__t)) 
                              + (1U & ((IData)(vlSelf->sw) 
                                       >> 4U))) >> 4U));
                top__DOT__alu__DOT__t_s = (0xfU & (
                                                   (((IData)(vlSelf->sw) 
                                                     >> 0xcU) 
                                                    + (IData)(top__DOT__alu__DOT__t)) 
                                                   + 
                                                   (1U 
                                                    & ((IData)(vlSelf->sw) 
                                                       >> 4U))));
                top__DOT__alu__DOT__t_w = (IData)((8U 
                                                   == 
                                                   (0x8008U 
                                                    & (IData)(vlSelf->sw))));
                vlSelf->top__DOT____Vcellout__alu__out_s 
                    = (1U & ((~ (IData)(top__DOT__alu__DOT__t_w)) 
                             & ((IData)(top__DOT__alu__DOT__t_s) 
                                >> 3U)));
            }
        } else {
            vlSelf->top__DOT____Vcellout__alu__out_s 
                = (0xfU & ((1U & (IData)(vlSelf->btn))
                            ? (((IData)(vlSelf->sw) 
                                >> 0xcU) ^ (IData)(vlSelf->sw))
                            : (((IData)(vlSelf->sw) 
                                >> 0xcU) | (IData)(vlSelf->sw))));
        }
    } else if ((2U & (IData)(vlSelf->btn))) {
        vlSelf->top__DOT____Vcellout__alu__out_s = 
            (0xfU & ((1U & (IData)(vlSelf->btn)) ? 
                     (((IData)(vlSelf->sw) >> 0xcU) 
                      & (IData)(vlSelf->sw)) : (~ ((IData)(vlSelf->sw) 
                                                   >> 0xcU))));
    } else if ((1U & (IData)(vlSelf->btn))) {
        top__DOT__alu__DOT__t = (0xfU & ((IData)(1U) 
                                         + (~ (IData)(vlSelf->sw))));
        vlSelf->top__DOT____Vcellout__alu__out_c = 
            (1U & ((((0xfU & ((IData)(vlSelf->sw) >> 0xcU)) 
                     + (IData)(top__DOT__alu__DOT__t)) 
                    + (1U & ((IData)(vlSelf->sw) >> 4U))) 
                   >> 4U));
        vlSelf->top__DOT____Vcellout__alu__out_s = 
            (0xfU & ((((IData)(vlSelf->sw) >> 0xcU) 
                      + (IData)(top__DOT__alu__DOT__t)) 
                     + (1U & ((IData)(vlSelf->sw) >> 4U))));
        vlSelf->top__DOT____Vcellout__alu__ow = (1U 
                                                 & (IData)(
                                                           ((0U 
                                                             == 
                                                             (6U 
                                                              & (IData)(vlSelf->btn))) 
                                                            & ((~ 
                                                                (((IData)(vlSelf->sw) 
                                                                  >> 0xfU) 
                                                                 ^ 
                                                                 ((IData)(vlSelf->sw) 
                                                                  >> 3U))) 
                                                               & (((IData)(vlSelf->sw) 
                                                                   >> 0xfU) 
                                                                  ^ 
                                                                  ((IData)(vlSelf->top__DOT____Vcellout__alu__out_s) 
                                                                   >> 3U))))));
        vlSelf->top__DOT____Vcellout__alu__neg = (1U 
                                                  & ((IData)(vlSelf->top__DOT____Vcellout__alu__out_s) 
                                                     >> 3U));
        vlSelf->top__DOT____Vcellout__alu__zero = (1U 
                                                   & (~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->top__DOT____Vcellout__alu__out_s)))));
    } else {
        vlSelf->top__DOT____Vcellout__alu__out_s = 
            (0xfU & ((((IData)(vlSelf->sw) >> 0xcU) 
                      + (IData)(vlSelf->sw)) + (1U 
                                                & ((IData)(vlSelf->sw) 
                                                   >> 4U))));
        vlSelf->top__DOT____Vcellout__alu__out_c = 
            (1U & ((((0xfU & ((IData)(vlSelf->sw) >> 0xcU)) 
                     + (0xfU & (IData)(vlSelf->sw))) 
                    + (1U & ((IData)(vlSelf->sw) >> 4U))) 
                   >> 4U));
        vlSelf->top__DOT____Vcellout__alu__ow = (1U 
                                                 & (IData)(
                                                           ((0U 
                                                             == 
                                                             (6U 
                                                              & (IData)(vlSelf->btn))) 
                                                            & ((~ 
                                                                (((IData)(vlSelf->sw) 
                                                                  >> 0xfU) 
                                                                 ^ 
                                                                 ((IData)(vlSelf->sw) 
                                                                  >> 3U))) 
                                                               & (((IData)(vlSelf->sw) 
                                                                   >> 0xfU) 
                                                                  ^ 
                                                                  ((IData)(vlSelf->top__DOT____Vcellout__alu__out_s) 
                                                                   >> 3U))))));
        vlSelf->top__DOT____Vcellout__alu__neg = (1U 
                                                  & ((IData)(vlSelf->top__DOT____Vcellout__alu__out_s) 
                                                     >> 3U));
        vlSelf->top__DOT____Vcellout__alu__zero = (1U 
                                                   & (~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->top__DOT____Vcellout__alu__out_s)))));
    }
    vlSelf->ledr = ((0xffe0U & (IData)(vlSelf->ledr)) 
                    | (((IData)(vlSelf->top__DOT____Vcellout__alu__out_c) 
                        << 4U) | (IData)(vlSelf->top__DOT____Vcellout__alu__out_s)));
    vlSelf->ledr = ((0x1fffU & (IData)(vlSelf->ledr)) 
                    | (((IData)(vlSelf->top__DOT____Vcellout__alu__ow) 
                        << 0xfU) | (((IData)(vlSelf->top__DOT____Vcellout__alu__neg) 
                                     << 0xeU) | ((IData)(vlSelf->top__DOT____Vcellout__alu__zero) 
                                                 << 0xdU))));
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*23:0*/ top__DOT__vga_data;
    top__DOT__vga_data = 0;
    CData/*0:0*/ top__DOT__my_vga_ctrl__DOT__h_valid;
    top__DOT__my_vga_ctrl__DOT__h_valid = 0;
    CData/*0:0*/ top__DOT__my_vga_ctrl__DOT__v_valid;
    top__DOT__my_vga_ctrl__DOT__v_valid = 0;
    SData/*9:0*/ __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt;
    __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 0;
    SData/*9:0*/ __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt;
    __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = 0;
    CData/*2:0*/ __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync;
    __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync = 0;
    CData/*3:0*/ __Vdly__top__DOT__my_keyboard__DOT__count;
    __Vdly__top__DOT__my_keyboard__DOT__count = 0;
    // Body
    __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync;
    __Vdly__top__DOT__my_keyboard__DOT__count = vlSelf->top__DOT__my_keyboard__DOT__count;
    __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt;
    __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt;
    __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = ((6U & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->ps2_clk));
    if (vlSelf->rst) {
        __Vdly__top__DOT__my_keyboard__DOT__count = 0U;
    } else if ((IData)((4U == (6U & (IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync))))) {
        if ((0xaU == (IData)(vlSelf->top__DOT__my_keyboard__DOT__count))) {
            if (VL_UNLIKELY((((~ (IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer)) 
                              & (IData)(vlSelf->ps2_data)) 
                             & VL_REDXOR_32((0x1ffU 
                                             & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer) 
                                                >> 1U)))))) {
                VL_WRITEF("receive %x\n",8,(0xffU & 
                                            ((IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer) 
                                             >> 1U)));
            }
            __Vdly__top__DOT__my_keyboard__DOT__count = 0U;
        } else {
            vlSelf->top__DOT__my_keyboard__DOT____Vlvbound_h1a91ade8__0 
                = vlSelf->ps2_data;
            if (VL_LIKELY((9U >= (IData)(vlSelf->top__DOT__my_keyboard__DOT__count)))) {
                vlSelf->top__DOT__my_keyboard__DOT__buffer 
                    = (((~ ((IData)(1U) << (IData)(vlSelf->top__DOT__my_keyboard__DOT__count))) 
                        & (IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer)) 
                       | (0x3ffU & ((IData)(vlSelf->top__DOT__my_keyboard__DOT____Vlvbound_h1a91ade8__0) 
                                    << (IData)(vlSelf->top__DOT__my_keyboard__DOT__count))));
            }
            __Vdly__top__DOT__my_keyboard__DOT__count 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_keyboard__DOT__count)));
        }
    }
    if (vlSelf->rst) {
        __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 1U;
        __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = 1U;
    } else if ((0x320U == (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt))) {
        __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = 
            ((0x20dU == (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt))
              ? 1U : (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt))));
        __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 1U;
    } else {
        __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 
            (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)));
    }
    vlSelf->top__DOT__my_keyboard__DOT__count = __Vdly__top__DOT__my_keyboard__DOT__count;
    vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync;
    vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt = __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt;
    vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt = __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt;
    vlSelf->VGA_HSYNC = (0x60U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt));
    top__DOT__my_vga_ctrl__DOT__h_valid = ((0x90U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)) 
                                           & (0x310U 
                                              >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)));
    vlSelf->VGA_VSYNC = (2U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt));
    top__DOT__my_vga_ctrl__DOT__v_valid = ((0x23U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)) 
                                           & (0x203U 
                                              >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)));
    vlSelf->VGA_BLANK_N = ((IData)(top__DOT__my_vga_ctrl__DOT__h_valid) 
                           & (IData)(top__DOT__my_vga_ctrl__DOT__v_valid));
    top__DOT__vga_data = vlSelf->top__DOT__my_vmem__DOT__vga_mem
        [((((IData)(top__DOT__my_vga_ctrl__DOT__h_valid)
             ? (0x3ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt) 
                          - (IData)(0x91U))) : 0U) 
           << 9U) | ((IData)(top__DOT__my_vga_ctrl__DOT__v_valid)
                      ? (0x1ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt) 
                                   - (IData)(0x24U)))
                      : 0U))];
    vlSelf->VGA_R = (0xffU & (top__DOT__vga_data >> 0x10U));
    vlSelf->VGA_G = (0xffU & (top__DOT__vga_data >> 8U));
    vlSelf->VGA_B = (0xffU & top__DOT__vga_data);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/gx/ysyx/Experiment_3/vsrc/top.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/gx/ysyx/Experiment_3/vsrc/top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/gx/ysyx/Experiment_3/vsrc/top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->btn & 0xe0U))) {
        Verilated::overWidthError("btn");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
    if (VL_UNLIKELY((vlSelf->uart_rx & 0xfeU))) {
        Verilated::overWidthError("uart_rx");}
}
#endif  // VL_DEBUG
