/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_more_leaks.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artblin <artblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:37:13 by artblin           #+#    #+#             */
/*   Updated: 2022/02/06 18:39:49 by artblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef NO_MORE_LEAKS_H

# define NO_MORE_LEAKS_H

# define ERROR 0
# define NOERR 1

typedef struct s_memlst		t_memlst;

struct	s_memlst
{
	void		*address;
	t_memlst	*nxt;
};

int		mempush(void *ptr, const size_t byte, const size_t size);

int		memfree(void *ptr);

int		memrelease(void);

#endif
