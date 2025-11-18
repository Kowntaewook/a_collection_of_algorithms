#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int score;
} Person;

int main() {
    Person people[5];
    int num1;

    scanf("%d", &num1);
    
    
    for (int i = 0; i < num1; i++) {
        scanf("%s %d", people[i].name, &people[i].score);
    }

    
    for (int i = 0; i < num1; i++) {
        for (int j = i + 1; j < num1; j++) {
            if (people[i].score < people[j].score) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    
    printf("%s\n", people[3].name);

    return 0;
}