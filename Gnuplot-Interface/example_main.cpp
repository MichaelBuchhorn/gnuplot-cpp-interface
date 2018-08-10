#include "Gnuplot.h"

void main(void) {
	Gnuplot gnuplot1;
	gnuplot1.sendInstruction("plot sin(x) lc 1\n");
	
	Gnuplot gnuplot2;
	gnuplot2.sendInstruction("plot cos(x) lc 2\n");

	Sleep(5000);
}