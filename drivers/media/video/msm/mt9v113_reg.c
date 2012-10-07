/*
 * HTC Corporation Proprietary Rights Acknowledgment
 *
 * Copyright (C) 2008 HTC Corporation
 *
 * All Rights Reserved.
 *
 * The information contained in this work is the exclusive property
 * of HTC Corporation("HTC").  Only the user who is legally authorized
 * by HTC ("Authorized User") has right to employ this work within the
 * scope of this statement.  Nevertheless, the Authorized User shall not
 * use this work for any purpose other than the purpose agreed by HTC.
 * Any and all addition or modification to this work shall be  unconditionally
 * granted back to HTC and such addition or modification shall be solely
 * owned by HTC.  No right is granted under this statement, including but not
 * limited to, distribution, reproduction, and transmission, except as
 * otherwise provided in this statement.  Any other usage of this work shall
 *  be subject to the further written consent of HTC.
 */



#include "mt9v113.h"

#if 0
static const struct mt9v113_i2c_reg_conf const pll_setup_tbl[] = {
	{0x3E, 0xD0, WORD_LEN, 5},
	{0x3E, 0xD0, WORD_LEN, 5},
	{0x12, 0x80, WORD_LEN, 5}
};
#endif

/* WB : AUTO mode*/
static struct mt9v113_i2c_reg_conf wb_auto[] = {
	/*{0x098C, 0xA11F, WORD_LEN, 0},
	{0x0990, 0x0001, WORD_LEN, 0},
	{0x098C, 0xA103, WORD_LEN, 0},
	{0x0990, 0x0005, WORD_LEN, 0}, */ /*move to mt9v113.c*/
	{0x098C, 0x2306, WORD_LEN, 0},
	{0x0990, 0x03C0, WORD_LEN, 0},
	{0x098C, 0x2308, WORD_LEN, 0},
	{0x0990, 0xFD7C, WORD_LEN, 0},
	{0x098C, 0x230A, WORD_LEN, 0},
	{0x0990, 0xFFF7, WORD_LEN, 0},
	{0x098C, 0x230C, WORD_LEN, 0},
	{0x0990, 0xFF25, WORD_LEN, 0},
	{0x098C, 0x230E, WORD_LEN, 0},
	{0x0990, 0x0384, WORD_LEN, 0},
	{0x098C, 0x2310, WORD_LEN, 0},
	{0x0990, 0xFFD6, WORD_LEN, 0},
	{0x098C, 0x2312, WORD_LEN, 0},
	{0x0990, 0xFED2, WORD_LEN, 0},
	{0x098C, 0x2314, WORD_LEN, 0},
	{0x0990, 0xFCB2, WORD_LEN, 0},
	{0x098C, 0x2316, WORD_LEN, 0},
	{0x0990, 0x068E, WORD_LEN, 0},
	{0x098C, 0x2318, WORD_LEN, 0},
	{0x0990, 0x001B, WORD_LEN, 0},
	{0x098C, 0x231A, WORD_LEN, 0},
	{0x0990, 0x0039, WORD_LEN, 0},
	{0x098C, 0x231C, WORD_LEN, 0},
	{0x0990, 0xFF65, WORD_LEN, 0},
	{0x098C, 0x231E, WORD_LEN, 0},
	{0x0990, 0x0052, WORD_LEN, 0},
	{0x098C, 0x2320, WORD_LEN, 0},
	{0x0990, 0x0012, WORD_LEN, 0},
	{0x098C, 0x2322, WORD_LEN, 0},
	{0x0990, 0x0007, WORD_LEN, 0},
	{0x098C, 0x2324, WORD_LEN, 0},
	{0x0990, 0xFFCF, WORD_LEN, 0},
	{0x098C, 0x2326, WORD_LEN, 0},
	{0x0990, 0x0037, WORD_LEN, 0},
	{0x098C, 0x2328, WORD_LEN, 0},
	{0x0990, 0x00DB, WORD_LEN, 0},
	{0x098C, 0x232A, WORD_LEN, 0},
	{0x0990, 0x01C8, WORD_LEN, 0},
	{0x098C, 0x232C, WORD_LEN, 0},
	{0x0990, 0xFC9F, WORD_LEN, 0},
	{0x098C, 0x232E, WORD_LEN, 0},
	{0x0990, 0x0010, WORD_LEN, 0},
	{0x098C, 0x2330, WORD_LEN, 0},
	{0x0990, 0xFFF3, WORD_LEN, 0}
};

/*WB : Fluorescent mode*/
static struct mt9v113_i2c_reg_conf wb_fluorescent[] = {
	/* {0x098C, 0xA115, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xA11F, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xA103, WORD_LEN, 0},
	{0x0990, 0x0005, WORD_LEN, 0}, */ /*move to mt9v113.c*/
	{0x098C, 0xA353, WORD_LEN, 0},
	{0x0990, 0x0043, WORD_LEN, 0},
	{0x098C, 0xA34E, WORD_LEN, 0},
	{0x0990, 0x00A0, WORD_LEN, 0},
	{0x098C, 0xA34F, WORD_LEN, 0},
	{0x0990, 0x0086, WORD_LEN, 0},
	{0x098C, 0xA350, WORD_LEN, 0},
	{0x0990, 0x008A, WORD_LEN, 0}
};

/*WB : Incandescent mode */
static struct mt9v113_i2c_reg_conf wb_incandescent[] = {
	/* {0x098C, 0xA115, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xA11F, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xA103, WORD_LEN, 0},
	{0x0990, 0x0005, WORD_LEN, 0}, */ /*move to mt9v113.c*/
	{0x098C, 0xA353, WORD_LEN, 0},
	{0x0990, 0x000B, WORD_LEN, 0},
	{0x098C, 0xA34E, WORD_LEN, 0},
	{0x0990, 0x0090, WORD_LEN, 0},
	{0x098C, 0xA34F, WORD_LEN, 0},
	{0x0990, 0x0085, WORD_LEN, 0},
	{0x098C, 0xA350, WORD_LEN, 0},
	{0x0990, 0x00A0, WORD_LEN, 0}
};

/*WB : Daylight mode*/
static struct mt9v113_i2c_reg_conf wb_daylight[] = {
	/* {0x098C, 0xA115, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xA11F, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xA103, WORD_LEN, 0},
	{0x0990, 0x0005, WORD_LEN, 0}, */ /*move to mt9v113.c*/
	{0x098C, 0xA353, WORD_LEN, 0},
	{0x0990, 0x007F, WORD_LEN, 0},
	{0x098C, 0xA34E, WORD_LEN, 0},
	{0x0990, 0x00A2, WORD_LEN, 0},
	{0x098C, 0xA34F, WORD_LEN, 0},
	{0x0990, 0x0085, WORD_LEN, 0},
	{0x098C, 0xA350, WORD_LEN, 0},
	{0x0990, 0x0080, WORD_LEN, 0}
};


/* Contract 0 */
static struct mt9v113_i2c_reg_conf contract_setup_tb0[] = {
	{0x098C, 0xAB3C, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xAB3D, WORD_LEN, 0},
	{0x0990, 0x0023, WORD_LEN, 0},
	{0x098C, 0xAB3E, WORD_LEN, 0},
	{0x0990, 0x0045, WORD_LEN, 0},
	{0x098C, 0xAB3F, WORD_LEN, 0},
	{0x0990, 0x0064, WORD_LEN, 0},
	{0x098C, 0xAB40, WORD_LEN, 0},
	{0x0990, 0x0080, WORD_LEN, 0},
	{0x098C, 0xAB41, WORD_LEN, 0},
	{0x0990, 0x0099, WORD_LEN, 0},
	{0x098C, 0xAB42, WORD_LEN, 0},
	{0x0990, 0x00B0, WORD_LEN, 0},
	{0x098C, 0xAB43, WORD_LEN, 0},
	{0x0990, 0x00C1, WORD_LEN, 0},
	{0x098C, 0xAB44, WORD_LEN, 0},
	{0x0990, 0x00CF, WORD_LEN, 0},
	{0x098C, 0xAB45, WORD_LEN, 0},
	{0x0990, 0x00D9, WORD_LEN, 0},
	{0x098C, 0xAB46, WORD_LEN, 0},
	{0x0990, 0x00E1, WORD_LEN, 0},/*{0x0990, 0x0000, WORD_LEN, 0},*/
	{0x098C, 0xAB47, WORD_LEN, 0},
	{0x0990, 0x00E8, WORD_LEN, 0},/*{0x0990, 0x0000, WORD_LEN, 0},*/
	{0x098C, 0xAB48, WORD_LEN, 0},
	{0x0990, 0x00EE, WORD_LEN, 0},
	{0x098C, 0xAB49, WORD_LEN, 0},
	{0x0990, 0x00F2, WORD_LEN, 0},
	{0x098C, 0xAB4A, WORD_LEN, 0},
	{0x0990, 0x00F6, WORD_LEN, 0},
	{0x098C, 0xAB4B, WORD_LEN, 0},
	{0x0990, 0x00F9, WORD_LEN, 0},
	{0x098C, 0xAB4C, WORD_LEN, 0},
	{0x0990, 0x00FB, WORD_LEN, 0},
	{0x098C, 0xAB4D, WORD_LEN, 0},
	{0x0990, 0x00FD, WORD_LEN, 0},
	{0x098C, 0xAB4E, WORD_LEN, 0},
	{0x0990, 0x00FF, WORD_LEN, 0}
};

/* Contract 1 */
static struct mt9v113_i2c_reg_conf contract_setup_tb1[] = {
	{0x098C, 0xAB3C, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xAB3D, WORD_LEN, 0},
	{0x0990, 0x001B, WORD_LEN, 0},
	{0x098C, 0xAB3E, WORD_LEN, 0},
	{0x0990, 0x002E, WORD_LEN, 0},
	{0x098C, 0xAB3F, WORD_LEN, 0},
	{0x0990, 0x004C, WORD_LEN, 0},
	{0x098C, 0xAB40, WORD_LEN, 0},
	{0x0990, 0x0078, WORD_LEN, 0},
	{0x098C, 0xAB41, WORD_LEN, 0},
	{0x0990, 0x0098, WORD_LEN, 0},
	{0x098C, 0xAB42, WORD_LEN, 0},
	{0x0990, 0x00B0, WORD_LEN, 0},
	{0x098C, 0xAB43, WORD_LEN, 0},
	{0x0990, 0x00C1, WORD_LEN, 0},
	{0x098C, 0xAB44, WORD_LEN, 0},
	{0x0990, 0x00CF, WORD_LEN, 0},
	{0x098C, 0xAB45, WORD_LEN, 0},
	{0x0990, 0x00D9, WORD_LEN, 0},
	{0x098C, 0xAB46, WORD_LEN, 0},
	{0x0990, 0x00E1, WORD_LEN, 0},/*{0x0990, 0x0000, WORD_LEN, 0},*/
	{0x098C, 0xAB47, WORD_LEN, 0},
	{0x0990, 0x00E8, WORD_LEN, 0},/*{0x0990, 0x0000, WORD_LEN, 0},*/
	{0x098C, 0xAB48, WORD_LEN, 0},
	{0x0990, 0x00EE, WORD_LEN, 0},
	{0x098C, 0xAB49, WORD_LEN, 0},
	{0x0990, 0x00F2, WORD_LEN, 0},
	{0x098C, 0xAB4A, WORD_LEN, 0},
	{0x0990, 0x00F6, WORD_LEN, 0},
	{0x098C, 0xAB4B, WORD_LEN, 0},
	{0x0990, 0x00F9, WORD_LEN, 0},
	{0x098C, 0xAB4C, WORD_LEN, 0},
	{0x0990, 0x00FB, WORD_LEN, 0},
	{0x098C, 0xAB4D, WORD_LEN, 0},
	{0x0990, 0x00FD, WORD_LEN, 0},
	{0x098C, 0xAB4E, WORD_LEN, 0},
	{0x0990, 0x00FF, WORD_LEN, 0}
};

/* Contract 2 */
static struct mt9v113_i2c_reg_conf contract_setup_tb2[] = {
	{0x098C, 0xAB3C, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xAB3D, WORD_LEN, 0},
	{0x0990, 0x0014, WORD_LEN, 0},
	{0x098C, 0xAB3E, WORD_LEN, 0},
	{0x0990, 0x0027, WORD_LEN, 0},
	{0x098C, 0xAB3F, WORD_LEN, 0},
	{0x0990, 0x0041, WORD_LEN, 0},
	{0x098C, 0xAB40, WORD_LEN, 0},
	{0x0990, 0x0074, WORD_LEN, 0},
	{0x098C, 0xAB41, WORD_LEN, 0},
	{0x0990, 0x0093, WORD_LEN, 0},
	{0x098C, 0xAB42, WORD_LEN, 0},
	{0x0990, 0x00AD, WORD_LEN, 0},
	{0x098C, 0xAB43, WORD_LEN, 0},
	{0x0990, 0x00C1, WORD_LEN, 0},
	{0x098C, 0xAB44, WORD_LEN, 0},
	{0x0990, 0x00CA, WORD_LEN, 0},
	{0x098C, 0xAB45, WORD_LEN, 0},
	{0x0990, 0x00D4, WORD_LEN, 0},
	{0x098C, 0xAB46, WORD_LEN, 0},
	{0x0990, 0x00DC, WORD_LEN, 0},
	{0x098C, 0xAB47, WORD_LEN, 0},
	{0x0990, 0x00E4, WORD_LEN, 0},
	{0x098C, 0xAB48, WORD_LEN, 0},
	{0x0990, 0x00E9, WORD_LEN, 0},
	{0x098C, 0xAB49, WORD_LEN, 0},
	{0x0990, 0x00EE, WORD_LEN, 0},
	{0x098C, 0xAB4A, WORD_LEN, 0},
	{0x0990, 0x00F2, WORD_LEN, 0},
	{0x098C, 0xAB4B, WORD_LEN, 0},
	{0x0990, 0x00F5, WORD_LEN, 0},
	{0x098C, 0xAB4C, WORD_LEN, 0},
	{0x0990, 0x00F8, WORD_LEN, 0},
	{0x098C, 0xAB4D, WORD_LEN, 0},
	{0x0990, 0x00FD, WORD_LEN, 0},
	{0x098C, 0xAB4E, WORD_LEN, 0},
	{0x0990, 0x00FF, WORD_LEN, 0}
};

/* Contract 3 */
static struct mt9v113_i2c_reg_conf contract_setup_tb3[] = {
	{0x098C, 0xAB3C, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xAB3D, WORD_LEN, 0},
	{0x0990, 0x0008, WORD_LEN, 0},
	{0x098C, 0xAB3E, WORD_LEN, 0},
	{0x0990, 0x0017, WORD_LEN, 0},
	{0x098C, 0xAB3F, WORD_LEN, 0},
	{0x0990, 0x002F, WORD_LEN, 0},
	{0x098C, 0xAB40, WORD_LEN, 0},
	{0x0990, 0x0050, WORD_LEN, 0},
	{0x098C, 0xAB41, WORD_LEN, 0},
	{0x0990, 0x006D, WORD_LEN, 0},
	{0x098C, 0xAB42, WORD_LEN, 0},
	{0x0990, 0x0088, WORD_LEN, 0},
	{0x098C, 0xAB43, WORD_LEN, 0},
	{0x0990, 0x009E, WORD_LEN, 0},
	{0x098C, 0xAB44, WORD_LEN, 0},
	{0x0990, 0x00AF, WORD_LEN, 0},
	{0x098C, 0xAB45, WORD_LEN, 0},
	{0x0990, 0x00BD, WORD_LEN, 0},
	{0x098C, 0xAB46, WORD_LEN, 0},
	{0x0990, 0x00C9, WORD_LEN, 0},
	{0x098C, 0xAB47, WORD_LEN, 0},
	{0x0990, 0x00D3, WORD_LEN, 0},
	{0x098C, 0xAB48, WORD_LEN, 0},
	{0x0990, 0x00DB, WORD_LEN, 0},
	{0x098C, 0xAB49, WORD_LEN, 0},
	{0x0990, 0x00E3, WORD_LEN, 0},/*{0x0990, 0x0000, WORD_LEN, 0},*/
	{0x098C, 0xAB4A, WORD_LEN, 0},
	{0x0990, 0x00EA, WORD_LEN, 0},
	{0x098C, 0xAB4B, WORD_LEN, 0},
	{0x0990, 0x00F0, WORD_LEN, 0},
	{0x098C, 0xAB4C, WORD_LEN, 0},
	{0x0990, 0x00F5, WORD_LEN, 0},
	{0x098C, 0xAB4D, WORD_LEN, 0},
	{0x0990, 0x00FA, WORD_LEN, 0},
	{0x098C, 0xAB4E, WORD_LEN, 0},
	{0x0990, 0x00FF, WORD_LEN, 0}
};

/* Contract 4 */
static struct mt9v113_i2c_reg_conf contract_setup_tb4[] = {
	{0x098C, 0xAB3C, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xAB3D, WORD_LEN, 0},
	{0x0990, 0x0006, WORD_LEN, 0},
	{0x098C, 0xAB3E, WORD_LEN, 0},
	{0x0990, 0x0012, WORD_LEN, 0},
	{0x098C, 0xAB3F, WORD_LEN, 0},
	{0x0990, 0x0027, WORD_LEN, 0},
	{0x098C, 0xAB40, WORD_LEN, 0},
	{0x0990, 0x0048, WORD_LEN, 0},
	{0x098C, 0xAB41, WORD_LEN, 0},
	{0x0990, 0x0069, WORD_LEN, 0},
	{0x098C, 0xAB42, WORD_LEN, 0},
	{0x0990, 0x008A, WORD_LEN, 0},
	{0x098C, 0xAB43, WORD_LEN, 0},
	{0x0990, 0x00A4, WORD_LEN, 0},
	{0x098C, 0xAB44, WORD_LEN, 0},
	{0x0990, 0x00B7, WORD_LEN, 0},
	{0x098C, 0xAB45, WORD_LEN, 0},
	{0x0990, 0x00C6, WORD_LEN, 0},
	{0x098C, 0xAB46, WORD_LEN, 0},
	{0x0990, 0x00D1, WORD_LEN, 0},
	{0x098C, 0xAB47, WORD_LEN, 0},
	{0x0990, 0x00DB, WORD_LEN, 0},
	{0x098C, 0xAB48, WORD_LEN, 0},
	{0x0990, 0x00E2, WORD_LEN, 0},
	{0x098C, 0xAB49, WORD_LEN, 0},
	{0x0990, 0x00E9, WORD_LEN, 0},/*{0x0990, 0x0000, WORD_LEN, 0},*/
	{0x098C, 0xAB4A, WORD_LEN, 0},
	{0x0990, 0x00EE, WORD_LEN, 0},
	{0x098C, 0xAB4B, WORD_LEN, 0},
	{0x0990, 0x00F3, WORD_LEN, 0},
	{0x098C, 0xAB4C, WORD_LEN, 0},
	{0x0990, 0x00F7, WORD_LEN, 0},
	{0x098C, 0xAB4D, WORD_LEN, 0},
	{0x0990, 0x00FB, WORD_LEN, 0},
	{0x098C, 0xAB4E, WORD_LEN, 0},
	{0x0990, 0x00FF, WORD_LEN, 0}
};

static struct mt9v113_i2c_reg_conf power_up_tbl[] = {
	/* Power Up */
#ifdef CONFIG_MSM_CAMERA_8X60
	{0x001A, 0x0011, WORD_LEN, 10},
	{0x001A, 0x0010, WORD_LEN, 10},
#else
	{0x001A, 0x0011, WORD_LEN, 1},
	{0x001A, 0x0000, WORD_LEN, 1},
#endif
	{0x301A, 0x1218, WORD_LEN, 10},
	{0x301A, 0x121C, WORD_LEN, 10},
};

/* sensor register init */
static struct mt9v113_i2c_reg_conf register_init_tbl[] = {
	/* move to code */
#if 0
	/* RESET and MISC Contro*/
	{0x0018, 0x4028, WORD_LEN, 0},
	{0x001A, 0x0003, WORD_LEN, 2},
	{0x001A, 0x0000, WORD_LEN, 2},
	{0x0018, 0x4028, WORD_LEN, 0},
	{0x001A, 0x0210, WORD_LEN, 0},
	{0x001E, 0x0777, WORD_LEN, 0},
	{0x0016, 0x42DF, WORD_LEN, 0},
	/* PLL Setup 24Mhz In/28Mhz Out */
	{0x0014, 0xB04B, WORD_LEN, 0},
	{0x0014, 0xB049, WORD_LEN, 0},
	{0x0010, 0x021C, WORD_LEN, 0},
	{0x0012, 0x0000, WORD_LEN, 0},
	{0x0014, 0x244B, WORD_LEN, 10},
	{0x0014, 0x304B, WORD_LEN, 0},
	{0x0014, 0xB04A, WORD_LEN, 0},
#endif
	/* Enable AVE Luma DRT */
	{0x098C, 0xA11D, WORD_LEN, 0},
	{0x0990, 0x0002, WORD_LEN, 0},
	{0x098C, 0xA244, WORD_LEN, 0},
	{0x0990, 0x00BF, WORD_LEN, 0},
	/* AE */
	{0x098C, 0xA24F, WORD_LEN, 0},
	{0x0990, 0x0033, WORD_LEN, 0},
	{0x098C, 0xA207, WORD_LEN, 0},
	{0x0990, 0x0002, WORD_LEN, 0},
	/* Char_settings */
	{0x098C, 0xAB1F, WORD_LEN, 0},
	{0x0990, 0x00C9, WORD_LEN, 0},
	{0x326C, 0x0900, WORD_LEN, 0},
	{0x001E, 0x0400, WORD_LEN, 0},
	/* Sharpness */
	{0x098C, 0xAB22, WORD_LEN, 0},
	{0x0990, 0x0003, WORD_LEN, 0},
	/* Flicker Setting */
	{0x098C, 0xA404, WORD_LEN, 0},
	{0x0990, 0x0010, WORD_LEN, 0},
	{0x098C, 0x222D, WORD_LEN, 0},
	{0x0990, 0x008B, WORD_LEN, 0},
	{0x098C, 0xA408, WORD_LEN, 0},
	{0x0990, 0x0021, WORD_LEN, 0},
	{0x098C, 0xA409, WORD_LEN, 0},
	{0x0990, 0x0024, WORD_LEN, 0},
	{0x098C, 0xA40A, WORD_LEN, 0},
	{0x0990, 0x0028, WORD_LEN, 0},
	{0x098C, 0xA40B, WORD_LEN, 0},
	{0x0990, 0x002B, WORD_LEN, 0},
	{0x098C, 0x2411, WORD_LEN, 0},
	{0x0990, 0x008B, WORD_LEN, 0},
	{0x098C, 0x2413, WORD_LEN, 0},
	{0x0990, 0x00A6, WORD_LEN, 0},
	{0x098C, 0x2415, WORD_LEN, 0},
	{0x0990, 0x008B, WORD_LEN, 0},
	{0x098C, 0x2417, WORD_LEN, 0},
	{0x0990, 0x00A6, WORD_LEN, 0},
	{0x098C, 0xA40D, WORD_LEN, 0},
	{0x0990, 0x0002, WORD_LEN, 0},
	{0x098C, 0xA40E, WORD_LEN, 0},
	{0x0990, 0x0003, WORD_LEN, 0},
	{0x098C, 0xA410, WORD_LEN, 0},
	{0x0990, 0x000A, WORD_LEN, 0},
	/* Micron lens Correction *//*Mu Lee update for new lens 0126*/
	{0x364E, 0x0330, WORD_LEN, 0},
	{0x3650, 0x010B, WORD_LEN, 0},
	{0x3652, 0x2312, WORD_LEN, 0},
	{0x3654, 0xC2AF, WORD_LEN, 0},
	{0x3656, 0x9F50, WORD_LEN, 0},
	{0x3658, 0x0290, WORD_LEN, 0},
	{0x365A, 0x0FEB, WORD_LEN, 0},
	{0x365C, 0x4E52, WORD_LEN, 0},
	{0x365E, 0xC0CF, WORD_LEN, 0},
	{0x3660, 0xCB12, WORD_LEN, 0},
	{0x3662, 0x02B0, WORD_LEN, 0},
	{0x3664, 0x620C, WORD_LEN, 0},
	{0x3666, 0x1AD2, WORD_LEN, 0},
	{0x3668, 0xA7B0, WORD_LEN, 0},
	{0x366A, 0xBB91, WORD_LEN, 0},
	{0x366C, 0x0290, WORD_LEN, 0},
	{0x366E, 0xCE2A, WORD_LEN, 0},
	{0x3670, 0x2AD2, WORD_LEN, 0},
	{0x3672, 0x8BAE, WORD_LEN, 0},
	{0x3674, 0xABAF, WORD_LEN, 0},
	{0x3676, 0xCB8D, WORD_LEN, 0},
	{0x3678, 0xA24E, WORD_LEN, 0},
	{0x367A, 0x2F91, WORD_LEN, 0},
	{0x367C, 0x0991, WORD_LEN, 0},
	{0x367E, 0xC594, WORD_LEN, 0},
	{0x3680, 0xAC2B, WORD_LEN, 0},
	{0x3682, 0xA4AC, WORD_LEN, 0},
	{0x3684, 0x6891, WORD_LEN, 0},
	{0x3686, 0xAD30, WORD_LEN, 0},
	{0x3688, 0x9295, WORD_LEN, 0},
	{0x368A, 0x380B, WORD_LEN, 0},
	{0x368C, 0x464C, WORD_LEN, 0},
	{0x368E, 0x4C2C, WORD_LEN, 0},
	{0x3690, 0xE9AF, WORD_LEN, 0},
	{0x3692, 0xC312, WORD_LEN, 0},
	{0x3694, 0xA50D, WORD_LEN, 0},
	{0x3696, 0xF6AD, WORD_LEN, 0},
	{0x3698, 0x2E11, WORD_LEN, 0},
	{0x369A, 0x11F0, WORD_LEN, 0},
	{0x369C, 0xB534, WORD_LEN, 0},
	{0x369E, 0x0573, WORD_LEN, 0},
	{0x36A0, 0xA431, WORD_LEN, 0},
	{0x36A2, 0x81B6, WORD_LEN, 0},
	{0x36A4, 0x0895, WORD_LEN, 0},
	{0x36A6, 0x5D19, WORD_LEN, 0},
	{0x36A8, 0x17F3, WORD_LEN, 0},
	{0x36AA, 0xF1F1, WORD_LEN, 0},
	{0x36AC, 0x80D6, WORD_LEN, 0},
	{0x36AE, 0x42B4, WORD_LEN, 0},
	{0x36B0, 0x3499, WORD_LEN, 0},
	{0x36B2, 0x55F2, WORD_LEN, 0},
	{0x36B4, 0x9492, WORD_LEN, 0},
	{0x36B6, 0x9456, WORD_LEN, 0},
	{0x36B8, 0x22B5, WORD_LEN, 0},
	{0x36BA, 0x4AB9, WORD_LEN, 0},
	{0x36BC, 0x0093, WORD_LEN, 0},
	{0x36BE, 0xA391, WORD_LEN, 0},
	{0x36C0, 0x85B6, WORD_LEN, 0},
	{0x36C2, 0x4C34, WORD_LEN, 0},
	{0x36C4, 0x4BF9, WORD_LEN, 0},
	{0x36C6, 0xBD0F, WORD_LEN, 0},
	{0x36C8, 0x1DD1, WORD_LEN, 0},
	{0x36CA, 0xEE54, WORD_LEN, 0},
	{0x36CC, 0xAAB5, WORD_LEN, 0},
	{0x36CE, 0x0CD7, WORD_LEN, 0},
	{0x36D0, 0xA770, WORD_LEN, 0},
	{0x36D2, 0x9C11, WORD_LEN, 0},
	{0x36D4, 0xA635, WORD_LEN, 0},
	{0x36D6, 0x1576, WORD_LEN, 0},
	{0x36D8, 0x0058, WORD_LEN, 0},
	{0x36DA, 0xC4F1, WORD_LEN, 0},
	{0x36DC, 0xD3F1, WORD_LEN, 0},
	{0x36DE, 0x5134, WORD_LEN, 0},
	{0x36E0, 0x2696, WORD_LEN, 0},
	{0x36E2, 0x8F19, WORD_LEN, 0},
	{0x36E4, 0xD98F, WORD_LEN, 0},
	{0x36E6, 0xA911, WORD_LEN, 0},
	{0x36E8, 0xD1F4, WORD_LEN, 0},
	{0x36EA, 0x7054, WORD_LEN, 0},
	{0x36EC, 0x76D6, WORD_LEN, 0},
	{0x36EE, 0x93D5, WORD_LEN, 0},
	{0x36F0, 0x0934, WORD_LEN, 0},
	{0x36F2, 0x63B9, WORD_LEN, 0},
	{0x36F4, 0xC178, WORD_LEN, 0},
	{0x36F6, 0xEA7C, WORD_LEN, 0},
	{0x36F8, 0xA7D5, WORD_LEN, 0},
	{0x36FA, 0x0A55, WORD_LEN, 0},
	{0x36FC, 0x3979, WORD_LEN, 0},
	{0x36FE, 0x8597, WORD_LEN, 0},
	{0x3700, 0xA03C, WORD_LEN, 0},
	{0x3702, 0xE194, WORD_LEN, 0},
	{0x3704, 0x74F4, WORD_LEN, 0},
	{0x3706, 0x7A19, WORD_LEN, 0},
	{0x3708, 0xC5B6, WORD_LEN, 0},
	{0x370A, 0xD9BC, WORD_LEN, 0},
	{0x370C, 0x8F55, WORD_LEN, 0},
	{0x370E, 0x6FF4, WORD_LEN, 0},
	{0x3710, 0x01DA, WORD_LEN, 0},
	{0x3712, 0xE317, WORD_LEN, 0},
	{0x3714, 0xE93C, WORD_LEN, 0},
	{0x3644, 0x0144, WORD_LEN, 0},
	{0x3642, 0x00F0, WORD_LEN, 0},
};

static struct mt9v113_i2c_reg_conf register_init_tb2[] = {

	/*{0x3210[3], 0x0001, WORD_LEN, 0},*/

	/* Saturation */
	{0x098C, 0xA354, WORD_LEN, 0},
	{0x0990, 0x0048, WORD_LEN, 0},
	{0x098C, 0xAB20, WORD_LEN, 0},
	{0x0990, 0x0048, WORD_LEN, 0},
	/* Micron AWB and CCMs */
	{0x098C, 0xA11F, WORD_LEN, 0},
	{0x0990, 0x0001, WORD_LEN, 0},
	{0x098C, 0x2306, WORD_LEN, 0},
	{0x0990, 0x03C0, WORD_LEN, 0},
	{0x098C, 0x2308, WORD_LEN, 0},
	{0x0990, 0xFD7C, WORD_LEN, 0},
	{0x098C, 0x230A, WORD_LEN, 0},
	{0x0990, 0xFFF7, WORD_LEN, 0},
	{0x098C, 0x230C, WORD_LEN, 0},
	{0x0990, 0xFF25, WORD_LEN, 0},
	{0x098C, 0x230E, WORD_LEN, 0},
	{0x0990, 0x0384, WORD_LEN, 0},
	{0x098C, 0x2310, WORD_LEN, 0},
	{0x0990, 0xFFD6, WORD_LEN, 0},
	{0x098C, 0x2312, WORD_LEN, 0},
	{0x0990, 0xFED2, WORD_LEN, 0},
	{0x098C, 0x2314, WORD_LEN, 0},
	{0x0990, 0xFCB2, WORD_LEN, 0},
	{0x098C, 0x2316, WORD_LEN, 0},
	{0x0990, 0x068E, WORD_LEN, 0},
	{0x098C, 0x2318, WORD_LEN, 0},
	{0x0990, 0x001B, WORD_LEN, 0},
	{0x098C, 0x231A, WORD_LEN, 0},
	{0x0990, 0x0036, WORD_LEN, 0},
	{0x098C, 0x231C, WORD_LEN, 0},
	{0x0990, 0xFF65, WORD_LEN, 0},
	{0x098C, 0x231E, WORD_LEN, 0},
	{0x0990, 0x0052, WORD_LEN, 0},
	{0x098C, 0x2320, WORD_LEN, 0},
	{0x0990, 0x0012, WORD_LEN, 0},
	{0x098C, 0x2322, WORD_LEN, 0},
	{0x0990, 0x0007, WORD_LEN, 0},
	{0x098C, 0x2324, WORD_LEN, 0},
	{0x0990, 0xFFCF, WORD_LEN, 0},
	{0x098C, 0x2326, WORD_LEN, 0},
	{0x0990, 0x0037, WORD_LEN, 0},
	{0x098C, 0x2328, WORD_LEN, 0},
	{0x0990, 0x00D8, WORD_LEN, 0},
	{0x098C, 0x232A, WORD_LEN, 0},
	{0x0990, 0x01C8, WORD_LEN, 0},
	{0x098C, 0x232C, WORD_LEN, 0},
	{0x0990, 0xFC9F, WORD_LEN, 0},
	{0x098C, 0x232E, WORD_LEN, 0},
	{0x0990, 0x0010, WORD_LEN, 0},
	{0x098C, 0x2330, WORD_LEN, 0},
	{0x0990, 0xFFF7, WORD_LEN, 0},
	{0x098C, 0xA348, WORD_LEN, 0},
	{0x0990, 0x0008, WORD_LEN, 0},
	{0x098C, 0xA349, WORD_LEN, 0},
	{0x0990, 0x0002, WORD_LEN, 0},
	{0x098C, 0xA34A, WORD_LEN, 0},
	{0x0990, 0x0059, WORD_LEN, 0},
	{0x098C, 0xA34B, WORD_LEN, 0},
	{0x0990, 0x00E6, WORD_LEN, 0},
	{0x098C, 0xA351, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xA352, WORD_LEN, 0},
	{0x0990, 0x007F, WORD_LEN, 0},
	{0x098C, 0xA355, WORD_LEN, 0},
	{0x0990, 0x0001, WORD_LEN, 0},
	{0x098C, 0xA35D, WORD_LEN, 0},
	{0x0990, 0x0078, WORD_LEN, 0},
	{0x098C, 0xA35E, WORD_LEN, 0},
	{0x0990, 0x0086, WORD_LEN, 0},
	{0x098C, 0xA35F, WORD_LEN, 0},
	{0x0990, 0x007E, WORD_LEN, 0},
	{0x098C, 0xA360, WORD_LEN, 0},
	{0x0990, 0x0082, WORD_LEN, 0},
	{0x098C, 0x2361, WORD_LEN, 0},
	{0x0990, 0x0040, WORD_LEN, 0},
	{0x098C, 0xA363, WORD_LEN, 0},
	{0x0990, 0x00D2, WORD_LEN, 0},
	{0x098C, 0xA364, WORD_LEN, 0},
	{0x0990, 0x00F6, WORD_LEN, 0},
	{0x098C, 0xA302, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xA303, WORD_LEN, 0},
	{0x0990, 0x00EF, WORD_LEN, 0},
	{0x098C, 0xA366, WORD_LEN, 0},
	{0x0990, 0x00C0, WORD_LEN, 0},
	{0x098C, 0xA367, WORD_LEN, 0},
	{0x0990, 0x0073, WORD_LEN, 0},
	{0x098C, 0xA368, WORD_LEN, 0},
	{0x0990, 0x0038, WORD_LEN, 0},
	/* Gamma Morph brightness setting */
#ifndef CONFIG_MSM_CAMERA_8X60
	{0x098C, 0x2B1B, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
#endif
	{0x098C, 0x2B28, WORD_LEN, 0},
	{0x0990, 0x157C, WORD_LEN, 0},
	{0x098C, 0x2B2A, WORD_LEN, 0},
	{0x0990, 0x1B58, WORD_LEN, 0},
	{0x098C, 0xAB37, WORD_LEN, 0},
	{0x0990, 0x0003, WORD_LEN, 0},
	{0x098C, 0x2B38, WORD_LEN, 0},
	{0x0990, 0x157C, WORD_LEN, 0},
	{0x098C, 0x2B3A, WORD_LEN, 0},
	{0x0990, 0x1B58, WORD_LEN, 0},
	/* Gamma Table Context A (normal light) */
	{0x098C, 0xAB3C, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xAB3D, WORD_LEN, 0},
	{0x0990, 0x0014, WORD_LEN, 0},
	{0x098C, 0xAB3E, WORD_LEN, 0},
	{0x0990, 0x0027, WORD_LEN, 0},
	{0x098C, 0xAB3F, WORD_LEN, 0},
	{0x0990, 0x0041, WORD_LEN, 0},
	{0x098C, 0xAB40, WORD_LEN, 0},
	{0x0990, 0x0074, WORD_LEN, 0},
	{0x098C, 0xAB41, WORD_LEN, 0},
	{0x0990, 0x0093, WORD_LEN, 0},
	{0x098C, 0xAB42, WORD_LEN, 0},
	{0x0990, 0x00AD, WORD_LEN, 0},
	{0x098C, 0xAB43, WORD_LEN, 0},
	{0x0990, 0x00C1, WORD_LEN, 0},
	{0x098C, 0xAB44, WORD_LEN, 0},
	{0x0990, 0x00CA, WORD_LEN, 0},
	{0x098C, 0xAB45, WORD_LEN, 0},
	{0x0990, 0x00D4, WORD_LEN, 0},
	{0x098C, 0xAB46, WORD_LEN, 0},
	{0x0990, 0x00DC, WORD_LEN, 0},
	{0x098C, 0xAB47, WORD_LEN, 0},
	{0x0990, 0x00E4, WORD_LEN, 0},
	{0x098C, 0xAB48, WORD_LEN, 0},
	{0x0990, 0x00E9, WORD_LEN, 0},
	{0x098C, 0xAB49, WORD_LEN, 0},
	{0x0990, 0x00EE, WORD_LEN, 0},
	{0x098C, 0xAB4A, WORD_LEN, 0},
	{0x0990, 0x00F2, WORD_LEN, 0},
	{0x098C, 0xAB4B, WORD_LEN, 0},
	{0x0990, 0x00F5, WORD_LEN, 0},
	{0x098C, 0xAB4C, WORD_LEN, 0},
	{0x0990, 0x00F8, WORD_LEN, 0},
	{0x098C, 0xAB4D, WORD_LEN, 0},
	{0x0990, 0x00FD, WORD_LEN, 0},
	{0x098C, 0xAB4E, WORD_LEN, 0},
	{0x0990, 0x00FF, WORD_LEN, 0},
	/* Gamma Table Context B (dark scene) */
	{0x098C, 0xAB4F, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0xAB50, WORD_LEN, 0},
	{0x0990, 0x000F, WORD_LEN, 0},
	{0x098C, 0xAB51, WORD_LEN, 0},
	{0x0990, 0x001A, WORD_LEN, 0},
	{0x098C, 0xAB52, WORD_LEN, 0},
	{0x0990, 0x002E, WORD_LEN, 0},
	{0x098C, 0xAB53, WORD_LEN, 0},
	{0x0990, 0x0050, WORD_LEN, 0},
	{0x098C, 0xAB54, WORD_LEN, 0},
	{0x0990, 0x006A, WORD_LEN, 0},
	{0x098C, 0xAB55, WORD_LEN, 0},
	{0x0990, 0x0080, WORD_LEN, 0},
	{0x098C, 0xAB56, WORD_LEN, 0},
	{0x0990, 0x0091, WORD_LEN, 0},
	{0x098C, 0xAB57, WORD_LEN, 0},
	{0x0990, 0x00A1, WORD_LEN, 0},
	{0x098C, 0xAB58, WORD_LEN, 0},
	{0x0990, 0x00AF, WORD_LEN, 0},
	{0x098C, 0xAB59, WORD_LEN, 0},
	{0x0990, 0x00BB, WORD_LEN, 0},
	{0x098C, 0xAB5A, WORD_LEN, 0},
	{0x0990, 0x00C6, WORD_LEN, 0},
	{0x098C, 0xAB5B, WORD_LEN, 0},
	{0x0990, 0x00D0, WORD_LEN, 0},
	{0x098C, 0xAB5C, WORD_LEN, 0},
	{0x0990, 0x00D9, WORD_LEN, 0},
	{0x098C, 0xAB5D, WORD_LEN, 0},
	{0x0990, 0x00E2, WORD_LEN, 0},
	{0x098C, 0xAB5E, WORD_LEN, 0},
	{0x0990, 0x00EA, WORD_LEN, 0},
	{0x098C, 0xAB5F, WORD_LEN, 0},
	{0x0990, 0x00F1, WORD_LEN, 0},
	{0x098C, 0xAB60, WORD_LEN, 0},
	{0x0990, 0x00F9, WORD_LEN, 0},
	{0x098C, 0xAB61, WORD_LEN, 0},
	{0x0990, 0x00FF, WORD_LEN, 0},
	/* Mode-set up Preview (VGA) /Capture Mode (VGA) */
	{0x098C, 0x2703, WORD_LEN, 0},
	{0x0990, 0x0280, WORD_LEN, 0},
	{0x098C, 0x2705, WORD_LEN, 0},
	{0x0990, 0x01E0, WORD_LEN, 0},
	{0x098C, 0x270D, WORD_LEN, 0},
	{0x0990, 0x0004, WORD_LEN, 0},
	{0x098C, 0x270F, WORD_LEN, 0},
	{0x0990, 0x0004, WORD_LEN, 0},
	{0x098C, 0x2711, WORD_LEN, 0},
	{0x0990, 0x01EB, WORD_LEN, 0},
	{0x098C, 0x2713, WORD_LEN, 0},
	{0x0990, 0x028B, WORD_LEN, 0},
	{0x098C, 0x2715, WORD_LEN, 0},
	{0x0990, 0x0001, WORD_LEN, 0},
	{0x098C, 0x2717, WORD_LEN, 0},
#ifdef CONFIG_MSM_CAMERA_8X60
	{0x0990, 0x0024, WORD_LEN, 0},/* 0x0027: mirror/flip , 0x0024: none*/
#else
	{0x0990, 0x0027, WORD_LEN, 0},/* 0x0027: mirror/flip , 0x0024: none*/
#endif
	{0x098C, 0x2719, WORD_LEN, 0},
	{0x0990, 0x001A, WORD_LEN, 0},
	{0x098C, 0x271B, WORD_LEN, 0},
	{0x0990, 0x006B, WORD_LEN, 0},
	{0x098C, 0x271D, WORD_LEN, 0},
	{0x0990, 0x006B, WORD_LEN, 0},
	{0x098C, 0x271F, WORD_LEN, 0},
	{0x0990, 0x022A, WORD_LEN, 0},
	{0x098C, 0x2721, WORD_LEN, 0},
	{0x0990, 0x034A, WORD_LEN, 0},
	{0x098C, 0x2739, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0x273B, WORD_LEN, 0},
	{0x0990, 0x027F, WORD_LEN, 0},
	{0x098C, 0x273D, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0x273F, WORD_LEN, 0},
	{0x0990, 0x01DF, WORD_LEN, 0},
	{0x098C, 0x2707, WORD_LEN, 0},
	{0x0990, 0x0280, WORD_LEN, 0},
	{0x098C, 0x2709, WORD_LEN, 0},
	{0x0990, 0x01E0, WORD_LEN, 0},
	{0x098C, 0x2723, WORD_LEN, 0},
	{0x0990, 0x0004, WORD_LEN, 0},
	{0x098C, 0x2725, WORD_LEN, 0},
	{0x0990, 0x0004, WORD_LEN, 0},
	{0x098C, 0x2727, WORD_LEN, 0},
	{0x0990, 0x01EB, WORD_LEN, 0},
	{0x098C, 0x2729, WORD_LEN, 0},
	{0x0990, 0x028B, WORD_LEN, 0},
	{0x098C, 0x272B, WORD_LEN, 0},
	{0x0990, 0x0001, WORD_LEN, 0},
	{0x098C, 0x272D, WORD_LEN, 0},
#ifdef CONFIG_MSM_CAMERA_8X60
	{0x0990, 0x0024, WORD_LEN, 0},/* 0x0027: mirror/flip , 0x0024: none*/
#else
	{0x0990, 0x0027, WORD_LEN, 0},/* 0x0027: mirror/flip , 0x0024: none*/
#endif
	{0x098C, 0x272F, WORD_LEN, 0},
	{0x0990, 0x001A, WORD_LEN, 0},
	{0x098C, 0x2731, WORD_LEN, 0},
	{0x0990, 0x006B, WORD_LEN, 0},
	{0x098C, 0x2733, WORD_LEN, 0},
	{0x0990, 0x006B, WORD_LEN, 0},
	{0x098C, 0x2735, WORD_LEN, 0},
	{0x0990, 0x022A, WORD_LEN, 0},
	{0x098C, 0x2737, WORD_LEN, 0},
	{0x0990, 0x034A, WORD_LEN, 0},
	{0x098C, 0x2747, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0x2749, WORD_LEN, 0},
	{0x0990, 0x027F, WORD_LEN, 0},
	{0x098C, 0x274B, WORD_LEN, 0},
	{0x0990, 0x0000, WORD_LEN, 0},
	{0x098C, 0x274D, WORD_LEN, 0},
	{0x0990, 0x01DF, WORD_LEN, 0},
	{0x098C, 0x2755, WORD_LEN, 0},
	{0x0990, 0x0002, WORD_LEN, 0},
	{0x098C, 0x2757, WORD_LEN, 0},
	{0x0990, 0x0002, WORD_LEN, 0},
	{0x098C, 0xA20C, WORD_LEN, 0},/*Mu add for min frame rate =15fps 0126*/
	{0x0990, 0x0008, WORD_LEN, 0},/*Mu add for min frame rate =15fps 0126*/

#if 0
	/* move to code */
	{0x098C, 0xA103, WORD_LEN, 0},
	{0x0990, 0x0006, WORD_LEN, 0},
	{0x098C, 0xA103, WORD_LEN, 0},
	{0x0990, 0x0005, WORD_LEN, 0},
	{0x098C, 0xA102, WORD_LEN, 0},
	{0x0990, 0x000F, WORD_LEN, 0},
#endif

};


struct mt9v113_reg mt9v113_regs = {
	.power_up_tbl = (struct mt9v113_i2c_reg_conf *)&power_up_tbl,
	.power_up_tbl_size = ARRAY_SIZE(power_up_tbl),
	.register_init_1 = (struct mt9v113_i2c_reg_conf *)&register_init_tbl,
	.register_init_size_1 = ARRAY_SIZE(register_init_tbl),
	.register_init_2 = (struct mt9v113_i2c_reg_conf *)&register_init_tb2,
	.register_init_size_2 = ARRAY_SIZE(register_init_tb2),
	.contract_tb0 = (struct mt9v113_i2c_reg_conf *)&contract_setup_tb0,
	.contract_tb0_size = ARRAY_SIZE(contract_setup_tb0),
	.contract_tb1 = (struct mt9v113_i2c_reg_conf *)&contract_setup_tb1,
	.contract_tb1_size = ARRAY_SIZE(contract_setup_tb1),
	.contract_tb2 = (struct mt9v113_i2c_reg_conf *)&contract_setup_tb2,
	.contract_tb2_size = ARRAY_SIZE(contract_setup_tb2),
	.contract_tb3 = (struct mt9v113_i2c_reg_conf *)&contract_setup_tb3,
	.contract_tb3_size = ARRAY_SIZE(contract_setup_tb3),
	.contract_tb4 = (struct mt9v113_i2c_reg_conf *)&contract_setup_tb4,
	.contract_tb4_size = ARRAY_SIZE(contract_setup_tb4),
	.wb_auto = (struct mt9v113_i2c_reg_conf *)&wb_auto,
	.wb_auto_size = ARRAY_SIZE(wb_auto),
	.wb_fluorescent = (struct mt9v113_i2c_reg_conf *)&wb_fluorescent,
	.wb_fluorescent_size = ARRAY_SIZE(wb_fluorescent),
	.wb_incandescent = (struct mt9v113_i2c_reg_conf *)&wb_incandescent,
	.wb_incandescent_size = ARRAY_SIZE(wb_incandescent),
	.wb_daylight = (struct mt9v113_i2c_reg_conf *)&wb_daylight,
	.wb_daylight_size = ARRAY_SIZE(wb_daylight)
};
