#include "../../include/my_stdio.h"

	//!= ctoi take a value and return a buffer. 

    // ref ITOA : https://www.strudel.org.uk/itoa/
	char* their_itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char = 0;
		int tmp_value;

		// Translating number to string with base and storing it:
		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		
		my_revswap(ptr, ptr1, tmp_char);
		
		return result;
	}