#include "Gnuplot.h"


Gnuplot::Gnuplot(void) {
	/* Create an anonymous pipe with default size. The handles are inheritable. */
	SECURITY_ATTRIBUTES pipeSecurityAttributes = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
	CreatePipe(&stdinReadPipe, &stdinWritePipe, &pipeSecurityAttributes, 0);
	CreatePipe(&stdoutReadPipe, &stdoutWritePipe, &pipeSecurityAttributes, 0);
	CreatePipe(&stderrReadPipe, &stderrWritePipe, &pipeSecurityAttributes, 0);

	/* Setup process startup information */
	STARTUPINFO startupinfo;
	GetStartupInfo(&startupinfo);
	startupinfo.hStdInput = stdinReadPipe;
	//startupinfo.hStdOutput = stdoutWritePipe;
	//startupinfo.hStdError = stderrWritePipe;
	startupinfo.hStdOutput = stdout;
	startupinfo.hStdError = stdout;
	startupinfo.dwFlags = STARTF_USESTDHANDLES;

	/* Create a gnuplot process */
	if (!CreateProcess("gnuplot", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &startupinfo, &processInformation)) {
		if (!CreateProcess("C:\\Program Files\\gnuplot\\bin\\gnuplot.exe", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &startupinfo, &processInformation)) {
			throw std::runtime_error("Couldn't find the gnuplot executable.");
		}
	}
}


Gnuplot::~Gnuplot(void) {
	sendInstruction("\nexit gnuplot\n\0");
	
	DWORD timeout_ms = 10000;
	WaitForSingleObject(processInformation.hProcess, timeout_ms);

	CloseHandle(processInformation.hThread);
	CloseHandle(stdinReadPipe);
	CloseHandle(stdoutWritePipe);
	CloseHandle(stderrWritePipe);
	CloseHandle(processInformation.hProcess);
}


void Gnuplot::sendInstruction(char* instruction) {
	DWORD bytesWritten;
	WriteFile(stdinWritePipe, instruction, (DWORD)strlen(instruction), &bytesWritten, NULL);
}
