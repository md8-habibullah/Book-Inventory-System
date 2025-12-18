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

// Function prototypes
void addBook();
void displayInventory();
void findBook();
void removeBook();

int main() {
  int choice;

  do {
    printf("\nBook Inventory System\n");
    printf("1. Add Book\n");
    printf("2. Display Inventory\n");
    printf("3. Find Book\n");
    printf("4. Remove Book\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addBook();
      break;
    case 2:
      displayInventory();
      break;
    case 3:
      findBook();
      break;
    case 4:
      removeBook();
      break;
    case 0:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 0);

  return 0;
}

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
}

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

void removeBook() {
  int idToRemove;
  printf("Enter the ID of the book to remove: ");
  scanf("%d", &idToRemove);

  int found = 0;
  for (int i = 0; i < bookCount; i++) {
    if (inventory[i].id == idToRemove) {
      // Shift remaining books to fill the gap
      for (int j = i; j < bookCount - 1; j++) {
        inventory[j] = inventory[j + 1];
      }
      bookCount--;
      printf("Book with ID %d removed successfully.\n", idToRemove);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Book with ID %d not found.\n", idToRemove);
  }
}