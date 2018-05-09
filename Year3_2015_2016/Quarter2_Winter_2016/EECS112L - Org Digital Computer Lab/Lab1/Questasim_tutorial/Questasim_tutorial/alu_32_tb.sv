module alu_32_tb;
  logic[31:0] A;
  logic[31:0]  B;
  logic[3:0] opcode;
  wire overflow;
  wire c_out;
  wire equal;
  wire[31:0] output1;
  
alu_32 L1(
          .A(A)
         ,.B(B)
         ,.opcode(opcode)
         ,.overflow(overflow)
         ,.c_out(c_out)
         ,.equal(equal)
         ,.output1(output1)
         );

initial begin
/*arithmetic operation*/
           A = 32'b01010101010101010101010101010101;
	   B = 32'b10101010101010101010101010101010;
	   opcode = 4'b0000;
           #100;                
	   opcode = 4'b0001;	/*-- ADD*/	
	   #100;
	   opcode = 4'b0010;	/*--SUB*/
	   #100;
	   opcode = 4'b0011;	/*--COMP*/
	   #100	;
	   opcode = 4'b0101;	/*--AND*/
	   #100;
           opcode = 4'b0110;	/*--OR*/
           #100;
	   opcode = 4'b0111;	/*--NOT*/
           #100;
	   opcode = 4'b1000;	/*--XOR*/
	   #100;
	   opcode = 4'b1001;	/*--SLL*/
	   #100;
           opcode = 4'b1011;	/*--MOV*/
	   #100;
	   
       /*round 2*/
	   A = 32'b10101010101010101010101010101010;
	   B = 32'b01010101010101010101010101010101;
           opcode = 4'b0000;
           #100;                
	   opcode = 4'b0001;	/*-- ADD*/	
	   #100;
	   opcode = 4'b0010;	/*--SUB*/
	   #100;
	   opcode = 4'b0011;	/*--COMP*/
	   #100	;
	   opcode = 4'b0101;	/*--AND*/
	   #100;
           opcode = 4'b0110;	/*--OR*/
           #100;
	   opcode = 4'b0111;	/*--NOT*/
           #100;
	   opcode = 4'b1000;	/*--XOR*/
	   #100;
	   opcode = 4'b1001;	/*--SLL*/
	   #100;
           opcode = 4'b1011;	/*--MOV*/
	   #100;

 /*round 3*/
	   A = 32'b00101010101110111010101011111110;
	   B = 32'b00101010101110111010101011111110;
           opcode = 4'b0000;
           #100;                
	   opcode = 4'b0001;	/*-- ADD*/	
	   #100;
	   opcode = 4'b0010;	/*--SUB*/
	   #100;
	   opcode = 4'b0011;	/*--COMP*/
	   #100	;
	   opcode = 4'b0101;	/*--AND*/
	   #100;
           opcode = 4'b0110;	/*--OR*/
           #100;
	   opcode = 4'b0111;	/*--NOT*/
           #100;
	   opcode = 4'b1000;	/*--XOR*/
	   #100;
	   opcode = 4'b1001;	/*--SLL*/
	   #100;
           opcode = 4'b1011;	/*--MOV*/
	   #100;

 /*round 4*/ /* Test SLL */
	   A = 32'b00101010101110111010101011111110;
	   B = 32'b00000000000000000000000000000011;
           opcode = 4'b1001;
	   #100;

end
endmodule
    
