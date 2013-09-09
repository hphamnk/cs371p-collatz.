// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

// ------------
// Global
// ------------
int cycle_cache[1000001] = {0};

// ------------
// collatz_read
// ------------

bool collatz_read (std::istream& r, int& i, int& j) {
	r >> i;
	if (!r)
		return false;
	r >> j;
	assert(i > 0);
	assert(j > 0);
	return true;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
	cycle_cache[1] = 1;
	// <your code>
	int v = collatz_cycle_length(j);
	assert(v > 0);
	return v;}

// ------------
// collatz_eval
// ------------

int collatz_cycle_length(int n) {
	int previous_cycle;
	int x;

	if (n == 1)
		return 1;

	// even: n / 2, check if value is in cache, else call recursively,
	if ( (n % 2) == 0) {
		x = n /2;
		previous_cycle = cycle_cache[x];
		if (previous_cycle == 0)
			return collatz_cycle_length(x) + 1;
		else
			return previous_cycle + 1;
	}

	// odd: n * 3 + 1, since this will be even, skip another step by / 2
	// check if value is in cache, else call recursively
	if ( (n % 2) != 0) {
		x = (3 * n + 1) / 2;
		previous_cycle = cycle_cache[x];
		if (previous_cycle == 0)
			return collatz_cycle_length(x) + 2;
		else
			return previous_cycle + 2;
	}
}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
	w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
	int i;
	int j;
	while (collatz_read(r, i, j)) {
		const int v = collatz_eval(i, j);
		collatz_print(w, i, j, v);}}
