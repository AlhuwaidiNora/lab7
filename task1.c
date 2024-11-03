#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &students[i].id);

        printf("Enter name for student %d: ", i + 1);
        scanf(" %[^\n]s", students[i].name);

        printf("Enter GPA for student %d: ", i + 1);
        scanf("%f", &students[i].gpa);
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    return 0;
}
