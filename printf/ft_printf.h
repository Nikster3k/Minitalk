/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:44:45 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/16 16:31:47 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "Libft/libft.h"

int		ft_printf(const char *s, ...);
int		ft_putstr_cnt(char *s);
int		ft_putnbr_cnt(long n, int fd);
int		ft_putunbr_cnt(unsigned int n, int fd);
int		ft_putnbr_base(unsigned int num, const char *base);
int		ft_printptr_cnt(size_t adress, const char *base);

#endif //!FT_PRINTF_H
