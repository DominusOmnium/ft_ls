/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:37:42 by dkathlee          #+#    #+#             */
/*   Updated: 2020/02/26 16:13:41 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <unistd.h>
# include "ft_printf.h"
#define			LS_FLAG_L		1
#define			LS_FLAG_A		1 << 1
#define			LS_FLAG_R		1 << 2
#define			LS_FLAG_R_BIG	1 << 3
#define			LS_FLAG_T		1 << 4

typedef t_uint8	t_ls_flags;
#endif
