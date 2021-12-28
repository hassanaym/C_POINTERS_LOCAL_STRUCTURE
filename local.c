#include <stdio.h>
#include <string.h>
#include<conio.h>
typedef struct local
{
    int num;
    int nombreplaces;
    char type[10];
} Local;

void lireLocal(Local *l)
{
    printf("Donner un numero:");
    scanf("%d", &l->num);

    printf("Donner le nombre de places:");
    scanf("%d", &l->nombreplaces);

    printf("Donner le type:");
    scanf("%s", l->type);
}

void afficheLocal(Local l)
{
    printf("Num : %d\n", l.num);
    printf("Nombre places : %d\n", l.nombreplaces);
    printf("Type : %s\n", l.type);
    printf("------------\n");
}

int estTrie(Local *l, int taille) // *l  ======  l[]
{
    int i;
    for (i = 0; i < taille - 1; i++)
    {
        if (l[i].num > l[i + 1].num)
        {
            return -1;
        }
    }

    return 1;
}

int ChercherLocal(Local *l, int taille, int numLoc)
{
    int i, mid, min = 0, max = taille ;
    if (estTrie(l, taille) == -1)
    {
        for (i = 0; i < taille; i++)
        {
            if (l[i].num == numLoc)
            {
                return 1;
            }
        }
    }
    else
    {
        do
        {
            mid = (min + max + 1) / 2;
            printf("mid = %d max = %d min = %d\n", mid, max, min);
            getch();
            if (numLoc == l[mid].num)
            {
                return 1;
            }
            else
            {
                if (numLoc > l[mid].num)
                {
                    min = mid;
                }
                else
                {
                    max = mid;
                }
            }
        } while (max-min>1);
    }
    return -1;
}

/*
int t[3] = {3,9,0};
int a[3] = {1,99,0};

t=a;

if (t==a){

}
IMPOSSIBLE

#include<string>
strcpy(a,b); copie
strcmp(a,b); comparaison
strlen(a); la taille
*/

int FiltrerParType(Local *l, int taille, char *type)
{
    int i = 0;
    for (i = 0; i < taille; i++)
    {
        if (strcmp(l[i].type, type) == 0)
        {
            afficheLocal(l[i]);
        }
    }
}

int main()
{
    Local l[5];

    l[0].num = 3;
    strcpy(l[0].type, "salle");
    l[1].num = 5;
    strcpy(l[1].type, "amphi");
    l[2].num = 9;
    strcpy(l[2].type, "amphi");
    l[3].num = 12;
    strcpy(l[3].type, "amphi");
l[4].num = 72;
    strcpy(l[3].type, "amphi");	

    printf("%d",ChercherLocal(l, 5, 66));
}
