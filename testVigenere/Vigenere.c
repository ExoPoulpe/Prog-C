/*
*
*Author:    Troller Fabian
*Grade:     Tecnician ES in ComputerScientist
*Version:   1.0.0.0
*Date:      01.28.2018
*Description:   Encode and Decode by Vigenere methods with password
*
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE_TEXT 2048
#define MAX_LETTRE_NUMBER 26
#define MAX_PASSWORD_LENGTH 128

char Key[MAX_PASSWORD_LENGTH],Text[MAX_SIZE_TEXT],Chiffrer[MAX_SIZE_TEXT],lettre[MAX_LETTRE_NUMBER]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};//,' '};
unsigned int nombre[MAX_LETTRE_NUMBER] =                                              {0, 1,  2,   3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13,  14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};//, 26};
signed int valueChiffrer=0,valueDechiffrer=0;
char Choice;
char result[MAX_SIZE_TEXT];

unsigned int carFindInList(char alphabet[],char caractere)
{

    unsigned int i=0;

    for(i=0;i<strlen(alphabet);i++)
    {
        if(alphabet[i]==caractere)
        {
            return i;
            break;
        }

    }
}

signed int carOverFlowList(signed int Value)
{
    if(Value>MAX_LETTRE_NUMBER)
    {
        Value=Value-MAX_LETTRE_NUMBER;
    }
    if(Value<0)
    {
        Value=Value+MAX_LETTRE_NUMBER;
    }



    return Value;
}




char chiffreVigenere(char texte[],char key[],char stringResult[MAX_SIZE_TEXT])
{
    unsigned int i=0,valueKey=0,valueText=0,valueResult=0;
    signed long int j=0;

    for(i=0; i < strlen(texte)-1; i++)
    {
        //printf("%d",strlen(texte));
        if(j>=strlen(Key))
            j=0;
        valueKey = carFindInList(lettre,key[j]);
        if(texte[i]!=' ')
        {
            valueText = carFindInList(lettre,texte[i]);
        }
        else
        {
            j--;
        }




       // valueChiffrer = Cut((locate(texte[i],key[i]) + locate(Key[j])));
       // valueDechiffrer=Cut((locate(texte[i]) - locate(Key[j])-1));
        //printf("%d",(locate(Text[i]) + locate(Key[j])) % 26);


        if(Choice=='C' || Choice == 'c')
        {
            if(texte[i]!=' ')
        {
            valueResult=carOverFlowList(valueText+valueKey);
            stringResult[i] = lettre[valueResult];//=  %d\n
        }
        else if(texte[i]==' ')
        {
            stringResult[i] = ' ';
        }


        }
        else if(Choice == 'D' || Choice == 'd')
        {
            if(texte[i]!=' ')
        {
            valueResult=carOverFlowList(valueText-valueKey);
            stringResult[i] = lettre[valueResult];//=  %d\n
        }
        else if(texte[i]==' ')
        {
            stringResult[i] = ' ';
        }


        }

        if(i>=strlen(texte))
        {
            break;
        }
        j++;

    }




}

void stringTableClear(char texte[])
{
    unsigned int i =0;
    for(i=0;i<strlen(texte);i++)
    {
        texte[i] = '\000';
    }
}







int main()
{
    printf("Bienvenu dans se programme de vigenere\n");
    while (Choice != 'Q')
    {
    stringTableClear(Text);
    stringTableClear(Key);
    printf("\nPour chiffrer taper (C) pour dechiffrer taper (D) (Q = quit) :");
    scanf("%c",&Choice);
    if(Choice=='C' || Choice == 'c')
    {

    printf("Entrer votre cle : ");
    scanf("%s",Key);
    //printf("%d",strlen(Key));
    printf("Entrer votre Texte a Chiffrer :\n");
    //fgets(Text,MAX_SIZE_TEXT,stdin);
    gets(stdin);
    fgets(&Text,MAX_SIZE_TEXT,stdin);
    //scanf("%s",Text);
    //fgets(Text,MAX_SIZE_TEXT,stdin);
    chiffreVigenere(Text,Key,result);
    printf("%s",result);
    }
    else if(Choice=='D' || Choice == 'd')
    {
    stringTableClear(Text);
    stringTableClear(Key);
    printf("Entrer votre cle : ");
    scanf("%s",Key);
    printf("Entrer votre Texte a Dechiffrer :\n");
    gets(stdin);
    fgets(Text,MAX_SIZE_TEXT,stdin);
    //scanf("%s",Text);
    chiffreVigenere(Text,Key,result);
    printf("%s",result);
    }
    else if(Choice == 'h' || Choice == 'H')
    {
        printf("\n|Pour utiliser Vigenere il vous suffis de taper 'c' d'entrer votre cle pour le chiffrement puis d'appuier sur enter ceci donnera un texte chiffrer a l'aide de votre cle reproduiser cette etape en tapeant 'd' pour dechiffrer |\n\n");
    }

    }

    return 0;
}
