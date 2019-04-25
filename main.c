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

	// printf("kol : %d\n", ft_printf("%#5.1o\n", 255));
	// printf("kol : %d\n", printf("%#5.1o\n", 255));
	// printf("kol : %d\n", ft_printf("%#o\n", 255));
	// printf("kol : %d\n", printf("%#o\n", 255));
	// printf("kol : %d\n", ft_printf("%#5.3o\n", 255));
	// printf("kol : %d\n", printf("%#5.3o\n", 255));
	// printf("kol : %d\n", ft_printf("%#5.4o\n", 255));
	// printf("kol : %d\n", printf("%#5.4o\n", 255));
	// printf("kol : %d\n", ft_printf("%#15.2o\n", 255));
	// printf("kol : %d\n", printf("%#15.2o\n", 255));
	//ft_printf("%-4.0x\n", 0);
	// printf("%#-4x\n", 0);
	// printf("%#-4x\n", 1);
	//ft_printf("%#x", 42);
	//ft_printf("%#8x", 42);
	// printf("@moulitest: %.u %.0u\n", 0, 0);
	// printf("@moulitest: %.d %.0d\n", 0, 0);
	// printf("01 : %#7.6x\n", 1024);
	// ft_printf("00 : %#7.6x\n", 1024);
	// printf("01 : %03o\n", 125);
	// printf("02 : %-+5.0i\n", 0);
	// printf("03 : %-+5.0o\n", 0);
	// printf("04 : %-+5.0u\n", 0);
	// printf("05 : %-+5.0x\n", 0);
	// printf("06 : %-+5.0X\n", 0);
	// printf("07 : %-+5.0d\n", 1);
	// printf("08 : %-+5.0i\n", 1);
	// printf("09 : %-+5.0o\n", 1);
	// printf("10 : %-+5.0u\n", 1);
	// printf("11 : %-+5.0x\n", 1);
	// printf("12 : %-+5.0X\n", 1);
	// printf("13 : %#.0d\n", 0);
	// printf("14 : %#.0i\n", 0);
	// printf("15 : %#.0o\n", 0);
	// printf("16 : %#.0u\n", 0);
	// printf("17 : %#.0x\n", 0);
	// printf("18 : %#.0X\n", 0);
	// printf("19 : %#.0d\n", 1);
	// printf("20 : %#.0i\n", 1);
	// printf("21 : %#.0o\n", 1);
	// printf("22 : %#.0u\n", 1);
	// printf("23 : %#.0x\n", 1);
	// printf("24 : %#.0X\n", 1);

	// printf("24 : %-#6.5X\n", 123);
	// printf("25 : %+10u\n", 0);
	
	// ft_printf("%.0d\n", 0);
	// ft_printf("%.0i\n", 0);
	// ft_printf("%.0o\n", 0);
	// ft_printf("%.0u\n", 0);
	// ft_printf("%.0x\n", 0);
	// ft_printf("%.0X\n", 0);
	// ft_printf("%.0d\n", 1);
	// ft_printf("%.0i\n", 1);
	// ft_printf("%.0o\n", 1);
	// ft_printf("%.0u\n", 1);
	// ft_printf("%.0x\n", 1);
	// ft_printf("%.0X\n", 1);
	// ft_printf("%#.1d\n", 0);
	// ft_printf("%#.0i\n", 0);
	// ft_printf("%#.0u\n", 0);
	// ft_printf("%#.0o\n", 0);
	// ft_printf("%#.6x\n", 0);
	// ft_printf("%#.0X\n", 0);
	// ft_printf("%#.0d\n", 1);
	// ft_printf("%#.0i\n", 1);
	// ft_printf("%#.0u\n", 1);
	// ft_printf("%#.0o\n", 1);
	// ft_printf("%#.0x\n", 1);
	// ft_printf("%#.0X\n", 1);

	// ft_printf("01 ft : %-.6x\n", 0);	/* точность да, минус да */
	//    printf("01 no : %-.6x\n", 0);
	// ft_printf("02 ft : %-x\n", 0);	/* точность нет, минус да */
	//    printf("02 no : %-x\n", 0);
	// ft_printf("03 ft : %-.0x\n", 0);	/* точность =0, минус да */ // fail
	//    printf("03 no : %-.0x\n", 0);
	// ft_printf("04 ft : %.6x\n", 0);	/* точность да, минус нет */
	//    printf("04 no : %.6x\n", 0);
	// ft_printf("05 ft : %x\n", 0);	/* точность нет, минус нет */
	//    printf("05 no : %x\n", 0);
	// ft_printf("06 ft : %.0x\n", 0);	/* точность =0, минус нет */ // fail
	//    printf("06 no : %.0x\n", 0);

	// ft_printf("01 ft : %-+7.d\n", 15);	/* точность =0, минус да, плюс да, num != 0 */
	//    printf("01 no : %-+7.d\n", 15);
	// ft_printf("02 ft : %-+7.d\n", 0);	/* точность =0, минус да, плюс да, num != 0 */ // fail
	//    printf("02 no : %-+7.d\n", 0);
	
	
	// ft_printf("01 != 0 ft : %-+8.0d\n", 123); 
	//    printf("01 != 0 no : %-+8.0d\n", 123);
	// ft_printf("01 == 0 ft : %-+8.0d\n", 0);
	//    printf("01 == 0 no : %-+8.0d\n", 0);
	// ft_printf("02 != 0 ft : %- 8.0d\n", 123);
	//    printf("02 != 0 no : %- 8.0d\n", 123);
	// ft_printf("02 == 0 ft : %- 8.0d\n", 0);
	//    printf("02 == 0 no : %- 8.0d\n", 0);
	// ft_printf("03 != 0 ft : %-8.0d\n", 123);
	//    printf("03 != 0 no : %-8.0d\n", 123);
	// ft_printf("03 == 0 ft : %-8.0d\n", 0);
	//    printf("03 == 0 no : %-8.0d\n", 0);
	// ft_printf("04 != 0 ft : %-+8.6d\n", 123);
	//    printf("04 != 0 no : %-+8.6d\n", 123);
	// ft_printf("04 == 0 ft : %-+8.6d\n", 0);
	//    printf("04 == 0 no : %-+8.6d\n", 0);
	// ft_printf("05 != 0 ft : %- 8.6d\n", 123);
	//    printf("05 != 0 no : %- 8.6d\n", 123);
	// ft_printf("05 == 0 ft : %- 8.6d\n", 0);
	//    printf("05 == 0 no : %- 8.6d\n", 0);
	// ft_printf("06 != 0 ft : %-8.6d\n", 123);
	//    printf("06 != 0 no : %-8.6d\n", 123);
	// ft_printf("06 == 0 ft : %-8.6d\n", 0);
	//    printf("06 == 0 no : %-8.6d\n", 0);
	// ft_printf("07 != 0 ft : %-+8d\n", 123);
	//    printf("07 != 0 no : %-+8d\n", 123);
	// ft_printf("07 == 0 ft : %-+8d\n", 0);
	//    printf("07 == 0 no : %-+8d\n", 0);
	// ft_printf("08 != 0 ft : %- 8d\n", 123);
	//    printf("08 != 0 no : %- 8d\n", 123);
	// ft_printf("08 == 0 ft : %- 8d\n", 0);
	//    printf("08 == 0 no : %- 8d\n", 0);
	ft_printf("09 != 0 ft : %-8d\n", 123);
	   printf("09 != 0 no : %-8d\n", 123);
	ft_printf("09 == 0 ft : %-8d\n", 0);
	   printf("09 == 0 no : %-8d\n", 0);
	return (0);
 }
