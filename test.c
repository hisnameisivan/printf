/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:18:30 by draudrau          #+#    #+#             */
/*   Updated: 2019/04/26 14:11:38 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

	printf("1 stroka: %#6.1x\n", 123);
	printf("1 stroka: %#6x\n", 123);
	printf("1 stroka: %#.6x\n", 123);
	// printf("2 stroka: %#2x\n", 123);
	// printf("3 stroka: %#3x\n", 123);
	// printf("4 stroka: %#4x\n", 123);
	// printf("5 stroka: %#5x\n", 123);
	// printf("6 stroka: %#6x\n", 123);
	// printf("7 stroka: %#7x\n", 123);
	//printf("23 stroka: %6.6x\n", 123);
	printf("%+08.0d\n", 0);
	printf("%+8.0d\n", 0);
	printf("%+8.0o\n", 0);
	return (0);
}
