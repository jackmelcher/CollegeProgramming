module processor_tb;
	// Inputs
	reg p_clk;
	reg pc_enable;
	reg p_rst_s;
	
	// Outputs
	//wire ref_clk;
	//wire reset;
	wire [31:0]rom_addrs;
	wire [31:0]instruction;
	wire [4:0]reg_read1;
	wire [4:0]reg_read2;
	wire [31:0]reg_data1;
	wire [31:0]reg_data2;
	wire [31:0]immediate;
	wire [31:0]b_output;
	wire [31:0]alu_output;
	wire ram_we;
	wire [31:0]ram_rdata;
	wire reg_we;
	wire [4:0]reg_waddr;
	wire [31:0]o_output;

	// Instantiate the Unit Under Test (UUT)
	processor uut(
		.p_clk(p_clk),
		.pc_enable(pc_enable),
		.p_rst_s(p_rst_s),
		.rom_addrs(rom_addrs),
		.instruction(instruction),
		.reg_read1(reg_read1),
		.reg_read2(reg_read2),
		.reg_data1(reg_data1),
		.reg_data2(reg_data2),
		.immediate(immediate),
		.b_output(b_output),
		.alu_output(alu_output),
		.ram_we(ram_we),
		.ram_rdata(ram_rdata),
		.reg_we(reg_we),
		.reg_waddr(reg_waddr),
		.o_output(o_output)
	);

initial begin
	p_clk = 0;
	pc_enable = 1;
	p_rst_s = 0;
	#100;
	//addi
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//slti
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//andi
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;	
	//ori
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//xori
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//add
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//sub
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//and
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//or
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//xor
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//nor
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;	
	//slt
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//sw
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//lw
	p_clk = 1;
	#100;
	p_clk = 0;
	#100;
	//addi
	end
	
endmodule