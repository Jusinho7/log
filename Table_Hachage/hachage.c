#include "Hachage.h"

int	main(int ac, char **av)
{
	int i;
	int choice;
	char content[256];

	i = 1;
	while (i < ac)
	{
		addHachage(av[i]);
		i++;
	}
	while (1)
	{
		printf("\n===== HASH TABLE =====\n");
		printf("1. Display\n");
		printf("2. Add\n");
		printf("3. Delete\n");
		printf("0. Quit\n");
		printf("Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
            case 1:
                printTable();
                break ;
            case 2:
                printf("Word: ");
                scanf("%255s", content);
                addHachage(content);
                break ;
            case 3:
                printf("Word: ");
                scanf("%255s", content);
                deleteHachage(content);
                break ;
            case 0:
                free_table();
                return (0);
            default:
                printf("Invalid choice.\n");
		}
	}

	return (0);
}