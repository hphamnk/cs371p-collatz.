// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream

// ------------
// collatz_read
// ------------

/**
 * reads two ints into i and j
 * @param r a  std::istream
 * @param i an int by reference
 * @param j an int by reference
 * @return true if that succeeds, false otherwise
 */
bool collatz_read (std::istream&, int&, int&);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param swap i and j if j is smaller than i
 * @param for loop from i to j
 * @param 	if cycle for an element is not in cache, call collatz_cycle_length and save it to cache 
 * @param 	if cycle is in cache, save to current_cycle_num
 * @param	compare current_cycle_num to max_cycle_num, if current > max, set max to current
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int, int);

// -------------
// collatz_cycle_length
// -------------

/**
 * read 1 int into n
 * @param finds cycle length of n
 * @param if n is 1, return 1
 * @param if n is even, do n/2
 * @param 	if n/2 is in cache and smaller than 100001, get the cycle length from cache
 * @param 	else call collatz_cycle_length recursively and +1 to that
 * @param if n is odd, do (3*n +1) /2
 * @param 	if (3*n +1) /2 is in cache and smaller than 100001, get the cycle length from cache
 * @param 	else call collatz_cycle_length recursively and +2 to that
 */
int collatz_cycle_length (int);

// -------------
// collatz_print
// -------------

/**
 * prints the values of i, j, and v
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream&, int, int, int);

// -------------
// collatz_solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void collatz_solve (std::istream&, std::ostream&);

#endif // Collatz_h
