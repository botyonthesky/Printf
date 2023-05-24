/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:30:19 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/05 16:26:31 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst)
	{
		ft_lstlast(*lst)->next = new;
	}
	else
		*lst = new;
}

/*#include <stdio.h>

int main()
{
    t_list *lst = NULL;
    t_list *new_elem;

    new_elem = ft_lstnew("Premier element");
    ft_lstadd_back(&lst, new_elem);

    new_elem = ft_lstnew("Deuxeme element");
    ft_lstadd_back(&lst, new_elem);

    new_elem = ft_lstnew("Troisieme element");
    ft_lstadd_back(&lst, new_elem);

    new_elem = ft_lstnew("Quatrieme element");
    ft_lstadd_back(&lst, new_elem);

    new_elem = ft_lstnew("Cinquieme element");
    ft_lstadd_front(&lst, new_elem);

    
    t_list *current = lst;
    while (current != NULL)
    {
        printf("%s\n", (char*)current->content);
        current = current->next;
    }

    return 0;
}*/
