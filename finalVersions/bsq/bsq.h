/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moham <moham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:31:31 by snazzal           #+#    #+#             */
/*   Updated: 2025/11/26 10:10:53 by moham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
	int		rows;
	int		cols;
	char	empty;
	char	full;
	char	obstacle;
	char	**map;
	// char	**out_map;
	FILE	*stream;
}	data;

#endif
