#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

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
	errno = 0;
	ret = ft_write(1, s1, 3);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s1);
	errno = 0;
	ret = write(1, s1, 3);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s1);
	printf("\n");

	char s2[] = "abcd";
	errno = 0;
	ret = ft_write(1, s2, -3);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s2);
	errno = 0;
	ret = write(1, s2, -3);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s2);
	printf("\n");


	char s3[] = "abcd";
	errno = 0;
	ret = ft_write(0, s3, 3);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s3);
	errno = 0;
	ret = write(0, s3, 3);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s3);
	printf("\n");


	char s4[] = "abcd";
	errno = 0;
	ret = ft_write(-1, s4, 3);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s4);
	errno = 0;
	ret = write(-1, s4, 3);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s4);
	printf("\n");


	char s5[] = "abcd";
	errno = 0;
	ret = ft_write(2, s5, -3);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s5);
	errno = 0;
	ret = write(2, s5, -3);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s5);
	printf("\n");


	char s6[] = "abcd";
	errno = 0;
	ret = ft_write(1, NULL, 1);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s6);
	errno = 0;
	ret = write(1, NULL, 1);
	printf("\n12345678901234567890\nerrno:%d,ret:%d->%s\n", errno, ret, s6);
	printf("\n");


}

void
	check_read(void)
{
	int  ret;
	int  fd;

	char buf1[100];
	char buf2[100];
	fd = open("./text.txt", O_RDONLY);
	errno = 0;
	ret = ft_read(fd, buf1, 16);
	buf1[16] = '\0';
	printf("\nerrno:%d,ret:%d->%s\n", errno, ret, buf1);
	close(fd);
	fd = open("./text.txt", O_RDONLY);
	errno = 0;
	ret = read(fd, buf2, 16);
	buf2[16] = '\0';
	printf("\nerrno:%d,ret:%d->%s\n", errno, ret, buf2);
	close(fd);

	char buf3[100];
	char buf4[100];
	fd = open("./text.tx", O_RDONLY);
	errno = 0;
	ret = ft_read(fd, buf3, 20);
	buf3[20] = '\0';
	printf("\nerrno:%d,ret:%d->%s\n", errno, ret, buf3);
	close(fd);
	fd = open("./text.tx", O_RDONLY);
	errno = 0;
	ret = read(fd, buf4, 20);
	buf4[20] = '\0';
	printf("\nerrno:%d,ret:%d->%s\n", errno, ret, buf4);
	close(fd);
}

void
	check_strdup(void)
{
	char *dst;
	char src1[] = "hello";
	dst = ft_strdup(src1);
	printf("%s\n", dst);
	free(dst);

	char src2[] = "12345678901234567890";
	dst = ft_strdup(src2);
	printf("%s\n", dst);
	free(dst);
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
	printf("\n\n\n>>>>>>check_strdup<<<<<<\n");
	check_strdup();
	return (0);
}
