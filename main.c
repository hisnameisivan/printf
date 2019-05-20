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
	// ft_printf("01 : %-+5.0d\n", 0);
	// ft_printf("02 : %-+5.0i\n", 0);
	// ft_printf("03 : %-+5.0o\n", 0);
	// ft_printf("04 : %-+5.0u\n", 0);
	// ft_printf("05 : %-+5.0x\n", 0);
	// ft_printf("06 : %-+5.0X\n", 0);
	// ft_printf("07 : %-+5.0d\n", 1);
	// ft_printf("08 : %-+5.0i\n", 1);
	// ft_printf("09 : %-+5.0o\n", 1);
	// ft_printf("10 : %-+5.0u\n", 1);
	// ft_printf("11 : %-+5.0x\n", 1);
	// ft_printf("12 : %-+5.0X\n", 1);
	// ft_printf("13 : %#.0d\n", 0);
	// ft_printf("14 : %#.0i\n", 0);
	// ft_printf("15 : %#.0o\n", 0);
	// ft_printf("16 : %#.0u\n", 0);
	// ft_printf("17 : %#.0x\n", 0);
	// ft_printf("18 : %#.0X\n", 0);
	// ft_printf("19 : %#.0d\n", 1);
	// ft_printf("20 : %#.0i\n", 1);
	// ft_printf("21 : %#.0o\n", 1);
	// ft_printf("22 : %#.0u\n", 1);
	// ft_printf("23 : %#.0x\n", 1);
	// ft_printf("24 : %#.0X\n", 1);

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
	// ft_printf("09 != 0 ft : %-8d\n", 123);
	//    printf("09 != 0 no : %-8d\n", 123);
	// ft_printf("09 == 0 ft : %-8d\n", 0);
	//    printf("09 == 0 no : %-8d\n", 0);

	// ft_printf("ft : %08d:\n", 123);
	//    printf("no : %08d:\n", 123);
	// ft_printf("ft : % 08d:\n", 123);
	//    printf("no : % 08d:\n", 123);
	// ft_printf("ft : % 08.6d:\n", 123);
	//    printf("no : % 08.6d:\n", 123);
	// ft_printf("ft : %08.6d:\n", 123);
	//    printf("no : %08.6d:\n", 123);

	// printf("01 stroka: %-+8.6d\n", -123);
	// ft_printf("01 stroka: %-+8.6d\n", -123);
	// printf("02 stroka: % -+8.6d\n", -123);
	// ft_printf("02 stroka: % -+8.6d\n", -123);
	// printf("03 stroka: %-+8.6d\n", 123);
	// ft_printf("03 stroka: %-+8.6d\n", 123);
	// printf("04 stroka: % -+8.6d\n", 123);
	// ft_printf("04 stroka: % -+8.6d\n", 123);
	// printf("05 stroka: %-8.6d\n", 123);
	// ft_printf("05 stroka: %-8.6d\n", 123);
	// printf("06 stroka: % -8.6d\n", 123);
	// ft_printf("06 stroka: % -8.6d\n", 123);
	// printf("07 stroka: %+8.6d\n", -123);
	// ft_printf("07 stroka: %+8.6d\n", -123);
	// printf("08 stroka: % +8.6d\n", -123);
	// ft_printf("08 stroka: % +8.6d\n", -123);
	// printf("09 stroka: %+8.6d\n", 123);
	// ft_printf("09 stroka: %+8.6d\n", 123);
	// printf("10 stroka: % +8.6d\n", 123);
	// ft_printf("10 stroka: % +8.6d\n", 123);
	// printf("11 stroka: %8.6d\n", 123);
	// ft_printf("11 stroka: %8.6d\n", 123);
	// printf("12 stroka: % 8.6d\n", 123);
	// ft_printf("12 stroka: % 8.6d\n", 123);
	// printf("13 stroka: %+8d\n", -123);
	// ft_printf("13 stroka: %+8d\n", -123);
	// printf("14 stroka: % +8d\n", -123);
	// ft_printf("14 stroka: % +8d\n", -123);
	// printf("15 stroka: %8.6d\n", 123);
	// ft_printf("15 stroka: %8.6d\n", 123);
	// printf("16 stroka: % 8.6d\n", 123);
	// ft_printf("16 stroka: % 8.6d\n", 123);
	// printf("17 stroka: %+ 8.6d\n", 123);
	// ft_printf("17 stroka: %+ 8.6d\n", 123);
	// printf("18 stroka: % 8.6 d\n", 123);
	// ft_printf("18 stroka: % 8.6 d\n", 123);
	// printf("19 stroka: %      8d\n", -123);
	// ft_printf("19 stroka: %      8d\n", -123);
	// printf("20 stroka: % 8.6d\n", 123);
	// ft_printf("20 stroka: % 8.6d\n", 123);
	// printf("21 stroka: % d\n", -123);
	// ft_printf("21 stroka: % d\n", -123);
	// printf("22 stroka: %      d\n", -123);
	// ft_printf("22 stroka: %      d\n", -123);
	// printf("23 stroka: %08.6d\n", 123);
	// ft_printf("23 stroka: %08.6d\n", 123);
	// printf("24 stroka: %-010d\n", 123);
	// ft_printf("24 stroka: %-010d\n", 123);
	// printf("25 stroka: % 010d\n", 123);
	// ft_printf("25 stroka: % 010d\n", 123);
	// printf("26 stroka: % 010.5d\n", 123);
	// ft_printf("26 stroka: % 010.5d\n", 123);
	// printf("27 stroka: %9 0d\n", 123);
	// ft_printf("27 stroka: %9 0d\n", 123);
	// printf("28 stroka: %9d\n", 123);
	// ft_printf("28 stroka: %9d\n", 123);
	// printf("29 stroka: % 08.6d\n", 123);
	// ft_printf("29 stroka: % 08.6d\n", 123);
	// printf("30 stroka: % 06d\n", 123);
	// ft_printf("30 stroka: % 06d\n", 123);
	// printf("31 stroka: %+08.6d\n", 123);
	// ft_printf("31 stroka: %+08.6d\n", 123);
	// // printf("32 stroka: % 15s\n", "privet");
	// // ft_printf("32 stroka: % 15s\n", "privet");
	// // printf("33 stroka: % c\n", 'c');
	// // ft_printf("33 stroka: % c\n", 'c');
	// printf("34 stroka: % 08.6hhd\n", (char)128);
	// ft_printf("34 stroka: % 08.6hhd\n", (char)128);
	// printf("35 stroka: % 06hhd\n", (char)212);
	// ft_printf("35 stroka: % 06hhd\n", (char)212);
	// printf("36 stroka: %+08.6hhd\n", (char)212);
	// ft_printf("36 stroka: %+08.6hhd\n", (char)212);
	// ft_printf("37 stroka: % 1.2d\n", -1);
	// printf("37 stroka: % 1.2d\n", -1);
	// printf("38 stroka: %9.5d\n", 345);
	// ft_printf("38 stroka: %9.5d\n", 345);

	//printf("%#08x", 255);
	//ft_printf("%#x", 42);

	// printf("%0.0d\n", 0);
	//printf("%08.5x\n", 255);

	// ft_printf("%lllllhhhhhhhd\n", 145577434352);
	// double x = 15.9;
	// int z;

	// z = (int)x;
	// printf("\n%d\n", z);
	// x = x - z;
	// printf("\n%f\n", x);

	// ft_printf("stroka 01: %-+5.0f\n", 0.);
	// ft_printf("stroka 02: %- 5.0f\n", 0.);
	// ft_printf("stroka 03: %-5.0f\n", 0.);
	// ft_printf("stroka 04: %-+5f\n", 0.);
	// ft_printf("stroka 05: %- 5f\n", 0.);
	// ft_printf("stroka 06: %-5f\n", 0.);
	// ft_printf("stroka 71: %+5.0f\n", 0.);
	// ft_printf("stroka 72: % 5.0f\n", 0.);
	// ft_printf("stroka 08: %5.0f\n", 0.);


	// ft_printf("stroka 09: %+05f\n", 0.);
	// ft_printf("stroka 10: %+5f\n", 0.);
	// ft_printf("stroka 11: % 05f\n", 0.);
	// ft_printf("stroka 12: %05f\n", 0.);
	// ft_printf("stroka 13: % 5f\n", 0.);
	// ft_printf("stroka 14: %5f\n", 0.);

	// ft_printf("stroka 01: %#-+5.0f\n", 0.);
	// ft_printf("stroka 02: %#- 5.0f\n", 0.);
	// ft_printf("stroka 03: %#-5.0f\n", 0.);
	// ft_printf("stroka 04: %#-+5f\n", 0.);
	// ft_printf("stroka 05: %#- 5f\n", 0.);
	// ft_printf("stroka 06: %#-5f\n", 0.);
	// ft_printf("stroka 71: %#+5.0f\n", 0.);
	// ft_printf("stroka 72: %# 5.0f\n", 0.);
	// ft_printf("stroka 08: %#5.0f\n", 0.);


	// ft_printf("stroka 09: %#+05f\n", 0.);
	// ft_printf("stroka 10: %#+5f\n", 0.);
	// ft_printf("stroka 11: %# 05f\n", 0.);
	// ft_printf("stroka 12: %#05f\n", 0.);
	// ft_printf("stroka 13: %# 5f\n", 0.);
	// ft_printf("stroka 14: %#5f\n", 0.);

	// int main(void)
// {
// 	/* тесты для десятичной записи */

// 	// printf("01 stroka: %-+8.6d\n", -123);
	// ft_printf("01 stroka: %-+8.6d\n", -123);
	// printf("02 stroka: % -+8.6d\n", -123);
	// ft_printf("02 stroka: % -+8.6d\n", -123);
	// printf("03 stroka: %-+8.6d\n", 123);
	// ft_printf("03 stroka: %-+8.6d\n", 123);
	// printf("04 stroka: % -+8.6d\n", 123);
	// ft_printf("04 stroka: % -+8.6d\n", 123);
	// printf("05 stroka: %-8.6d\n", 123);
	// ft_printf("05 stroka: %-8.6d\n", 123);
	// printf("06 stroka: % -8.6d\n", 123);
	// ft_printf("06 stroka: % -8.6d\n", 123);
	// printf("07 stroka: %+8.6d\n", -123);
	// ft_printf("07 stroka: %+8.6d\n", -123);
	// printf("08 stroka: % +8.6d\n", -123);
	// ft_printf("08 stroka: % +8.6d\n", -123);
	// printf("09 stroka: %+8.6d\n", 123);
	// ft_printf("09 stroka: %+8.6d\n", 123);
	// printf("10 stroka: % +8.6d\n", 123);
	// ft_printf("10 stroka: % +8.6d\n", 123);
	// printf("11 stroka: %8.6d\n", 123);
	// ft_printf("11 stroka: %8.6d\n", 123);
	// printf("12 stroka: % 8.6d\n", 123);
	// ft_printf("12 stroka: % 8.6d\n", 123);
	// printf("13 stroka: %+8d\n", -123);
	// ft_printf("13 stroka: %+8d\n", -123);
	// printf("14 stroka: % +8d\n", -123);
	// ft_printf("14 stroka: % +8d\n", -123);
	// printf("15 stroka: %8.6d\n", 123);
	// ft_printf("15 stroka: %8.6d\n", 123);
	// printf("16 stroka: % 8.6d\n", 123);
	// ft_printf("16 stroka: % 8.6d\n", 123);
	// printf("17 stroka: %+ 8.6d\n", 123);
	// ft_printf("17 stroka: %+ 8.6d\n", 123);
	// printf("18 stroka: % 8.6 d\n", 123);
	// ft_printf("18 stroka: % 8.6 d\n", 123);
	// printf("19 stroka: %      8d\n", -123);
	// ft_printf("19 stroka: %      8d\n", -123);
	// printf("20 stroka: % 8.6d\n", 123);
	// ft_printf("20 stroka: % 8.6d\n", 123);
	// printf("21 stroka: % d\n", -123);
	// ft_printf("21 stroka: % d\n", -123);
	// printf("22 stroka: %      d\n", -123);
	// ft_printf("22 stroka: %      d\n", -123);
	// printf("23 stroka: %08.6d\n", 123);
	// ft_printf("23 stroka: %08.6d\n", 123);
	// printf("24 stroka: %-010d\n", 123);
	// ft_printf("24 stroka: %-010d\n", 123);
	// printf("25 stroka: % 010d\n", 123);
	// ft_printf("25 stroka: % 010d\n", 123);
	// printf("26 stroka: % 010.5d\n", 123);
	// ft_printf("26 stroka: % 010.5d\n", 123);
	// printf("27 stroka: %9 0d\n", 123);
	// ft_printf("27 stroka: %9 0d\n", 123);
	// printf("28 stroka: %9d\n", 123);
	// ft_printf("28 stroka: %9d\n", 123);
	// printf("29 stroka: % 08.6d\n", 123);
	// ft_printf("29 stroka: % 08.6d\n", 123);
	// printf("30 stroka: % 06d\n", 123);
	// ft_printf("30 stroka: % 06d\n", 123);
	// printf("31 stroka: %+08.6d\n", 123);
	// ft_printf("31 stroka: %+08.6d\n", 123);
	// printf("32 stroka: % 15s\n", "privet");
	// ft_printf("32 stroka: % 15s\n", "privet");
	// printf("33 stroka: % c\n", 'c');
	// ft_printf("33 stroka: % c\n", 'c');
	// printf("34 stroka: % 08.6hhd\n", (char)128);
	// ft_printf("34 stroka: % 08.6hhd\n", (char)128);
	// printf("35 stroka: % 06hhd\n", (char)212);
	// ft_printf("35 stroka: % 06hhd\n", (char)212);
	// printf("36 stroka: %+08.6hhd\n", (char)212);
	// ft_printf("36 stroka: %+08.6hhd\n", (char)212);
	// ft_printf("37 stroka: % 1.2d\n", -1);
	// printf("37 stroka: % 1.2d\n", -1);
	// printf("38 stroka: %9.5d\n", 345);
	// ft_printf("38 stroka: %9.5d\n", 345);

	/* тесты для восьмиричной записи */

	// printf("01 stroka: %-+8.6o\n", -123);
	// ft_printf("01 stroka: %-+8.6o\n", -123);
    // printf("02 stroka: % -+8.6o\n", -123);
	// ft_printf("02 stroka: % -+8.6o\n", -123);
	// printf("03 stroka: %-+8.6o\n", 123);
	// ft_printf("03 stroka: %-+8.6o\n", 123);
	// printf("04 stroka: % -+8.6o\n", 123);
	// ft_printf("04 stroka: % -+8.6o\n", 123);
	// printf("05 stroka: %-8.6o\n", 123);
	// ft_printf("05 stroka: %-8.6o\n", 123);
	// printf("06 stroka: % -8.6o\n", 123);
	// ft_printf("06 stroka: % -8.6o\n", 123);
	// printf("07 stroka: %+8.6o\n", -123);
	// ft_printf("07 stroka: %+8.6o\n", -123);
	// printf("08 stroka: % +8.6o\n", -123);
	// ft_printf("08 stroka: % +8.6o\n", -123);
	// printf("09 stroka: %+8.6o\n", 123);
	// ft_printf("09 stroka: %+8.6o\n", 123);
	// printf("10 stroka: % +8.6o\n", 123);
	// ft_printf("10 stroka: % +8.6o\n", 123);
	// printf("11 stroka: %8.6o\n", 123);
	// ft_printf("11 stroka: %8.6o\n", 123);
	// printf("12 stroka: % 8.6o\n", 123);
	// ft_printf("12 stroka: % 8.6o\n", 123);
	// printf("13 stroka: %+8o\n", -123);
	// ft_printf("13 stroka: %+8o\n", -123);
	// printf("14 stroka: % +8o\n", -123);
	// ft_printf("14 stroka: % +8o\n", -123);
	// printf("15 stroka: %8.6o\n", 123);
	// ft_printf("15 stroka: %8.6o\n", 123);
	// printf("16 stroka: % 8.6o\n", 123);
	// ft_printf("16 stroka: % 8.6o\n", 123);
	// printf("17 stroka: %+ 8.6o\n", 123);
	// ft_printf("17 stroka: %+ 8.6o\n", 123);
	// printf("18 stroka: % 8.6 o\n", 123);
	// ft_printf("18 stroka: % 8.6 o\n", 123);
	// printf("19 stroka: %      15o\n", -123);
	// ft_printf("19 stroka: %      15o\n", -123);
	// printf("20 stroka: % 8.6o\n", 123);
	// ft_printf("20 stroka: % 8.6o\n", 123);
	// printf("21 stroka: % o\n", -123);
	// ft_printf("21 stroka: % o\n", -123);
	// printf("22 stroka: %      o\n", -123);
	// ft_printf("22 stroka: %      o\n", -123);
	// printf("23 stroka: %08.6o\n", 123);
	// ft_printf("23 stroka: %08.6o\n", 123);
	// printf("24 stroka: %-010o\n", 123);
	// ft_printf("24 stroka: %-010o\n", 123);
	// printf("25 stroka: % 010o\n", 123);
	// ft_printf("25 stroka: % 010o\n", 123);
	// printf("26 stroka: % 010.5o\n", 123);
	// ft_printf("26 stroka: % 010.5o\n", 123);
	// printf("27 stroka: %9 0o\n", 123);
	// ft_printf("27 stroka: %9 0o\n", 123);
	// printf("28 stroka: %9o\n", 123);
	// ft_printf("28 stroka: %9o\n", 123);
	// printf("29 stroka: % 08.6o\n", 123);
	// ft_printf("29 stroka: % 08.6o\n", 123);
	// printf("30 stroka: % 06o\n", 123);
	// ft_printf("30 stroka: % 06o\n", 123);
	// printf("31 stroka: %+08.6o\n", 123);
	// ft_printf("31 stroka: %+08.6o\n", 123);
	// printf("32 stroka: % 15s\n", "privet");
	// ft_printf("32 stroka: % 15s\n", "privet");
	// printf("33 stroka: % c\n", 'c');
	// ft_printf("33 stroka: % c\n", 'c');
	// printf("34 stroka: % 08.6hho\n", (char)128);
	// ft_printf("34 stroka: % 08.6hho\n", (char)128);
	// printf("35 stroka: % 06hho\n", (char)212);
	// ft_printf("35 stroka: % 06hho\n", (char)212);
	// printf("36 stroka: %+08.6hho\n", (char)212);
	// ft_printf("36 stroka: %+08.6hho\n", (char)212);
	// printf("37 stroka: % 1.2o\n", -1);
	// ft_printf("37 stroka: % 1.2o\n", -1);
	// printf("38 stroka: % -8hho\n", (char)255);
	// ft_printf("38 stroka: % -8hho\n", (char)255);
	// printf("39 stroka: % -8hho\n", (char)255);
	// ft_printf("39 stroka: % -8hho\n", (char)255);
	// printf("40 stroka: %9.5o\n", 345);
	// ft_printf("40 stroka: %9.5o\n", 345);

	/* тесты для char */

	// char	ch = 'x';
	// printf("kolichestvo %d\n", printf("01 stroka: %c\n", ch));
	// printf("kolichestvo %d\n", ft_printf("01 stroka: %c\n", ch));
	// printf("kolichestvo %d\n", printf("02 stroka: %15.6c\n", ch));
	// printf("kolichestvo %d\n", ft_printf("02 stroka: %15.6c\n", ch));
	// printf("kolichestvo %d\n", printf("03 stroka: %-15c\n", ch));
	// printf("kolichestvo %d\n", ft_printf("03 stroka: %-15c\n", ch));
	// printf("kolichestvo %d\n", printf("04 stroka: % -15c\n", ch));
	// printf("kolichestvo %d\n", ft_printf("04 stroka: % -15c\n", ch));
	// printf("kolichestvo %d\n", printf("05 stroka: % -015c\n", ch));
	// printf("kolichestvo %d\n", ft_printf("05 stroka: % -015c\n", ch));

	/* тесты для string */

	// char	*str = "hello";
	// printf("kolichestvo %d\n", printf("01 stroka: %s\n", str));
	// printf("kolichestvo %d\n", ft_printf("01 stroka: %s\n", str));
	// printf("kolichestvo %d\n", printf("02 stroka: %15.6s\n", str));
	// printf("kolichestvo %d\n", ft_printf("02 stroka: %15.6s\n", str));
	// printf("kolichestvo %d\n", printf("03 stroka: %-15s\n", str));
	// printf("kolichestvo %d\n", ft_printf("03 stroka: %-15s\n", str));
	// printf("kolichestvo %d\n", printf("04 stroka: % -15s\n", str));
	// printf("kolichestvo %d\n", ft_printf("04 stroka: % -15s\n", str));
	// printf("kolichestvo %d\n", printf("05 stroka: % -015s\n", str));
	// printf("kolichestvo %d\n", ft_printf("05 stroka: % -015s\n", str));

	/* тесты для pointer */

	// char	*str = "hello";
	// printf("kolichestvo %d\n", printf("01 stroka: %p\n", str));
	// printf("kolichestvo %d\n", ft_printf("01 stroka: %p\n", str));
	// printf("kolichestvo %d\n", printf("02 stroka: %15.6p\n", str));
	// printf("kolichestvo %d\n", ft_printf("02 stroka: %15.6p\n", str));
	// printf("kolichestvo %d\n", printf("03 stroka: %-15p\n", str));
	// printf("kolichestvo %d\n", ft_printf("03 stroka: %-15p\n", str));
	// printf("kolichestvo %d\n", printf("04 stroka: % -15p\n", str));
	// printf("kolichestvo %d\n", ft_printf("04 stroka: % -15p\n", str));
	// printf("kolichestvo %d\n", printf("05 stroka: % -015p\n", str));
	// printf("kolichestvo %d\n", ft_printf("05 stroka: % -015p\n", str));

	/* тесты для count */

	// printf("kolichestvo %d\n", printf("01 stroka: %-+8.6d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("01 stroka: %-+8.6d\n", -123));
	// printf("kolichestvo %d\n", printf("02 stroka: % -+8.6d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("02 stroka: % -+8.6d\n", -123));
	// printf("kolichestvo %d\n", printf("03 stroka: %-+8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("03 stroka: %-+8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("04 stroka: % -+8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("04 stroka: % -+8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("05 stroka: %-8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("05 stroka: %-8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("06 stroka: % -8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("06 stroka: % -8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("07 stroka: %+8.6d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("07 stroka: %+8.6d\n", -123));
	// printf("kolichestvo %d\n", printf("08 stroka: % +8.6d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("08 stroka: % +8.6d\n", -123));
	// printf("kolichestvo %d\n", printf("09 stroka: %+8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("09 stroka: %+8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("10 stroka: % +8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("10 stroka: % +8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("11 stroka: %8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("11 stroka: %8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("12 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("12 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("13 stroka: %+8d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("13 stroka: %+8d\n", -123));
	// printf("kolichestvo %d\n", printf("14 stroka: % +8d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("14 stroka: % +8d\n", -123));
	// printf("kolichestvo %d\n", printf("15 stroka: %8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("15 stroka: %8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("16 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("16 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("17 stroka: %+ 8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("17 stroka: %+ 8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("18 stroka: % 8.6 d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("18 stroka: % 8.6 d\n", 123));
	// printf("kolichestvo %d\n", printf("19 stroka: %      8d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("19 stroka: %      8d\n", -123));
	// printf("kolichestvo %d\n", printf("20 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("20 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("21 stroka: % d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("21 stroka: % d\n", -123));
	// printf("kolichestvo %d\n", printf("22 stroka: %      d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("22 stroka: %      d\n", -123));
	// printf("kolichestvo %d\n", printf("23 stroka: %08.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("23 stroka: %08.6d\n", 123));
	// printf("kolichestvo %d\n", printf("24 stroka: %-010d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("24 stroka: %-010d\n", 123));
	// printf("kolichestvo %d\n", printf("25 stroka: % 010d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("25 stroka: % 010d\n", 123));
	// printf("kolichestvo %d\n", printf("26 stroka: % 010.5d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("26 stroka: % 010.5d\n", 123));
	// printf("kolichestvo %d\n", printf("27 stroka: %9 0d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("27 stroka: %9 0d\n", 123));
	// printf("kolichestvo %d\n", printf("28 stroka: %9d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("28 stroka: %9d\n", 123));
	// printf("kolichestvo %d\n", printf("29 stroka: % 08.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("29 stroka: % 08.6d\n", 123));
	// printf("kolichestvo %d\n", printf("30 stroka: % 06d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("30 stroka: % 06d\n", 123));
	// printf("kolichestvo %d\n", printf("31 stroka: %+08.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("31 stroka: %+08.6d\n", 123));
	// printf("kolichestvo %d\n", printf("32 stroka: % 15s\n", "privet"));
	// printf("kolichestvo %d\n", ft_printf("32 stroka: % 15s\n", "privet"));
	// printf("kolichestvo %d\n", printf("33 stroka: % c\n", 'c'));
	// printf("kolichestvo %d\n", ft_printf("33 stroka: % c\n", 'c'));
	// printf("kolichestvo %d\n", printf("34 stroka: % 08.6hhd\n", (char)128));
	// printf("kolichestvo %d\n", ft_printf("34 stroka: % 08.6hhd\n", (char)128));
	// printf("kolichestvo %d\n", printf("35 stroka: % 06hhd\n", (char)212));
	// printf("kolichestvo %d\n", ft_printf("35 stroka: % 06hhd\n", (char)212));
	// printf("kolichestvo %d\n", printf("36 stroka: %+08.6hhd\n", (char)212));
	// printf("kolichestvo %d\n", ft_printf("36 stroka: %+08.6hhd\n", (char)212));
	// printf("kolichestvo %d\n", ft_printf("37 stroka: % 1.2d\n", -1));
	// printf("kolichestvo %d\n", printf("37 stroka: % 1.2d\n", -1));
	// printf("kolichestvo %d\n", printf("38 stroka: %9.5d\n", 345));
	// printf("kolichestvo %d\n", ft_printf("38 stroka: %9.5d\n", 345));
	// ft_printf("%.0d\n", 0);
	// ft_printf("%.0x\n", 0);
	// ft_printf("%.0o\n", 0);
	// ft_printf("%.0x\n", 0);
	// ft_printf("%#.0d\n", 0);
	// ft_printf("%#.0x\n", 0);
	// ft_printf("%#.0o\n", 0);
	// ft_printf("%#.0x\n", 0);
// 	ft_printf("01 %#hhx\n", (char)256);
// 	ft_printf("02 %hh#x\n", (char)256);
// 	printf("04 %#hhx\n", (char)256);
// 	printf("05 %hh#x\n", (char)256);
// 	printf("%%\n");
// 	printf("%5%\n");
// 	printf("%-5%\n");
// 	printf("%.0%\n");

	//printf("\n#0074\n");
	// ft_printf("%.2c", NULL);
	// ft_printf("%.2c", 0);
	// printf("\n#0075\n");
	// printf("%s %s", NULL, "string");
	// printf("\n#0079\n");
	// printf("@moulitest: %c", 0);
	// printf("\n#0080\n");
	// printf("%2c", 0);
	// printf("\n#0081\n");
	// printf("null %c and text", 0);
	// printf("\n#0082\n");
	// printf("% c", 0);
	//ft_printf("%+d\n", 0);
	//ft_printf("%+0d\n", 0);
	//printf("%+0d\n", 0);
	//ft_printf("%#8x\n", 0);
	//printf("%#8x\n", 0);
	// ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	//printf("@moulitest: %#.o %#.0o\n", 0, 0);
	//printf("@moulitest: %#.x %#.0x", 0, 0);
	//ft_printf("%.o\n", 0);
	//printf("%#.x\n", 0);
	//printf("%#.0o\n", 0);

	// printf("%d\n", printf("%llu\n", (long long)-42));
	// ft_printf("%d\n",ft_printf("%llu\n", (long long)-42));

	// ft_printf("%d\n", ft_printf("%.8s\n", "hello"));
	// printf("%d\n", printf("%.8s\n", "hello"));
	//float nb = -0.00;
	//ft_printf("%-+10.14f\n", nb);
// 	//printf("original %-+10.14f\n", nb);
// 	// ft_printf("\n%d\n", -100);

// 	ft_printf("%023i\n", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN);
// 	printf("%023i", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN);
// 	ft_printf("%hd", (char)-32768);
// 	printf("\n%hd", (char)-32768);
// 	ft_printf("ft %03.2d\n", 0);
// 	printf("za %03.2d", 0);
// 	 ft_printf("%15.8f\n", -0.);
// 	printf("%15.8f\n", -0.);
// 	ft_printf("%f|%-f|%+f|% f|%#f|%0f\n", 0., 0., 0., 0., 0., 0.);
// 	printf("%f|%-f|%+f|% f|%#f|%0f\n", 0., 0., 0., 0., 0., 0.);
// 	ft_printf("%4f|%-f|%+f|% f|%#f|%0f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);
// 	printf("%1f|%-f|%+f|% f|%#f|%0f", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);
// 	return (0);
// }
	//printf("%f|%-f|%+f|% f|%#f|%0f\n", 1.0 / 0.0, 1.0 / 0.0, 1.0 / 0.0, 1.0 / 0.0, 1.0 / 0.0, 1.0 / 0.0);
	//ft_printf("%f|%-f|%+f|% f|%#f|%0f\n", 1.0 / 0.0, 1.0 / 0.0, 1.0 / 0.0, 1.0 / 0.0, 1.0 / 0.0, 1.0 / 0.0);

	// ft_printf("%.f|%.f|%.f|%.f|%.f\n", 44.5001, 44.4, 44.6, 44.50001, 44.5 + 1e-52);
	// printf("%.f|%.f|%.f|%.f|%.f", 44.500001, 44.4, 44.6, 44.50001, 44.5 + 1e-14);

	// ft_printf("%o%o%o%o%o", 1, 100, 999, 42, 999988888);
	// printf("\n");
	// printf("%o%o%o%o%o", 1, 100, 999, 42, 999988888);
	//printf("% \n");
	//printf("% Zoo");
	//char	*s = "3456789#%\n";

	// ft_printf("%010s is a string", "this");
	// printf("\n");
	// printf("%010s is a string", "this");
	//ft_printf("% 123Z\n");

	//ft_printf("%jx\n", -4294967295);
	//printf("%jx\n", -4294967295);
	//printf("% Zoooo\n");
	//printf("\n");
	//ft_printf("% Zoooo");
	//ft_printf("%hhU\n", -1);
	// ft_printf("%jx", -42949672997);
	// printf("\n");
	// printf("%jx", -4294967297);

	// printf("\n");
	// ft_printf("%zd", 4294967295);
	// printf("\n");
	// printf("%zd", 4294967295);
	// printf("%h-hhd", 128);
	// printf("\n");
	// printf("%jhd", 9223372036854775809);
	//ft_printf("%S", L"Á±≥");
	//printf("%d\n", ft_printf("%o%o%o%o%o", 1, 100, 999, 42, 999988888));
	//int x = printf("%o%o%o%o%o", 1, 100, 999, 42, 999988888);
	//printf("\n");
	//printf("%d\n", x);

	// ft_printf("%d\n",ft_printf("%o%o%o%o%o\n", 1, 100, 999, 42, 999988888));
	// ft_printf("%llo, %llo", 0, ULLONG_MAX);
	// printf("\n");
	// printf("%llo, %llo", 0, ULLONG_MAX);
	// printf("\n");
	// ft_printf("%.4o", 424242);
	// printf("\n");
	// printf("%.4o", 424242);
	// printf("\n");
	// ft_printf("%o, %ho, %hho", -42, -42, -42);
	// printf("\n");
	// printf("%o, %ho, %hho", -42, -42, -42);

	//printf("%p", 123);
	//printf("%4.0s", "42");
	// ft_printf("%23.50s|%-23.5s|%-23.50s", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84");
	// printf("\n");
	// printf("%23.50s|%-23.5s|%-23.50s", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84", "xF0x9Fx98x84");

	// ft_printf("%jx", -2294967295);
	// printf("\n");
	// printf("%jx", -2294967295);
	// ft_printf("%jx", -4294967297);
	// printf("%jx", -4294967297);
	// ft_printf("%jx", -11111111126);
	// printf("\n");
	// printf("%jx", -11111111126);
	// int x = -11111111126;
	// int	y = (unsigned long)x;
	// ft_printf("%jx", y);
	// printf("\n");
	// printf("%jx", y);

	// ft_printf("%jo, %jo", 0, ULLONG_MAX);
	// printf("\n");
	// printf("%jo, %jo", 0, ULLONG_MAX);
	// ft_printf("%zu, %zu", 0, ULLONG_MAX);
	// printf("\n");
	// printf("%zu, %zu", 0, ULLONG_MAX);

	// ft_printf("%U", ULONG_MAX);
	// printf("\n");
	// printf("%U", ULONG_MAX);

	// ft_printf("{%05.s}", 0);
	// printf("\n");
	// printf("{%05.s}", 0);

	// ft_printf("%U", ULONG_MAX);
	// printf("\n");
	// ft_printf("%jU", ULONG_MAX);

	// ft_printf("%23.50s|%-23.5s|%-23.50s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	// printf("\n");
	// printf("%23.50s|%-23.5s|%-23.50s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	//ft_printf("%10.1 f", 35);
	// ft_printf("@main_ftprintf: %###-#0000 33.12..#0+0d\n", 256);
	// printf("@main_printf: %###-#0000 33.12..#0+0d", 256);

	// printf("\n");
	// printf("%10.5d", 35);
	// printf("\n");
	// printf("%10..5.3d", 35);

	// ft_printf("{%05.2c}", 'f');
	// printf("\n");
	// printf("{%05.2c}", 'f');


	// ft_printf("%20.10f", 1.23);
	// printf("\n");
	// printf("%20.10f", 1.23);

	// ft_printf("{%05.s}", 0);
	// printf("\n");
	// printf("{%05.s}", 0);
	// ft_printf("{%05.%}", 0);
	// printf("\n");
	// printf("{%05.%}", 0);

	// float		nb;
	// nb = 0;
	// ft_printf("null prec : %+.0f\n", nb);
	// printf("null prec : %+.0f\n", nb);
	// nb = 20.5;
	// ft_printf("null prec : %+.0f\n", nb);
	// printf("null prec : %+.0f\n", nb);
	// nb = -25632.2541;
	// ft_printf("null prec : %+.0f\n", nb);
	// printf("null prec : %+.0f\n", nb);
	// nb = -1.0123;
	// ft_printf("null prec : %+.0f\n", nb);
	// printf("null prec : %+.0f\n", nb);
	// nb = 12354.569874;
	// ft_printf("null prec : %+.0f\n", nb);
	// printf("null prec : %+.0f\n", 24.);

	//ft_printf(NULL, 123, 'A', 1235.123);
	// //printf(NULL, 123, 'A', 1235.123);
	// ft_printf("%d, %c, %f", 123, 'A');
	// ft_printf(NULL);
	// printf("\n", NULL);
	// ft_printf("%05.2Zr", 1);
	// printf("\n");
	// printf("%05.2Zr", 1);



	// printf("%hD", 222222);
	// ft_printf("%hhu", -2557);
	// printf("\n");
	// printf("%hho", -2557);
	//printf("%f|%-f|%+f|% f|%#f|%0f", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);
	// printf("\n");
	// printf("%#.O", 0);

	// printf("01 stroka: %-+8.6hu\n", -123111);
	// ft_printf("01 stroka: %-+8.6hu\n",0);
	// printf("02 stroka: % -+8.6hhu\n", -123111);
	// ft_printf("02 stroka: % -+8.6hhu\n", -123111);
	// printf("03 stroka: %-+8.6hu\n", 123111);
	// ft_printf("03 stroka: %-+8.6hu\n", 123111);
	// printf("04 stroka: % -+8.6hhu\n", 123111);
	// ft_printf("04 stroka: % -+8.6hhu\n", 123111);
	// printf("05 stroka: %-8.6lu\n", 123111);
	// ft_printf("05 stroka: %-8.6lu\n", 123111);
	// ft_printf("%.1150f|%.1150f|%.1150f|%.1150f", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);
	// printf("\n");
	// printf("%.1150f|%.1150f|%.1150f|%.1150f", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);

	// ft_printf("%d", -1);
	// printf("\n");
	// printf("%d", -1);
	// printf("\n");

	ft_printf("%x", -42);
	printf("\n");
	printf("%x", -42);

	// long long	x;
	// int			y;
	// y = -1;
	// x = (long long) -1;
	// printf("%lld", x);
	// return (0);
 }











	// int		x = 1040;
	// char	*a;
	// char	*b;
	// char	*c;
	// char	*d;
	// d = (char *)&x;
	// c = (char *)&x;
	// c += 1;
	// b = (char *)&x;
	// b += 2;
	// a = (char *)&x;
	// a += 3;
	// //printf("%d",x);
	// write(1, a, 4);
