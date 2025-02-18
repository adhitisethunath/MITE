#include<stdio.h>

long factorial(int n){
    if(n){
     return(n*factorial(n-1));
    } else{
        return 1;
    }
}

int main(){
    int n,fact;
    
    printf("Enter a Number :");
    scanf("%d",&n);
    fact=factorial(n);
    printf("Factorial is: %d",fact);

}