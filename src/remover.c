/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:24:02 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/16 09:59:08 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_object	vector_pop(t_vector *const vector)
{
	if (vector->size == 0)
		return (NULL);
	_vec_memcpy(vector->buffer,
		vector->data + vector->type_size * (vector->size - 1),
		vector->type_size);
	vector->size--;
	return (vector->buffer);
}

t_object	vector_erase(t_vector *const vector, t_length const index)
{
	if (vector->size == 0 || index >= vector->size)
		return (NULL);
	_vec_memcpy(vector->buffer, vector->data + vector->type_size * index,
		vector->type_size);
	_vec_memcpy(vector->data + vector->type_size * index,
		vector->data + vector->type_size * (index + 1),
		vector->type_size * (vector->type_size - index));
	vector->size--;
	return (vector->buffer);
}