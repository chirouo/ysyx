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