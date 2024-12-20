#include "Vtop.h"
#include "verilated.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated_fst_c.h"
int main(int argc, char **argv) {
    VerilatedContext *contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vtop *top = new Vtop{contextp};

    //waveforms
    Verilated::traceEverOn(true);
    VerilatedFstC* tfp = new VerilatedFstC;
    top->trace(tfp, 99);
    Verilated::mkdir("logs");
    tfp->open("logs/simx.fst");
    while (!contextp->gotFinish()) {
        contextp->timeInc(1);
        int a = rand() & 1;
        int b = rand() & 1;
        top->a = a;
        top->b = b;
        top->eval();
        printf("a = %d, b = %d, f = %d\n", a, b, top->f);
        assert(top->f == (a ^ b));
        if (contextp->time() >= 60)
        {
            break;
        }
        tfp->dump(contextp->time());
    }
    top->final();
    tfp->close();
    delete tfp;
    delete top;
    delete contextp;
    return 0;
}