/**
Filename: pcolor_driver.c (driver of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 30/10/2017
**/

#include <stdio.h>
#include "pcolor.h"
#include "pcolor.c"
int main() {
	printf("*****\n* ");
    print_red('R');
	printf(" *\n");
    print_green('G');
    print_magenta('M');
    print_cyan('C');
    print_yellow('Y');
    print_blue('B');
    printf("\n");
    return 0;
}
