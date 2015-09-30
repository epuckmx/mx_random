#include <time.h>
#include <stdlib.h>
#include "mx_random.h"
// From http://www.cse.yorku.ca/~oz/marsaglia-rng.html
#define znew  (z = 36969 * (z & 65535) + (z >> 16))
#define wnew  (w = 18000 * (w & 65535) + (w >> 16))
#define MWC   ((znew << 16) + wnew)
#define SHR3  (jsr ^= (jsr << 17), jsr ^= (jsr >> 13), jsr ^= (jsr << 5))
#define CONG  (jcong = 69069 * jcong + 1234567)
#define KISS  ((MWC ^ CONG) + SHR3)

int _max16, _seed16;

static UL z, w, jsr, jcong;

void mx_random_init() {
	clock_t time = clock();
	srand((unsigned) time);
	_seed16 = rand();
	z = rand(); 
	w = rand(), 
	jsr = rand(); 
	jcong = rand();
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

UL mx_random_kiss() {
	return KISS;
}