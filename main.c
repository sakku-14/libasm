#include <stdio.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);

void
	check_strlen(void)
{
	char *str1 = "123456789";
	printf("len=%d: %s\n", (int)ft_strlen(str1), str1);
	char *str2 = "\0";
	printf("len=%d: %s\n", (int)ft_strlen(str2), str2);
	char *str3 = NULL;
	printf("len=%d: NULL-ptr\n", (int)ft_strlen(str3));
}

void
	check_strcpy(void)
{
	char *dst1 = "0000000000";
	char *src1 = "1234567890";
	printf("%s=>%s", src1, ft_strcpy(dst1, src1));
	char *dst2 = "0000000000";
	char *src2 = "12345";
	printf("%s=>%s", src2, ft_strcpy(dst2, src2));
	char *dst3 = "00000";
	char *src3 = "123456789";
	printf("%s=>%s", src3, ft_strcpy(dst3, src3));
}

int		main()
{
	check_strlen();
	check_strcpy();
	return (0);
}
