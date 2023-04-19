/* Checks whether the input only contains digits */
char	**check_input(int argc, char	**argv, int	*arg_len)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[(*arg_len)])
			ft_digit_str(args[(*arg_len)++]);
		return (args);
	}
	else
	{
		(*arg_len)++;
		while (argv[(*arg_len)])
			ft_digit_str(argv[(*arg_len)++]);
		(*arg_len)--;
		return (&argv[1]);
	}
	return (NULL);
}

/* Checks if there are only digits in the string */
int	ft_digit_str(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) == 0 && str[i] != '-' && str[i] != '+')
			|| ((str[i] == '-' || str[i] == '+') && i != 0))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (1);
}