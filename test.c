/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:18:30 by draudrau          #+#    #+#             */
/*   Updated: 2019/04/17 17:02:27 by waddam           ###   ########.fr       */
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

	// printf("1 stroka: %-+8.6d\n", -123);
    // printf("2 stroka: %0-+8.6d\n", -123); /* */
	// printf("3 stroka: %-+8.6d\n", 123);
	// printf("4 stroka: %0-+8.6d\n", 123); /* */
	// printf("5 stroka: %-8.6d\n", 123);
	// printf("6 stroka: %0-8.6d\n", 123); /* */
	// printf("7 stroka: %+8.6d\n", -123);
	// printf("8 stroka: %0+8.6d\n", -123);
	// printf("9 stroka: %+8.6d\n", 123);
	// printf("10 stroka: %0+8.6d\n", 123);
	// printf("11 stroka: %8.6d\n", 123);
	// printf("12 stroka: %08.6d\n\n", 123);

	// printf("13 stroka: %+8d\n", -123);
	// printf("14 stroka: %0+8d\n", -123);
	// printf("15 stroka: %-8.6d\n", 123);
	// printf("16 stroka: %+8.6d\n", 123);
	// printf("17 stroka: %+8.6d\n", 123);
	// printf("18 stroka: %08.0004d\n", 123);
	// printf("19 stroka: %0-8d\n", -123);

	char		*s = "hello";

	printf("rabotaet %15s\n", "privet");
	printf("ignore %.15s\n", "privet");
	printf("rabotaet %-15s\n", "privet");
	printf("ub %+15s\n", "privet");
	printf("ub %0s\n\n", "privet");

	printf("rabotaet %15c\n", '1');
	printf("ub%.15c\n", '1');
	printf("rabotaet %-15c\n", '1');
	printf("ub %+15c\n", '1');
	printf("ub %0c\n\n", '1');

	printf("rabotaet %15p\n", s);
	printf("rabotaet %.15p\n", s);
	printf("rabotaet %-15p\n", s);
	printf("ub %+15p\n", s);
	printf("ub %0p\n", s);
	return (0);
}