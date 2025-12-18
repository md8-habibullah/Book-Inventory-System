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


void findBook() {
  char searchTitle[MAX_TITLE_LENGTH];
  printf("Enter the title of the book to find: ");
  scanf(" %[^\n]s", searchTitle);

  int found = 0;
  for (int i = 0; i < bookCount; i++) {
    if (strcmp(inventory[i].title, searchTitle) == 0) {
      printf("Book found:\n");
      printf("ID: %d\n", inventory[i].id);
      printf("Title: %s\n", inventory[i].title);
      printf("Author: %s\n", inventory[i].author);
      printf("Quantity: %d\n", inventory[i].quantity);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Book with title '%s' not found.\n", searchTitle);
  }
}