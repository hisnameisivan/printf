#include "ft_printf.h"
#include <stdio.h>

int main(void)
 {
	ft_printf("%-5.1s is a string", "this");
	printf("\n%-5.1s is a string", "this");
	return (0);
 }
