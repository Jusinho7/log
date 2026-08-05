#include "Hachage.h"

t_node	*table[SIZE];

t_node	*createNode(char *word)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->word = strdup(word);
	new->next = NULL;
	return (new);
}

int	TotalAscii(char *str)
{
	int	sum;

	sum = 0;
	while (*str)
	{
		sum += tolower((unsigned char)*str);
		str++;
	}
	return (sum);
}

void	addHachage(char *content)
{
	int		index;
	t_node	*new;

	index = TotalAscii(content) % SIZE;
	new = createNode(content);
	if (new == NULL)
		return ;
	new->next = table[index];
	table[index] = new;
}

void	deleteHachage(char *word)
{
	int		index;
	t_node	*curr;
	t_node	*prev;

	index = TotalAscii(word) % SIZE;
	curr = table[index];
	prev = NULL;
	while (curr)
	{
		if (strcmp(curr->word, word) == 0)
		{
			if (prev == NULL)
				table[index] = curr->next;
			else
				prev->next = curr->next;
			free(curr->word);
			free(curr);
			printf("\"%s\" supprimé.\n", word);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("\"%s\" introuvable.\n", word);
}

void	printTable(void)
{
	t_node	*tmp;
	int		i;

	printf("\tTABLE DE HACHAGE\n");
	i = 0;
	while (i < SIZE)
	{
		tmp = table[i];
		printf("[%d] ", i);
		if (tmp == NULL)
			printf("VIDE");
		else
		{
			while (tmp)
			{
				printf("%s", tmp->word);
				if (tmp->next)
					printf(" -> ");
				tmp = tmp->next;
			}
		}
		printf("\n");
		i++;
	}
}

void	free_table(void)
{
	int i;
	t_node *tmp;
	t_node *next;

	i = 0;
	while (i < SIZE)
	{
		tmp = table[i];
		while (tmp)
		{
			next = tmp->next;
			free(tmp->word);
			free(tmp);
			tmp = next;
		}
		i++;
	}
}