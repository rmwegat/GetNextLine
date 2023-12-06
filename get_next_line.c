/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:21:19 by rwegat            #+#    #+#             */
/*   Updated: 2023/12/06 16:24:32 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line_len(t_list *list)
{
	int	len;
	int	i;

	len = 0;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list -> str_buf[i])
		{
			if (list -> str_buf[i] != '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

char	*get_line(t_list *list)
{
	char	*next_str;
	int		str_len;

	if (!list)
		return (NULL);
	str_len = get_line_len(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	create_list(t_list **list, int fd)
{
	int		chars_read;
	char	*buf;

	while (find_newline(*list) == 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buf);
			return ;
		}
		buf[chars_read] = '\0';
		lst_add_back(list, buf);
	}
}

void	free_upto_newline(t_list **list)
{
	t_list	*temp;
	t_list	*new_node;
	int		i;
	int		len;
	char	*buf;

	if (*list == NULL)
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (!buf || !new_node)
		return ;
	new_node = find_last(*list);
	i = 0;
	len = 0;
	while (new_node->str_buf[len] && new_node->str_buf[i] != '\n')
		len++;
	while (new_node->str_buf[i] && new_node->str_buf[i++])
		buf[i++] = new_node->str_buf[len];
	buf[i] = '\0';
	temp->str_buf = buf;
	temp->next = NULL;
	free_list(list, temp, buf);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	free_all_but_last(&list);
	return (next_line);
}
