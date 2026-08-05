#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <ctype.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define SIZE 7

typedef struct s_node
{
	char			*word;
	struct s_node	*next;
}					t_node;

extern t_node		*table[SIZE];

t_node				*createNode(char *word);
int					TotalAscii(char *str);

void				addHachage(char *content);
void				deleteHachage(char *word);
void				printTable(void);
void				free_table(void);

#endif