#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_book.h"
#include "findBook.h"

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
