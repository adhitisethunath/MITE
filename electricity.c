#include<stdio.h>
#include<string.h>
int main(){
    char name[255];
    int id,units,bill;
    float surcharge,total;

    printf("Enter name:");
    scanf("%s",name);

    printf("Enter ID:");
    scanf("%d",&id);

    printf("Enter total units consumed:");
    scanf("%d",&units);

    //calculating bill
    bill = 100;
    if(units <= 100){
        bill = 5.0f * units;
    }else if(units > 300){
        bill = 10 * units;
    }else{
        bill = 7 * units;
    }
   

    //calculating surcharge
    if(bill > 1000){
        surcharge =  (bill / 100.0f) * 5.0f; 
    }

    //printing
     printf("\tCustomer Name:%s\n",name);
     printf("\tCustomer ID:%d\n",id);
     printf("\ttotal units consumed:%d\n",units);
     printf("\tBase Bill:%d\n",bill);
     if(surcharge > 0){
       printf("\tSurcharge:%f\n",surcharge);
     }
     printf("\tTotal Bill:%f\n",bill + surcharge);

    return 0;
}