#ifndef MX_RANDOM_H
#define	MX_RANDOM_H

typedef unsigned long UL;

void mx_random_init(void);
int mx_random_rand(void);
void mx_random_set_max16(int max);
int mx_random_next16(void);
UL mx_random_kiss(void);

#endif