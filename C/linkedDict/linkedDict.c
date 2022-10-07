#include "main.h"
/**
 * printList - function that displays a list
 * insertFirst - function that inserts a node at the
 * beginning of a list
 * deleteFirst - function that deletes first element of a 
 * list
 * isEmpty - function that checks if a list is empty
 * length - A function that returns the length of a list
 * find - A pointer function that returns a node with an input key
 * del - A pointer function that deletes a node with an input key
 * and returns deleted node
 * sort - function that sort the list in ascending order
 *reverse - Function that reverses the list
 */

void main(){
    insertFirst(1,10);
    insertFirst(2,11);
    insertFirst(3,12);
    insertFirst(7,1);
    insertFirst(8,2);

    printf("List: ");
    //print_list
    printList();
    //
    printf("after reversing the list");
    //sort the list
    reverse(&head);
    printList();
    //sorting the list
    printf("after sorting the list");
    sort();
    printList();
    //deleting first nodes value
    printf("deleting element from the beginning of the list");
    while(!isEmpty()){
        Node *temp = deleteFirst();
        printf("\nDeleted value:");
        printf("(%d, %d) ",temp->key,(*temp).data);
    }
    putchar('\n');
    //restoring the list
    
    insertFirst(1,10);
    insertFirst(2,11);
    insertFirst(3,12);
    insertFirst(7,1);
    insertFirst(8,2);

    putchar('\n');  
    printf("list after restoration\n");
    printList();

    //finding a link
    printf("finding element with key : 7\n");
   Node *findlink = find(7);
   if(findlink != NULL){
       printf("Element found: (%d,%d) \n",findlink->key,findlink->data);
    }
    else{
        printf("Element not found.");
    }
    putchar('\n');
    //deleting element at node 7

    del(7);
    printf("list after deleting element with key 7: ");
    putchar('\n');
    printList();    

    //finding the deleted element
    printf("finding the deleted element with key 7:\n");
    findlink = find(7);
     if(findlink != NULL){
       printf("Element found: (%d,%d) \n",findlink->key,findlink->data);
    }
    else{
        printf("Element not found.\n");
    }

    //kapish <<(^___^)>>  

}

//display the list
void printList(){
    Node *ptr = head;
    printf("\n[");
    int x = length();
    int y = 0;

    //start from the beginning
    while(ptr != NULL){        
        printf("(%d, %d)", ptr->key, ptr->data);
        if (y != x-1)
        printf(" -> ");
        ptr = ptr->Next;
        y++;        
    }
    printf("]\n");
    putchar('\n');
}

//insert link at the first location
void insertFirst(int key, int data){
    //create link
    Node *link = (Node *) malloc(sizeof(Node));
    link -> key = key;
    link -> data = data;
    //point to first old node
    link -> Next = head;
    //point first to new
    head = link;
}

//delete first item
Node *deleteFirst(){
    //save reference to first link
    Node *tempLink = head;
    //mark next to first link
    head = head->Next;
    //return the deleted link
    return tempLink;
}
//is list Empty

bool isEmpty(){
    return head == NULL;
}
//find length of the list
int length(){
    Node *pointer = head;
    int len = 0;
    //iterate through the list
    while(pointer != NULL){
        pointer = pointer->Next;
        len++;
    }
    return len;
}

//find a link with a given key
Node *find(int key){
    Node *itrate = head;
    //check if list is empty
    if (itrate == NULL)
    return NULL;

    //iterate through the list
    while(itrate->key != key){
        //check if its last node
        if (itrate->Next == NULL)
          return NULL;
        //else goto next link
        itrate = itrate->Next;
    }
    //
    return itrate;
}
//Delete a link with a given key
Node *del(int key){
    //start form first link
    Node *current = head;
    Node* previous = NULL;

    //if list is empty
    if (head == NULL)
      return NULL;
    //navigate through the list

    while(current->key != key){
        //if its the last Node
        if(current->Next == NULL)
          return NULL;
        //else goto the next link
        else{
            previous = current;
            current = current->Next;
        }
    }
    //if the node is first
    if(current == head)
       head = head->Next;
    //else
    //set previous node to next of current node
    previous->Next = current->Next;
    
    //return the deleted node
    return current;
}
//sorting the list
void sort(){
    int x,z;
    x = length();
    Node *current;
    Node *next;
    
    while(true){
        int finish_sort = 0;
        current = head;
        next = head->Next;
        for(z = 0;z < x - 1; z++){
            //sorting in ascending order
            if(current->data > next->data){
                int tempData = next->data;
                next->data = current->data;
                current->data = tempData;

                //swapping the keys
                int tempKey = next->key;
                next->key = current->key;
                current->key = tempKey;
                //increment our finish_sort
                finish_sort++;
            }
        current = next;
        next = next->Next;
        }
    if (finish_sort == 0)
    break;
    }
}

//reverse the list

void reverse(Node **head_ref){
    Node *prev = NULL;
    Node *current = *head_ref;
    Node *next;

    while (current != NULL){
        next = current->Next;
        current->Next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
