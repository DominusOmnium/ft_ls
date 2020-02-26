/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:38:00 by dkathlee          #+#    #+#             */
/*   Updated: 2020/02/26 16:24:36 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	permissions_to_str(mode_t m, char *str)
{
	int	i;

	if ((m >> 14) % 2 == 0)
		str[0] = '-';
	else
		str[0] = 'd';
	i = 0;
	while (i < 9)
	{
		if ((m >> i) % 2 == 1)
		{
			if (i % 3 == 0)
				str[9 - i] = 'x';
			else if (i % 3 == 1)
				str[9 - i] = 'w';
			else
				str[9 - i] = 'r';
		}
		else
			str[9 - i] = '-';
		i++;
	}
}

int	ft_ls(char *name, t_ls_flags flags)
{
	DIR				*d;
	struct stat		st;
	struct dirent	*dir;
	struct passwd	*pw;
	struct group	*gr;
	char			str[11];

	if ((d = opendir(".")) != NULL)
	{
		ft_printf("total %ld\n");
		while ((dir = readdir(d)) != NULL)
		{
			stat(dir->d_name, &st);
			pw = getpwuid(st.st_uid);
			gr = getgrgid(st.st_gid);
			permissions_to_str(st.st_mode, str);
			ft_printf("%s %3d %s  %s %6lld %s\n", str, st.st_nlink, pw->pw_name, gr->gr_name, st.st_size, dir->d_name);
		}
		closedir(d);
	}
}

t_ls_flags	ls_parse_flags(int ac, char **av)
{
	t_ls_flags	flags;
	int			i;
	int			j;

	flags = 0;
	i = 1;
	while (i < ac)
	{
		j = 1;
		if (av[i][0] == '-' && av[i][1] != 0)
			while (av[i][j] != 0)
			{
				flags |= (av[i][j] == 'a') ? LS_FLAG_A : 0;
				flags |= (av[i][j] == 'l') ? LS_FLAG_L : 0;
				flags |= (av[i][j] == 'R') ? LS_FLAG_R_BIG : 0;
				flags |= (av[i][j] == 'r') ? LS_FLAG_R : 0;
				flags |= (av[i][j] == 't') ? LS_FLAG_T : 0;
				j++;
			}
		i++;
	}
	return (flags);
}

int main(int ac, char **av)
{
	t_ls_flags	flags;

	flags = ls_parse_flags(ac, av);
	return(0);
}
