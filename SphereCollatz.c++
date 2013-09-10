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


// ------------
// Global
// ------------
int cycle_cache[100000000] = {0};

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
// collatz_cycle_length
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
	else {
		x = (3 * n + 1) / 2;
		previous_cycle = cycle_cache[x];
		if (previous_cycle == 0)
			return collatz_cycle_length(x) + 2;
		else
			return previous_cycle + 2;
	}
}


// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
	// <your code>
	cycle_cache[1] = 1;
	int temp;
	int max_cycle_num = 0;

	if (i > j)
	{
		temp = i;
		i = j;
		j = temp;
	}

	for ( int x = i; x <= j; x++) 
	{
		// value is in cache, use cache to find cycle length
		int current_cycle_num = cycle_cache[x];

		// value is not in cache, find cycle length and add it to cache
		if (current_cycle_num == 0)
		{
			cycle_cache[x] = collatz_cycle_length(x);
			current_cycle_num = cycle_cache[x];
		}

		// check if current_cycle_num > max_cycle_num
        if (current_cycle_num > max_cycle_num)
            max_cycle_num = current_cycle_num;

	}

	//int v = collatz_cycle_length(j);
	//assert(v > 0);
	return max_cycle_num;}

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

// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz
    % valgrind RunCollatz < RunCollatz.in > RunCollatz.out

To configure Doxygen:
    % doxygen -g
That creates the file "Doxyfile".
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    % doxygen Doxyfile
*/

// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
