#include <float.h>
#include <math.h>
#include <stdio.h>

#define MAX 10
#define EPS 1e-9

typedef struct { double a, b, d; }  Contrainte;
typedef struct { double x, y; }     Point;
typedef struct 
{
    Contrainte  c[MAX];
    int         n, max;
    double      c1, c2;
}               Probleme;

void    ajouter(Probleme *pb, double a, double b, double d)
{
    if (pb->n >= MAX) 
    { 
        printf("Limite atteinte!\n"); 
        return ; 
    }
    pb->c[pb->n++] = (Contrainte){a, b, d};
}

int     intersection(Contrainte d1, Contrainte d2, Point *p)
{
    double det = d1.a * d2.b - d2.a * d1.b;

    if (fabs(det) < EPS) 
        return (0);
    p->x = (d1.d * d2.b - d2.d * d1.b) / det;
    p->y = (d1.a * d2.d - d2.a * d1.d) / det;
    return (1);
}

int     realisable(Point p, Probleme *pb)
{
    if (p.x < -EPS || p.y < -EPS) 
        return (0);
    for (int i = 0; i < pb->n; i++)
        if (pb->c[i].a * p.x + pb->c[i].b * p.y > pb->c[i].d + EPS)
            return (0);
    return (1);
}

void    resoudre(Probleme *pb)
{
    Contrainte  t[MAX + 2];
    Point       p, p_opt;
    double      z, z_opt = pb->max ? -DBL_MAX : DBL_MAX;
    int         trouve = 0;

    for (int i = 0; i < pb->n; i++) 
        t[i] = pb->c[i];
    t[pb->n]     = (Contrainte){1, 0, 0};
    t[pb->n + 1] = (Contrainte){0, 1, 0};

    for (int i = 0; i < pb->n + 2; i++)
        for (int j = i + 1; j < pb->n + 2; j++)
        {
            if (!intersection(t[i], t[j], &p) || !realisable(p, pb))
                continue ;
            z = pb->c1 * p.x + pb->c2 * p.y;
            printf("  (%.2f, %.2f) → Z = %.2f\n", p.x, p.y, z);
            if ((pb->max && z > z_opt) || (!pb->max && z < z_opt))
            { z_opt = z; p_opt = p; trouve = 1; }
        }
    if (trouve)
        printf("\n→ x=%.2f, y=%.2f, Z=%.2f\n", p_opt.x, p_opt.y, z_opt);
    else
        printf("\nAucune solution.\n");
}

int     main(void)
{
    Probleme    pb = {.n = 0};
    double      a, b, d;
    int         n;

    printf("Entrez les coefficients de Z = c1*x + c2*y\n");
    printf("c1 : ");      scanf("%lf", &pb.c1);
    printf("c2 : ");      scanf("%lf", &pb.c2);
    printf("\nMax(1)/Min(0) : "); scanf("%d", &pb.max);

    printf("\nNombre de contraintes : "); scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Contrainte %d (a b d) =>  a*x + b*y <= d : \n", i + 1);
        scanf("%lf %lf %lf", &a, &b, &d);
        ajouter(&pb, a, b, d);
    }

    printf("\n%s Z = %.2fx + %.2fy\n", pb.max ? "Max" : "Min", pb.c1, pb.c2);
    resoudre(&pb);
    return (0);
}