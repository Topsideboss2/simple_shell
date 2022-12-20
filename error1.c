#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 *
 * @datas: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(data_shell *datas, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datas->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datas->args[0]);
	_strcat(error, msg);
	if (datas->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datas->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, datas->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @datas: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(data_shell *datas)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(datas->counter);
	if (datas->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(datas->args[1]);
	}

	length = _strlen(datas->av[0]) + _strlen(datas->args[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datas, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - generic error message for command not found
 * @datas: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_not_found(data_shell *datas)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datas->counter);
	length = _strlen(datas->av[0]) + _strlen(ver_str);
	length += _strlen(datas->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datas->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datas->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_exit_shell - generic error message for exit in get_exit
 * @datas: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *error_exit_shell(data_shell *datas)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datas->counter);
	length = _strlen(datas->av[0]) + _strlen(ver_str);
	length += _strlen(datas->args[0]) + _strlen(datas->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datas->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datas->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datas->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
