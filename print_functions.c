#include "main.h"

/*** PRINT WITOUTH USING PRINF AND ADDING NEWLINE AS NEEDED ***/
/**
 * print_string - Prints a string character by character.
 * @string: String to be printed. If the string is NULL it will print (null)
 * @newline: If integer is 0 a new line will be printed. Otherwise a new line
 * will not be printed.
 */
void print_string(char *string, int newline)
{
	int i;

	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i] != '\0'; i++)
		write(STDOUT_FILENO, &string[i], 1);
	if (newline == 0)
		write(STDOUT_FILENO, "\n", 1);
}

/*** PRINT A SINGLE LETTER ***/
/**
 * _putchar - Writes a character to stdout
 * @c: Character that will be written to stdout
 * Return: Upon success how many characters were written.
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/*** PRINT EVERY DIGIT OF A NUMBER AS SINGLE CHARS ***/
/**
 * print_numbers - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_numbers(int n)
{
	int division;
	int length;
	unsigned int number;

	division = 1;
	length = 0;

	number = n;

	for (; number / division > 9; )
		division *= 10;

	for (; division != 0; )
	{
		length += _putchar('0' + number / division);
		number %= division;
		division /= 10;
	}

	return (length);
}
