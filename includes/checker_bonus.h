/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:48:34 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/29 16:43:21 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# ifndef MAX_FD_OPEN
#  define MAX_FD_OPEN 1
# endif

char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
bool	found_nl(char *str);
size_t	ft_linelen(char *str);

#endif
