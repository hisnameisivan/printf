#include "ft_printf.h"
#include <stdio.h>

int main(void)
 {
	//ft_printf("%-5.1s is a string", "this");
	//printf("\n%-5.1s is a string", "this");

	// ft_printf("%-5.1x\n", 255);
	// printf("%-5.1x\n", 255);
	// ft_printf("%-x\n", 255);
	// printf("%-x\n", 255);
	// ft_printf("%-5.3x\n", 255);
	// printf("%-5.3x\n", 255);
	// ft_printf("%-5.1X\n", 255);
	// printf("%-5.1X\n", 255);
	// ft_printf("%-5.4x\n", 255);
	// printf("%-5.4x\n", 255);
	// ft_printf("%-15.2x\n", 255);
	// printf("%-15.2x\n", 255);

	printf("kol : %d\n", ft_printf("%#5.1o\n", 255));
	printf("kol : %d\n", printf("%#5.1o\n", 255));
	printf("kol : %d\n", ft_printf("%#o\n", 255));
	printf("kol : %d\n", printf("%#o\n", 255));
	printf("kol : %d\n", ft_printf("%#5.3o\n", 255));
	printf("kol : %d\n", printf("%#5.3o\n", 255));
	printf("kol : %d\n", ft_printf("%#5.4o\n", 255));
	printf("kol : %d\n", printf("%#5.4o\n", 255));
	printf("kol : %d\n", ft_printf("%#15.2o\n", 255));
	printf("kol : %d\n", printf("%#15.2o\n", 255));
	ft_printf("%#x", 42);
	return (0);
 }
