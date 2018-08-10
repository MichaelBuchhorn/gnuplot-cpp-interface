#include "Gnuplot.h"

Gnuplot::Gnuplot(void) {
	/* Create an anonymous pipe with default size. The handles are inheritable. */
	bSuccess = CreatePipe(&stdinReadPipe, &stdinWritePipe, &pipeSecurityAttributes, 0);
	bSuccess = CreatePipe(&stdoutReadPipe, &stdoutWritePipe, &pipeSecurityAttributes, 0);
	bSuccess = CreatePipe(&stderrReadPipe, &stderrWritePipe, &pipeSecurityAttributes, 0);

	/* Create gnuplot process with redirected STDIN, STDOUT, STDERR. */
	GetStartupInfo(&startupinfo);
	startupinfo.hStdInput = stdinReadPipe;
	//startupinfo.hStdOutput = stdoutWritePipe;
	//startupinfo.hStdError = stderrWritePipe;
	startupinfo.hStdOutput = stdout;
	startupinfo.hStdError = stdout;
	startupinfo.dwFlags = STARTF_USESTDHANDLES;
	if (CreateProcess("C:\\Program Files\\gnuplot\\bin\\gnuplot.exe", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &startupinfo, &processInformation)) {
		//printf("Created Gnuplot Process\n");
	}
	else {
		//TODO: Throw exception
	}


	//WriteFile(stdinWritePipe, outBuffer, sizeof(outBuffer), &dwWritten, NULL);
	//DWORD bytes_available;
	//int number_of_chars_to_check;
	//int j;
	//int quit_loop = FALSE;

	//do {
	//	PeekNamedPipe(gp_stdout_read, NULL, (DWORD)0, NULL, &bytes_available, NULL);
	//} while (bytes_available <= 0);
	//while (!quit_loop) {
	//	number_of_chars_to_check = (int)bytes_available;
	//	PeekNamedPipe(gp_stdout_read, inBuf, number_of_chars_to_check, NULL, &bytes_available, NULL);
	//	for (j = 0; j < number_of_chars_to_check; j++) {
	//		if (inBuf[j] == '\n') {
	//			quit_loop = TRUE;
	//			break;
	//		}
	//	}
	//}


	//double mouse_x, mouse_y;
	//DWORD bytes_read;
	//ReadFile(gp_stdout_read, NULL, (DWORD)j, &bytes_read, 0);
	//sscanf_s(inBuf, "%lf %lf\n", &mouse_x, &mouse_y);
	//printf("%lf, %lf\r\n", mouse_x, mouse_y);
}

Gnuplot::~Gnuplot(void) {
	sendInstruction("\nexit gnuplot\n\0");
	WaitForSingleObject(processInformation.hProcess, INFINITE);
	CloseHandle(processInformation.hThread);
	CloseHandle(stdinReadPipe);
	CloseHandle(stdoutWritePipe);
	CloseHandle(stderrWritePipe);
	CloseHandle(processInformation.hProcess);
}

void Gnuplot::sendInstruction(char* instruction) {
	strncpy_s(outBuffer, instruction, sizeof(outBuffer));
	WriteFile(stdinWritePipe, outBuffer, strlen(instruction), &dwWritten, NULL);
}

void Gnuplot::waitTillProcessed(void) {
	sendInstruction("print 'z'\n\0");
	//ReadFile(stdoutReadPipe, inBuffer, 1, &dwRead, NULL);
	if (inBuffer[0] == 'z') {
		printf("passt");
	}
}