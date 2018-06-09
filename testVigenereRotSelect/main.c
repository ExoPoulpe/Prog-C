/*
*
*Author:    Troller Fabian
*Grade:     Tecnician ES in ComputerScientist
*Version:   1.7.0.0  // 1.7.0.0 IS STABLE
*Date:      01.28.2018
*Description:   Encode and Decode by Vigenere methods with password and encode by cezar with select value
*Use: For use that you must just type c/C or cr/CR or cra/CRA for encode your word value with your password
*Show help for more Informations
*
*/

#include <stdio.h>
#include <string.h>

#define VERSION_SOFT 1.7.0.0
#define MAX_SIZE_TEXT 2048
#define MAX_LETTRE_NUMBER 26
#define MAX_PASSWORD_LENGTH 128

char Key[MAX_PASSWORD_LENGTH],Text[MAX_SIZE_TEXT],Chiffrer[MAX_SIZE_TEXT],lettre[MAX_LETTRE_NUMBER]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};//,' '};
unsigned int nombre[MAX_LETTRE_NUMBER] =                                                              {0, 1,  2,   3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13,  14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};//, 26};
signed int valueChiffrer=0,valueDechiffrer=0,valueRot=0;
char Choice[10];
char result[MAX_SIZE_TEXT];


/** \brief
 * Find character on list
 * \param char alphabet[]
 * \param char character
 * \return unsigned int
 *
 */
/**< Found char */
///Found character on list.
unsigned int carFindInList(char alphabet[],char caractere) // methods for finding character in table of character
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

/** \brief
 * Insert character in alphabet
 * \param signed int Value
 * \return signed int
 *
 */

///Check value for character on alphabet.
signed int carOverFlowList(signed int Value) // methods for secure value in alaphabet
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

/** \brief
 * Make Hash with Adler32 methods
 * \param char Word[]
 * \return char
 *
 */

///Make hash Adler32 with word.
char hashAdler32(char mot[])
{
    unsigned int a=1,b=0,i=0;
    char resultA[16],resultB[16];

    for(i=0;i<strlen(mot);i++)
    {
       a = a + (int)mot[i];
       b=b+a;
    }
    printf("0%x",b);
    printf("0%x",a);
}

/** \brief
 *  Make Rotation on alphabet
 * \param unsigned int Number
 * \param char Choice[]
 * \param  signed int NumberRotate
 * \return unsigned int
 *
 */

///Make rotation alphabet.
unsigned int chiffreRot(unsigned int Number, char choice[],signed int NumberRotate) // method for substituate character on alaphabet
{
    signed int rot=13;
    rot=NumberRotate;
    if((choice[0]=='C' || choice[0] == 'c') && (choice[1] =='R' || choice[1] == 'r'))
    {
       Number = Number+rot;
    }
    else if((choice[0]=='D' || choice[0] == 'd') && (choice[1] =='R' || choice[1] == 'r'))
    {
       Number = Number-rot;
    }
    Number = carOverFlowList(Number);

    return Number;

}


/** \brief
 *  Make chiffrement Vigenere
 * \param char Text[]
 * \param char Key[]
 * \param char StringResult[]
 * \param char Choice[]
 * \param signed int NumberRotate
 * \return char
 *
 */

///Make chiffrement Vigenere with Text , Key , Choice , RotateNumber.
char chiffreVigenere(char texte[],char key[],char stringResult[MAX_SIZE_TEXT],char choice[],signed int NumberRotate) // methods for chiffre word with vigenere
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
        if((choice[0]=='D' || choice[0] == 'd') && (choice[1] =='R' || choice[1] == 'r'))
        {
            if(texte[i]!=' ')
            {
                valueText = chiffreRot(valueText,choice,NumberRotate);
                valueResult=carOverFlowList(valueText-valueKey);
                stringResult[i] = lettre[carOverFlowList(chiffreRot(valueResult,choice,NumberRotate))];//=  %d\n
            }
            else if(texte[i]== ' ')
            {
                stringResult[i] = ' ';
            }
        }

        if((choice[0]=='C' || choice[0] == 'c') && (choice[1] =='R' || choice[1] == 'r'))
        {

            if(texte[i]!=' ')
            {
                valueResult=carOverFlowList(valueText+valueKey);
                stringResult[i] = lettre[carOverFlowList(chiffreRot(valueResult,choice,NumberRotate))];//=  %d\n
            }
            else if(texte[i]== ' ')
            {
                stringResult[i] = ' ';
            }
            //printf("chiffre vig plus rot");
            //break;
        }
        else if(choice[0]=='C' || choice[0] == 'c')
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
        else if(choice[0] == 'D' || choice[0] == 'd')
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

/** \brief
 * Clear table
 * \param char Table[]
 * \return void
 *
 */
void stringTableClear(char texte[])
{
    unsigned int i =0;
    for(i=0;i<strlen(texte);i++)
    {
        //texte[i] = NULL;
        //texte[i] = '\0';
        memset(texte,0,255);

    }
}







int main()
{
    printf("Bienvenu dans se programme de chiffrement basique \n");
    while (Choice[0] != 'Q')
    {
    stringTableClear(Text);
    stringTableClear(Key);
    printf("\nChiffrement (h = Help) >");
    //scanf("%c",&Choice);
    fgets(&Choice,10,stdin);
    if((Choice[0]=='H' || Choice[0] == 'h') && (Choice[1]=='A' || Choice[1] == 'a'))
    {
        printf("Entrer votre cle : ");
        scanf("%s",&Key);
        hashAdler32(Key);
    }
    if(Choice[0]=='C' || Choice[0] == 'c')
    {

    printf("Entrer votre cle : ");
    scanf("%s",Key);
    //printf("%d",strlen(Key));
    if(Choice[2]=='A' || Choice[2] == 'a')
    {
        printf("Entrer valeur rotation : ");
        scanf("%d",&valueRot);
    }
    printf("Entrer votre Texte a Chiffrer :\n");
    //fgets(Text,MAX_SIZE_TEXT,stdin);
    gets(stdin);
    fgets(&Text,MAX_SIZE_TEXT,stdin);
    //scanf("%s",Text);
    //fgets(Text,MAX_SIZE_TEXT,stdin);
    if(Choice[2]=='A' || Choice[2] == 'a')
    {
        chiffreVigenere(Text,Key,result,&Choice,valueRot);
    }
    else
        chiffreVigenere(Text,Key,result,&Choice,13);
    puts("\n=========Chiffrer===============\n");
    printf("%s\n",result);
    puts("\n================================\n");
    stringTableClear(Text);
    stringTableClear(Key);
    }
    else if(Choice[0]=='D' || Choice[0] == 'd')
    {
    stringTableClear(Text);
    stringTableClear(Key);
    printf("Entrer votre cle : ");
    scanf("%s",Key);
    if(Choice[2]=='A' || Choice[2] == 'a')
    {
        printf("Entrer valeur rotation : ");
        scanf("%d",&valueRot);
    }
    printf("Entrer votre Texte a Dechiffrer :\n");
    gets(stdin);
    fgets(Text,MAX_SIZE_TEXT,stdin);
    //scanf("%s",Text);
    if(Choice[2]=='A' || Choice[2] == 'a')
    {
        chiffreVigenere(Text,Key,result,&Choice,valueRot);
    }
    else
        chiffreVigenere(Text,Key,result,&Choice,13);
    puts("\n=========Dechiffrer=============\n");
    printf("%s\n",result);
    puts("\n================================\n");
    }
    else if((Choice[0] == 'h' || Choice[0] == 'H') && (Choice[1]=='\n' || Choice[1] == '\n'))
    {
        puts("\nBienvenu dans se systeme de chiffrement basique\n");
        puts("\nVersion : 1.7.0.0 Is Stable\n");
        puts("\n================================================================\n");
        puts("\nMETHODS\n");
        puts("\n================================================================\n");
        puts("\nvous pouvez Chiffrer/Dechiffrer a l'aide de : \n\n - Vigenere\n\n - Vigenere + Cezar \n\n - Vigenere + rotation choisis \n");
        puts("\n================================================================\n");
        puts("\nCOMMANDS\n");
        puts("\n================================================================\n");
        puts("\nvous pouvez chiffrer avec vigenere en utilisant : \n\n - c/C \n \n dechiffrer avec : \n\n - d/D");
        puts("\npour chiffrer avec vigenere + cezar : \n\n - cr/CR \n\npour dechiffrer avec vigenere + cezar : \n \n - dr/DR");
        puts("\npour chiffrer avec vigenere + rotation choisis: \n\n - cra/CRA \n\npour dechiffrer avec vigenere + rotation choisis: \n\n - dra/DRA");
        puts("\n\nVous pouvez quitter cette application a l'aide de la commande 'Q' et entrer \n");
        puts("\n================================================================\n");
   }

    }

    return 0;
}
