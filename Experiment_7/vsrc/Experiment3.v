module ALU(
    input  [2:0]  ALU_control,
    input  [3:0]  in_x,
    input  [3:0]  in_y,
    input  in_c,
    output reg [3:0] out_s,
    output reg out_c,
    output reg ow,
    output reg neg,
    output reg zero
);
    reg[3:0] t;
    reg[3:0] t_s;
    reg t_w;
    always@(*) begin
        t_w = 0; t_s = 0; t = 0;
        case(ALU_control)
            3'd0:begin
                {out_c, out_s} = in_x + in_y + {3'b000,in_c};
                ow = (~(in_x[3] ^ in_y[3])) & (in_x[3] ^ out_s[3]) & ~ALU_control[2] & ~ALU_control[1];
                neg = out_s[3];
                zero = ~(|out_s);
            end
            3'd1:begin
                t = ~in_y[3:0] + 4'b0001;
                {out_c, out_s} = in_x + t + {3'b000,in_c};
                ow = (~(in_x[3] ^ in_y[3])) & (in_x[3] ^ out_s[3]) & ~ALU_control[2] & ~ALU_control[1];
                neg = out_s[3];
                zero = ~(|out_s);
            end
            3'd2:out_s = ~(in_x);
            3'd3:out_s = in_x & in_y;
            3'd4:out_s = in_x | in_y;
            3'd5:out_s = in_x ^ in_y;
            3'd6:begin
                t = ~in_y[3:0] + 4'b0001;
                {out_c, t_s} = in_x + t + {3'b000,in_c};
                t_w = ~in_x[3] & in_y[3];//特殊情况 正数-负数=正数+正数 可能会溢出导致符号位为1
                out_s = {3'b000,~t_w & t_s[3]};
            end
            3'd7:begin
                t = ~in_y[3:0] + 4'b0001;
                {out_c, t_s} = in_x + t + {3'b000,in_c};
                out_s = {3'b000,~(|t_s)};
            end
        endcase 
    end
endmodule