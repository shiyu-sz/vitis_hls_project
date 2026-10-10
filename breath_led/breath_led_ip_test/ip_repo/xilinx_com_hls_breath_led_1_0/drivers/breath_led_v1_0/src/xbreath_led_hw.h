// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x00 : reserved
// 0x04 : reserved
// 0x08 : reserved
// 0x0c : reserved
// 0x10 : Data signal of sw_ctrl
//        bit 31~0 - sw_ctrl[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of freq_step
//        bit 31~0 - freq_step[31:0] (Read/Write)
// 0x1c : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XBREATH_LED_CONTROL_ADDR_SW_CTRL_DATA   0x10
#define XBREATH_LED_CONTROL_BITS_SW_CTRL_DATA   32
#define XBREATH_LED_CONTROL_ADDR_FREQ_STEP_DATA 0x18
#define XBREATH_LED_CONTROL_BITS_FREQ_STEP_DATA 32

