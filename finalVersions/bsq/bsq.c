/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moham <moham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:50:39 by snazzal           #+#    #+#             */
/*   Updated: 2025/11/29 13:50:04 by moham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return i;
}

char *ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i = 0;
	char	*sub;

	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return NULL;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return sub;
}

void	read_map(char **argv, data *d)
{
	(void)argv;
	char	*line = NULL;
	size_t	len;

	getline(&line, &len, d->stream);
	len = ft_strlen(line);
	for(size_t i = 0; i < len - 4; i++)
	{
		d->rows = d->rows * 10 + (line[i] - '0');
	}
	printf("rows: %d\n", d->rows);
	d->empty = line[len - 4];
	printf("empty: %c\n", d->empty);
	d->obstacle = line[len - 3];
	printf("obstacle: %c\n", d->obstacle);
	d->full = line[len - 2];
	printf("full: %c\n", d->full);
	free(line);
	d->map = malloc(sizeof(char *) * d->rows);
	if (!d->map)
		return ;
	int	i = 0;
	while (i < d->rows)
	{
		line = NULL;  // Reset for each getline call
		len = 0;
		getline(&line, &len, d->stream);
		d->map[i] = line;
		i++;
	}
	d->cols = ft_strlen(d->map[0]);
}

int is_square(int r, int c, int size, data *d)
{
    if (r + size > d->rows || c + size > d->cols)
        return 0;
    for (int i = r; i < r + size; i++)//this loop checks the rows of the square
        for (int j = c; j < c + size; j++)
            if (d->map[i][j] != d->empty)
                return 0;
    return 1;
}

void	free_map(data *d)
{
	int i = 0;
	while (i < d->rows)
	{
		free(d->map[i]);
		i++;
	}
	free(d->map);
	fclose(d->stream);
}

void fill_square(int r, int c, int size, data *d)
{
    for (int i = r; i < r + size; i++)
        for (int j = c; j < c + size; j++)
            d->map[i][j] = d->full;
}

int	main(int argc, char **argv)
{
	data d;
	if (argc == 1)
		d.stream = stdin;
	else
		d.stream = fopen(argv[1], "r");
	read_map(argv, &d);
	int best_size = 0, best_r = 0, best_c = 0;
    for (int r = 0; r < d.rows; r++) {
        for (int c = 0; c < d.cols; c++) {
            for (int s = 1; is_square(r, c, s, &d); s++) {
                if (s > best_size) {
                    best_size = s;
                    best_r = r;
                    best_c = c;
                }
            }
        }
    }
	fill_square(best_r, best_c, best_size, &d);
	// for (int i = 0; i < d.rows; i++)
    //     printf("%s", d.map[i]);
	// fprintf(stdout,"------map------\n");
	int i = 0;
	while (i < d.rows)
	{
		fprintf(stdout, "%s", d.map[i]);
		i++;
	}
	// fprintf(stdout, "------chars------\n");
	// fprintf(stdout, "empty:%c\n", d.empty);
	// fprintf(stdout, "obstacle:%c\n", d.obstacle);
	// fprintf(stdout, "full:%c\n", d.full);
	// fprintf(stdout, "rows:%d\n", d.rows);
	// fprintf(stdout, "rows:%d\n", d.cols);

	free_map(&d);
	return 0;
}
