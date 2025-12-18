#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void register_user();
int get_next_id();
void login_user();

int main() { register_user(); }

void register_user() {
  FILE *fp;
  int id = get_next_id();
  char username[50], email[100], password[50];

  printf("Username: ");
  scanf("%s", username);

  printf("Email: ");
  scanf("%s", email);

  printf("Password: ");
  scanf("%s", password);

  fp = fopen("database.txt", "a");
  fprintf(fp, "%d,%s,%s,%s\n", id, username, email, password);
  fclose(fp);

  printf("Registration successful! Your ID: %d\n", id);
}

int get_next_id() {
  FILE *fp = fopen("database.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  };
  int count = 0;
  char ch;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n')
      count++;
  }
  fclose(fp);
  return count;
}