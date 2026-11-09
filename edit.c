
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "edit.h"

int get_size(char size_buf[])
{
    return (size_buf[0] << 24) |
           (size_buf[1] << 16) |
           (size_buf[2] << 8)  |
            size_buf[3];
}

void do_edit(char *argv[])
{
    char *option = argv[3];
    char *new_data = argv[4];
    char *tag_name;

    if(strcmp(option, "-t") == 0)
        tag_name = "TIT2";
    else if(strcmp(option, "-a") == 0)
        tag_name = "TPE1";
    else if(strcmp(option, "-A") == 0)
        tag_name = "TALB";
    else if(strcmp(option, "-y") == 0)
        tag_name = "TYER";
    else if(strcmp(option, "-g") == 0)
        tag_name = "TCON";
    else
    {
        printf("\n+------------------------------------------+\n");
        printf("|             INVALID EDIT OPTION          |\n");
        printf("+------------------------------------------+\n");
        return;
    }

    FILE *src = fopen("sample.mp3", "rb");

    if(src == NULL)
    {
        printf("\n+------------------------------------------+\n");
        printf("|            FILE OPENING FAILED           |\n");
        printf("+------------------------------------------+\n");
        return;
    }

    edit_tag(src, tag_name, new_data);
}

void edit_tag(FILE *src, char *tag_name, char *new_data)
{
    char tag[5];
    char size_buf[4];
    char flag[2];
    char header[10];
    int size;
    int found = 0;

    FILE *temp = fopen("temp.mp3", "wb");

    if(temp == NULL)
    {
        printf("\n+------------------------------------------+\n");
        printf("|        TEMPORARY FILE OPENING FAILED     |\n");
        printf("+------------------------------------------+\n");
        fclose(src);
        return;
    }

    fread(header, 1, 10, src);
    fwrite(header, 1, 10, temp);

    for(int i = 0; i < 6; i++)
    {
        fread(tag, 1, 4, src);
        tag[4] = '\0';

        fread(size_buf, 1, 4, src);
        size = get_size(size_buf);

        fread(flag, 1, 2, src);

        if(strcmp(tag, tag_name) == 0)
        {
            int new_size = strlen(new_data) + 1;

            char new_size_buf[4];

            new_size_buf[0] = (new_size >> 24) & 0xFF;
            new_size_buf[1] = (new_size >> 16) & 0xFF;
            new_size_buf[2] = (new_size >> 8) & 0xFF;
            new_size_buf[3] = new_size & 0xFF;

            fwrite(tag, 1, 4, temp);
            fwrite(new_size_buf, 1, 4, temp);
            fwrite(flag, 1, 2, temp);

            fputc(0, temp);
            fwrite(new_data, 1, strlen(new_data), temp);

            fseek(src, size, SEEK_CUR);

            char ch;

            while(fread(&ch, 1, 1, src))
                fwrite(&ch, 1, 1, temp);

            found = 1;
            break;
        }
        else
        {
            fwrite(tag, 1, 4, temp);
            fwrite(size_buf, 1, 4, temp);
            fwrite(flag, 1, 2, temp);

            char data[size];

            fread(data, 1, size, src);
            fwrite(data, 1, size, temp);
        }
    }

    fclose(src);
    fclose(temp);

    if(found)
    {
        remove("sample.mp3");
        rename("temp.mp3", "sample.mp3");

        printf("\n+------------------------------------------+\n");
        printf("|             TAG UPDATED SUCCESSFULLY     |\n");
        printf("+------------------------------------------+\n");
        printf("| Tag      : %-30.30s |\n", tag_name);
        printf("| New Value: %-30.30s |\n", new_data);
        printf("+------------------------------------------+\n");
    }
    else
    {
        remove("temp.mp3");

        printf("\n+------------------------------------------+\n");
        printf("|               TAG NOT FOUND              |\n");
        printf("+------------------------------------------+\n");
    }
}


