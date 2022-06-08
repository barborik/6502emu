#ifndef __CPU
#define __CPU

void cpu_init();
void cpu_exec(int8_t opcode);

enum // addressing modes
{
    AM_ACC,  // OPC A
    AM_ABS,  // OPC $LLHH
    AM_ABSX, // OPC $LLHH, X
    AM_ABSY, // OPC $LLHH, Y
    AM_IMMD, // OPC #$BB
    AM_IMPL, // OPC
    AM_INDR, // OPC ($LLHH)
    AM_XIND, // OPC ($LL, X)
    AM_INDY, // OPC ($LL), Y
    AM_REL,  // OPC $BB
    AM_ZPG,  // OPC $LL
    AM_ZPGX, // OPC $LL, X
    AM_ZPGY, // OPC $LL, Y
};

typedef struct
{
    int8_t bytes;
    int8_t opcode;
    int8_t addrmode;
    void (*exec)(void);
} ins_t;

static const ins_t inset[] = {
    {
        .bytes = 1,
        .opcode = 0x00,
        .addrmode = AM_IMPL,
        .exec = ix00,
    },
};

#endif