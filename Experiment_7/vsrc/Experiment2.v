module decode38(x,en,y);
  input  [2:0] x;
  input  en;
  output reg [7:0]y;

  always @(x or en)
    if (en)
    begin
      case (x)
// Common Anode
        3'd0 : y = 8'b11111111;
        3'd1 : y = 8'b11111001;
        3'd2 : y = 8'b10100100;
        3'd3 : y = 8'b10110000;
        3'd4 : y = 8'b10011001;
        3'd5 : y = 8'b10010010;
        3'd6 : y = 8'b10000010;
        3'd7 : y = 8'b11111000;
      endcase
    end
    else  y = 8'b00000000;

endmodule

module pri_encode83(x,en,y);
  input  [7:0] x;
  input  en;
  output reg [2:0]y;
  integer i;
  always @(x or en) begin
    if (en) begin
      y = 0;
      for( i = 0; i <= 7; i = i+1)
          if(x[i] == 1)  y = i[2:0];
    end
    else  y = 0;
  end
endmodule