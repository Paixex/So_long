/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:33:27 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 16:01:14 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	*clean_printed(char *global_buffer)
{
	size_t	i;
	size_t	k;
	char	*new;

	i = 0;
	while (global_buffer[i] && global_buffer[i] != '\n')
		i++;
	if (!global_buffer[i])
	{
		free(global_buffer);
		return (NULL);
	}
	new = malloc(((ft_strlen(global_buffer) - i) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	k = 0;
	while (global_buffer[i])
		new[k++] = global_buffer[i++];
	new[k] = '\0';
	free(global_buffer);
	return (new);
}

static char	*get_line(char *global_buffer)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	len = 0;
	if (!global_buffer[i])
		return (NULL);
	while (global_buffer[len] && global_buffer[len] != '\n')
		len++;
	line = malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (i <= len)
	{
		line[i] = global_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char *join_n_free(char *global_buffer, char *local_buffer)
{
	size_t	i;
	size_t	k;
	size_t	len_global;
	size_t	len_local;
	char	*appended;

	if (!global_buffer || !local_buffer)
		return (NULL);
	len_global = ft_strlen(global_buffer);
	len_local = ft_strlen(local_buffer);
	appended = malloc((len_global + len_local + 1) * sizeof(char));
	if(!appended)
		return (NULL);
	i = 0;
	k = 0;
	while (k < len_global)
		appended[i++] = global_buffer[k++];
	k = 0;
	while (k < len_local)
		appended[i++] = local_buffer[k++];
	appended[i] = '\0';
	free (global_buffer);
	return (appended);
}

static char *read_buffsize(int fd, char *global_buffer)
{
	char	*buffer;
	int		bytes_read;

	if (global_buffer == NULL)
		global_buffer = ft_calloc(1, sizeof(char));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && global_buffer == NULL))
		{
		free(global_buffer);
		free(buffer);
		return (NULL);
		}
		buffer[bytes_read] = '\0';
		global_buffer = join_n_free(global_buffer, buffer);
		if (is_onstr(global_buffer, '\n') == true)
			break ;
	}
	free(buffer);
	return (global_buffer);
}

char	*get_next_line(int fd)
{
	static char	*global_buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	global_buffer[fd] = read_buffsize(fd, global_buffer[fd]);
	if (!global_buffer[fd])
		return (NULL);
	line = get_line(global_buffer[fd]);
	global_buffer[fd] = clean_printed(global_buffer[fd]);
	return (line);
}
