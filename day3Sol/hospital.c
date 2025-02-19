#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 10

// defining a structure to store patient data
typedef struct {
    char name[20];
    int level;
}Patient;

// sorting patients in terms of emergency level
void sort_Patients(Patient patients[], int n) {
    Patient temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (patients[i].level < patients[j].level) {
               
                temp = patients[i];
                patients[i] = patients[j];
                patients[j] = temp;
            }
        }
    }
}

// main function
int main() {
    int n;
   
    printf("Enter number of patients: ");
    scanf("%d", &n);

    Patient patients[MAX_PATIENTS];

    // Get the patient data
    printf("Patient Data:\n");
    for (int i = 0; i < n; i++) {
        printf("%d.Enter name: ",i+1);
        scanf("%s", patients[i].name);
        printf("Enter emergency level (1-5): ");
        scanf("%d", &patients[i].level);
    }

    sort_Patients(patients, n);

    printf("\nSorted by Emergency Level:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - Level %d\n", patients[i].name, patients[i].level);
    }

    // Display top 3 critical patients
    printf("\n 3 Most Critical Patients:\n");
    for (int i = 0; i < 3 ; i++) {
        printf("%d. %s\n", i + 1, patients[i].name);
    }

    return 0;
}
