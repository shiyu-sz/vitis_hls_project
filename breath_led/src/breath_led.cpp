#include "breath_led.h"

void breath_led(ap_uint<32> sw_ctrl, ap_uint<32> freq_step, ap_uint<1>* led)
{
#pragma HLS INTERFACE ap_none port=led
#pragma HLS INTERFACE s_axilite port=sw_ctrl
#pragma HLS INTERFACE s_axilite port=freq_step
#pragma HLS INTERFACE ap_ctrl_none port=return
    unsigned int duty_cycle,period_cnt=0;

    if(sw_ctrl == 1){
        for( duty_cycle = 0; duty_cycle < 50000; duty_cycle += freq_step){
            for( period_cnt = 0; period_cnt < 50000; period_cnt++){
            	if(period_cnt <= duty_cycle){
            		*led = 1;
            	}
            	else
            		*led = 0;
            }
        }
        for( duty_cycle = 50000; duty_cycle > 0; duty_cycle -= freq_step){
            for( period_cnt = 0; period_cnt < 50000; period_cnt++){
            	if(period_cnt <= duty_cycle){
            		*led = 1;
            	}
                else
                	*led = 0;
            }
        }
    }
    else
        *led = 0;
}

