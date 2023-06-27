#ifndef LIB_H
#define LIB_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 5

void _puts(const char *str);
void _puts_fd(const char *str, int fd);
size_t _strlen(const char *str);
int _atoi(const char *str);
size_t _strclen(const char *str, char c);
char *_substr(const char *s, int start, int len);
ssize_t _str_index_of(const char *str, char c);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *strjoin(const char *s1, const char *s2);
int _getline(int fd, char **line);

#endif /* LIB_H */
