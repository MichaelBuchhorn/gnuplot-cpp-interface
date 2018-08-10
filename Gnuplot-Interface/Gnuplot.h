#pragma once


#include <iostream>
#include <stdexcept>
#include <Windows.h>


class Gnuplot {
	public:
		Gnuplot(void);
		~Gnuplot(void);
		void sendInstruction(char* instruction);

	private:
		HANDLE stdinReadPipe, stdinWritePipe;
		HANDLE stdoutReadPipe, stdoutWritePipe;
		HANDLE stderrReadPipe, stderrWritePipe;

		PROCESS_INFORMATION  processInformation;
};
