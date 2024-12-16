module mealy(
    input in_x,
    output  out_s,
    output reg [3:0] state,
    input clk,
    input reset
);
    always@(posedge clk) begin
        case(state)
        4'b0000:begin
            if(in_x)    state <= 4'b0101;
            else        state <= 4'b0001; 
        end
        4'b0001:begin
            if(in_x)    state <= 4'b0101;
            else        state <= 4'b0010; 
        end
        4'b0010:begin
            if(in_x)    state <= 4'b0101;
            else        state <= 4'b0011; 
        end
        4'b0011:begin
            if(in_x)    state <= 4'b0101;
            else        state <= 4'b0100; 
        end
        4'b0100:begin
            if(in_x)    state <= 4'b0101;
            else        state <= 4'b0100; 
        end
        4'b0101:begin
            if(in_x)    state <= 4'b0110;
            else        state <= 4'b0001; 
        end
        4'b0110:begin
            if(in_x)    state <= 4'b0111;
            else        state <= 4'b0001; 
        end
        4'b0111:begin
            if(in_x)    state <= 4'b1000;
            else        state <= 4'b0001; 
        end
        4'b1000:begin
            if(in_x)    state <= 4'b1000;
            else        state <= 4'b0001; 
        end
        default:state<=4'b0000;
        endcase
        if(reset) state <= 4'b0000;

    end
    assign out_s = ((state == 4'b0100) ||(state == 4'b1000)) ? 1 : 0;
endmodule
module moore(
    input in_x,
    output reg out_s,
    output reg [3:0] state,
    input clk,
    input reset
);
    always@(posedge clk) begin
        if(reset) state <= 4'b0000;
        if(state == 4'b0100) out_s <= 1;
        else if(state == 4'b1000) out_s <= 1;
        else out_s <= 0;
        case(state)
        4'b0000:begin
            if(in_x)    state <= 4'b0101;
            else        state <= 4'b0001; 
        end
        4'b0001:begin
            if(in_x)    state <= 4'b0101;
            else        state <= 4'b0010; 
        end
        4'b0010:begin
            if(in_x)    state <= 4'b0101;
            else        state <= 4'b0011; 
        end
        4'b0011:begin
            if(in_x)    state <= 4'b0101;
            else        state <= 4'b0100; 
        end
        4'b0100:begin
            if(in_x)    state <= 4'b0101;
            else        state <= 4'b0100; 
        end
        4'b0101:begin
            if(in_x)    state <= 4'b0110;
            else        state <= 4'b0001; 
        end
        4'b0110:begin
            if(in_x)    state <= 4'b0111;
            else        state <= 4'b0001; 
        end
        4'b0111:begin
            if(in_x)    state <= 4'b1000;
            else        state <= 4'b0001; 
        end
        4'b1000:begin
            if(in_x)    state <= 4'b1000;
            else        state <= 4'b0001; 
        end
        default:state<=4'b0000;
        endcase
        if(reset) state <= 4'b0000;
    end
endmodule


module ps2_keyboard_temp(clk,clrn,ps2_clk,ps2_data,data,
                    ready,nextdata_n,overflow, count_c);
    input clk,clrn,ps2_clk,ps2_data;
    input nextdata_n;
    output [7:0] data;
    output reg ready;
    output reg overflow;     // fifo overflow
    output reg [7:0] count_c;
    // internal signal, for test
    reg [9:0] buffer;        // ps2_data bits
    reg [7:0] fifo[7:0];     // data fifo
    reg [2:0] w_ptr,r_ptr;   // fifo write and read pointers
    reg [3:0] count;  // count ps2_data bits
    // detect falling edge of ps2_clk
    reg [2:0] ps2_clk_sync;

    always @(posedge clk) begin
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
        if (clrn == 0) begin // reset
            count <= 0; w_ptr <= 0; r_ptr <= 0; overflow <= 0; ready<= 0;
        end
        else begin
            if ( ready ) begin // read to output next data
                if(nextdata_n == 1'b0) //read next data
                begin
                    r_ptr <= r_ptr + 3'b1;
                    if(w_ptr==(r_ptr+1'b1)) //empty
                        ready <= 1'b0;
                end
            end
            if (sampling) begin
              if (count == 4'd10) begin
                if ((buffer[0] == 0) &&  // start bit
                    (ps2_data)       &&  // stop bit
                    (^buffer[9:1])) begin      // odd  parity
                    fifo[w_ptr] <= buffer[8:1];  // kbd scan code
                    $display("receive %x", buffer[8:1]);
                    w_ptr <= w_ptr+3'b1;
                    ready <= 1'b1;
                    overflow <= overflow | (r_ptr == (w_ptr + 3'b1));
                    if(buffer[8:1] == 8'hf0) count_c <= count_c + 8'd1;
                end
                count <= 0;     // for next
              end else begin
                buffer[count] <= ps2_data;  // store ps2_data
                count <= count + 3'b1;
              end
            end
        end
    end
    assign data = fifo[r_ptr]; //always set output data

endmodule

module LUT (clk, in_x, dout);
  input clk;
  input [7:0]in_x;
  output reg [7:0] dout;

  reg [7:0] ram [255:0];

  initial
  begin
    ram[8'h1C] = 8'h41;
  end

  always @(posedge clk)
  begin
        dout <= ram[in_x];
  end
endmodule 

module SEGSHOW(seg_1, seg_2, in_x);
    input  [7:0] in_x;
    output reg [7:0] seg_1, seg_2;
    always@(*) begin
    case (in_x[3:0])
// Common Anode (倒序后)
        4'd0 : seg_1 = 8'b00000011; // 倒序: 11111111
        4'd1 : seg_1 = 8'b10011111; // 倒序: 11111001
        4'd2 : seg_1 = 8'b00100101; // 倒序: 10100100
        4'd3 : seg_1 = 8'b00001101; // 倒序: 10110000
        4'd4 : seg_1 = 8'b10011001; // 倒序: 10011001
        4'd5 : seg_1 = 8'b01001001; // 倒序: 10010010
        4'd6 : seg_1 = 8'b01000001; // 倒序: 10000010
        4'd7 : seg_1 = 8'b00011111; // 倒序: 11111000
        4'd8 : seg_1 = 8'b00000001; // 倒序: 10000000
        4'd9 : seg_1 = 8'b00011001; // 倒序: 10011000
        4'd10 : seg_1 = 8'b00010001; // 倒序: 10001000
        4'd11 : seg_1 = 8'b00000001; // 倒序: 10000000
        4'd12 : seg_1 = 8'b01100011; // 倒序: 11000110
        4'd13 : seg_1 = 8'b00000011; // 倒序: 11000000
        4'd14 : seg_1 = 8'b01100001; // 倒序: 10000110
        4'd15 : seg_1 = 8'b01110001; // 倒序: 10001110
    endcase

    case (in_x[7:4])
// Common Anode (倒序后)
        4'd0 : seg_2 = 8'b00000011; // 倒序: 11111111
        4'd1 : seg_2 = 8'b10011111; // 倒序: 11111001
        4'd2 : seg_2 = 8'b00100101; // 倒序: 10100100
        4'd3 : seg_2 = 8'b00001101; // 倒序: 10110000
        4'd4 : seg_2 = 8'b10011001; // 倒序: 10011001
        4'd5 : seg_2 = 8'b01001001; // 倒序: 10010010
        4'd6 : seg_2 = 8'b01000001; // 倒序: 10000010
        4'd7 : seg_2 = 8'b00011111; // 倒序: 11111000
        4'd8 : seg_2 = 8'b00000001; // 倒序: 10000000
        4'd9 : seg_2 = 8'b00011001; // 倒序: 10011000
        4'd10 : seg_2 = 8'b00010001; // 倒序: 10001000
        4'd11 : seg_2 = 8'b00000001; // 倒序: 10000000
        4'd12 : seg_2 = 8'b01100011; // 倒序: 11000110
        4'd13 : seg_2 = 8'b00000011; // 倒序: 11000000
        4'd14 : seg_2 = 8'b01100001; // 倒序: 10000110
        4'd15 : seg_2 = 8'b01110001; // 倒序: 10001110
    endcase
    end

endmodule