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
	case 3:
		test_ft_strcmp();
		break;
	case 4:
		test_ft_write();
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

void test_ft_strcmp(void)
{
	const char	*str1a = "Hello";
	const char	*str1b = "Hello";
	const char	*str2a = "Hello";
	const char	*str2b = "World";
	const char	*str3a = "abc";
	const char	*str3b = "abcd";
	const char	*str4a = "";
	const char	*str4b = "";

	printf("Testing ft_strcmp:\n");
	printf("Comparing \"%s\" and \"%s\" | strcmp Result: %d | ft_strcmp Result: %d\n", str1a, str1b, strcmp(str1a, str1b), ft_strcmp(str1a, str1b));
	printf("Comparing \"%s\" and \"%s\" | strcmp Result: %d | ft_strcmp Result: %d\n", str2a, str2b, strcmp(str2a, str2b), ft_strcmp(str2a, str2b));
	printf("Comparing \"%s\" and \"%s\" | strcmp Result: %d | ft_strcmp Result: %d\n", str2b, str2a, strcmp(str2b, str2a), ft_strcmp(str2b, str2a));
	printf("Comparing \"%s\" and \"%s\" | strcmp Result: %d | ft_strcmp Result: %d\n", str3a, str3b, strcmp(str3a, str3b), ft_strcmp(str3a, str3b));
	printf("Comparing \"%s\" and \"%s\" | strcmp Result: %d | ft_strcmp Result: %d\n", str3b, str3a, strcmp(str3b, str3a), ft_strcmp(str3b, str3a));
	printf("Comparing \"%s\" and \"%s\" | strcmp Result: %d | ft_strcmp Result: %d\n", str4a, str4b, strcmp(str4a, str4b), ft_strcmp(str4a, str4b));
}

void test_ft_write(void)
{
	const char *str = "Hello, ft_write!\n";
	ssize_t ret_libc, ret_ft;

	printf("Testing ft_write:\n");
	ret_libc = write(1, str, strlen(str));
	printf(" (libc write returned: %zd)\n", ret_libc);
	ret_ft = ft_write(1, str, strlen(str));
	printf(" (ft_write returned: %zd)\n", ret_ft);
	printf("\nTesting ft_write with invalid fd:\n");
	ret_libc = write(-1, str, strlen(str));
	printf(" (libc write returned: %zd, errno: %d)\n", ret_libc, errno);
	ret_ft = ft_write(-1, str, strlen(str));
	printf(" (ft_write returned: %zd, errno: %d)\n", ret_ft, errno);
	printf("\nTesting ft_write with zero count:\n");
	ret_libc = write(1, str, 0);
	printf(" (libc write returned: %zd)\n", ret_libc);
	ret_ft = ft_write(1, str, 0);
	printf(" (ft_write returned: %zd)\n", ret_ft);
	printf("\nTesting ft_write with large count:\n");
	ret_libc = write(1, str, 1000000);
	printf(" (libc write returned: %zd)\n", ret_libc);
	ret_ft = ft_write(1, str, 1000000);
	printf(" (ft_write returned: %zd)\n", ret_ft);
	printf("\nTesting ft_write with empty string:\n");
	ret_libc = write(1, "", 0);
	printf(" (libc write returned: %zd)\n", ret_libc);
	ret_ft = ft_write(1, "", 0);
	printf(" (ft_write returned: %zd)\n", ret_ft);
	printf("\nTesting ft_write with file descriptor:\n");
	int fd = open("ft_write_test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return;
	}
	ret_libc = write(fd, str, strlen(str));
	printf(" (libc write to file returned: %zd)\n", ret_libc);
	ret_ft = ft_write(fd, str, strlen(str));
	printf(" (ft_write to file returned: %zd)\n", ret_ft);
	close(fd);
}
