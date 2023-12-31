#include "lib.h"

/**
 * _atoi - convert string to integer
 * @str: string
 * Return: parsed value
*/
int _atoi(const char *str)
{
	unsigned int n;
	int sign;
	int i;

	n = 0;
	sign = 1;
	i = 0;
	while (_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * sign);
}
