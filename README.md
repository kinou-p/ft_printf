# ft_printf

## Description
ft_printf est un projet de l'École 42 qui consiste à recoder la fonction `printf` de la libc. Ce projet permet de comprendre en profondeur le fonctionnement des fonctions variadiques et de la gestion de format en C.

## Objectifs pédagogiques
- Maîtriser les **fonctions variadiques** (`va_list`, `va_start`, `va_arg`, `va_end`)
- Comprendre le **parsing de format strings**
- Gérer différents **types de données** et leur affichage
- Optimiser les **performances** d'affichage
- Respecter le **comportement exact** de printf

## Conversions supportées

### Conversions obligatoires
- `%c` - Caractère unique
- `%s` - Chaîne de caractères
- `%p` - Pointeur (adresse mémoire en hexadécimal)
- `%d` - Entier décimal signé
- `%i` - Entier décimal signé
- `%u` - Entier décimal non signé
- `%x` - Entier hexadécimal minuscules
- `%X` - Entier hexadécimal majuscules
- `%%` - Caractère pourcentage littéral

### Bonus (flags, width, precision)
- **Flags** : `-`, `0`, `#`, ` `, `+`
- **Width** : largeur minimale d'affichage
- **Precision** : précision pour les nombres/strings

## Technologies utilisées
- **Langage** : C (C99)
- **Fonctions variadiques** : `stdarg.h`
- **Gestion mémoire** : malloc/free
- **I/O** : write system call uniquement

## Installation et compilation

### 1. Cloner le projet
```bash
git clone <repository-url>
cd ft_printf
```

### 2. Compiler la bibliothèque
```bash
make
```

### 3. Nettoyer les fichiers objets
```bash
make clean    # Supprime les .o
make fclean   # Supprime tout + la bibliothèque
make re       # Recompile tout
```

### 4. Utiliser dans un projet
```c
#include "ft_printf.h"

// Compiler avec : gcc -L. -lftprintf main.c
```

## Structure du projet
```
ft_printf/
├── Makefile          # Compilation
├── ft_printf.h       # Header principal
├── ft_printf.c       # Fonction principale
├── utils.c           # Fonctions utilitaires
└── README.md         # Documentation
```

## Utilisation

### Syntaxe de base
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

### Exemples de conversions
```c
// Caractères et strings
ft_printf("Char: %c\n", 'A');           // Char: A
ft_printf("String: %s\n", "Hello");     // String: Hello

// Nombres entiers
ft_printf("Decimal: %d\n", 42);         // Decimal: 42
ft_printf("Integer: %i\n", -42);        // Integer: -42
ft_printf("Unsigned: %u\n", 42U);       // Unsigned: 42

// Hexadécimal
ft_printf("Hex lower: %x\n", 255);      // Hex lower: ff
ft_printf("Hex upper: %X\n", 255);      // Hex upper: FF

// Pointeurs
ft_printf("Address: %p\n", ptr);        // Address: 0x7fff5fbff710

// Pourcentage littéral
ft_printf("Percentage: %%\n");          // Percentage: %
```

## Implémentation

### Architecture générale
1. **Parsing** de la format string
2. **Identification** du type de conversion
3. **Extraction** des arguments avec `va_arg`
4. **Conversion** vers string/affichage
5. **Écriture** avec write()

### Gestion des types
```c
int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    // Parse format string
    // Handle each conversion specifier
    // Use va_arg to get arguments
    
    va_end(args);
    return (chars_written);
}
```

### Fonctions utilitaires
- Conversion nombres → strings
- Gestion base hexadécimale
- Calcul longueur des nombres
- Affichage optimisé

## Tests et validation

### Tests de base
```bash
# Comparaison avec printf système
gcc -o test_printf test.c -L. -lftprintf
./test_printf
```

### Tests automatisés
- Comparaison output avec printf original
- Tests edge cases (NULL pointers, 0, INT_MAX/MIN)
- Tests de performance
- Memory leak detection

## Contraintes et spécifications

### Normes 42
- **Norme de codage** stricte
- **Pas de variables globales**
- **Gestion d'erreurs** appropriée
- **Pas de memory leaks**

### Fonctions autorisées
- `malloc`, `free`
- `write`
- `va_start`, `va_arg`, `va_copy`, `va_end`

### Valeur de retour
- Nombre de caractères affichés
- -1 en cas d'erreur (comme printf)

## Performance et optimisations
- **Buffer interne** pour réduire les appels write
- **Conversion directe** sans sprintf
- **Gestion efficace** des strings longues
- **Précalcul** des tailles d'affichage

## Compétences développées
- Fonctions variadiques en C
- Parsing et traitement de chaînes
- Conversion de types de données
- Optimisation des I/O
- Gestion mémoire rigoureuse

## Auteur
Alexandre Pommier (apommier) - École 42

## Licence
Projet académique - École 42