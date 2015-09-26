#include <time.h>
#include <stdlib.h>
#include "mx_random.h"

int _max16;
int _seed16;

void mx_random_init() {
	clock_t time = clock();
	srand((unsigned) time);
	_seed16 = rand();
}

int mx_random_rand() {
	return rand();
}

void mx_random_set_max16(int max) {
	_max16 = max; 
}

int mx_random_next16() {
	do {
		unsigned int bit = (_seed16 ^ (_seed16 >> 2) ^ (_seed16 >> 4) ^ (_seed16 >> 9)) & 1;
		_seed16 = (_seed16 >> 1) | (bit << 15);
	} while (_seed16 >= _max16);
	return _seed16;
}