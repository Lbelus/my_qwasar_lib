#include "../../include/my_stdio.h"

//custom itoa that accept unsigned value accept integer overflow
//!= ctoi take a value and return a buffer. 
// ref ITOA : https://www.strudel.org.uk/itoa/

char* unsigned_itoa(unsigned long int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }

	char* ptr = result, *ptr1 = result, tmp_char = 0;
	unsigned long int tmp_value;
	
	// Translating number to string with base and storing it :
	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );
	*ptr-- = '\0';
  	my_revswap(ptr, ptr1, tmp_char);
	
	return result;
}