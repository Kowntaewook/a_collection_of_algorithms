#include <stdio.h>
#include <string.h>

#define B "kitpa_4th_it_contest_20250315"

int main() {
    char a[50][50];
    int a_count = 0;
    char chars[] = "abcdefghijklmnopqrstuvwxyz0123456789_";
    int len_b = strlen(B);
    
    for (int i = 0; i < strlen(chars); i++) {
        char c[50];
        int c_index = 0;
        int modified = 0;
        
        for (int j = 0; j < len_b; j++) {
            if (B[j] != chars[i]) {
                c[c_index++] = B[j];
            } else {
                modified = 1;
            }
        }
        c[c_index] = '\0';
        
        if (modified && strlen(c) > 0 && strlen(c) != len_b) {
            strcpy(a[a_count++], c);
        }
    }

    if (a_count == 0) {
        printf("\n");
    } else {
        for (int i = 0; i < a_count - 1; i++) {
            for (int j = i + 1; j < a_count; j++) {
                if (strcmp(a[i], a[j]) > 0) {
                    char temp[50];
                    strcpy(temp, a[i]);
                    strcpy(a[i], a[j]);
                    strcpy(a[j], temp);
                }
            }
        }
        
        printf("%s\n", a[2]);
    }
    
    return 0;
}