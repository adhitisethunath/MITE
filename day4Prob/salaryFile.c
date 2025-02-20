#include<stdio.h>
struct employee_t{
    int id;
    char name[255];
    float salary;
    char department[40];
};

typedef struct employee_t employee;
void readEmployees(employee emp[],int employeeCount);
void saveEmployees(employee emp[],int employeeCount);
void loadEmployees(employee emp[],int employeeCount);
void displayemployees(employee emp[], int employeeCount);
employee findHighest(employee emp[], int employeeCount);


int main(){
    int employeeCount;

    printf("Enter number of employees:");
    scanf("%d",&employeeCount);
    employee employees[1000];
    
    readEmployees(employees,employeeCount);
    saveEmployees(employees,employeeCount);
    loadEmployees(employees, employeeCount);
    displayemployees(employees,employeeCount);
    employee highestSalariedEmployee = findHighest(employees,employeeCount);
    
    
    printf("\nEmployee with the highest salaries: %s,%.2f (%s)\n",
        highestSalariedEmployee.name,
        highestSalariedEmployee.salary,
        highestSalariedEmployee.department);
    return 0;
}

void readEmployees(employee emp[],int employeeCount){
    for(int i=0; i<employeeCount; i++){
        printf("\nEnter details (ID,Name,Salary,Department):");
        scanf(" %d %s %f %s",
            &emp[i].id,
            emp[i].name,
            &emp[i].salary,
            emp[i].department);
    }
}

void saveEmployees(employee emp[],int employeeCount){
    FILE* file = fopen("employee.txt","w");
    if(file == NULL){
        printf("Cannot open file.\n");
        return;
    }

    for(int i=0; i<employeeCount; i++){
        fprintf(file,"%d %s %.2f %s",emp[i].id,
            emp[i].name,
            emp[i].salary,
            emp[i].department);
    }
    fclose(file);
}

void loadEmployees(employee emp[],int employeeCount){
    FILE* file = fopen("employee.txt","r");
    if(file == NULL){
        printf("Cannot open file.\n");
        return;
    }

    for(int i=0; i<employeeCount; i++){
        fscanf(file,"%d%s%.2f%s",&emp[i].id,
            emp[i].name,
            &emp[i].salary,
            emp[i].department);
    }
    fclose(file);
}

void displayemployees(employee emp[], int employeeCount){
    printf("\nID\t\tNAME\t\tSALARY\t\tDEPARTMENT\n");
    for(int i=0; i<employeeCount; i++){
        printf("%d\t\t%s\t\t%0.2f\t\t%s\n",
            emp[i].id,
            emp[i].name,
            emp[i].salary,
            emp[i].department);
    }

}

employee findHighest(employee emp[], int employeeCount){
    employee highestSalariedEmployee = emp[0];

    for(int i=1; i<employeeCount; i++){
        if(emp[i].salary > highestSalariedEmployee.salary){
            highestSalariedEmployee = emp[i];
        }
    }
    return highestSalariedEmployee;
    
}
