#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_book.h"


typedef struct {
    int id;
    char title[100];
    char author[50];
    int quantity;
} Book;
extern Book inventory[]; 

extern int bookCount ;
// extern Book inventory[MAX_BOOKS];
void displayInventory() {
  if (bookCount == 0) {
    printf("Inventory is empty.\n");
    return;
  }

  printf("\n--- Book Inventory ---\n");
  for (int i = 0; i < bookCount; i++) {
    printf("ID: %d\n", inventory[i].id);
    printf("Title: %s\n", inventory[i].title);
    printf("Author: %s\n", inventory[i].author);
    printf("Quantity: %d\n", inventory[i].quantity);
    printf("--------------------\n");
  }
}\