#ifndef LIBASM_H
#define LIBASM_H

#include <stdio.h>		// For printf
#include <unistd.h>		// For write, read
#include <stdlib.h>		// For malloc, free
#include <string.h>		// For strlen, strcmp, strcpy, strdup
#include <fcntl.h>		// For file open flags

size_t	ft_strlen(const char *s);							// size_t strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);			// char *strcpy(char *restrict dst, const char *restrict src);
int		ft_strcmp(const char *s1, const char *s2);			// int strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);	// ssize_t write(int fd, const void buf[], size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);			// ssize_t read(int fd, void buf[], size_t count);
char	*ft_strdup(const char *s);							// char *strdup(const char *s);

#endif // LIBASM_H
