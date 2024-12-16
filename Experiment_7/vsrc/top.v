module top(
    input clk,
    input rst,
    input [4:0] btn,
    input [15:0] sw,
    input ps2_clk,
    input ps2_data,
    input uart_rx,
    output uart_tx,
    output [15:0] ledr,
    output VGA_CLK,
    output VGA_HSYNC,
    output VGA_VSYNC,
    output VGA_BLANK_N,
    output [7:0] VGA_R,
    output [7:0] VGA_G,
    output [7:0] VGA_B,
    output [7:0] seg0,
    output [7:0] seg1,
    output [7:0] seg2,
    output [7:0] seg3,
    output [7:0] seg4,
    output [7:0] seg5,
    output [7:0] seg6,
    output [7:0] seg7
);


//Experiment_7
wire[7:0]  temp_seg_1, temp_seg_2, temp_seg_3;
ps2_keyboard_temp my_keyboard(
    .clk(clk),
    .clrn(~rst),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .data(temp_seg_3),
    .nextdata_n(sw[0]),
    .ready(ledr[15]),
    .overflow(ledr[14]),

    .count_c(temp_seg_1)
);
LUT mylut(
    .clk(clk),
    .in_x(temp_seg_3),
    .dout(temp_seg_2)
);
SEGSHOW myshow01(
    .seg_1(seg0),
    .seg_2(seg1),
    .in_x(temp_seg_3)
);
SEGSHOW myshow23(
    .seg_1(seg2),
    .seg_2(seg3),
    .in_x(temp_seg_2)
);
SEGSHOW myshow45(
    .seg_1(seg4),
    .seg_2(seg5),
    .in_x(temp_seg_1)
);

// mealy mymealy(
//     .reset(sw[0]),
//     .in_x(sw[1]),
//     .clk(sw[3]),
//     .out_s(ledr[0]),
//     .state(ledr[7:4])
// );
// mealy mymoore(
//     .reset(sw[0]),
//     .in_x(sw[1]),
//     .clk(sw[3]),
//     .out_s(ledr[0]),
//     .state(ledr[7:4])
// );
//Experiment_6
// LSFR mylsfr(
//     .clk(sw[15]),
//     .led(ledr[15]),
//     .out_s(ledr[7:0])
// );
// BSF mybsf(
//     .in_x(sw[7:0]),
//     .shamt(sw[10:8]),
//     .clk(sw[15]),
//     .out_s(ledr[7:0]),
//     .A_L(sw[11]),
//     .L_R(sw[12])
// );
//Experiment_3
//Test btn
    // assign ledr[4:0] = btn[4:0];
// ALU alu(
//     .ALU_control(btn[2:0]), 
//     .in_x(sw[15:12]),
//     .in_y(sw[3:0]),
//     .in_c(sw[4]),
//     .out_s(ledr[3:0]),
//     .out_c(ledr[4]),
//     .ow(ledr[15]),
//     .neg(ledr[14]),
//     .zero(ledr[13])
// );
//Experiment_2
// assign seg0=8'b01011100;
// wire[2:0] temp;
// decode38 my_decode38(
//     .x(temp[2:0]),
//     .en(sw[15]),
//     .y({seg0[0], seg0[1], seg0[2], seg0[3], seg0[4], seg0[5], seg0[6], seg0[7]})
// );
// pri_encode83 my_encode83(
//     .x(sw[7:0]),
//     .en(sw[14]),
//     .y(temp)
// );
// Experiment_1
// MuxKeyWithDefault  #(4, 2, 2) my_mux41 (
//     .out(ledr[1:0]), 
//     .key(sw[1:0]), 
//     .default_out(2'b00), 
//     .lut({
//         2'b00, sw[3:2],
//         2'b01, sw[5:4],
//         2'b10, sw[7:6],
//         2'b11, sw[9:8]
//     }));

//Example of running water lamp
// light my_led(
//     .clk(clk),
//     .rst(rst),
//     .led(ledr)
// );

assign VGA_CLK = clk;

wire [9:0] h_addr;
wire [9:0] v_addr;
wire [23:0] vga_data;

vga_ctrl my_vga_ctrl(
    .pclk(clk),
    .reset(rst),
    .vga_data(vga_data),
    .h_addr(h_addr),
    .v_addr(v_addr),
    .hsync(VGA_HSYNC),
    .vsync(VGA_VSYNC),
    .valid(VGA_BLANK_N),
    .vga_r(VGA_R),
    .vga_g(VGA_G),
    .vga_b(VGA_B)
);

// ps2_keyboard my_keyboard(
//     .clk(clk),
//     .resetn(~rst),
//     .ps2_clk(ps2_clk),
//     .ps2_data(ps2_data),
//     .buffer(ledr[7:0])
// );

// seg my_seg(
//     .clk(clk),
//     .rst(rst),
//     // .o_seg0(seg0),
//     .o_seg1(seg1),
//     .o_seg2(seg2),
//     .o_seg3(seg3),
//     .o_seg4(seg4),
//     .o_seg5(seg5),
//     .o_seg6(seg6),
//     .o_seg7(seg7)
// );

vmem my_vmem(
    .h_addr(h_addr),
    .v_addr(v_addr[8:0]),
    .vga_data(vga_data)
);

uart my_uart(
  .tx(uart_tx),
  .rx(uart_rx)
);

endmodule

module vmem(
    input [9:0] h_addr,
    input [8:0] v_addr,
    output [23:0] vga_data
);

reg [23:0] vga_mem [524287:0];

initial begin
    $readmemh("resource/picture.hex", vga_mem);
end

assign vga_data = vga_mem[{h_addr, v_addr}];

endmodule
