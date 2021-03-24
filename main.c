#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

void
	___test_case___(char *test_name, int num)
{
	printf("__________%s__%d__________\n", test_name, num);
}

void
	print_strlen_result(char *str)
{
	printf("ft_strlen:%3d:%s\n", (int)ft_strlen(str), str);
	printf("strlen   :%3d:%s\n", (int)strlen(str), str);
}

void
	check_strlen(void)
{
	int index = 0;
	___test_case___("strlen", ++index);
	print_strlen_result("123456789");
	___test_case___("strlen", ++index);
	print_strlen_result("hello world");
	___test_case___("strlen", ++index);
	print_strlen_result("aaaaaa\nbbbbb\nccc\tdd");
}

void
	print_strcpy_result(char *dst, char *src)
{
	char *dst1 = strdup(dst);
	const char *src1 = strdup(src);
	char *dst2 = strdup(dst);
	const char *src2 = strdup(src);

	printf("dst:%s\nsrc:%s\n", dst, src);
	printf("ft_strcpy:%s\n", ft_strcpy(dst1, src1));
	printf("strcpy   :%s\n", strcpy(dst2, src2));
}

void
	check_strcpy(void)
{
	int index = 0;
	___test_case___("strcpy", ++index);
	print_strcpy_result("00000", "12345");
	___test_case___("strcpy", ++index);
	print_strcpy_result("0000000000", "12345");
	___test_case___("strcpy", ++index);
	print_strcpy_result("00000", "1234567890");
	___test_case___("strcpy", ++index);
	print_strcpy_result("0000000000", "123\n456\n789");
	___test_case___("strcpy", ++index);
	print_strcpy_result("", "123456789");
}

void
	print_result_strcmp(const char *s1, const char *s2)
{
	int	ret;

	printf("s1:%s\ns2:%s\n", s1, s2);
	if ((ret = ft_strcmp(s1, s2)) == 0)
		printf("ft_strcmp:ret=%4d:OK\n", ret);
	else
		printf("ft_strcmp:ret=%4d:NG\n", ret);
	if ((ret = strcmp(s1, s2)) == 0)
		printf("strcmp   :ret=%4d:OK\n", ret);
	else
		printf("strcmp   :ret=%4d:NG\n", ret);
}

void
	check_strcmp(void)
{
	int index = 0;
	___test_case___("strcmp", ++index);
	print_result_strcmp("12345", "12345");
	___test_case___("strcmp", ++index);
	print_result_strcmp("123456789", "12345");
	___test_case___("strcmp", ++index);
	print_result_strcmp("12345", "123456789");
	___test_case___("strcmp", ++index);
	print_result_strcmp("bonjour", "onjour");
	___test_case___("strcmp", ++index);
	print_result_strcmp("hello world", "helloworld");
	___test_case___("strcmp", ++index);
	print_result_strcmp("\n\t\n", "\n\n\n");
}

void
	print_result_write(int fd, char *str, int len)
{
	int	ret;

	printf("fd:%3d\nstr:%s\nlen:%3d\n", fd, str, len);
	errno = 0;
	printf(">>>>ft_write<<<<\n");
	ret = ft_write(fd, str, len);
	printf("\nerrno:%d\nret:%d\n", errno, ret);
	printf(">>>>>write<<<<<<\n");
	errno = 0;
	ret = write(fd, str, len);
	printf("\nerrno:%d\nret:%d\n", errno, ret);
}

void
	check_write(void)
{
	int index = 0;
	___test_case___("write", ++index);
	print_result_write(1, "abcd", 4);
	___test_case___("write", ++index);
	print_result_write(1, "abcd", -3);
	___test_case___("write", ++index);
	print_result_write(0, "abcd", 3);
	___test_case___("write", ++index);
	print_result_write(-1, "abcd", 3);
	___test_case___("write", ++index);
	print_result_write(2, "abcd", 3);
	___test_case___("write", ++index);
	print_result_write(2, "abcd", -3);
	___test_case___("write", ++index);
	print_result_write(1, NULL, 1);
	___test_case___("write", ++index);
	print_result_write(1, "aaa", 5);
}

void
	print_result_read(char *path, int len)
{
	int		fd;
	int		ret;
	char	buf1[100];
	char	buf2[100];

	bzero(buf1, sizeof(char) * 100);
	bzero(buf2, sizeof(char) * 100);
	fd = open(path, O_RDONLY);
	errno = 0;
	ret = ft_read(fd, buf1, len);
	buf1[len] = '\0';
	printf("ft_read:\n\terrno:%d\n\tret:%d\n\tread_buf:\n%s\n", errno, ret, buf1);
	close(fd);
	fd = open(path, O_RDONLY);
	errno = 0;
	ret = read(fd, buf2, len);
	buf2[len] = '\0';
	printf("\n");
	printf("read   :\n\terrno:%d\n\tret:%d\n\tread_buf:\n%s\n", errno, ret, buf2);
	close(fd);
}

void
	check_read(void)
{
	int index = 0;
	___test_case___("read", ++index);
	print_result_read("./text.txt", 10);
	___test_case___("read", ++index);
	print_result_read("./text.txt", 100);
	___test_case___("read", ++index);
	print_result_read("./text.txt", 1000);
	___test_case___("read", ++index);
	print_result_read("./text.tx", 10);
}

void
	print_result_strdup(char *src)
{
	char *dst;
	printf("src:\n%s\n", src);
	dst = ft_strdup(src);
	printf("ft_strdup:\n\tdst:\n%s\n\tlen:%d\n\t\n", dst, (int)strlen(dst));
	free(dst);
	dst = NULL;
	dst = strdup(src);
	printf("strdup:\n\tdst:\n%s\n\tlen:%d\n\t\n", dst, (int)strlen(dst));
	free(dst);
	dst = NULL;
}

void
	check_strdup(void)
{
	int index = 0;
	___test_case___("strdup", ++index);
	print_result_strdup("hello");
	___test_case___("strdup", ++index);
	print_result_strdup("1234567890");
	___test_case___("strdup", ++index);
	print_result_strdup("aaaaa\nbbb\ncc\nd");
	___test_case___("strdup", ++index);
	print_result_strdup("aaaaa\0bbb\0");
	___test_case___("strdup", ++index);
	print_result_strdup("000000000\n000000\n\t000000");
	___test_case___("strdup", ++index);
	print_result_strdup("");
}

int		main()
{
	printf(">>>>>>>>>check_strlen<<<<<<<<\n");
	check_strlen();
	printf("\n\n\n>>>>>>>>>check_strcpy<<<<<<<<\n");
	check_strcpy();
	printf("\n\n\n>>>>>>>>>check_strcmp<<<<<<<<\n");
	check_strcmp();
	printf("\n\n\n>>>>>>>>>check_write<<<<<<<<<\n");
	check_write();
	printf("\n\n\n>>>>>>>>>check_read<<<<<<<<<<\n");
	check_read();
	printf("\n\n\n>>>>>>>>>check_strdup<<<<<<<<<\n");
	check_strdup();
	return (0);
}
