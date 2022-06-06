#include "includes.h"

struct
{
	// general purpose registers
	int8_t A; // accumulator
	int8_t X; // X register
	int8_t Y; // Y register
	// special registers
	int8_t SP; // stack pointer
	int8_t SR; // status register (flags)
	// bit    7         |   6        | 5       |  4      |  3        |  2          |  1     |  0
	// flag  (N)egative | o(V)erflow | ignored | (B)reak | (D)ecimal | (I)nterrupt | (Z)ero | (C)arry
	int16_t PC; // program counter
	// system memory
	void *mem;
} cpu;

void cpu_init()
{
	cpu.mem = malloc(64 * 1024); // 64 KiB
	cpu.A = 0;
	cpu.X = 0;
	cpu.Y = 0;
	cpu.SP = 0xff;
	cpu.SR = 0b00100000;
}

// opcode and addressing mode reference:
// https://masswerk.at/6502/6502_instruction_set.html
void cpu_exec(int8_t opcode)
{
	int8_t hi = opcode & 0xf0;
	int8_t lo = opcode & 0x0f;
}
