#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int marks;
} Student;

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    
    for (int i = 0; i < n; i++) {
        printf("\nEnter Student %d Name: ", i + 1);
        scanf(" %s", students[i].name);
        printf("Enter Student %d Marks: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }

    free(students);

    return 0;
}
