# Méthode du Simplexe pour la Programmation Linéaire

Ce document décrit la méthode du simplexe, un algorithme classique pour résoudre les problèmes de programmation linéaire. Contrairement à l'énumération des sommets utilisée dans `ro.c` (limitée à 2 variables), la méthode du simplexe peut gérer un nombre arbitraire de variables et contraintes.

## Qu'est-ce que la Programmation Linéaire ?

La programmation linéaire consiste à optimiser (maximiser ou minimiser) une fonction objectif linéaire sous contraintes linéaires :

```
Max/Min Z = c₁x₁ + c₂x₂ + ... + cₙxₙ
Sous :
a₁₁x₁ + a₁₂x₂ + ... + a₁ₙxₙ ≤ b₁
a₂₁x₁ + a₂₂x₂ + ... + a₂ₙxₙ ≤ b₂
...
aₘ₁x₁ + aₘ₂x₂ + ... + aₘₙxₙ ≤ bₘ
x₁, x₂, ..., xₙ ≥ 0
```

## Principe de la Méthode du Simplexe

La méthode du simplexe est un algorithme itératif qui :

1. **Convertit le problème en forme standard** : Ajoute des variables d'écart pour transformer les inégalités en égalités
2. **Construit le tableau du simplexe** : Une matrice contenant les coefficients des contraintes et de la fonction objectif
3. **Itère vers l'optimum** :
   - Identifie la variable entrante (celle qui améliore le plus Z)
   - Identifie la variable sortante (celle qui limite le plus l'amélioration)
   - Effectue un pivot pour mettre à jour le tableau
4. **S'arrête** quand aucune amélioration n'est possible

## Avantages par rapport à l'énumération des sommets

- **Efficacité** : Complexité polynomiale en moyenne, contrairement à l'énumération exponentielle
- **Généralité** : Fonctionne pour n variables et m contraintes
- **Robustesse** : Gère les problèmes de grande taille
- **Détection automatique** : Identifie les problèmes non bornés ou irréalisables

## Exemple Simple

Max Z = 3x + 2y
x + y ≤ 4
x ≤ 3
y ≤ 3
x, y ≥ 0

Après ajout des variables d'écart s₁, s₂, s₃ :

Max Z = 3x + 2y + 0s₁ + 0s₂ + 0s₃
x + y + s₁ = 4
x + s₂ = 3
y + s₃ = 3

Tableau initial :
```
   x   y  s1  s2  s3   b
   3   2   0   0   0   0  (Z)
   1   1   1   0   0   4  (s1)
   1   0   0   1   0   3  (s2)
   0   1   0   0   1   3  (s3)
```

Après plusieurs pivots, on atteint la solution optimale x=3, y=1, Z=11.

## Implémentation en C

Une implémentation complète nécessiterait :

- Gestion dynamique des tableaux 2D
- Fonctions de pivotage
- Détection de l'optimalité
- Gestion des cas dégénérés
- Conversion en forme standard

## Comparaison avec ro.c

| Aspect | ro.c (Énumération) | Simplexe |
|--------|-------------------|----------|
| Variables | 2 max | Illimité |
| Contraintes | 10 max | Illimité |
| Complexité | O(2^m) | O(n*m) moyen |
| Précision | Exacte | Exacte |
| Facilité d'implémentation | Simple | Complexe |

## Références

- "Linear Programming" de George Dantzig (inventeur du simplexe)
- Cours d'optimisation et recherche opérationnelle
- Implémentations open-source comme GLPK ou CPLEX

## Code d'exemple simplifié

Voici un squelette pour une implémentation basique :

```c
#define MAX_VAR 100
#define MAX_CON 100

typedef struct {
    double tableau[MAX_CON+1][MAX_VAR+MAX_CON+1];
    int nb_var, nb_con;
    int base[MAX_CON];
} Simplex;

void pivot(Simplex *s, int entree, int sortie) {
    // Implémentation du pivotage
}

int resoudre_simplex(Simplex *s) {
    while (1) {
        // Trouver variable entrante
        // Trouver variable sortante
        // Pivoter ou arrêter
    }
}
```

Pour une implémentation complète, consultez des ressources spécialisées.</content>
<parameter name="filePath">/home/srasolov/log/README_2.md