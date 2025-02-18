#include<stdio.h>

int calculateDiscount(int amount) {
	int discount;
	if((amount >= 500) && (amount <= 1000)) {
		discount = amount * 0.10;
	} else if(amount > 1000) {
		discount = amount * 0.20;
	}
	return discount;
}


int main() {
	int amount,discount,totalBill;

	printf("Enter total bill amount: ");
	scanf("%d",&amount);

	discount = calculateDiscount( amount);

	if(discount) {
		totalBill= amount - discount;
	}
	else {
		totalBill = amount;
	}
	printf("Final Payable Amount : %d ",totalBill);


	return 0;

}
