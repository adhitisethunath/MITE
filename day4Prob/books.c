#include<stdio.h>

struct Fiction_t{ //383
    char title[250];
    char author[125];
    float price;
};
typedef struct Fiction_t Fiction;

struct NonFiction { //758
    char title[250];
    char subject[500];
    float price;
};
typedef struct NonFiction_t NonFiction;

union BookType_t {
    Fiction fiction;
    NonFiction nonFiction;
};
typedef union Book_t BookType;

struct Book_t {
    int type;
    BookType booktype;
};
typedef struct Book_t Book;

Book books[1000];
int bookCount;

void addBooks();
void displayBooks();

int main(){
    addBooks();
    displayBooks();
    return 0;
}

void addBooks(){
    printf("Enter number of Books:");
    scanf("%d",&bookCount);

    for(int i=0; i<bookCount; i++){
        printf("Type of book (1-Fiction, 2-Non fiction):");
        scanf("%d",&book[i].type);

        switch(book[i].type){
            case 1: {
                printf("Enter Fiction Book Details(Title, Author, Price):");
                scanf("%s%s%f",
                    book[i].booktype.fiction.title,
                    book[i].booktype.fiction.author,
                    book[i].booktype.fiction.price);
            }break;

            case 2:{
                printf("Enter Fiction Book Details(Title, subject, Price):");
                scanf("%s%s%f",
                    book[i].booktype.nonFictionfiction.title,
                    book[i].booktype.nonFictionfiction.author,
                    book[i].booktype.nonFictionfiction.price);
            }break;
        }
    }
}

void displayBooks(){
    for(int i=0; i<bookCount; i++){
        switch(book[i].type){
         case 1: {
                    printf("Fiction Book: %s,Author: %s,Price: $%.2f",
                     book[i].booktype.fiction.title,
                    book[i].booktype.fiction.author,
                    book[i].booktype.fiction.price);
                    }break;
         case 2:{
            printf("Non Fiction Book: %s,subject: %s,Price: $%.2f",
                book[i].booktype.nonFictionfiction.title,
                    book[i].booktype.nonFictionfiction.author,
                    book[i].booktype.nonFictionfiction.price);
               }break;
        }
    }
}
