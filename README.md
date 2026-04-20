# Résolveur de Programmation Linéaire 2D

Ce programme en C résout des problèmes de programmation linéaire en deux variables (x, y) en utilisant la méthode d'énumération des sommets. Il trouve le maximum ou le minimum d'une fonction objectif sous contraintes linéaires.

## Fonctionnalités

- Saisie interactive des coefficients de la fonction objectif
- Choix entre maximisation ou minimisation
- Ajout dynamique de contraintes linéaires
- Calcul automatique de la solution optimale
- Affichage des sommets évalués et de la solution finale

## Compilation

Assurez-vous d'avoir GCC installé. Compilez avec :

```bash
gcc ro.c -o ro -lm
```

## Utilisation

Lancez le programme :

```bash
./ro
```

Le programme vous guidera à travers la saisie :

1. **Coefficients de la fonction objectif** : Entrez c1 et c2 pour Z = c1*x + c2*y
2. **Type d'optimisation** : 1 pour maximiser, 0 pour minimiser
3. **Nombre de contraintes** : Entrez le nombre de contraintes (max 10)
4. **Contraintes** : Pour chaque contrainte, entrez a, b, d pour a*x + b*y <= d

## Exemple

Voici un exemple d'exécution pour maximiser Z = 3x + 2y sous les contraintes :
- x + y <= 4
- x <= 3
- y <= 3

```
Entrez les coefficients de Z = c1*x + c2*y :
c1 : 3
c2 : 2
Maximiser (1) ou minimiser (0) ? 1

Entrez le nombre de contraintes : 3
=== AJOUT DES CONTRAINTES ===
Contrainte 1 : a*x + b*y <= d
a : 1
b : 1
d : 4
Contrainte ajoutée : 1.00x + 1.00y <= 4.00
Contrainte 2 : a*x + b*y <= d
a : 1
b : 0
d : 3
Contrainte ajoutée : 1.00x + 0.00y <= 3.00
Contrainte 3 : a*x + b*y <= d
a : 0
b : 1
d : 3
Contrainte ajoutée : 0.00x + 1.00y <= 3.00

=== RESOLUTION ===
Max Z = 3.00x + 2.00y

Evaluation des sommets :
  Sommet (3.00, 1.00) → Z = 11.00
  Sommet (1.00, 3.00) → Z = 9.00
  Sommet (3.00, 0.00) → Z = 9.00
  Sommet (-0.00, 3.00) → Z = 6.00
  Sommet (0.00, 0.00) → Z = 0.00

→ Optimum : x=3.00, y=1.00, Z=11.00
```

## Limitations

- Limité à 2 variables (x, y)
- Maximum 10 contraintes
- Suppose un problème réalisable avec solution optimale aux sommets
- Pas de gestion des problèmes non bornés ou irréalisables (sauf détection basique)

## Structure du code

- `main()` : Gestion de la saisie utilisateur
- `init_probleme()` : Initialisation du problème
- `ajouter_contrainte()` : Ajout d'une contrainte
- `intersection()` : Calcul de l'intersection de deux droites
- `est_realisable()` : Vérification si un point satisfait toutes les contraintes
- `resoudre()` : Résolution par énumération des sommets

## Dépendances

- `<stdio.h>` : Entrées/sorties
- `<math.h>` : Fonctions mathématiques (fabs, etc.)
- `<float.h>` : Constantes pour DBL_MAX</content>
<parameter name="filePath">/home/srasolov/log/README.md