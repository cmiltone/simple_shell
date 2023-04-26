#include "main.h"


/**
 * main - program entry point
 * @argc: number of arguments
 * @argv: argument list
 * Return: always 0
*/
int main(int argc, char *argv[])
{
	(void)argc;

	signal(SIGINT, &ctrl_c);
	shell(argv[0]);

	return (0);
}
