#pragma once


#include <Windows.h>
#include <iostream>
#include <string>


class Gnuplot {
	private:
		DWORD i;
		HANDLE stdinReadPipe, stdinWritePipe;
		HANDLE stdoutReadPipe, stdoutWritePipe;
		HANDLE stderrReadPipe, stderrWritePipe;

		SECURITY_ATTRIBUTES pipeSecurityAttributes = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
		char outBuffer[128] = "plot sin(x)'\n";
		char inBuffer[128];
		DWORD dwWritten, dwRead;
		BOOL  bSuccess = FALSE;
		PROCESS_INFORMATION  processInformation;
		STARTUPINFO startupinfo;

	public:
		Gnuplot(void);
		~Gnuplot(void);
		void sendInstruction(char* instruction);
		void waitTillProcessed(void);
};
