#ifndef __CPU
#define __CPU

typedef struct
{
	// general purpose registers
	uint8_t A; // accumulator
	uint8_t X; // X register
	uint8_t Y; // Y register
	// special registers
	uint8_t SP; // stack pointer
	uint8_t SR; // status register (flags)
	// bit    7         |   6        | 5       |  4      |  3        |  2          |  1     |  0
	// flag  (N)egative | o(V)erflow | ignored | (B)reak | (D)ecimal | (I)nterrupt | (Z)ero | (C)arry
	uint16_t PC; // program counter
	// system memory
	uint8_t* mem;
} cpu_t;

extern cpu_t cpu;

void cpu_init();
void cpu_load();
void cpu_exec();

enum // addressing modes
{
	AM_ACCU, // OPC A
	AM_ABS,  // OPC $LLHH
	AM_ABSX, // OPC $LLHH, X
	AM_ABSY, // OPC $LLHH, Y
	AM_IMMD, // OPC #$BB
	AM_IMPL, // OPC
	AM_INDR, // OPC ($LLHH)
	AM_INDX, // OPC ($LL, X)
	AM_INDY, // OPC ($LL), Y
	AM_REL,  // OPC $BB
	AM_ZPG,  // OPC $LL
	AM_ZPGX, // OPC $LL, X
	AM_ZPGY, // OPC $LL, Y
};

typedef struct
{
	int8_t addrmode;
	void (*exec)(void);
} ins_t;

extern const ins_t inset[];

#endif