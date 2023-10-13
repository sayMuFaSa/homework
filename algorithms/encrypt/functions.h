#ifndef FUNCTIONS_H
#define FUNCTIONS_H

bool check(const char *seq, const int length);

void decode(const int *in, const int len, char* const out, const int seed);

void encode(char *string, int* const ptr, const int seed);

int rand(const int ch, const int seed);

extern int x;

#define TERM 2

#endif
