/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artblin <artblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:21:32 by artblin           #+#    #+#             */
/*   Updated: 2022/02/06 23:53:29 by artblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "no_more_leaks.h"
#include <unistd.h>

static inline t_memlst	**vram(void)
{
	static t_memlst		*vrm = NULL;
	return (&vrm);
}

int	memfree(void *ptr)
{
	t_memlst	*elm;
	t_memlst	*prv;

	if (!ptr)
		return (ERROR);
	prv = NULL;
	elm = *(vram());
	while (elm)
	{
		if (elm->address == *(void **)ptr)
		{
			if (!prv)
				*(vram()) = elm->nxt;
			else prv->nxt = elm->nxt;
			free(elm->address);
			*(void **)ptr = NULL;
			return (free(elm), NOERR);
		}
		prv = elm;
		elm = elm->nxt;
	}
	return (ERROR);
}

int	memrelease(void)
{
	t_memlst	*elm;
	int			deleted;

	deleted = 0;
	while (*(vram()))
	{
		++deleted;
		elm = *(vram());
		*(vram()) = (*(vram()))->nxt;
		if (elm->address)
			free(elm->address);
		free(elm);
	}
	return (deleted);
}

int	mempush(void *ptr, const size_t byte, const size_t size)
{
	t_memlst	*elm;

	*(void **)ptr = NULL;
	elm = malloc(sizeof(t_memlst));
	if (!elm || !byte || !size)
		return (ERROR);
	elm->address = malloc(byte * size);
	if (!elm->address)
		return (free(elm), ERROR);
	elm->nxt = *(vram());
	*(void **)ptr = elm->address;
	*(vram()) = elm;
	return (NOERR);
}
