/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:23:48 by rwegat            #+#    #+#             */
/*   Updated: 2023/12/04 16:40:28 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_last(t_list *list)
{
	if (list == NULL)
		return (NULL);
	if (list -> next == NULL)
		return (list);
	return (find_last(list -> next));
}

void	lst_add_back(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
	{
		*list = new_node;
	}
	else
		last_node -> next = new_node;
	new_node -> str_buf = buf;
	new_node -> next = NULL;
}

int	find_newline(t_list *list)
{
	while (list)
	{
		if (strchr(list->str_buf, '\n'))
			return (1);
		list = list->next;
	}
	return (0);
}

//replace strcpy 
void	copy_str(t_list *list, char *next_str)
{
	while (list)
	{
		strcpy(next_str, list->str_buf);
		next_str += strlen(list->str_buf);
		list = list->next;
	}
	*next_str = '\0';
}

void	free_all_but_last(t_list **list)
{
	t_list	*temp;
	t_list	*current;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	current = *list;
	while (current->next != NULL)
	{
		temp = current;
		current = current->next;
		free(temp->str_buf);
		free(temp);
	}
	current->next = NULL;
}
