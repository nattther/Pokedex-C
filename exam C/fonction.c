#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fonction.h"

char pokemonTypesFR[36][40] = {
    "Normal", "Feu", "Eau", "Electrik", "Plante", "Glace", "Combat",
    "Poison", "Sol", "Vol", "Psy", "Insecte", "Roche", "Spectre",
    "Dragon", "Tenebres", "Acier", "Fee", "normal", "feu", "eau", "electrik", "plante", "glace", "combat",
    "poison", "sol", "vol", "psy", "insecte", "roche", "spectre",
    "dragon", "tenebres", "acier", "fee"};
char pokemonTypesEN[36][40] = {
    "Normal", "Fire", "Water", "Electric", "Grass", "Ice", "Fighting",
    "Poison", "Ground", "Flying", "Psychic", "Bug", "Rock", "Ghost",
    "Dragon", "Dark", "Steel", "Fairy", "Normal", "Fire", "Water", "Electric", "Grass", "Ice", "Fighting",
    "Poison", "Ground", "Flying", "Psychic", "Bug", "Rock", "Ghost",
    "Dragon", "Dark", "Steel", "Fairy"};

struct Pokemon informationPokemon(int n)

{

    struct Pokemon Pokn;
    FILE *pokedex;
    pokedex = fopen("C:\\Users\\Nathan\\Documents\\cours\\exam C\\CSV Annexe.csv", "r");
    if (pokedex == NULL)
    {
        printf("Impossible d'ouvrir le fichier \n");
    }
    char line[100];
    int count = 0;
    char *information;

    while (fgets(line, sizeof(line), pokedex))
    {
        count++;
        if (count == n + 1)
        {
            information = strtok(line, ",");
            Pokn.Num = atoi(information);

            information = strtok(NULL, ",");
            strcpy(Pokn.Name, information);

            information = strtok(NULL, ",");
            strcpy(Pokn.Type1, information);
            for (int i = 0; i < 18; i++)
            {
                if (strcmp(Pokn.Type1, pokemonTypesEN[i]) == 0)
                {

                    strcpy(Pokn.Type1, pokemonTypesFR[i]);
                }
            }
            information = strtok(NULL, ",");
            char rien[60]= "Pas de type secondaire";
            strcpy(Pokn.Type2, rien);
            if (atoi(information) == 0)
            {
                strcpy(Pokn.Type2, information);
                information = strtok(NULL, ",");
            }
            for (int i = 0; i < 18; i++)
            {
                if (strcmp(Pokn.Type2, pokemonTypesEN[i]) == 0)
                {
                    strcpy(Pokn.Type2, pokemonTypesFR[i]);
                }
            }
            Pokn.Total = atoi(information);

            information = strtok(NULL, ",");
            Pokn.HP = atoi(information);

            information = strtok(NULL, ",");
            Pokn.Attack = atoi(information);

            information = strtok(NULL, ",");
            Pokn.Defense = atoi(information);

            information = strtok(NULL, ",");
            Pokn.SpAtk = atoi(information);

            information = strtok(NULL, ",");
            Pokn.SpDef = atoi(information);

            information = strtok(NULL, ",");
            Pokn.Speed = atoi(information);

            information = strtok(NULL, ",");
            Pokn.Generation = atoi(information);

            information = strtok(NULL, "\n");
            if (strcmp(information, "False") == 0)
            {
                char Faux[5]="non";         
                information = Faux;
                strcpy(Pokn.Legendary, information);
            }
            else {
                char Vrai[5]="oui";         
                information = Vrai;
                strcpy(Pokn.Legendary, information);

            }



            break;
        }
    }

    fclose(pokedex);

    return Pokn;
}

int nomParType()
{

    struct Pokemon Pokn;
    char typechoix[3000];
    char type[3000];
    char type2[3000];
    char typemin[3000];
    char type2min[3000];
    int a = 0;
    while (a != 1)
    {
        printf("entrez le type sans accent \n");
        scanf("%s", &typechoix);
        for (int i = 0; i < 36; i++)
        {
            if (strcmp(typechoix, pokemonTypesFR[i]) == 0)
            {
                a = 1;
            }
        }
        if (a != 1)
        {
            printf("Ce n'est pas un type réessayer ! \n");
        }
    }

    int t = 0;

    while (t <= 721)
    {
        Pokn = informationPokemon(t);
        sprintf(type, "%s", Pokn.Type1);
        for (int i = 0; i < 18; i++)
        {
            if (strcmp(Pokn.Type1, pokemonTypesFR[i]) == 0)
            {

                sprintf(typemin, pokemonTypesFR[i + 18]);
            }
        }
        sprintf(type2, "%s", Pokn.Type2);

        for (int i = 0; i < 18; i++)
        {
            if (strcmp(Pokn.Type2, pokemonTypesFR[i]) == 0)
            {

                sprintf(type2min, pokemonTypesFR[i + 18]);
            }
        }
        if (strcmp(type, typechoix) == 0 || strcmp(type2, typechoix) == 0 || strcmp(type2min, typechoix) == 0 || strcmp(typemin, typechoix) == 0)
        {
            printf("%s \n", Pokn.Name);
        }
        t++;
        sprintf(typemin, "vide");
        sprintf(type2min, "vide");
        sprintf(type, "vide");
        sprintf(type2, "vide");
    }

    return 0;
}

int nomParGeneration()
{

    struct Pokemon Pokn;
    int Choix;
    int Gen;
    int a = 0;
    while (a != 1)
    {
        printf("entrez la génération \n");
        scanf("%d", &Choix);
        fflush(stdin);

        if (Choix > 0 && Choix < 7)
        {
            a = 1;
        }
        else
        {
            printf("Aucune génération ne correspond a votre entrée ! \n");
        }
    }

    int t = 0;
    while (t <= 721)
    {
        Pokn = informationPokemon(t);
        Gen = Pokn.Generation;
        if (Gen == Choix)
        {
            printf("%s \n", Pokn.Name);
        }
        t++;
    }

    return 0;
}

int nomSup600()

{

    struct Pokemon Pokn;
    int t = 0;
    while (t <= 721)
    {
        Pokn = informationPokemon(t);

        if (Pokn.Total >= 600)
        {
            printf("%s \n", Pokn.Name);
        }
        t++;
    }
    return 1;
}

int Rechercheparnom()
{

    struct Pokemon Pokn;
    char nomchoix[3000];
    char nom[3000];
    int a = 0;

    while (a != 1)
    {

        printf("entrez le nom avec une majuscule et en anglais \n");
        scanf("%s", &nomchoix);
        int t = 0;

        while (t <= 722)
        {
            if (t == 722)
            {
                printf("entrez un bon nom \n");
                sleep(1);
                
            }
            else
            {

                Pokn = informationPokemon(t);
                sprintf(nom, "%s", Pokn.Name);

                if (strcmp(nomchoix, nom) == 0)
                {
                    printf("Numéro: %d\n", Pokn.Num);
                    printf("Nom: %s\n", Pokn.Name);
                    printf("Type: %s\n", Pokn.Type1);
                    printf("Type Secondaire: %s\n", Pokn.Type2);
                    printf("Total: %d\n", Pokn.Total);
                    printf("HP: %d\n", Pokn.HP);
                    printf("Attaque: %d\n", Pokn.Attack);
                    printf("Défense: %d\n", Pokn.Defense);
                    printf("Attaque Spé: %d\n", Pokn.SpAtk);
                    printf("Défense spé: %d\n", Pokn.SpDef);
                    printf("Vitesse: %d\n", Pokn.Speed);
                    printf("Génération: %d\n", Pokn.Generation);
                    printf("Légendaire: %s\n", Pokn.Legendary);
                    a = 1;
                    break;
                }
            }

            t++;
        }
        
    }
    return 1;
    }