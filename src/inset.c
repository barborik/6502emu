#include "includes.h"

// illegal instructions included for ease of searching (index = opcode)
const ins_t inset[] = {
	// high 0
	{
		.addrmode = AM_IMPL,
		.exec = ix00,
	},
	{
		.addrmode = AM_INDX,
		.exec = ix01,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix05,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix06,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix08,
	},
	{
		.addrmode = AM_IMMD,
		.exec = ix09,
	},
	{
		.addrmode = AM_ACCU,
		.exec = ix0a,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix0d,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix0e,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high 1
	{
		.addrmode = AM_REL,
		.exec = ix10,
	},
	{
		.addrmode = AM_INDY,
		.exec = ix11,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ix15,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ix16,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix18,
	},
	{
		.addrmode = AM_ABSY,
		.exec = ix19,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ix1d,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ix1e,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high 2
	{
		.addrmode = AM_ABS,
		.exec = ix20,
	},
	{
		.addrmode = AM_INDX,
		.exec = ix21,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix24,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix25,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix26,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix28,
	},
	{
		.addrmode = AM_IMMD,
		.exec = ix29,
	},
	{
		.addrmode = AM_ACCU,
		.exec = ix2a,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix2c,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix2d,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix2e,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high 3
	{
		.addrmode = AM_REL,
		.exec = ix30,
	},
	{
		.addrmode = AM_INDY,
		.exec = ix31,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ix35,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ix36,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix38,
	},
	{
		.addrmode = AM_ABSY,
		.exec = ix39,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ix3d,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ix3e,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high 4
	{
		.addrmode = AM_IMPL,
		.exec = ix40,
	},
	{
		.addrmode = AM_INDX,
		.exec = ix41,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix45,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix46,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix48,
	},
	{
		.addrmode = AM_IMMD,
		.exec = ix49,
	},
	{
		.addrmode = AM_ACCU,
		.exec = ix4a,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix4c,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix4d,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix4e,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high 5
	{
		.addrmode = AM_REL,
		.exec = ix50,
	},
	{
		.addrmode = AM_INDY,
		.exec = ix51,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ix55,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ix56,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix58,
	},
	{
		.addrmode = AM_ABSY,
		.exec = ix59,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ix5d,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ix5e,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high 6
	{
		.addrmode = AM_IMPL,
		.exec = ix60,
	},
	{
		.addrmode = AM_INDX,
		.exec = ix61,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix65,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix66,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix68,
	},
	{
		.addrmode = AM_IMMD,
		.exec = ix69,
	},
	{
		.addrmode = AM_ACCU,
		.exec = ix6a,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_INDR,
		.exec = ix6c,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix6d,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix6e,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high 7
	{
		.addrmode = AM_REL,
		.exec = ix70,
	},
	{
		.addrmode = AM_INDY,
		.exec = ix71,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ix75,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ix76,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix78,
	},
	{
		.addrmode = AM_ABSY,
		.exec = ix79,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ix7d,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ix7e,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high 8
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_INDR,
		.exec = ix81,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix84,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix85,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ix86,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix88,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix8a,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix8c,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix8d,
	},
	{
		.addrmode = AM_ABS,
		.exec = ix8e,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high 9
	{
		.addrmode = AM_REL,
		.exec = ix90,
	},
	{
		.addrmode = AM_INDY,
		.exec = ix91,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ix94,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ix95,
	},
	{
		.addrmode = AM_ZPGY,
		.exec = ix96,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix98,
	},
	{
		.addrmode = AM_ABSY,
		.exec = ix99,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ix9a,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ix9d,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high a
	{
		.addrmode = AM_IMMD,
		.exec = ixa0,
	},
	{
		.addrmode = AM_INDX,
		.exec = ixa1,
	},
	{
		.addrmode = AM_IMMD,
		.exec = ixa2,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ixa4,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ixa5,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ixa6,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ixa8,
	},
	{
		.addrmode = AM_IMMD,
		.exec = ixa9,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ixaa,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABS,
		.exec = ixac,
	},
	{
		.addrmode = AM_ABS,
		.exec = ixad,
	},
	{
		.addrmode = AM_ABS,
		.exec = ixae,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high b
	{
		.addrmode = AM_REL,
		.exec = ixb0,
	},
	{
		.addrmode = AM_INDY,
		.exec = ixb1,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ixb4,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ixb5,
	},
	{
		.addrmode = AM_ZPGY,
		.exec = ixb6,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ixb8,
	},
	{
		.addrmode = AM_ABSY,
		.exec = ixb9,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ixba,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ixbc,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ixbd,
	},
	{
		.addrmode = AM_ABSY,
		.exec = ixbe,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high c
	{
		.addrmode = AM_IMMD,
		.exec = ixc0,
	},
	{
		.addrmode = AM_INDX,
		.exec = ixc1,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ixc4,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ixc5,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ixc6,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ixc8,
	},
	{
		.addrmode = AM_IMMD,
		.exec = ixc9,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ixca,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABS,
		.exec = ixcc,
	},
	{
		.addrmode = AM_ABS,
		.exec = ixcd,
	},
	{
		.addrmode = AM_ABS,
		.exec = ixce,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high d
	{
		.addrmode = AM_REL,
		.exec = ixd0,
	},
	{
		.addrmode = AM_INDY,
		.exec = ixd1,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ixd5,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ixd6,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ixd8,
	},
	{
		.addrmode = AM_ABSY,
		.exec = ixd9,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ixdd,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ixde,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high e
	{
		.addrmode = AM_IMMD,
		.exec = ixe0,
	},
	{
		.addrmode = AM_INDX,
		.exec = ixe1,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ixe4,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ixe5,
	},
	{
		.addrmode = AM_ZPG,
		.exec = ixe6,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ixe8,
	},
	{
		.addrmode = AM_IMMD,
		.exec = ixe9,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ixea,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABS,
		.exec = ixec,
	},
	{
		.addrmode = AM_ABS,
		.exec = ixed,
	},
	{
		.addrmode = AM_ABS,
		.exec = ixee,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},

	// high f
	{
		.addrmode = AM_REL,
		.exec = ixf0,
	},
	{
		.addrmode = AM_INDY,
		.exec = ixf1,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ixf5,
	},
	{
		.addrmode = AM_ZPGX,
		.exec = ixf6,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_IMPL,
		.exec = ixf8,
	},
	{
		.addrmode = AM_ABSY,
		.exec = ixf9,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ixfd,
	},
	{
		.addrmode = AM_ABSX,
		.exec = ixfe,
	},
	{
		.addrmode = NULL,
		.exec = NULL,
	},
};