#include "breath_led.h"

int main(void)
{
	ap_uint<1> led;

	breath_led(1, 2000, &led);
	breath_led(0, 2000, &led);

	printf("test passed!\n");
	return 0;
}
