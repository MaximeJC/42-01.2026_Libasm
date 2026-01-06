#include "libasm.h"

int main(int argc, char **argv)
{
	int result = 0;
	if (argc > 1)
		result = atoi(argv[1]);
	switch (result)
	{
	case 1:
		test_ft_strlen();
		break;
	case 2:
		test_ft_strcpy();
		break;
	default:
		printf("Please provide a test number (1-6) as an argument to run a specific test.\n");
		printf("1: ft_strlen\n2: ft_strcpy\n3: ft_strcmp\n4: ft_write\n5: ft_read\n6: ft_strdup\n");
		break;
	}
	return 0;
}

void test_ft_strlen(void)
{
	const char	*str1 = "Hello, World!";
	const char	*str2 = "";
	const char	*str3 = "This is a longer string to test the ft_strlen function.";

	printf("Testing ft_strlen:\n");
	printf("String: \"%s\" | strlen Length: %zu | ft_strlen Length: %zu\n", str1, strlen(str1), ft_strlen(str1));
	printf("String: \"%s\" | strlen Length: %zu | ft_strlen Length: %zu\n", str2, strlen(str2), ft_strlen(str2));
	printf("String: \"%s\" | strlen Length: %zu | ft_strlen Length: %zu\n", str3, strlen(str3), ft_strlen(str3));
}

void test_ft_strcpy(void)
{
	char	dest1[50];
	char	dest2[50];
	char	dest3[60];
	const char	*src1 = "Hello, World!";
	const char	*src2 = "";
	const char	*src3 = "This is a longer string to test the ft_strcpy function.";

	printf("Testing ft_strcpy:\n");
	printf("Source: \"%s\" | strcpy Result: \"%s\" | ft_strcpy Result: \"%s\"\n", src1, strcpy(dest1, src1), ft_strcpy(dest1, src1));
	printf("Source: \"%s\" | strcpy Result: \"%s\" | ft_strcpy Result: \"%s\"\n", src2, strcpy(dest2, src2), ft_strcpy(dest2, src2));
	printf("Source: \"%s\" | strcpy Result: \"%s\" | ft_strcpy Result: \"%s\"\n", src3, strcpy(dest3, src3), ft_strcpy(dest3, src3));
}
