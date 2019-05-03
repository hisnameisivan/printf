/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:18:30 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/03 19:14:58 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(void)
{
	/*printf("1 stroka:%d", 123);
	printf("\n2 stroka:%+d", 123);
	printf("\n3 stroka:%-d", 123);
	printf("\n4 stroka:%0d", 123);

	printf("\n\n5 stroka:%10d", 123);
	printf("\n6 stroka:%.10d", 123);
	printf("\n7 stroka:%2.10d", 123);
	printf("\n8 stroka:%10.10d", 123);
	printf("\n9 stroka:%-10.10d", 123);

	printf("\n10 stroka:% +d", -123);
	printf("\n11 stroka:%     d", 123);
	printf("\n12 stroka:%hld", 20000);
	printf("\n13 stroka:%+8. 6d", 123);
	printf("\n14 stroka:%+8.6d", -123);*/

	/* Спецификатор d */
	// printf("01 stroka: %-+8.6d\n", -123);
    // printf("02 stroka: % -+8.6d\n", -123);
	// printf("03 stroka: %-+8.6d\n", 123);
	// printf("04 stroka: % -+8.6d\n", 123);
	// printf("05 stroka: %-8.6d\n", 123);
	// printf("06 stroka: % -8.6d\n", 123);
	// printf("07 stroka: %+8.6d\n", -123);
	// printf("08 stroka: % +8.6d\n", -123);
	// printf("09 stroka: %+8.6d\n", 123);
	// printf("10 stroka: % +8.6d\n", 123);
	// printf("11 stroka: %8.6d\n", 123);
	// printf("12 stroka: % 8.6d\n\n", 123);
	// printf("13 stroka: %+8d\n", -123);
	// printf("14 stroka: % +8d\n", -123);
	// printf("15 stroka: %8.6d\n", 123);
	// printf("16 stroka: % 8.6d\n", 123);
	// printf("17 stroka: %+ 8.6d\n", 123);
	// printf("18 stroka: % 8.6 d\n", 123);
	// printf("19 stroka: %      8d\n", -123);
	// printf("20 stroka: % 8.6d\n", 123);
	// printf("21 stroka: % d\n", -123);
	// printf("22 stroka: %      d\n", -123);
	// printf("23 stroka: %08.6d\n", 123);
	// printf("24 stroka: %-010d\n", 123);
	// printf("25 stroka: % 010d\n", 123);
	// printf("26 stroka: % 010.5d\n", 123);
	// printf("27 stroka: %9 0d\n", 123);
	// printf("28 stroka: %9d\n", 123);
	// printf("29 stroka: % 08.6d\n", 123);
	// printf("30 stroka: % 06d\n", 123);
	// printf("31 stroka: %+08.6d\n", 123);
	// printf("32 stroka: % s\n", "privet");
	// printf("33 stroka: % c\n", 'c');
	// printf("34 stroka: % 08.6hhd\n", (char)128);
	// printf("35 stroka: % 06hhd\n", (char)212);
	// printf("36 stroka: %+08.6hhdd\n", (char)212);

	// printf("36 stroka: % 06hhu\n", (char)-123);
	// printf("37 stroka: %+08.6hhu\n", (char)-123);
	// printf("38 stroka: % 06hhu\n", (char)-257);
	// printf("39 stroka: %hhu\n", (char)130);

	/* Перевод в восьмиричную */

	/*printf("40 stroka: %8o\n", 125);
	printf("41 stroka: %-08o\n", 125);
	printf("42 stroka: %+8o\n", 125);
	printf("43 stroka: %#8o\n", 125);
	printf("44 stroka: %8.5o\n", 125);
	printf("45 stroka: %08o\n", 125);
	printf("46 stroka: % 08o\n", 125);
	printf("47 stroka: %hhu\n", (char)225);
	printf("48 stroka: %hho\n", (char)225);
	printf("49 stroka: %hhu\n", (char)225);*/

	//char		*s = "hello";

	//printf("rabotaet %15s\n", "privet");
	//printf("ignore %.15s\n", "privet");
	//printf("rabotaet %-15s\n", "privet");
	//printf("ub %+15s\n", "privet");
	//printf("ub %0s\n\n", "privet");
//
	//printf("rabotaet %15c\n", '1');
	//printf("ub%.15c\n", '1');
	//printf("rabotaet %-15c\n", '1');
	//printf("ub %+15c\n", '1');
	//printf("ub %0c\n\n", '1');
//
	//printf("rabotaet %15p\n", s);
	//printf("rabotaet %.15p\n", s);
	//printf("rabotaet %-15p\n", s);
	//printf("ub %+15p\n", s);
	//printf("ub %0p\n", s);

	// printf("47 stroka: % -8hho\n", (char)255);
	// printf("48 stroka: % -8hhx\n", (char)255);
	// printf("47 stroka: % -8hhd\n", (char)255);
	// printf("48 stroka: % -8hhu\n", (char)255);

	// printf("49 stroka: % s\n", "privet1");
	// printf("50 stroka: % .s\n", "privet1");
	// printf("51 stroka: %.6s\n", "privet1");
	// printf("52 stroka: %5.6s\n", "privet1");
	// printf("53 stroka: %8.2s\n", "privet1");
	// printf("54 stroka: %5.2s\n", "privet1");
	// printf("55 stroka: %-8.2s\n", "privet1");
	// printf("56 stroka: %+8.2s\n", "privet1");
	// printf("57 stroka: %02.2s\n", "privet1");

	// printf("1 stroka: %#6.1x\n", 123);
	// printf("1 stroka: %#6x\n", 123);
	// printf("1 stroka: %#.6x\n", 123);
	// printf("2 stroka: %#2x\n", 123);
	// printf("3 stroka: %#3x\n", 123);
	// printf("4 stroka: %#4x\n", 123);
	// printf("5 stroka: %#5x\n", 123);
	// printf("6 stroka: %#6x\n", 123);
	// printf("7 stroka: %#7x\n", 123);
	//printf("23 stroka: %6.6x\n", 123);
	// printf("%+08.0d\n", 0);
	// printf("%+8.0d\n", 0);
	// printf("%+8.0o\n", 0);
	
	/* FCH исправить тесты */
	// тесты ОК

	// printf("% %\n");
	// printf("%+%\n");
	// printf("%   %%%\n", "test");
	// printf("#0006\n");
	// printf("%%");
	// printf("\n#0007\n");
	// printf("%5%");
	// printf("\n#0008\n");
	// printf("%-5%");
	// printf("\n#0009\n");
	// printf("%.0%");
	// printf("\n#0010\n");
	// printf("%%", "test");
	// printf("\n#0011\n");
	// printf("%   %", "test");
	// printf("\n\n#0028\n");
	// printf("%d\n", 4294967297);
	// printf("\n#0044\n");
	// printf("%#08x", 42);
	// printf("\n#0046\n");
	// printf("@moulitest: %#.x %#.0x", 0, 0);
	// printf("\n#0047\n");
	// printf("@moulitest: %.x %.0x", 0, 0);
	// printf("\n#0048\n");
	// printf("@moulitest: %5.x %5.0x", 0, 0);
	//printf("%5s", "");
	//printf("\n#0060\n");
	//printf("%.2s is a string", "");
	//printf("\n#0061\n");
	//printf("%5.2s is a string", "");
	//printf("\n#0066\n");
	//printf("%-.2s is a string", "");
	//printf("\n#0067\n");
	//printf("%-5.2s is a string", "");
	// printf("\n#0073\n");
	// printf("@moulitest: %s", NULL);
	// не ОК

	// printf("\n#0029\n");
	// printf("%jx\n", -4294967296);
	// printf("\n#0030\n");
	// printf("%jx\n", -4294967297);


	// printf("\n#0074\n");
	// printf("%.2c", NULL);
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
	// printf("\n#0093\n");
	// printf("@moulitest: %.o %.0o", 0, 0);
	// printf("\n#0094\n");
	// printf("@moulitest: %5.o %5.0o", 0, 0);
	// printf("\n#0095\n");
	// printf("@moulitest: %#.o %#.0o", 0, 0);
	// printf("\n#0151\n");
	// printf("%jd", 9223372036854775807);
	// printf("\n#0152\n");
	// printf("%jd", -9223372036854775808);
	// printf("\n#0153\n");
	// printf("%zd", 4294967295);
	// printf("\n#0154\n");
	// printf("%zd", 4294967296);
	// printf("\n#0175\n");
	// printf("@moulitest: %.d %.0d", 0, 0);
	// printf("\n#0176\n");
	// printf("@moulitest: %5.d %5.0d", 0, 0);
	// printf("\n#0190\n");
	// printf("%lu", -42);
	// printf("\n#0192\n");
	// printf("%ju", 4999999999);
	// printf("\n#0193\n");
	// printf("%ju", 4294967296);
	// printf("\n");

	/* тесты float */

	// printf("%f\n", 22222222222222222222.1);
	// printf("%.0f\n", -123.523);
	// printf("%.f\n", 123.523);
	// printf("%-8.1f\n", 123.523);
	// printf("%.6f\n", 123.523);
	// printf("%Lf\n", 41111111111294963296.523L); /* undefined behavior c ll */
	// printf("%f\n", 41111111111294963296.523);
	// printf("%.3f\n", 19999.99999 );
	// printf("%.9f", 1.1234560890123456);
	//printf("%.5048f\n", 1.2048);
	// printf("stroka 01 %+f\n", 123.456);
	// printf("stroka 02 %-12f\n", 123.456);
	// printf("stroka 03 % 12f\n", 123.456);
	// printf("stroka 03 %12f\n", 123.456);
	// printf("stroka 04 %#f\n", 123.456);
	// printf("stroka 05 %012f\n", 123.456);
	// printf("stroka 06 %+-12f\n", 123.456);
	// printf("stroka 07 %+12f\n", -123.456);
	// printf("stroka 08 %+12f\n", -123.456);
	// printf("stroka 09 % f\n", -123.456);
	// printf("stroka 10 %015.2f\n", -123.456);
	// printf("stroka 11 %015.2d\n", -123);

	printf("stroka 01: %-+5.0f\n", 0.);
	printf("stroka 02: %- 5.0f\n", 0.);
	printf("stroka 03: %-5.0f\n", 0.);
	printf("stroka 04: %-+5f\n", 0.);
	printf("stroka 05: %- 5f\n", 0.);
	printf("stroka 06: %-5f\n", 0.);
	printf("stroka 71: %+5.0f\n", 0.);
	printf("stroka 72: % 5.0f\n", 0.);
	printf("stroka 08: %5.0f\n", 0.);


	printf("stroka 09: %+05f\n", 0.);
	printf("stroka 10: %+5f\n", 0.);
	printf("stroka 11: % 05f\n", 0.);
	printf("stroka 12: %05f\n", 0.);
	printf("stroka 13: % 5f\n", 0.);
	printf("stroka 14: %5f\n", 0.);
	return (0);
}
