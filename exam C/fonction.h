#ifndef fonction_h
#define fonction_h

struct Pokemon
{
    int Num;
    char Name[50];
    char Type1[50];
    char Type2[50];
    int Total;
    int HP;
    int Attack;
    int Defense;
    int SpAtk;
    int SpDef;
    int Speed;
    int Generation;
    char Legendary[7];
};

struct Pokemon informationPokemon(int n);
int nomParType();
int nomParGeneration();
int nomSup600();
int Rechercheparnom();

#endif /* fonction_h */