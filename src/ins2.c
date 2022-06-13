#include "includes.h"

void ORA(int8_t op)
{
	cpu.A |= op;

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}

void ASL(int8_t op)
{
	if (op > 0b100000000)
	{
		cpu.SR |= 0b00000001;
	}

	op << 1;

	if (!op)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= op & 0b10000000;
}

void LSR(int8_t op)
{
	if (op > 0b100000000)
	{
		cpu.SR |= 0b00000001;
	}

	op >> 1;

	if (!op)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= 0b10000000;
}

void ROL(int8_t op)
{
	ASL(op);
}

void ROR(int8_t op)
{
	LSR(op);
}

void CLC()
{
	cpu.SR &= 0b11111110;
}

void CLD()
{
	cpu.SR &= 0b11110111;
}

void CLI()
{
	cpu.SR &= 0b11111011;
}

void CLV()
{
	cpu.SR &= 0b10111111;
}

void SEC()
{
	cpu.SR |= 0b00000001;
}

void SED()
{
	cpu.SR |= 0b00001000;
}

void SEI()
{
	cpu.SR |= 0b00000100;
}

void CMP(int8_t op)
{
	if (cpu.A < op)
	{
		cpu.SR &= 0b11111100;
	}

	if (cpu.A = op)
	{
		cpu.SR &= 0b01111111;
		cpu.SR |= 0b00000011;
	}

	if (cpu.A > op)
	{
		cpu.SR &= 0b11111101;
		cpu.SR |= 0b00000001;
	}
}

void CPX(int8_t op)
{
	if (cpu.X < op)
	{
		cpu.SR &= 0b11111100;
	}

	if (cpu.X = op)
	{
		cpu.SR &= 0b01111111;
		cpu.SR |= 0b00000011;
	}

	if (cpu.X > op)
	{
		cpu.SR &= 0b11111101;
		cpu.SR |= 0b00000001;
	}
}

void CPY(int8_t op)
{
	if (cpu.Y < op)
	{
		cpu.SR &= 0b11111100;
	}

	if (cpu.Y = op)
	{
		cpu.SR &= 0b01111111;
		cpu.SR |= 0b00000011;
	}

	if (cpu.Y > op)
	{
		cpu.SR &= 0b11111101;
		cpu.SR |= 0b00000001;
	}
}

void BCC(int8_t op)
{
	if (!(cpu.SR & 0b00000001))
	{
		cpu.PC += op;
	}
}

void BCS(int8_t op)
{
	if (cpu.SR & 0b00000001)
	{
		cpu.PC += op;
	}
}

void BEQ(int8_t op)
{
	if (cpu.SR & 0b00000010)
	{
		cpu.PC += op;
	}
}

void BMI(int8_t op)
{
	if (cpu.SR & 0b10000000)
	{
		cpu.PC += op;
	}
}

void BNE(int8_t op)
{
	if (!(cpu.SR & 0b00000010))
	{
		cpu.PC += op;
	}
}

void BPL(int8_t op)
{
	if (!(cpu.SR & 0b10000000))
	{
		cpu.PC += op;
	}
}

void BVC(int8_t op)
{
	if (!(cpu.SR & 0b01000000))
	{
		cpu.PC += op;
	}
}

void BVS(int8_t op)
{
	if (cpu.SR & 0b10000000)
	{
		cpu.PC += op;
	}
}

void JMP(int16_t op)
{
	cpu.PC = op;
}

void JSR(int16_t op)
{
	cpu.SP -= 2;
	cpu.mem[0x0100 + cpu.SP] = cpu.PC;
	cpu.PC = op;
}

void RTS()
{
	cpu.SP += 2;
	cpu.PC = cpu.mem[0x0100 + cpu.SP];
}

void BRK()
{
	cpu.SP -= 2;
	cpu.mem[0x0100 + cpu.SP] = cpu.PC + 2;
	cpu.SP--;
	cpu.mem[0x0100 + cpu.SP] = cpu.SR | 0b00010000;
	exit(0);
}

void RTI()
{
	cpu.SP++;
	cpu.SR = cpu.mem[0x0100 + cpu.SP] | 0b00000100;
	cpu.SP += 2;
	cpu.PC = cpu.mem[0x0100 + cpu.SP];
}

void BIT(int8_t op)
{
	cpu.A &= op;

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b11000000;
}

void NOP()
{
}