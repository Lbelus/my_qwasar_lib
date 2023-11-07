#include "../../include/my_stdio.h"

void my_revswap(char *ptr, char*ptr1, char tmp_char) {
    while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
}