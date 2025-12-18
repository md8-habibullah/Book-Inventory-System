#ifndef ADD_BOOK_H
#define ADD_BOOK_H

#define MAX_BOOKS 100
typedef struct {
    int id;
    char title[100];
    char author[50];
    int quantity;
} Book;
extern Book inventory[MAX_BOOKS];
extern int bookCount;

void addBook();


#endif
