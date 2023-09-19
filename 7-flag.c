#include "main.h"

/**
 * include_flags - Calculates available flags
 * @format: Formatted string to print the arguments
 * @i: Integer values
 * Return: Flags:
 */
int include_flags(const char *format, int *i)
{
	int j, k;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FLAG_M, FLAG_P, FLAG_Z, FLAG_H, FLAG_S, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
			if (format[k] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CHAR[j] == 0)
			break;
	}

	*i = k - 1;

	return (flags);
}
