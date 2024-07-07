#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hexadecimalnum[100];
int arrlen = 0;

void decToHexa(int n) {
    int i = 0;
    while (n > 0) {
        int remainder = n % 16;
        hexadecimalnum[i++] = (remainder < 10) ? (48 + remainder) : (55 + remainder);
        n /= 16;
    }
    arrlen = i;
    for (i = arrlen - 1; i >= 0; i--) {
        printf("%c", hexadecimalnum[i]);
    }
}

int main() {
    FILE *f1, *f2;
    int loc, sa, len, i;
    char la[20], m1[20], op[20], otp[20];

    f1 = fopen("input.txt", "r");
    f2 = fopen("optab.txt", "r");

    fscanf(f1, "%s %s %x", la, m1, &sa);
    printf("\nIntermediate file\n");

    if (strcmp(m1, "START") == 0) {
        loc = sa;
        printf("\t%s\t%s\t%x\n", la, m1, sa);
    } else {
        loc = 0;
    }

    fscanf(f1, "%s %s", la, m1);

    while (!feof(f1)) {
        fscanf(f1, "%s", op);
        printf("\n%x\t%s\t%s\t%s\n", loc, la, m1, op);

        if (strcmp(la, "-") != 0) {
            // Handle labels
        }

        fscanf(f2, "%s %d", otp, &i);

        while (!feof(f2)) {
            if (strcmp(m1, otp) == 0) {
                loc += 3;
                break;
            }
            fscanf(f2, "%s %d", otp, &i);
        }

        if (strcmp(m1, "WORD") == 0) {
            loc += 3;
        } else if (strcmp(m1, "RESW") == 0) {
            loc += 3 * atoi(op);
        } else if (strcmp(m1, "BYTE") == 0) {
            if (op[0] == 'X') {
                loc++;
            } else {
                len = strlen(op) - 3;
                loc += len;
            }
        } else if (strcmp(m1, "RESB") == 0) {
            loc += atoi(op);
        }

        fscanf(f1, "%s %s", la, m1);
    }

    printf("\n\nProgram length=\t");
    decToHexa(loc - sa);
    printf("\n");

    fclose(f1);
    fclose(f2);

    return 0;
}

