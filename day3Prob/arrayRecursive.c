#include<stdio.h>
void displayAges(short int* ages,int length,int index){
    if(index >= length){
        return;
    }
    printf("%d ",ages[index]);
    displayAges(ages,5,index+1);
}

void reverseAges(short int* ages,int length,int index){
    if(index >= length){
        return;
    }
    reverseAges(ages,5,index+1);
    printf("%d ",ages[index]);
}

int main(){
    short int ages[] = {45,42,14,20,70};
    displayAges(ages, 5,0);
    printf("\n");
    reverseAges(ages,5,0);
    return 0;
}
