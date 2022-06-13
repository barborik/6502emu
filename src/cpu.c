#include "includes.h"

void cpu_init()
{
	cpu.mem = malloc(64 * 1024); // 64 KiB
	cpu.A = 0;
	cpu.X = 0;
	cpu.Y = 0;
	cpu.SP = 0xff;
	cpu.SR = 0b00100000;
	cpu.PC = ldaddr;
}

void cpu_load()
{
	FILE* file = fopen(__argv[__argc - 1], "rb");

	if (file == NULL)
	{
		printf("ERROR: fopen() failed\n");
		exit(-1);
	}

	int c;
	for (int16_t i = ldaddr; (c = getc(file)) != EOF; i++)
	{
		cpu.mem[i] = (int8_t)c;
	}
}

// opcode and addressing mode reference:
// https://masswerk.at/6502/6502_instruction_set.html
void cpu_exec()
{
	while (1)
	{
		ins_t ins = inset[cpu.mem[cpu.PC]];
		ins.exec();

		switch (ins.addrmode)
		{
		case AM_ACCU:
			cpu.PC += 1;
			break;
		case AM_ABS:
			cpu.PC += 3;
			break;
		case AM_ABSX:
			cpu.PC += 3;
			break;
		case AM_ABSY:
			cpu.PC += 3;
			break;
		case AM_IMMD:
			cpu.PC += 2;
			break;
		case AM_IMPL:
			cpu.PC += 1;
			break;
		case AM_INDR:
			cpu.PC += 3;
			break;
		case AM_INDX:
			cpu.PC += 3;
			break;
		case AM_INDY:
			cpu.PC += 3;
			break;
		case AM_REL:
			cpu.PC += 2;
			break;
		case AM_ZPG:
			cpu.PC += 2;
			break;
		case AM_ZPGX:
			cpu.PC += 2;
			break;
		case AM_ZPGY:
			cpu.PC += 2;
			break;
		}
	}
}
