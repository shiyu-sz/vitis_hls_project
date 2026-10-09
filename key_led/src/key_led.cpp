#include "key_led.h"

void key_led(ap_uint<1> key,ap_uint<1>* led)
{
//#pragma HLS INTERFACE ap_none port=led
//#pragma HLS INTERFACE ap_none port=key
#pragma HLS INTERFACE ap_hs port=led
#pragma HLS INTERFACE ap_hs port=key
#pragma HLS INTERFACE ap_ctrl_none port=return

    ap_uint<1> key_value = key;

    switch(key_value)
    {
        case 1:
            *led = 1;
            break;
        case 0:
            *led = 0;
            break;
        default:
            *led = 0;
            break;
    }
}


