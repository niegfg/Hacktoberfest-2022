#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    int key;
    struct Node *Next;
}Node;

Node *head = NULL;
Node *current = NULL;

Node *linkedlist(); 
void printList();
void insertFirst(int key, int data);
Node *deleteFirst();
bool isEmpty();
int length();
Node *find(int key);
Node *del(int key);
void sort();
void reverse(Node **head_ref);

#endif
