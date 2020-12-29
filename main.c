/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:06:24 by cduvivie          #+#    #+#             */
/*   Updated: 2020/12/26 10:50:19 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

/*
**	nasm -fmacho64 %%%%%%%.s -o %%%%%%.o
**	gcc -m64 -g %%%%%%.o
*/

ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

int		ft_open_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		write(2, "Cannot read file.\n", 18);
	return (fd);
}

void	print_error(void)
{
	fprintf(stderr, "errno: [%d]\n", errno);
	perror("Error printed by perror");
	// fprintf(stderr, "Error opening file: [%s]\n", strerror(errnum));
}

int		main(void)
{
	const char string[] =  "Hello, world!";
	const char string_less[] = "Hello, oon!";
	const char string_more[] = "Hello, zzzzz!";

	int	str_len;
	char *ptr1;
	char *ptr2;
	int	i = 0;
	int copy_errnum;
	
	str_len = strlen(string);
	printf("ft_strlen = [%i]\n", ft_strlen(string));
	assert(ft_strlen(string) == str_len);

	if (!(ptr1 = (char *)malloc(sizeof(char) * str_len)))
	{
		printf("malloc fail exit\n");
		return (1);
	}
	while (i < str_len - 1)
		ptr1[i++] = 'a';
	ptr1[i] = '\0';
	
	if (!(ptr2 = (char *)malloc(sizeof(char) * str_len)))
	{
		printf("malloc fail exit\n");
		return (1);
	}
	while (i < str_len - 1)
		ptr2[i++] = 'a';
	ptr2[i] = '\0';
	
	printf("===== ft_strcpy =====\n");
	strcpy(ptr1, string);
	ft_strcpy(ptr2, string);
	printf("[%s]\n", ptr2);
	assert(strncmp(ptr1, ptr2, strlen(ptr1)) == 0);
	if (errno)
		print_error();
	free(ptr1);
	free(ptr2);

	printf("===== ft_strcmp =====\n");
	printf("ft_strcmp: [%i] = [%i] strcmp\n", ft_strcmp(string, string),  strcmp(string, string));
	assert(strcmp(string, string) == ft_strcmp(string, string));
	printf("ft_strcmp: [%i] = [%i] strcmp\n", ft_strcmp(string, string_less),  strcmp(string, string_less));
	assert(strcmp(string, string_less) == ft_strcmp(string, string_less));
	printf("ft_strcmp: [%i] = [%i] strcmp\n", ft_strcmp(string, string_more),  strcmp(string, string_more));
	assert(strcmp(string, string_more) == ft_strcmp(string, string_more));
	print_error();

	printf("===== ft_write =====\n");
	
	int output1;
	int output2;
	
	output1 = write(1, 	"ABCDEFG\n", 9);
	output2 = ft_write(1, "ABCDEFG\n", 9);
	assert(output1 == output2);

	output2 = ft_write(1, "fss", -3);
	copy_errnum = errno;
	output1 = write(1, "fss", -3);
	assert(copy_errnum = errno);

	printf("===== ft_read =====\n");

	int fd1;
	int fd2;
	int cursor1;
	int cursor2;
	char buf1[BUFFER_SIZE + 1];
	char buf2[BUFFER_SIZE + 1];

	fd1 = ft_open_file("test.txt");
    fd2 = ft_open_file("test.txt");

	cursor1 = read(fd1, buf1, BUFFER_SIZE);
	cursor2 = ft_read(fd2, buf2, BUFFER_SIZE);
	assert(cursor1 = cursor2);
	buf1[cursor1] = '\0';
	buf2[cursor2] = '\0';
	printf("buf1:[%s]\n", buf1);
	printf("buf2:[%s]\n", buf2);
	close(fd1);
	close(fd2);

	fd1 = ft_open_file("test.txt");
    fd2 = ft_open_file("test.txt");
	cursor1 = read(fd1, buf1, -1);
	copy_errnum = errno;
	cursor2 = ft_read(fd2, buf2, -1);
	assert(cursor1 = cursor2);
	assert(copy_errnum = errno);
	buf1[cursor1] = '\0';
	buf2[cursor2] = '\0';
	close(fd1);
	close(fd2);
	
	print_error();

	printf("===== ft_strdup =====\n");
	
	return (0);
}
