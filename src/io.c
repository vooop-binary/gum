#include "include/io.h"
#include <stdio.h>
#include <stdlib.h>

char*
read_file(const char* file_path)
{
    char* buffer = 0;
    long length;

    FILE* file = fopen(file_path, "rb");

    if (file)
    {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);

        buffer = calloc(length, length);

        if (buffer)
        {
            fread(buffer, 1, length, file);
        }

        fclose(file);

        return buffer;
    }

    printf("Error reading file `%s\n", file_path);
    exit(2);
}
