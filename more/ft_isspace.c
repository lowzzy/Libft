int	ft_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v')
			|| (c == '\r') || (c == '\f') || (c == 32))
		return (1);
	else
		return (0);
}
