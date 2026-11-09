
#include <stdio.h>
#include <string.h>
#include "view.h"

void do_view(char *filename)
{
    FILE *fp;

    fp = fopen(filename, "rb");

    if(fp == NULL)
    {
        printf("Problem in Opening File\n");
        return;
    }
    else
    {
        printf("\n+------------------------------------------+\n");
        printf("|            MP3 SONG DETAILS              |\n");
        printf("+------------------------------------------+\n");
        printf("| File Opened Successfully                 |\n");
        printf("+------------------------------------------+\n");
    }
    //header
    unsigned char buffer[10];

    fread(buffer, 1, 10, fp);

    if(buffer[0] != 'I' || buffer[1] != 'D' || buffer[2] != '3')
    {
        printf("| ID3 Tag Not Found                        |\n");
        printf("+------------------------------------------+\n");
        fclose(fp);
        return;
    }
    
    int tag_reader = (buffer[6] << 21) |
                     (buffer[7] << 14) |
                     (buffer[8] << 7)  |
                      buffer[9];

    printf("| Field          | Value                   |\n");
    printf("+------------------------------------------+\n");

    int processed = 0;

    while(processed < tag_reader)
    {
        char frame_id[5];

        fread(frame_id, 1, 4, fp);
        frame_id[4] = '\0';

        unsigned char store_buffer[4];

        fread(store_buffer, 1, 4, fp);

        int size = (store_buffer[0] << 24) |
                   (store_buffer[1] << 16) |
                   (store_buffer[2] << 8)  |
                    store_buffer[3];

        if(size == 0)
        {
            break;
        }

        unsigned char flag[2];

        fread(flag, 1, 2, fp);

        unsigned char encoding;

        fread(&encoding, 1, 1, fp);

        int data_size = size - 1;

        char data[data_size + 1];

        fread(data, 1, data_size, fp);

        data[data_size] = '\0';

        if(strcmp(frame_id, "TIT2") == 0)
        {
            printf("| Title          | %-23.23s |\n", data);
        }
        else if(strcmp(frame_id, "TPE1") == 0)
        {
            printf("| Artist         | %-23.23s |\n", data);
        }
        else if(strcmp(frame_id, "TALB") == 0)
        {
            printf("| Album          | %-23.23s |\n", data);
        }
        else if(strcmp(frame_id, "TYER") == 0)
        {
            printf("| Year           | %-23.23s |\n", data);
        }
        else if(strcmp(frame_id, "TCON") == 0)
        {
            printf("| Genre          | %-23.23s |\n", data);
        }

        processed = processed + 10 + size;
    }

    printf("+------------------------------------------+\n");

    fclose(fp);
}
