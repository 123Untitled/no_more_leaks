/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_more_leaks.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artblin <artblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:37:13 by artblin           #+#    #+#             */
/*   Updated: 2022/02/06 19:28:10 by artblin          ###   ########.fr       */
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

// memory allocation
int		mempush(void *ptr, const size_t byte, const size_t size);

// memory free
int		memfree(void *ptr);

// all memory free
int		memrelease(void);

#endif
