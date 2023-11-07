#include "../libft/incs/printf.h"
#include "../libft/incs/get_next_line.h"
#include "../libft/incs/libft.h"

int main(int n, char *str[])
{
	char **cur;
	char *file = str[1];

	cur = ft_file_to_dptr(file, 0);
	int i = 0;
	if (cur)
	{
		while (cur[i])
		{
			ft_printf("%s", cur[i]);
			i++;
		}
	}
}

