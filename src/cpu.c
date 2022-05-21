#include "cpu.h"
#include <stdlib.h>
#include <stdint.h>

struct
{
	// general purpose registers
	int8_t A; // accumulator
	int8_t X; // X register
	int8_t Y; // Y register
	// special registers
	int8_t SP;  // stack pointer
	int8_t SR;  // status register (flags)
	int16_t PC; // program counter
	// system memory
	void* mem;
} cpu;

void cpu_init()
{
	cpu.A = 0;
	cpu.X = 0;
	cpu.mem = malloc(64 * 1024); // 64 KiB
}