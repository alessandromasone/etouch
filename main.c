/*=============================================================================
 |   Assignment:  ETOUCH.
 |
 |       Author:  ALESSANDRO MASONE
 |     Language:  WRITTEN IN C
 |       Editor:  Xcode Version 13.1 (13A1030d)
 |
 |   To Compile:  clang-1300.0.29.30
 |                MINGW32-BASE V201307220
 |                MINGW32-GCC-G++ V6.3.0-1
 |                MINGW32-GCC-OBJC V6.3.1-1
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  Realizzare in C un comando touch in stile Unix con
 |                eventuale personalizzazione.
 |
 |        Input:  PARAMETERS.
 |
 |       Output:  RESULT.
 |
 |    Algorithm:  TOP-DOWN.
 |
 *===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#include "getopt.h"

//controllo esistenza del file
bool file_exists (char *filename)
{
    struct stat   buffer;
    return (stat (filename, &buffer) == 0);
}
//creazione del file
int CreateFile(char *filename)
{
    FILE *fp;
    fp  = fopen (filename, "w");
    if (fp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    fclose (fp);
    return 0;
}
//corpo principale
int main(int argc, char *argv[])
{
    int flag = 0, opt;
    //parser del passaggio di flag dal main
    if (argc == 1)
    {
        fprintf(stderr, "Usage: %s [-o overwrite] file ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    while ((opt = getopt(argc, argv, "o:")) != -1)
    {
        switch (opt)
        {
            case 'o': //se -o è inserito
                flag = 1;
                break;
            default: //altri flag non presenti
                fprintf(stderr, "Usage: %s [-o overwrite] file ...\n", argv[0]);
                exit(EXIT_FAILURE);
                break;
        }
    }
    //se tutto è OK creazione dei file in base al flag
    for (int i = 1; i < argc; i++)
    {
        if (!flag) //se -o non passato
        {
            if (!file_exists(argv[i])) //se esiste non sovrascrive
            {
                CreateFile(argv[i]); //creaziione file
            }
        }
        else
        {
            CreateFile(argv[i]); // creazione file con sovrascrizione
        }
    }
    return 0;
}
