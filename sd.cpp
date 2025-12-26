void tri_sequentiel(int tab[], int n)
{
    int i, j, temps;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (tab[j] > tab[i]) 
            {
                temps = tab[i];
                tab[i] = tab[j];
                tab[j] = temps;
            }
        }
    }
}

int recherche_dichotomique(int tab[], int n, int val)
{
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2; 
        if (tab[mid] == val)
            return mid; 
        else if (tab[mid] < val)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; 
}  

