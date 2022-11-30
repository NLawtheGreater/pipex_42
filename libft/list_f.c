#include "libft.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new)
	{
		if (!lst)
		{
			*lst = new;
			return ;
		}
		new->next = *lst;
		*lst = new;
	}
}

/*t_stack	*commence ()
{
	t_stack	*a;

	a = (t_stack*) malloc(sizeof(t_stack));
	ft_lstnew()

}*/


t_stack	*ft_lstnew(int data)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
		}
		else
		{
			ptr = ft_lstlast(*lst);
			ptr->next = new;
		}
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void	lst_check(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
	return;
	tmp = *lst;
	while (tmp != NULL)
	{
		ft_printf("%i\n", tmp->data);		
		tmp = tmp->next;
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*ptr;

	if (!*lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		free (*lst);
		*lst = ptr;
	}
	*lst = NULL;
}

void	ft_lstdelfront(t_stack **lst)
{
	t_stack	*ptr;

	ptr = (*lst)->next;
	free(*lst);
	*lst = ptr;
}

