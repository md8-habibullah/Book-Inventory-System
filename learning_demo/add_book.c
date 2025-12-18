

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
  int id;
  char title[MAX_TITLE_LENGTH];
  char author[MAX_AUTHOR_LENGTH];
  int quantity;
} Book;

Book inventory[MAX_BOOKS];
int bookCount = 0;



void addBook() {
  if (bookCount < MAX_BOOKS) {
    inventory[bookCount].id = bookCount + 1;
    printf("Enter book title: ");
    scanf(" %[^\n]s", inventory[bookCount].title); // Read title with spaces

    printf("Enter book author: ");
    scanf(" %[^\n]s", inventory[bookCount].author); // Read author with spaces

    printf("Enter quantity: ");
    scanf("%d", &inventory[bookCount].quantity);

    printf("Book added successfully with ID: %d\n", inventory[bookCount].id);
    bookCount++;
  } else {
    printf("Inventory is full. Cannot add more books.\n");
  }
}