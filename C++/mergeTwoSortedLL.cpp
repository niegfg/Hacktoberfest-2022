#include "iostream"
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtEnd(Node* &head, Node* &end, int d){

    //handling the case if there is no element in Linked List
    if(head == NULL){
        Node* new_node = new Node(d);
        head = new_node;
        end = new_node;
    }
    else{
        Node* new_node = new Node(d);   //new node create
        end -> next = new_node;         //it will store the address of new_node in its next pointer type
        end = new_node;                 //it will point to the new_node created
    }
}

Node* solve(Node* head1, Node* head2){

    Node* curr1 = head1;
    Node* forw1 = curr1 -> next;

    Node* curr2 = head2;
    Node* forw2 = curr2 -> next;

    while(forw1 != NULL && forw2 != NULL){
        if((curr1 -> data <= curr2 -> data) && (curr2 -> data <= forw1 -> data)){
            //add node between them
            curr1 -> next = curr2;
            forw2 = curr2 -> next;
            curr2 -> next = forw1;

            //updating the pointers
            curr1 = curr2;
            curr2 = forw2;
        }
        else{
            //go one step ahead in first list
            curr1 = forw1;
            forw1 = forw1 -> next;

            if(forw1 == NULL){
                curr1 -> next = curr2;
                return head1;
            }
        }
    }
    return head1;
}

Node* merge(Node* head1, Node* head2){

    if(head1 == NULL){
        return head2;
    }

    if(head2 == NULL){
        return head1;
    }

    if(head1 -> data >= head2 -> data){
        solve(head2, head1);
    }
    else{
        solve(head1, head2);
    }
    
}

void display(Node* head){
    Node* temp = head;              //created new node with name temp

    while(temp != NULL){
        cout<<temp -> data<<" ";    //it will print the data stored at particular node
        temp = temp -> next;        //it will update the address at next so that it will point to another node in LL
    }
    cout<<endl;
}

int main() {

    Node* l1 = new Node(5);
    Node* head1 = l1;
    Node* end1 = l1;
    insertAtEnd(head1, end1, 7);
    insertAtEnd(head1, end1, 9);

    Node* l2 = new Node(2);
    Node* head2 = l2;
    Node* end2 = l2;
    insertAtEnd(head2, end2, 8);
    insertAtEnd(head2, end2, 11);

    display(head1);
    display(head2);

    Node* res = merge(head1, head2);
    display(res);


    return 0;
}