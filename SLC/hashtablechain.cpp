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

  Node *next;
} * head[SIZE] = {NULL}, *tail[SIZE] = {NULL};

int hash_func(char c)
{
  return (c - 'A') % SIZE;
}

struct Node *create_node(char name[], int age)
{
  struct Node *curr = (struct Node *)malloc(sizeof(Node));

  strcpy(curr->name, name);
  curr->age = age;
  curr->next = NULL;
  return curr;
}

Node *search_node(char name[])
{
  int hash_key = hash_func(name[0]);

  Node *curr = head[hash_key];
  while (curr)
  {
    if (strcmp(curr->name, name) == 0)
    {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

void insert(char name[], int age)
{
  int hash_key = hash_func(name[0]);
  Node *curr = create_node(name, age);

  if (head[hash_key] == NULL)
  {
    head[hash_key] = tail[hash_key] = curr;
  }
  else
  {
    tail[hash_key]->next = curr;
    tail[hash_key] = curr;
  }
}

void print()
{
  for (int i = 0; i < SIZE; i++)
  {
    Node *curr = head[i];
    printf("%d ", i);
    while (curr)
    {
      printf("%s, %d -> ", curr->name, curr->age);
      curr = curr->next;
    }
    printf("\n");
  }
}

int main()
{
  insert("Andy", 25);
  insert("Andy", 25);
  insert("Andy", 25);

  print();

  return 0;
}