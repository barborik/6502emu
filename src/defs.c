#include "includes.h"

int16_t ldaddr = 0x0400;

char* help_ = "usage: 6502emu [flags] <program>\n";

void flags()
{
	if (__argc == 1)
	{
		printf(help_);
		exit(-1);
	}

	int fcount = 0;
	for (int i = 1; i < __argc; i++)
	{
		if (__argv[i][0] == '-')
		{
			fcount++;
		}
	}

	if (__argc != fcount + 2) // default argument + program path
	{
		printf(help_);
		exit(-1);
	}

	for (int i = 0; i < fcount; i++)
	{
		if (__argv[i + 1][0] != '-')
		{
			printf(help_);
			exit(-1);
		}

		if (!strcmp(__argv[i + 1], "--help"))
		{
			printf(help_);
			exit(0);
		}
	}
}