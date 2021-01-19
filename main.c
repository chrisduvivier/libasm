/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:06:24 by cduvivie          #+#    #+#             */
/*   Updated: 2021/01/19 23:14:48 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

/*
**	nasm -fmacho64 %%%%%%%.s -o %%%%%%.o
**	gcc -m64 -g %%%%%%.o
*/

// ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

int		ft_open_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		write(2, "Cannot read file.\n", 18);
	return (fd);
}

void	print_error(void)
{
	if (errno)
	{
		fprintf(stderr, "errno: [%d]\n", errno);
		perror("Error printed by perror");
	}
	// fprintf(stderr, "Error opening file: [%s]\n", strerror(errnum));
}

int		test_ft_strlen(const char *s1, const char *s2, const char *s3)
{
	printf("===== TEST: ft_strlen =====\n");
	
	assert(ft_strlen(s1) == strlen(s1));
	assert(ft_strlen(s2) == strlen(s2));
	assert(ft_strlen(s3) == strlen(s3));

	printf("OK\n");
	return 0;
}

int		test_ft_strcpy(const char *s1)
{
	printf("===== TEST: ft_strcpy =====\n");
	char *ptr1;
	char *ptr2;
	char src[128];
	char empty[1] = "";

	bzero(&src, strlen(src));
	if (!(ptr1 = strdup(src)))
		return (1);
	if (!(ptr2 = strdup(src)))
		return (1);
	strcpy(ptr1, s1);
	ft_strcpy(ptr2, s1);
	assert(strncmp(ptr1, ptr2, strlen(ptr1)) == 0);
	bzero(ptr1, strlen(src));
	bzero(ptr2, strlen(src));
	
	strcpy(ptr1, empty);
	ft_strcpy(ptr2, empty);
	assert(strncmp(ptr1, ptr2, strlen(ptr1)) == 0);
	bzero(ptr1, strlen(src));
	bzero(ptr2, strlen(src));

	free(ptr1);
	free(ptr2);

	printf("OK\n");
	return 0;
}

int		test_ft_strcmp(const char *s1, const char *s2, const char *s3)
{
	printf("===== TEST: ft_strcmp =====\n");
	
	// printf("ft_strcmp: [%i] = [%i] strcmp\n", ft_strcmp(s1, s1),  strcmp(s1, s1));
	assert(strcmp(s1, s1) == ft_strcmp(s1, s1));
	// printf("ft_strcmp: [%i] = [%i] strcmp\n", ft_strcmp(s1, s2),  strcmp(s1, s2));
	assert(strcmp(s1, s2) == ft_strcmp(s1, s2));
	// printf("ft_strcmp: [%i] = [%i] strcmp\n", ft_strcmp(s1, s3),  strcmp(s1, s3));
	assert(strcmp(s1, s3) == ft_strcmp(s1, s3));
	print_error();
	
	printf("OK\n");
	return 0;
}

int		test_ft_write(void)
{
	printf("===== TEST: ft_write =====\n");
	
	int output1;
	int output2;
	int	copy_errnum;
	
	printf("---TEST 1---\n");
	output1 = write(1, 	  "ABCDEFG\n", 9);
	print_error();
	copy_errnum = errno;
	errno = 0;

	output2 = ft_write(1, "ABCDEFG\n", 9);
	printf("output1: %d\n", output1);
	printf("output2: %d\n", output2);
	print_error();
	assert(output1 == output2);
	copy_errnum = 0;
	errno = 0;

	printf("---TEST 2 (errno test)---\n");
	output1 = write(1, "fss", -3);
	print_error();
	copy_errnum = errno;
	errno = 0;
	
	output2 = ft_write(1, "fss", -3);
	printf("output2: %d\n", output2);
	printf("output1: %d\n", output1);
	print_error();
	assert(copy_errnum == errno);		// THIS LINE CHECKS THE ERRNO FOR BOTY FUNCTIONS
	copy_errnum = 0;
	errno = 0;
	
	return (0);
}

int		test_ft_read(void)
{
	printf("===== TEST: ft_read =====\n");
	
	int	copy_errnum;
	int fd1;
	int fd2;
	int cursor1;
	int cursor2;
	char buf1[BUFFER_SIZE + 1];
	char buf2[BUFFER_SIZE + 1];
	

	printf("---TEST 1---\n");
	fd1 = ft_open_file("test.txt");
	cursor1 = read(fd1, buf1, BUFFER_SIZE);
	copy_errnum = errno;
	printf("cursor1: %d\n", cursor1);
	close(fd1);
    fd2 = ft_open_file("test.txt");
	cursor2 = ft_read(fd2, buf2, BUFFER_SIZE);
	printf("cursor2: %d\n", cursor2);
	close(fd2);
	
	buf1[cursor1] = '\0';
	buf2[cursor2] = '\0';
	printf("buf1:[%s]\n", buf1);
	printf("buf2:[%s]\n", buf2);
	assert(cursor1 == cursor2);
	print_error();
	assert(copy_errnum == errno);		// THIS LINE CHECKS THE ERRNO FOR BOTY FUNCTIONS
	copy_errnum = 0;
	errno = 0;
	bzero(buf1, BUFFER_SIZE+1);
	bzero(buf2, BUFFER_SIZE+1);

	printf("---TEST 2---\n");
	fd1 = ft_open_file("test.txt");
    fd2 = ft_open_file("test.txt");
	cursor1 = read(fd1, buf1, 4);
	printf("cursor1: %d\n", cursor1);
	print_error();

	copy_errnum = errno;
	cursor2 = ft_read(fd2, buf2, 4);
	printf("cursor2: %d\n", cursor2);
	print_error();

	assert(cursor1 == cursor2);
	buf1[cursor1] = '\0';
	buf2[cursor2] = '\0';
	printf("buf1:[%s]\n", buf1);
	printf("buf2:[%s]\n", buf2);
	close(fd1);
	close(fd2);
	
	// print_error();
	copy_errnum = 0;
	errno = 0;
	bzero(buf1, BUFFER_SIZE+1);
	bzero(buf2, BUFFER_SIZE+1);

	printf("---TEST 3 (errno test)---\n");
	fd1 = ft_open_file("test.txt");
    fd2 = ft_open_file("test.txt");
	cursor1 = read(fd1, buf1, -4);
	printf("cursor1: %d\n", cursor1);
	print_error();

	copy_errnum = errno;
	errno = 0;
	cursor2 = ft_read(fd2, buf2, -4);
	printf("cursor2: %d\n", cursor2);
	print_error();

	assert(cursor1 == cursor2);
	assert(copy_errnum == errno);		// THIS LINE CHECKS THE ERRNO FOR BOTY FUNCTIONS
	close(fd1);
	close(fd2);
	
	// print_error();
	copy_errnum = 0;
	errno = 0;
	bzero(buf1, BUFFER_SIZE+1);
	bzero(buf2, BUFFER_SIZE+1);
	printf("OK\n");
	return (0);
}

int		test_ft_strdup(const char *s1)
{
	printf("===== TEST: ft_strdup =====\n");

	char *my_ft;
	char *origi;
	char *empty = "";
	
	my_ft = ft_strdup(s1);
	origi = strdup(s1);
	assert(strncmp(my_ft, origi, strlen(origi)) == 0);
	free(my_ft);
	free(origi);

	my_ft = ft_strdup(empty);
	origi = strdup(empty);
	assert(strncmp(my_ft, origi, strlen(origi)) == 0);
	free(my_ft);
	free(origi);
	
	printf("OK\n");
	return 0;
}

int		main(void)
{
	const char string[] =  "Hello, world!";
	const char string_less[] = "Hello, oon!";
	const char string_more[] = "Hello, zzzzz!";

	test_ft_strlen(string, string_less, string_more);
	test_ft_strcpy(string);
	test_ft_strcmp(string, string_less, string_more);
	test_ft_write();
	test_ft_read();
	test_ft_strdup(string);
	return (0);
}
