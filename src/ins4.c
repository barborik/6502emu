#include "includes.h"

// high 8
void ix81()
{
	STA(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ix84()
{
	STY(cpu.mem[cpu.PC + 1]);
}
void ix85()
{
	STA(cpu.mem[cpu.PC + 1]);
}
void ix86()
{
	STX(cpu.mem[cpu.PC + 1]);
}
void ix88()
{
	DEY();
}
void ix8a()
{
	TXA();
}
void ix8c()
{
	STY(((int16_t*)cpu.mem)[cpu.PC + 1]);
}
void ix8d()
{
	STA(((int16_t*)cpu.mem)[cpu.PC + 1]);
}
void ix8e()
{
	STX(((int16_t*)cpu.mem)[cpu.PC + 1]);
}

// high 9
void ix90()
{
	BCC(cpu.mem[cpu.PC + 1]);
}
void ix91()
{
	STA(cpu.mem[cpu.mem[cpu.PC + 1]] + cpu.Y);
}
void ix94()
{
	STY(cpu.mem[cpu.PC + 1] + cpu.X);
}
void ix95()
{
	STA(cpu.mem[cpu.PC + 1] + cpu.X);
}
void ix96()
{
	STX(cpu.mem[cpu.PC + 1] + cpu.Y);
}
void ix98()
{
	TYA();
}
void ix99()
{
	STA(((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.Y);
}
void ix9a()
{
	TXS();
}
void ix9d()
{
	STA(((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X);
}

// high A
void ixa0()
{
	LDY(cpu.mem[cpu.PC + 1]);
}
void ixa1()
{
	LDA(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ixa2()
{
	LDX(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ixa4()
{
	LDY(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ixa5()
{
	LDA(cpu.mem[cpu.PC + 1]);
}
void ixa6()
{
	LDX(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ixa8()
{
	TAY();
}
void ixa9()
{
	LDA(cpu.mem[cpu.PC + 1]);
}
void ixaa()
{
	TAX();
}
void ixac()
{
	LDY(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ixad()
{
	LDA(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ixae()
{
	LDX(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}

// high B
void ixb0()
{
	BCS(cpu.mem[cpu.PC + 1]);
}
void ixb1()
{
	LDA(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.Y]);
}
void ixb4()
{
	LDY(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ixb5()
{
	LDA(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ixb6()
{
	LDX(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.Y]);
}
void ixb8()
{
	CLV();
}
void ixb9()
{
	LDA(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.Y]);
}
void ixba()
{
	TSX();
}
void ixbc()
{
	LDY(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}
void ixbd()
{
	LDA(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}
void ixbe()
{
	LDX(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.Y]);
}

// high C
void ixc0()
{
	CPY(cpu.mem[cpu.PC + 1]);
}
void ixc1()
{
	CMP(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ixc4()
{
	CPY(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ixc5()
{
	CMP(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ixc6()
{
	DEC(cpu.mem[cpu.PC + 1]);
}
void ixc8()
{
	INY();
}
void ixc9()
{
	CMP(cpu.mem[cpu.PC + 1]);
}
void ixca()
{
	DEX();
}
void ixcc()
{
	CPY(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ixcd()
{
	CMP(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ixce()
{
	DEC(((int16_t*)cpu.mem)[cpu.PC + 1]);
}

// high D
void ixd0()
{
	BNE(cpu.mem[cpu.PC + 1]);
}
void ixd1()
{
	CMP(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.Y]);
}
void ixd5()
{
	CMP(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ixd6()
{
	DEC(cpu.mem[cpu.PC + 1] + cpu.X);
}
void ixd8()
{
	CLD();
}
void ixd9()
{
	CMP(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.Y]);
}
void ixdd()
{
	CMP(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}
void ixde()
{
	DEC(((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X);
}

// high E
void ixe0()
{
	CPX(cpu.mem[cpu.PC + 1]);
}
void ixe1()
{
	SBC(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ixe4()
{
	CPX(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ixe5()
{
	SBC(cpu.mem[cpu.mem[cpu.PC + 1]]);
}
void ixe6()
{
	INC(cpu.mem[cpu.PC + 1]);
}
void ixe8()
{
	INX();
}
void ixe9()
{
	SBC(cpu.mem[cpu.PC + 1]);
}
void ixea()
{
	NOP();
}
void ixec()
{
	CPX(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ixed()
{
	SBC(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1]]);
}
void ixee()
{
	INC(((int16_t*)cpu.mem)[cpu.PC + 1]);
}

// high F
void ixf0()
{
	BEQ(cpu.mem[cpu.PC + 1]);
}
void ixf1()
{
	SBC(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.Y]);
}
void ixf5()
{
	SBC(cpu.mem[cpu.mem[cpu.PC + 1] + cpu.X]);
}
void ixf6()
{
	INC(cpu.mem[cpu.PC + 1] + cpu.X);
}
void ixf8()
{
	SED();
}
void ixf9()
{
	SBC(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.Y]);
}
void ixfd()
{
	SBC(cpu.mem[((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X]);
}
void ixfe()
{
	INC(((int16_t*)cpu.mem)[cpu.PC + 1] + cpu.X);
}
