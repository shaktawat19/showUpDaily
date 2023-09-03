#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        next = NULL;
    }
};


Node* takeInput(){
    int data;
    cin >> data;
    
    Node *head = NULL;
    Node *temp = NULL;

    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
        cin >> data;
    }

    return head;
}


void printLL(Node* head){
    if(head == NULL)    // edge case
        return;

    Node *temp = head;
    while(temp != NULL){
        cout << temp->data <<" -> ";
        temp = temp->next;
    }
}

int lengthLL(Node* head){
    if(head == NULL)  // edge case
        return 0;
    
    Node *temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }

    return length;
}

int lengthRecursive(Node *head){
    if(head == NULL) return 0;

    return lengthRecursive(head->next) + 1;
}

int main(){
    Node* head = takeInput();
    printLL(head);

    return 0;
}