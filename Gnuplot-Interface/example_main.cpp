#include "Gnuplot.h"

void main(void) {
	Gnuplot gnuplot1;
	gnuplot1.command("set xrange [0:30]");
	gnuplot1.command("plot sin(x) lc 1");
	
	Gnuplot gnuplot2;
	double randomData[20] = { 93.1, 72.4, 61.4, 7.5, 92.8, 8.1, 86.7, 5.2, 6.9, 31.2, 42.0, 22.4, 18.7, 42.5, 39.5, 49.3, 27.8, 99.4, 31.9, 85.0 };
	gnuplot2.command("plot '-' w lines");
	for (int i = 0; i < 20; i++) {
		gnuplot2.command("%d\t%f", i, randomData[i]);
	}
	gnuplot2.command("e");

	Sleep(5000);
}
