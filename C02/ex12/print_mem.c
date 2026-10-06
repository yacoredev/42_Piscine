#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_address(unsigned long addr, char *hex, int padding)
{
	if (addr == 0)
	{
		while (padding)
		{
			ft_putchar('0');
			padding--;
		}
		return ;
	}
	print_address(addr / 16, hex, padding - 1);
	ft_putchar(hex[addr % 16]);
}

void	print_hex_content(char *line, unsigned int size, unsigned int start, char *hex)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (start + i < size)
		{
			ft_putchar(hex[(unsigned char)line[i] / 16]);
			ft_putchar(hex[(unsigned char)line[i] % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 != 0)
			ft_putchar(' ');
		i++;
	}
}

void	print_ascii_content(char *line, unsigned int start, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (start + i < size && i < 16)
	{
		if (line[i] >= ' ' && line[i] <= '~')
			ft_putchar(line[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*byte = addr;
	char	*hexa = "0123456789abcdef";
	int		padding = 16;
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		print_address((unsigned long)byte, hexa, padding);
		write(1, ": ", 2);
		print_hex_content(byte, size, i, hexa);
		print_ascii_content(byte, i, size);
		ft_putchar('\n');
		i += 16;
		byte += 16;
	}
	return (addr);
}

int	main(void)
{
	char str[] = "Bonjour les aminches\t\n\tc\t est fou\tto"
	"ut\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";

	ft_print_memory(str, sizeof(str));

	return (0);
}