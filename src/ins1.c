#include "includes.h"

// by name
void LDA(uint8_t op)
{
	cpu.A = op;

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}

void LDX(uint8_t op)
{
	cpu.X = op;

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}

void LDY(uint8_t op)
{
	cpu.Y = op;

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}

void STA(uint16_t op)
{
	cpu.mem[op] = cpu.A;
}

void STX(uint16_t op)
{
	cpu.mem[op] = cpu.X;
}

void STY(uint16_t op)
{
	cpu.mem[op] = cpu.Y;
}

void TAX()
{
	cpu.X = cpu.A;

	if (!cpu.X)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.X & 0b10000000;
}

void TAY()
{
	cpu.Y = cpu.A;

	if (!cpu.Y)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.Y & 0b10000000;
}

void TSX()
{
	cpu.X = cpu.SP;

	if (!cpu.X)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.X & 0b10000000;
}

void TXA()
{
	cpu.A = cpu.X;

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}

void TXS()
{
	cpu.SP = cpu.X;
}

void TYA()
{
	cpu.A = cpu.Y;

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}

void PHA()
{
	cpu.mem[0x0100 + cpu.SP] = cpu.A;
	cpu.SP--;
}

void PHP()
{
	cpu.mem[0x100 + cpu.SP] = cpu.SR | 0b00110000;
	cpu.SP--;
}

void PLA()
{
	cpu.A = cpu.mem[0x0100 + cpu.SP];
	cpu.SP++;

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}

void PLP()
{
	cpu.SR = cpu.mem[0x0100 + cpu.SP];
	cpu.SP++;
}

void DEC(uint16_t op)
{
	cpu.mem[op]--;

	if (!cpu.mem[op])
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.mem[op] & 0b10000000;
}

void DEX()
{
	cpu.X--;

	if (!cpu.X)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.X & 0b10000000;
}

void DEY()
{
	cpu.X--;

	if (!cpu.Y)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.Y & 0b10000000;
}

void INC(uint16_t op)
{
	cpu.mem[op]++;

	if (!cpu.mem[op])
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.mem[op] & 0b10000000;
}

void INX()
{
	cpu.X++;

	if (!cpu.X)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.X & 0b10000000;
}

void INY()
{
	cpu.X++;

	if (!cpu.Y)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.Y & 0b10000000;
}

void ADC(uint8_t op)
{
	if (((int)cpu.A + op + (cpu.SR & 0b00000001)) > 0xff)
	{
		cpu.A = 0xff;
		cpu.SR |= 0b01000001;
	}
	else
	{
		cpu.A = (cpu.A + op + (cpu.SR & 0b00000001));
	}

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}

void SBC(uint8_t op)
{
	if ((cpu.A = cpu.A - op - !(cpu.SR & 0b00000001)) < 0)
	{
		cpu.SR |= 0b01000001;
	}

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}

void AND(uint8_t op)
{
	cpu.A &= op;

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}

void EOR(uint8_t op)
{
	cpu.A ^= op;

	if (!cpu.A)
	{
		cpu.SR |= 0b00000010;
	}

	cpu.SR |= cpu.A & 0b10000000;
}
