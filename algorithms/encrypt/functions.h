#ifndef FUNCTIONS_H
#define FUNCTIONS_H

bool check(const char *seq, const int length);

void decode(const int *in, const int len, char* const out, const int seed);


void encode(char *string, int* const ptr, const int a, const int b, const int c);

int rand(const int ch, const int a, const int b, const int c);

extern int seed;

extern int term;

void sseed(const int a);

struct encoder{
	int a, b, c, seed;
	encoder(const int s, const int x, const int y, const int z) : seed(s), a(x), b(y), c(z) {}

	void operator()(char *string, int* ptr) const;
};

struct decoder{
	int a, b, c;
	decoder(const int x, const int y, const int z) : a(x), b(y), c(z) {}
	void operator()(const int *in, const int len, char* const out, const int seed) const;
};

#endif
