#include<stdio.h>

long int factorial(int number) {
	if(number >= 1)
		return number*factorial(number-1);
	else
		return 1;
}

int main() {
	int number;

	printf("Enter a number: ");
	scanf("%d", &number);

	printf("Factorial of %d is: %ld", number, factorial(number));
	return 0;
}