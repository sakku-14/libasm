#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

void
	check_strlen(void)
{
	char *str1 = "123456789";
	printf("len=%d: %s\n", (int)ft_strlen(str1), str1);
	char *str2 = "\0";
	printf("len=%d: %s\n", (int)ft_strlen(str2), str2);
//	char *str3 = NULL;
//	printf("len=%d: NULL-ptr\n", (int)ft_strlen(str3));
}

void
	check_strcpy(void)
{
	char dst1[] = "0000000000";
	const char src1[] = "12345";
	printf("%s=>%s\n", src1, ft_strcpy(dst1, src1));
	char dst2[] = "0000000000";
	const char src2[] = "12345";
	printf("%s=>%s\n", src2, ft_strcpy(dst2, src2));
	char dst3[] = "00000";
	char src3[] = "123456789";
	printf("%s=>%s\n", src3, ft_strcpy(dst3, src3));
}

void
	print_result_strcmp(const char *s1, const char *s2)
{
	int	ret;

	ret = 0;
	if ((ret = ft_strcmp(s1, s2)) == 0)
		printf("ret=%d:OK:%s:%s\n", ret, s1, s2);
	else
		printf("ret=%d:NG:%s,%s\n", ret, s1, s2);
}

void
	check_strcmp(void)
{
	const char s1[] = "12345";
	const char s2[] = "12345";
	print_result_strcmp(s1, s2);
	const char s3[] = "123456789";
	const char s4[] = "12345";
	print_result_strcmp(s3, s4);
	const char s5[] = "12345";
	const char s6[] = "123456789";
	print_result_strcmp(s5, s6);
}

void
	check_write(void)
{
	int	ret;

	char s1[] = "abcd";
	ret = ft_write(1, s1, 3);
	printf("\n12345678901234567890\nret:%d->%s\n", ret, s1);
	char s2[] = "abcd";
	ret = ft_write(1, s2, -3);
	printf("\n12345678901234567890\nret:%d->%s\n", ret, s2);
}

void
	check_read(void)
{
	int  ret;
	int  fd;

	char buf[100];
	fd = open("./text.txt", O_RDONLY);
	errno = 0;
	ret = ft_read(fd, buf, 20);
	printf("%d\n", errno);
	printf("ret:%d\n%s\n", ret, buf);

	char buf2[100];
	fd = open("./text.tx", O_RDONLY);
	errno = 0;
	ret = ft_read(fd, buf2, 20);
	printf("%d\n", errno);
	printf("ret:%d\n%s\n", ret, buf2);
}

int		main()
{
	printf(">>>>>>check_strlen<<<<<<\n");
	check_strlen();
	printf("\n\n\n>>>>>>check_strcpy<<<<<<\n");
	check_strcpy();
	printf("\n\n\n>>>>>>check_strcmp<<<<<<\n");
	check_strcmp();
	printf("\n\n\n>>>>>>check_write<<<<<<\n");
	check_write();
	printf("\n\n\n>>>>>>check_read<<<<<<\n");
	check_read();
	return (0);
}
