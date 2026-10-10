// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XBREATH_LED_H
#define XBREATH_LED_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xbreath_led_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XBreath_led_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XBreath_led;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XBreath_led_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XBreath_led_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XBreath_led_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XBreath_led_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XBreath_led_Initialize(XBreath_led *InstancePtr, u16 DeviceId);
XBreath_led_Config* XBreath_led_LookupConfig(u16 DeviceId);
int XBreath_led_CfgInitialize(XBreath_led *InstancePtr, XBreath_led_Config *ConfigPtr);
#else
int XBreath_led_Initialize(XBreath_led *InstancePtr, const char* InstanceName);
int XBreath_led_Release(XBreath_led *InstancePtr);
#endif


void XBreath_led_Set_sw_ctrl(XBreath_led *InstancePtr, u32 Data);
u32 XBreath_led_Get_sw_ctrl(XBreath_led *InstancePtr);
void XBreath_led_Set_freq_step(XBreath_led *InstancePtr, u32 Data);
u32 XBreath_led_Get_freq_step(XBreath_led *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
