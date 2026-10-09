#include "key_led.h"

int main()
{
	ap_uint<1> key,led;

	key = 1;
	key_led(key,&led);
	key = 0;
	key_led(key,&led);

	printf("Run successfully!");

	return 0;
}


