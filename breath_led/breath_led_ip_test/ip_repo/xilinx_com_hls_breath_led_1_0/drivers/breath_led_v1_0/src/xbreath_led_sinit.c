// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xbreath_led.h"

extern XBreath_led_Config XBreath_led_ConfigTable[];

XBreath_led_Config *XBreath_led_LookupConfig(u16 DeviceId) {
	XBreath_led_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XBREATH_LED_NUM_INSTANCES; Index++) {
		if (XBreath_led_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XBreath_led_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XBreath_led_Initialize(XBreath_led *InstancePtr, u16 DeviceId) {
	XBreath_led_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XBreath_led_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XBreath_led_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

