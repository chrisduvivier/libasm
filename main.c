/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:06:24 by cduvivie          #+#    #+#             */
/*   Updated: 2020/11/11 22:47:07 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

/*
**	nasm -fmacho64 %%%%%%%.s -o %%%%%%.o
**	gcc -m64 -g %%%%%%.o
*/

int		main(void)
{
	const char string[] =  "Hello, world!";
	const char string_less[] = "Hello, oon!";
	const char string_more[] = "Hello, zzzzz!";
	int	str_len;
	char *ptr1;
	char *ptr2;
	int	i = 0;

	int errnum;
	int copy_errnum;
	errnum = errno;
	
	str_len = strlen(string);
	// printf("ft_strlen = [%i]\n", ft_strlen(string));
	// assert(ft_strlen(string) == str_len);

	// if (!(ptr1 = (char *)malloc(sizeof(char) * str_len)))
	// {
	// 	printf("malloc fail exit\n");
	// 	return (1);
	// }
	// while (i < str_len - 1)
	// 	ptr1[i++] = 'a';
	// ptr1[i] = '\0';
	
	// if (!(ptr2 = (char *)malloc(sizeof(char) * str_len)))
	// {
	// 	printf("malloc fail exit\n");
	// 	return (1);
	// }
	// while (i < str_len - 1)
	// 	ptr2[i++] = 'a';
	// ptr2[i] = '\0';
	
	// printf("===== ft_strcpy =====\n");
	// strcpy(ptr1, string);
	// ft_strcpy(ptr2, string);
	// printf("[%s]\n", ptr2);
	// assert(strncmp(ptr1, ptr2, strlen(ptr1)) == 0);
	// fprintf(stderr, "Value of errno: %d\n", errno);

	// printf("===== ft_strcmp =====\n");
	// printf("ft_strcmp: [%i] = [%i] strcmp\n", ft_strcmp(string, string),  strcmp(string, string));
	// assert(strcmp(string, string) == ft_strcmp(string, string));
	// printf("ft_strcmp: [%i] = [%i] strcmp\n", ft_strcmp(string, string_less),  strcmp(string, string_less));
	// assert(strcmp(string, string_less) == ft_strcmp(string, string_less));
	// printf("ft_strcmp: [%i] = [%i] strcmp\n", ft_strcmp(string, string_more),  strcmp(string, string_more));
	// assert(strcmp(string, string_more) == ft_strcmp(string, string_more));
	// fprintf(stderr, "Value of errno: %d\n", errno);

	printf("===== ft_write =====\n");
	
	// // write(1, 	"ABCDEFG\n", 9);
	ft_write(1, "ABCDEFG\n", 9);

	// fprintf(stderr, "Value of errno: [%d]\n", errno);
	// perror("Error printed by perror");
	// fprintf(stderr, "Error opening file: [%s]\n", strerror(errnum));

	// write(1, "fss", -3);
	printf("%zd\n", ft_write(1, 0, 4));
	// ft_write(1, "fss", -3);

	fprintf(stderr, "Value of errno: [%d]\n", errno);
	perror("Error printed by perror");
	fprintf(stderr, "Error opening file: [%s]\n", strerror(errnum));


	// write(1, "oOoOoOoO\n", 9);
	// // ft_write(1, "oOoOoOoO\n", 9);

	// write(1, "99999999\n", 9);
	// ft_write(1, "99999999\n", 9);

	return (0);
}
