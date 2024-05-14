#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SQUARE(a) (a)*(a)

// example that C and C++ language does not specify the order of evaluation for function call arguments
int example() {
    int x = 3;
    printf("%d\n", SQUARE(++x));
    printf("%d\n", (4)*(4));

    int y = 3;
    printf("%d\n", (++y)*(++y));

    int z = 3;
    int k = (++z)*(++z); // undefined behavior by the ANSI
    printf("%d\n", k);

 
    printf("\n\n\n");

    int p;
    int q;
    p = q = 1;
    printf ("%d %d %d", p, q, p=q=0);
 
 
    return 0;
}


int reading_fstream_string()
{
    char fileName[100];
    printf("input file name: ");
    scanf("%100s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%100s", line);
    }
    fclose(file);

    return 0;
}

int writting_fstream_string()
{
    char fileName[100];
    printf("output file name: ");
    scanf("%100s", fileName);

    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    printf("Enter lines, type 'quit' to finish:\n");
    char line[100];
    while (fgets(line, sizeof(line), stdin)) {
        if (strcmp(line, "quit\n") == 0) 
            break;
        fprintf(file, "%s", line);
    }
    fclose(file);

    return 0;
}

int reading_fstream_int()
{
    char fileName[100];
    printf("input file name: ");
    scanf("%100s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        printf("%d\n", num);
    }
    fclose(file);

    return 0;
}

int writting_fstream_int()
{
    char fileName[100];
    printf("output file name: ");
    scanf("%100s", fileName);

    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    printf("Enter integers, type '-1' to finish:\n");
    int num;
    while (scanf("%d", &num) == 1) {
        if (num == -1)
            break;
        fprintf(file, "%d\n", num);
    }
    fclose(file);

    return 0;
}

int main ()
{
    reading_fstream_string();
    writting_fstream_string();
    reading_fstream_int();
    writting_fstream_int();

    return 0;
}
