#include <stdio.h>
#include <string.h>

char mot[128] = {},motfinal[128] = {},mottmp[1] = {};
signed int nbRotation=0;
unsigned int i=0,number=0;
unsigned int valeurLettre[128] = {};

void rotate()
{
    printf("Entrer votre mot a transformer \n");
    scanf("%s",&mot);
    number = strlen(mot);
    printf("Entrer le nombre de rotation 0 for quit\n");
    scanf("%u",&nbRotation);



        for(i=0; i<128; i++)
        {
            //mottmp[] = mot[i];
#pragma switch
            switch (mot[i])
            {
            case 'a':
                valeurLettre[i]=0;
                break;

            case 'b':
                valeurLettre[i]=1;
                break;

            case 'c':
                valeurLettre[i]=2;
                break;

            case 'd':
                valeurLettre[i]=3;
                break;

            case 'e':
                valeurLettre[i]=4;
                break;

            case 'f':
                valeurLettre[i]=5;
                break;

            case 'g':

                valeurLettre[i]=6;
                break;

            case 'h':
                valeurLettre[i]=7;
                break;

            case 'i':
                valeurLettre[i]=8;
                break;

            case 'j':
                valeurLettre[i]=9;
                break;

            case 'k':
                valeurLettre[i]=10;
                break;

            case 'l':
                valeurLettre[i]=11;
                break;

            case 'm':
                valeurLettre[i]=12;
                break;

            case 'n':
                valeurLettre[i]=13;
                break;

            case 'o':
                valeurLettre[i]=14;
                break;

            case 'p':
                valeurLettre[i]=15;
                break;

            case 'q':
                valeurLettre[i]=16;
                break;

            case 'r':
                valeurLettre[i]=17;
                break;

            case 's':
                valeurLettre[i]=18;
                break;

            case 't':
                valeurLettre[i]=19;
                break;

            case 'u':
                valeurLettre[i]=20;
                break;

            case 'v':
                valeurLettre[i]=21;
                break;

            case 'w':
                valeurLettre[i]=22;
                break;

            case 'x':
                valeurLettre[i]=23;
                break;

            case 'y':
                valeurLettre[i]=24;
                break;

            case 'z':
                valeurLettre[i]=25;
                break;

            default:
                break;
            }
#pragma endswitch






        }

if(nbRotation>0)
{
    while(nbRotation>26)
    {
        nbRotation=nbRotation-26;
    }

    for(i=0; i<number; i++)
    {


            if((valeurLettre[i] + nbRotation+1) > 26)
            {
                valeurLettre[i] = (valeurLettre[i] + nbRotation+1)-26;
            }
            else
                valeurLettre[i] = valeurLettre[i] + nbRotation+1;

                #pragma switch
        switch (valeurLettre[i])
        {
        case 1:
            printf("a");
            break;

        case 2:
            printf("b");
            break;

        case 3:
            printf("c");
            break;

        case 4:
            printf("d");
            break;

        case 5:
            printf("e");
            break;

        case 6:
            printf("f");
            break;

        case 7:

            printf("g");
            break;

        case 8:
            printf("h");
            break;

        case 9:
            printf("i");
            break;

        case 10:
            printf("j");
            break;

        case 11:
            printf("k");
            break;

        case 12:
            printf("l");
            break;

        case 13:
            printf("m");
            break;

        case 14:
            printf("n");
            break;

        case 15:
            printf("o");
            break;

        case 16:
            printf("p");
            break;

        case 17:
            printf("q");
            break;

        case 18:
            printf("r");
            break;

        case 19:
            printf("s");
            break;

        case 20:
            printf("t");
            break;

        case 21:
            printf("u");
            break;

        case 22:
            printf("v");
            break;

        case 23:
            printf("w");
            break;

        case 24:
            printf("x");
            break;

        case 25:
            printf("y");
            break;

        case 26:
            printf("z");
            break;

        default:
            break;
        }
#pragma endswitch

        //printf("Valeur lettre les lettre = %c plus rot = %u\n",mot[i],valeurLettre[i]);
    }
}


    }






int main(int argc ,char *args[])
{


    rotate();






    return 0;
}
