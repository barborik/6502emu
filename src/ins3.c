#include "includes.h"

// high 0
void ix00()
{
	BRK();
}
void ix01()
{
	ORA(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix05()
{
	ORA(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ix06()
{
	ASL(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ix08()
{
	PHP();
}
void ix09()
{
	ORA(cpu.mem[cpu.PC + 1]);
}
void ix0a()
{
	ASL(cpu.A);
}
void ix0d()
{
	ORA(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ix0e()
{
	ASL(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}

// high 1
void ix10()
{
	BPL(cpu.mem[cpu.PC + 1]);
}
void ix11()
{
	ORA(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.Y]);
}
void ix15()
{
	ORA(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix16()
{
	ASL(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix18()
{
	CLC();
}
void ix19()
{
	ORA(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.Y]);
}
void ix1d()
{
	ORA(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix1e()
{
	ASL(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}

// high 2
void ix20()
{
	JSR(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ix21()
{
	AND(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix24()
{
	BIT(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ix25()
{
	AND(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ix26()
{
	ROL(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ix28()
{
	PLP();
}
void ix29()
{
	AND(cpu.mem[cpu.PC + 1]);
}
void ix2a()
{
	ROL(cpu.A);
}
void ix2c()
{
	BIT(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ix2d()
{
	AND(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ix2e()
{
	ROL(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}

// high 3
void ix30()
{
	BMI(cpu.mem[cpu.PC + 1]);
}
void ix31()
{
	AND(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.Y]);
}
void ix35()
{
	AND(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix36()
{
	ROL(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix38()
{
	SEC();
}
void ix39()
{
	AND(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.Y]);
}
void ix3d()
{
	AND(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}
void ix3e()
{
	ROL(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}

// high 4
void ix40()
{
	RTI();
}
void ix41()
{
	EOR(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix45()
{
	EOR(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ix46()
{
	LSR(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ix48()
{
	PHA();
}
void ix49()
{
	EOR(cpu.mem[cpu.PC + 1]);
}
void ix4a()
{
	LSR(cpu.A);
}
void ix4c()
{
	JMP(*(uint16_t*)(&cpu.mem[cpu.PC + 1]));
}
void ix4d()
{
	EOR(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ix4e()
{
	LSR(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}

// high 5
void ix50()
{
	BVC(cpu.mem[cpu.PC + 1]);
}
void ix51()
{
	EOR(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.Y]);
}
void ix55()
{
	EOR(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix56()
{
	LSR(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix58()
{
	CLI();
}
void ix59()
{
	EOR(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.Y]);
}
void ix5d()
{
	EOR(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}
void ix5e()
{
	LSR(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}

// high 6
void ix60()
{
	RTS();
}
void ix61()
{
	ADC(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix65()
{
	ADC(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ix66()
{
	ROR(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ix68()
{
	PLA();
}
void ix69()
{
	ADC(cpu.mem[cpu.PC + 1]);
}
void ix6a()
{
	ROR(cpu.A);
}
void ix6c()
{
	JMP(*(uint16_t*)(cpu.mem[*(uint16_t*)(&cpu.mem[cpu.PC + 1])]));
}
void ix6d()
{
	ADC(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ix6e()
{
	ROR(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}

// high 7
void ix70()
{
	BVS(cpu.mem[cpu.PC + 1]);
}
void ix71()
{
	ADC(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.Y]);
}
void ix75()
{
	ADC(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix76()
{
	ROR(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix78()
{
	SEI();
}
void ix79()
{
	ADC(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.Y]);
}
void ix7d()
{
	ADC(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}
void ix7e()
{
	ROR(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}
