#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_highlighted(const char *input, const char *substring, int start, int end) {
    printf("%.*s", start, input); 
    printf("(%s)", substring);    
    printf("%s\n", input + end + 1); 
}

int main() {
    char input[] = "29535123p48723487597645723645";
    int len = strlen(input);
    long long total = 0;

    for (int i = 0; i < len; i++) {
        if (isdigit(input[i])) {
            for (int j = i + 1; j < len; j++) {
                if (isdigit(input[j]) && input[i] == input[j]) {
                    int valid = 1;
                    for (int k = i + 1; k < j; k++) {
                        if (!isdigit(input[k]) || input[k] == input[i]) {
                            valid = 0;
                            break;
                        }
                    }
                    if (valid) {
                        char *substring = malloc(j - i + 2);
                        strncpy(substring, input + i, j - i + 1);
                        substring[j - i + 1] = '\0';
                        print_highlighted(input, substring, i, j);
                        total += atoll(substring);
                        free(substring);
                    }
                }
                if (!isdigit(input[j])) break; 
            }
        }
    }

    printf("\nTotal = %lld\n", total);
    return 0;
}
