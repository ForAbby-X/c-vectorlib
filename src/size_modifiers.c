/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:25:21 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/16 10:09:02 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_error	vector_reserve(t_vector *const vector, t_length const len)
{
	void	*data;

	if (len == vector->capacity)
		return (FAILURE);
	if (len > vector->capacity)
	{
		data = malloc(vector->type_size * len);
		if (data == NULL)
			return (MEMORY_FAILURE);
		_vec_memcpy(data, vector->data, vector->type_size * vector->size);
		free(vector->data);
		vector->data = data;
		vector->capacity = len;
	}
	return (0);
}

t_error	vector_resize(t_vector	*vector, t_length const len)
{
	t_error const	error = vector_reserve(vector, len);

	if (error)
		return (error);
	vector->size = len;
	return (0);
}

void	vector_clear(t_vector *const vector)
{
	vector->size = 0u;
}
