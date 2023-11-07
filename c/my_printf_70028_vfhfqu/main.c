#include "include/my_stdio.h"
//#include <stdio.h>

int main(void){
    
    char t1 = 97;
    char t2[] = "This is a test @99, oh my! it do go down!";
    int t3 = -25;
    unsigned int t4 = -16;
    unsigned int t5 = -10;
    unsigned int t6 = -100;
    void *t7 = "aaaaa";
    void *t8 = "aaaaa";
    int f = 0;
    //int g = 0;


    for(int i =0; i < 100;i++){
        f +=  my_printf("my_printf : char : %c,\n string : %s,\n deci : %d,\n octa : %o,\n un : %u,\n ex : %x,\n void : %p,\n void : %p,\n", t1, t2, t3, t4, t5, t6, t7, t8);
        //g += printf("QQQprintf : char : %c,\n string : %s,\n deci : %d,\n octa : %o,\n un : %u,\n ex : %x,\n void : %p,\n void : %p,\n", t1, t2, t3, t4, t5, t6, t7, t8);
    }

    //my_puts(t2);


    //my_printf("%s",t2);
    //char t2[] = "T";
    //int f = 0;
    //int g = 0;
    //void *t8 = "aaaaa";
    //printf("hello world!");
    //my_printf("%d", sizeof(my_printf("hello world!")));
    //f += printf("hello world!");
    //char *n = (char*)NULL;
     
     //printf("%lu", sizeof(NULL));
     //my_printf("NULL sSTRING %s!\n", (char*)NULL);
     //my_printf("NULL sSTRING %s!\n", "h");
     //printf("NULL sSTRING %p!\n", NULL);
    //printf("NULL sSTRING %s!\n", (char*)NULL);
    //f += my_printf("NULL STRING %s!\n", (char*)NULL); 
    //g += printf("NULL STRING %s!\n", (char*)NULL);

    my_printf("%d ", f);
    //printf("%d ", g);
    return 0;
}