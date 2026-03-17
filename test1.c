#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *input_file = NULL, *output_file = NULL;
    int mode = 0;
    int key = 3;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) mode = 1;
        else if (strcmp(argv[i], "-d") == 0) mode = -1;
        else if (input_file == NULL) input_file = argv[i];
        else output_file = argv[i];
    }

    if (mode == 0 || !input_file || !output_file) {
        printf("Usage: app.exe [-e|-d] <input> <output>\n");
        return 1;
    }

    FILE *fin = fopen(input_file, "rb");
    FILE *fout = fopen(output_file, "wb");
    if (!fin || !fout) {
        printf("Error opening files.\n");
        return 1;
    }
    
    int m; 
    while ((m = fgetc(fin)) != EOF) {
        int result;
        if (mode == 1) {
            result = (m + key) % 256;
        } else {
            result = (m - key + 256) % 256;
        }
        fputc(result, fout);
    }

    fclose(fin);
    fclose(fout);
    printf("Done.\n");
    return 0;
}