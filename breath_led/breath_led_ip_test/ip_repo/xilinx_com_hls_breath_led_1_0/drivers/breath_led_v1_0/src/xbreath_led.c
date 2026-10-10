// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xbreath_led.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XBreath_led_CfgInitialize(XBreath_led *InstancePtr, XBreath_led_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XBreath_led_Set_sw_ctrl(XBreath_led *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBreath_led_WriteReg(InstancePtr->Control_BaseAddress, XBREATH_LED_CONTROL_ADDR_SW_CTRL_DATA, Data);
}

u32 XBreath_led_Get_sw_ctrl(XBreath_led *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBreath_led_ReadReg(InstancePtr->Control_BaseAddress, XBREATH_LED_CONTROL_ADDR_SW_CTRL_DATA);
    return Data;
}

void XBreath_led_Set_freq_step(XBreath_led *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBreath_led_WriteReg(InstancePtr->Control_BaseAddress, XBREATH_LED_CONTROL_ADDR_FREQ_STEP_DATA, Data);
}

u32 XBreath_led_Get_freq_step(XBreath_led *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBreath_led_ReadReg(InstancePtr->Control_BaseAddress, XBREATH_LED_CONTROL_ADDR_FREQ_STEP_DATA);
    return Data;
}

