#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 26

// counter data yang udah masuk di dalam table kita
int ctr = 0;

struct Node
{
  char name[100];
  int age;
};

Node *table[SIZE] = {NULL};

// function sebagai pabrik untuk menghasilkan node kita
struct Node *create_node(char name[], int age)
{
  struct Node *curr = (struct Node *)malloc(sizeof(Node));
  strcpy(curr->name, name);
  curr->age = age;

  return curr;
}

int hash_func(char c)
{
  return (c - 'A') % SIZE;
}

void insert(char name[], int age)
{
  int hash_key = hash_func(name[0]);
  int pos = hash_key;

  if (ctr == SIZE)
  {
    printf("Table is full\n");
    return;
  }
  // mencari mana laci yang kosong
  while (table[pos] != NULL)
  {
    pos = (pos + 1) % SIZE;
    // laci kosong ketemu -> masukin datanya
  }
  table[pos] = create_node(name, age);
  ctr++;
}

Node *search_node(char name[])
{
  int hash_key = hash_func(name[0]);
  int pos = hash_key;

  do
  {
    if (table[pos] != NULL && strcmp(table[pos]->name, name) == 0)
    {
      return table[pos];
    }
    pos = (pos + 1) % SIZE;
  } while (pos != hash_key);

  return NULL;
}

void delete_node(char name[])
{
  int hash_key = hash_func(name[0]);
  int pos = hash_key;

  do
  {
    if (table[pos] != NULL && strcmp(table[pos]->name, name) == 0)
    {
      free(table[pos]);
      table[pos] = NULL;
      ctr -= 1;
      return;
    }
    pos = (pos + 1) % SIZE;
  } while (pos != hash_key);

  return;
}

void print_all()
{
  for (int i = 0; i < SIZE; i++)
  {
    if (table[i] == NULL)
    {
      printf("-\n");
    }
    else
    {
      printf("%d. %s | %d \n", i, table[i]->name, table[i]->age);
    }
  }
}

int main()
{
  insert("Andy", 25);
  insert("TinTin", 12);
  insert("Budi", 30);
  insert("Bida", 25);
  insert("Andis", 69);
  delete_node("Andy");
  print_all();

  Node *search = search_node("Justine");
  if (search)
  {
    printf("Data ketemu %s - %d\n", search->name, search->age);
  }
  else
  {
    printf("Data tidak ketemu");
  }

  return 0;
}