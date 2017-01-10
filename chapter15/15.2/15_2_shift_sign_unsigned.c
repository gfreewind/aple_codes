/*
 * =====================================================================================
 *
 *       Filename:  15_2_shift_sign_unsigned.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/2017 06:35:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 0x80000000;
	unsigned int b = 0x80000000;

	printf("a right shift value is 0x%X\n", a >> 1);
	printf("b right shift value is 0x%X\n", b >> 1);

	return 0;
}
