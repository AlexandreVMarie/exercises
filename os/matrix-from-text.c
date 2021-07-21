#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *file;
    int rows;
    int cols;
    int **m;
    int rc;

    if (argc <= 1) {
        fprintf(stderr, "No input file specified");
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Failed to open input file");
        exit(1);
    }

    rc = fscanf(file, "%d", &rows);
    if (rc <= 0) {
        perror("Could not read the number of rows");
        exit(1);
    }

    rc = fscanf(file, "%d", &cols);
    if (rc <= 0) {
        perror("Could not read the number of columns");
        exit(1);
    }

    m = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m[i] = malloc(cols * sizeof(int));

        for (int j = 0; j < cols; j++){
            rc = fscanf(file, "%d", &m[i][j]);
            if (rc <= 0) {
                perror("Could not read number");
                exit(1);
            }

            printf("%2d", m[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < rows; i++)
        free(m[i]);
    free(m);

    fclose(file);

    return 0;
}
