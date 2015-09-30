## mx random library for e-puck

### Usage

Include ```mx_random.h```. You init the seeds of the generators with ```mx_random_init()```. Then you can call ```mx_random_rand()``` to get the standard number generator of ```stdlib.h``` (i. e. ```rand()```). You can request a Linear Feedback Shift Register (LFSR) to generate a random sequence up to (16 bits integer) MAX calling ```mx_random_next16()```. You can set the maximum with```mx_random_set_max16(MAX)```. Be careful with the LFSR since it will never generate a 0. Example:

    #include "mx_random.h"

    int main(void) {
    	mx_random_init():
    	mx_random_set_max16(1600);
    	while (1) {
    		int next = mx_random_next16();
    		// The pseudo - random sequence will have a period of MAX - 1 = 1599
    	}
    	return 0;
    }

You can also test a KISS implementation:

    #include "mx_random.h"

    int main(void) {
        mx_random_init();
        while (1) {
            UL k = mx_random_kiss() % 1600;
        }
    }