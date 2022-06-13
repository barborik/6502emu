#ifndef __CPU
#define __CPU

static struct
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
	int8_t* mem;
} cpu;

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

extern ins_t inset[];

#endif