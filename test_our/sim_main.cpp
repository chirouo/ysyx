#include "Vour.h"
#include "verilated.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated_vcd_c.h"
  int main(int argc, char** argv) {
      VerilatedContext* contextp = new VerilatedContext;
      contextp->commandArgs(argc, argv);
      Vour* top = new Vour{contextp};
	//waveforms
		Verilated::traceEverOn(true);
		VerilatedVcdC* tfp = new VerilatedVcdC;
		top->trace(tfp, 99);
		Verilated::mkdir("logs");
		tfp->open("logs/simx.vcd");
      while (!contextp->gotFinish()) { top->eval(); }
	 top->final();
	  tfp->close();
      delete top;
	  delete tfp;
      delete contextp;
      return 0;
  }
