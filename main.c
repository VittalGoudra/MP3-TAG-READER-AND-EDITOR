/*
PROJECT NAME : MP3 TAG READER AND EDITOR

I developed an MP3 Tag Reader and Editor project in C to read, display, and modify ID3v2.3 metadata of MP3 files.
It allows users to view and edit song details such as Title, Artist, Album, Year, Genre, and Composer using file handling.
It also supports command-line operations to read and update MP3 tags while preserving the original audio data.

NAME   : Vittal Shivanagouda Goudra
MOB    : 8867462834
EMAIL  : vittalgoudra123@gmail.com
BATCH  : 26015B

*/
#include <stdio.h>
#include <string.h>
#include "view.h"
#include "edit.h"

int main(int argc, char *argv[])
{
    printf("\n");
    printf("+------------------------------------------+\n");
    printf("|          MP3 TAG READER & EDITOR         |\n");
    printf("+------------------------------------------+\n");

    if(argc < 3)
    {
        printf("\n");
        printf(" Give Command Line Aruguments like:\n");
        printf(" ------------------------------------------\n");
        printf(" View Tags : ./a.out -v <filename>\n");
        printf(" Edit Tags : ./a.out -e <filename> <option> <new_value>\n");
        printf("\n");
        printf(" Edit Options:\n");
        printf(" -t  : Title\n");
        printf(" -a  : Artist\n");
        printf(" -A  : Album\n");
        printf(" -y  : Year\n");
        printf(" -g  : Genre\n");
        printf("+------------------------------------------+\n");
        return 0;
    }

    if(strcmp(argv[1], "-v") == 0)
    {
        printf("|               VIEW MODE                  |\n");
        printf("+------------------------------------------+\n\n");

        do_view(argv[2]);
    }
    else if(strcmp(argv[1], "-e") == 0)
    {
        if(argc < 5)
        {
            printf("\n");
            printf(" Edit command format:\n");
            printf(" ------------------------------------------\n");
            printf(" ./a.out -e <filename> -t <new_title>\n");
            printf(" ./a.out -e <filename> -a <new_artist>\n");
            printf(" ./a.out -e <filename> -A <new_album>\n");
            printf(" ./a.out -e <filename> -y <new_year>\n");
            printf(" ./a.out -e <filename> -g <new_genre>\n");
            printf("+------------------------------------------+\n");

            return 0;
        }

        printf("|               EDIT MODE                  |\n");
        printf("+------------------------------------------+\n\n");

        do_edit(argv);
    }
    else
    {
        printf("\n");
        printf("+------------------------------------------+\n");
        printf("|             INVALID OPTION               |\n");
        printf("+------------------------------------------+\n");
        printf(" Use -v to view tags or -e to edit tags.\n");
    }

    printf("\n+------------------------------------------+\n");
    printf("|                THANK YOU!                |\n"); 
    printf("+------------------------------------------+\n");

    return 0;
}

