#include <stdio.h>
#include "mx_random.h"
#define MAX 65535

int nexts[MAX];

int main(void) {
	mx_random_init();
	printf("Test LFSR\n");
	mx_random_set_max16(MAX);
	int i;
	for (i = 0; i < MAX; i++) {
		nexts[i] = 0;
	}
	for (i = 0; i < MAX; i++) {
		int next = mx_random_next16();
		if (nexts[next] == 0) {
			nexts[next] = 1;
		} else {
			break;
		}
		printf("Next %d\n", next);
	}
	printf("MAX %d\n", i);
	printf("Test KISS\n");
	for (i = 0; i < MAX; i++) {
		nexts[i] = 0;
	}
	for (i = 0; i < MAX; i++) {
		UL k = mx_random_kiss() % MAX;
		nexts[k]++;
	}
	printf("KISS distribution\n");
	for (i = 0; i < MAX; i++) {
		printf("nexts[%d] %d\n", i, nexts[i]);
	}
	return 0;
}