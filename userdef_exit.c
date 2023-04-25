#include "main.h"
/**
 * teamexit - this terminates the shell
 * @info - the structure containing the arguments we assume, it is
 * used to maintain const funcs.
 *
 * Return: it does exit with an exist status of 0 for success
 */
int teamexit(info_t *info)
{
	int exit_status = 0;
	int arg_count;
	for (arg_count = 1; info->argv[arg_count] != NULL; arg_count++)
	{
		int exit_code = _erratoi(info->argv[arg_count]);

		while (exit_code == -1)
		{
			info->status = 2;
			print_error(info, "illegal number: ");
			_eputs(info->argv[arg_count]);
			_eputchar('\n');
			exit_status = 1;
			break;
		}

		info->err_num = exit_code;
		exit_status = -2;
	}

	while (arg_count == 1)
	{
		info->err_num = -1;
		break;
	}
	return exit_status;
}
