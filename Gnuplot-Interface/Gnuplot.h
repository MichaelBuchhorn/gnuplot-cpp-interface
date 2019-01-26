#pragma once


//#include <iostream>
#include <io.h>
#include <Fcntl.h> // contains the definitions for the options argument of the  _open_osfhandle function
#include <stdexcept>
#include <Windows.h>


#define command(format, ...) sendInstruction(format"\n", __VA_ARGS__);


class Gnuplot {
	public:
		Gnuplot(void);
		~Gnuplot(void);
		void sendInstruction(char* instruction, ...); // Not intendet to be used directly, instead use the "command"-macro

	private:
		HANDLE stdinReadPipe, stdinWritePipe;
		HANDLE stdoutReadPipe, stdoutWritePipe;
		HANDLE stderrReadPipe, stderrWritePipe;
		FILE* gnuplotInput;

		PROCESS_INFORMATION  processInformation;
};
