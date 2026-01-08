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
	case 5:
		test_ft_read();
		break;
	case 6:
		test_ft_strdup();
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
	errno = 0;
	ret_libc = write(1, str, strlen(str));
	printf(" (libc write returned: %zd, errno: %d)\n", ret_libc, errno);
	errno = 0;
	ret_ft = ft_write(1, str, strlen(str));
	printf(" (ft_write returned: %zd, errno: %d)\n", ret_ft, errno);

	printf("\nTesting ft_write with invalid fd:\n");
	errno = 0;
	ret_libc = write(-1, str, strlen(str));
	printf(" (libc write returned: %zd, errno: %d)\n", ret_libc, errno);
	errno = 0;
	ret_ft = ft_write(-1, str, strlen(str));
	printf(" (ft_write returned: %zd, errno: %d)\n", ret_ft, errno);

	printf("\nTesting ft_write with fd 0:\n");
	errno = 0;
	ret_libc = write(0, str, strlen(str));
	printf(" (libc write returned: %zd, errno: %d)\n", ret_libc, errno);
	errno = 0;
	ret_ft = ft_write(0, str, strlen(str));
	printf(" (ft_write returned: %zd, errno: %d)\n", ret_ft, errno);

	printf("\nTesting ft_write with zero count:\n");
	errno = 0;
	ret_libc = write(1, str, 0);
	printf(" (libc write returned: %zd, errno: %d)\n", ret_libc, errno);
	errno = 0;
	ret_ft = ft_write(1, str, 0);
	printf(" (ft_write returned: %zd, errno: %d)\n", ret_ft, errno);

	printf("\nTesting ft_write with empty string:\n");
	errno = 0;
	ret_libc = write(1, "", 0);
	printf(" (libc write returned: %zd, errno: %d)\n", ret_libc, errno);
	errno = 0;
	ret_ft = ft_write(1, "", 0);
	printf(" (ft_write returned: %zd, errno: %d)\n", ret_ft, errno);

	printf("\nTesting ft_write with file descriptor:\n");
	int fd = open("test_files/ft_write_test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return;
	}
	errno = 0;
	ret_libc = write(fd, str, strlen(str));
	printf(" (libc write to file returned: %zd, errno: %d)\n", ret_libc, errno);
	errno = 0;
	ret_ft = ft_write(fd, str, strlen(str));
	printf(" (ft_write to file returned: %zd, errno: %d)\n", ret_ft, errno);
	close(fd);
	errno = 0;
}

void test_ft_read(void)
{
	char buffer_libc[50];
	char buffer_ft[50];
	ssize_t ret_libc, ret_ft;
	int fd1 = open("test_files/ft_read_test1.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("open");
		return;
	}
	int fd2 = open("test_files/ft_read_test2.txt", O_RDONLY);
	if (fd2 < 0)
	{
		perror("open");
		close(fd1);
		return;
	}
	int fd3 = open("test_files/ft_read_test3.txt", O_RDONLY);
	if (fd3 < 0)
	{
		perror("open");
		close(fd1);
		close(fd2);
		return;
	}

	printf("Testing ft_read with fd1 - file size < buffer size:\n");

	ret_libc = read(fd1, buffer_libc, sizeof(buffer_libc) - 1);
	if (ret_libc < 0)
	{
		perror("read");
		close(fd1);
		close(fd2);
		close(fd3);
		return;
	}
	buffer_libc[ret_libc] = '\0';
	printf(" (libc read returned: %zd, buffer: \"%s\")\n", ret_libc, buffer_libc);

	lseek(fd1, 0, SEEK_SET); // Reset file offset

	ret_ft = ft_read(fd1, buffer_ft, sizeof(buffer_ft) - 1);
	if (ret_ft < 0)
	{
		perror("ft_read");
		close(fd1);
		close(fd2);
		close(fd3);
		return;
	}
	buffer_ft[ret_ft] = '\0';
	printf(" (ft_read returned: %zd, buffer: \"%s\")\n\n", ret_ft, buffer_ft);

	close(fd1);

	printf("Testing ft_read with fd2 - file size > buffer size:\n");

	ret_libc = read(fd2, buffer_libc, sizeof(buffer_libc) - 1);
	if (ret_libc < 0)
	{
		perror("read");
		close(fd2);
		close(fd3);
		return;
	}
	buffer_libc[ret_libc] = '\0';
	printf(" (libc read returned: %zd, buffer: \"%s\")\n", ret_libc, buffer_libc);
	ret_libc = read(fd2, buffer_libc, sizeof(buffer_libc) - 1);
	if (ret_libc < 0)
	{
		perror("read");
		close(fd2);
		close(fd3);
		return;
	}
	buffer_libc[ret_libc] = '\0';
	printf(" (libc read returned: %zd, buffer: \"%s\")\n", ret_libc, buffer_libc);

	lseek(fd2, 0, SEEK_SET);

	ret_ft = ft_read(fd2, buffer_ft, sizeof(buffer_ft) - 1);
	if (ret_ft < 0)
	{
		perror("ft_read");
		close(fd2);
		close(fd3);
		return;
	}
	buffer_ft[ret_ft] = '\0';
	printf(" (ft_read returned: %zd, buffer: \"%s\")\n\n", ret_ft, buffer_ft);
	ret_ft = ft_read(fd2, buffer_ft, sizeof(buffer_ft) - 1);
	if (ret_ft < 0)
	{
		perror("ft_read");
		close(fd2);
		close(fd3);
		return;
	}
	buffer_ft[ret_ft] = '\0';
	printf(" (ft_read returned: %zd, buffer: \"%s\")\n\n", ret_ft, buffer_ft);

	close(fd2);

	printf("Testing ft_read with fd3 - empty file:\n");

	ret_libc = read(fd3, buffer_libc, sizeof(buffer_libc) - 1);
	if (ret_libc < 0)
	{
		perror("read");
		close(fd3);
		return;
	}
	buffer_libc[ret_libc] = '\0';
	printf(" (libc read returned: %zd, buffer: \"%s\")\n", ret_libc, buffer_libc);

	lseek(fd3, 0, SEEK_SET);

	ret_ft = ft_read(fd3, buffer_ft, sizeof(buffer_ft) - 1);
	if (ret_ft < 0)
	{
		perror("ft_read");
		close(fd3);
		return;
	}
	buffer_ft[ret_ft] = '\0';
	printf(" (ft_read returned: %zd, buffer: \"%s\")\n", ret_ft, buffer_ft);

	close(fd3);

	printf("\nTesting ft_read with invalid fd:\n");
	errno = 0;
	ret_libc = read(-1, buffer_libc, sizeof(buffer_libc) - 1);
	printf(" (libc read returned: %zd, errno: %d)\n", ret_libc, errno);
	errno = 0;
	ret_ft = ft_read(-1, buffer_ft, sizeof(buffer_ft) - 1);
	printf(" (ft_read returned: %zd, errno: %d)\n", ret_ft, errno);
	errno = 0;
}

void test_ft_strdup(void)
{
	const char *str1 = "Hello, World!";
	const char *str2 = "";
	const char *str3 = "This is a longer string to test the ft_strdup function.";

	char *dup1_libc = strdup(str1);
	char *dup1_ft = ft_strdup(str1);
	printf("Testing ft_strdup:\n");
	// printf("Original: \"%s\" | strdup Result: \"%s\" | ft_strdup Result: \"%s\"\n", str1, dup1_libc, dup1_ft);
	printf("Original: \"%s\" | ", str1);
	printf("strdup Result: \"%s\" | ", dup1_libc);
	printf("ft_strdup Result: \"%s\"\n", dup1_ft);
	free(dup1_libc);
	free(dup1_ft);

	char *dup2_libc = strdup(str2);
	char *dup2_ft = ft_strdup(str2);
	printf("Original: \"%s\" | strdup Result: \"%s\" | ft_strdup Result: \"%s\"\n", str2, dup2_libc, dup2_ft);
	free(dup2_libc);
	free(dup2_ft);

	char *dup3_libc = strdup(str3);
	char *dup3_ft = ft_strdup(str3);
	// printf("Original: \"%s\" | strdup Result: \"%s\" | ft_strdup Result: \"%s\"\n", str3, dup3_libc, dup3_ft);
	printf("Original: \"%s\" | ", str3);
	printf("strdup Result: \"%s\" | ", dup3_libc);
	printf("ft_strdup Result: \"%s\"\n", dup3_ft);
	free(dup3_libc);
	free(dup3_ft);
}

