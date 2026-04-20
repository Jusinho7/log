#include <float.h>
#include <math.h>
#include <stdio.h>

#define MAX_VAR 10
#define MAX_CON 10
#define EPS     1e-9

typedef struct
{
    double  t[MAX_CON + 1][MAX_VAR + MAX_CON + 1];
    int     base[MAX_CON]; 
    int     m;             
    int     n;             
}           Simplexe;

void    init_simplexe(Simplexe *s, int m, int n)
{
    s->m = m;
    s->n = n;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j < n + m + 1; j++)
            s->t[i][j] = 0.0;
    for (int i = 0; i < m; i++)
    {
        s->t[i][n + i] = 1.0; 
        s->base[i] = n + i;
    }
}

void    ajouter_contrainte(Simplexe *s, int ligne, double coeffs[], double d)
{
    for (int j = 0; j < s->n; j++)
        s->t[ligne][j] = coeffs[j];
    s->t[ligne][s->n + s->m] = d; 
}

void    ajouter_objectif(Simplexe *s, double coeffs[])
{
    for (int j = 0; j < s->n; j++)
        s->t[s->m][j] = -coeffs[j]; 
}

int     col_pivot(Simplexe *s)
{
    int     col = -1;
    double  min = -EPS;

    for (int j = 0; j < s->n + s->m; j++)
    {
        if (s->t[s->m][j] < min)
        { 
            min = s->t[s->m][j];
            col = j; 
        }
    }
    return (col); 
}

int     ligne_pivot(Simplexe *s, int col)
{
    int     lig = -1;
    double  min = DBL_MAX;

    for (int i = 0; i < s->m; i++)
    {
        if (s->t[i][col] <= EPS) 
            continue ;
        double ratio = s->t[i][s->n + s->m] / s->t[i][col];
        if (ratio < min) { min = ratio; lig = i; }
    }
    return (lig); 
}

void    pivoter(Simplexe *s, int lig, int col)
{
    double  pivot = s->t[lig][col];
    int     total = s->n + s->m + 1;

    for (int j = 0; j < total; j++)
        s->t[lig][j] /= pivot;
    for (int i = 0; i <= s->m; i++)
    {
        if (i == lig) 
            continue ;
        double  f = s->t[i][col];
        for (int j = 0; j < total; j++)
            s->t[i][j] -= f * s->t[lig][j];
    }
    s->base[lig] = col;
}

void    resoudre(Simplexe *s)
{
    int col, lig;

    while (1)
    {
        col = col_pivot(s);
        if (col == -1) break ;          
        lig = ligne_pivot(s, col);
        if (lig == -1)                  
        { 
            printf("Solution non bornee.\n"); 
            return ; 
        }
        pivoter(s, lig, col);
    }

    printf("\n→ Solution optimale :\n");
    double sol[MAX_VAR] = {0};
    for (int i = 0; i < s->m; i++)
        if (s->base[i] < s->n)
            sol[s->base[i]] = s->t[i][s->n + s->m];

    for (int j = 0; j < s->n; j++)
        printf("  x%d = %.2f\n", j + 1, sol[j]);
    printf("  Z  = %.2f\n", s->t[s->m][s->n + s->m]);
}

int     main(void)
{
    Simplexe    s;
    int         m, n;
    double      coeffs[MAX_VAR];
    double      d;

    printf("Nombre de variables : ");   scanf("%d", &n);
    printf("Nombre de contraintes : "); scanf("%d", &m);

    init_simplexe(&s, m, n);

    printf("\nCoefficients de Z (maximisation) :\n");
    for (int j = 0; j < n; j++)
    { 
        printf("  c%d : ", j + 1); 
        scanf("%lf", &coeffs[j]); 
    }
    ajouter_objectif(&s, coeffs);
    printf("\nContraintes (ax + by <= d) :\n");
    for (int i = 0; i < m; i++)
    {
        printf("Contrainte %d :\n", i + 1);
        for (int j = 0; j < n; j++)
        { 
            printf("  a%d : ", j + 1); 
            scanf("%lf", &coeffs[j]); 
        }
        printf("  d  : "); scanf("%lf", &d);
        ajouter_contrainte(&s, i, coeffs, d);
    }
    resoudre(&s);
    return (0);
}
