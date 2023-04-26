#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "fonction.h"

int main()
{
    int fin = 0;
    char finchoix;
    while (fin != 1)
    {
        struct Pokemon Pok = {};
        int choix;
        printf("Que voulez vous faire ? Tapez \n 1 pour voir les données d'un pokemon,\n 2 pour voir tous les pokemon d'un type, \n 3 pour voir tous les pokemon d'une génération, \n 4 pour voir tous les pokemon avec un total supérieur ou égal à 600, \n 5 pour avoir les informations avec un nom \n");
        scanf("%d", &choix);
        fflush(stdin);
        switch (choix)
        {
        case 1:
        {
            int a = 0;
            int n = 0;
            while (a != 1)
            {

                printf("entrez le numéro de pokemon souhaitez : ");
                scanf("%d", &n);
                if (n > 0 && n <= 721)
                {
                    a = 1;
                }
                else
                {
                    printf("Ce numéro n'existe pas ou n'est pas attribué a un pokemon réessayer !\n ");
                }

                fflush(stdin);
            }
            Pok = informationPokemon(n);
            printf("Numéro: %d\n", Pok.Num);
            printf("Nom: %s\n", Pok.Name);
            printf("Type: %s\n", Pok.Type1);
            printf("Type Secondaire: %s\n", Pok.Type2);
            printf("Total: %d\n", Pok.Total);
            printf("HP: %d\n", Pok.HP);
            printf("Attaque: %d\n", Pok.Attack);
            printf("Défense: %d\n", Pok.Defense);
            printf("Attaque Spé: %d\n", Pok.SpAtk);
            printf("Défense spé: %d\n", Pok.SpDef);
            printf("Vitesse: %d\n", Pok.Speed);
            printf("Génération: %d\n", Pok.Generation);
            printf("Légendaire: %s\n", Pok.Legendary);
            struct Pokemon Pok = {};
            break;
        }
        case 2:
        {
            nomParType();
            break;
        }
        case 3:
        {
            nomParGeneration();
            break;
        }
        case 4:
        {
            nomSup600();
            break;
        }
        case 5:
        {
            Rechercheparnom();
            break;
        }
        default:
            printf("Je ne comprend pas réessayer \n");
            sleep(1);
            continue;
        }
        fflush(stdin);
        printf("Voulez vous avoir une autre information ? Y/N \n");
        scanf("%c", &finchoix);
        if (finchoix == 78 || finchoix == 110)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    printf("Au revoir !");
    return 0;
}
