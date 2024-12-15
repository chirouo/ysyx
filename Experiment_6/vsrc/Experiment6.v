module LSFR(
    input  clk,
    output led,
    output reg [7:0] out_s
);
    initial begin
        out_s = 8'b00000001;
    end
    assign led = clk;
    always@(posedge clk) begin
        out_s <= {out_s[4] ^ out_s[3] ^ out_s[2] ^ out_s[0], out_s[7:1]};
    end
endmodule

module BSF(
    input [7:0] in_x,
    input [2:0] shamt,
    input clk,
    input L_R,
    input A_L,
    output reg [7:0] out_s
);
    always@(posedge clk) begin
        if(L_R)begin
            out_s <= in_x << shamt;
        end else begin
            if(A_L) begin
                case (shamt)
                    3'd0: out_s <= in_x;
                    3'd1: out_s <= {{1{in_x[7]}}, in_x[7:1]};  // 左移1
                    3'd2: out_s <= {{2{in_x[7]}}, in_x[7:2]};  // 左移2
                    3'd3: out_s <= {{3{in_x[7]}}, in_x[7:3]};  // 左移3
                    3'd4: out_s <= {{4{in_x[7]}}, in_x[7:4]};  // 左移4
                    3'd5: out_s <= {{5{in_x[7]}}, in_x[7:5]};  // 左移5
                    3'd6: out_s <= {{6{in_x[7]}}, in_x[7:6]};  // 左移6
                    3'd7: out_s <= {{7{in_x[7]}}, in_x[7]};  // 左移7
                    // Add more cases if needed
                    default: out_s <= in_x; // Default to no shift
                endcase
            end
            else    out_s <= in_x >> shamt;
        end
    end
endmodule
