// LeetCode - Easy : 876. Middle of the Linked List

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value){
        data=value;
        next=nullptr;
    }
};

Node *middleNode(Node *head){
    Node *slow=head;
    Node *fast=head;

    while(fast!=nullptr and fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

int main(){
    Node *head= new Node(10);
    Node *first= new Node(20);
    Node *second= new Node(30);
    Node *third= new Node(40);
    Node *fourth= new Node(50);
    Node *fifth= new Node(60);
    Node *sixth= new Node(70);
    Node *seventh= new Node(80);
    Node *eighth= new Node(90);
    Node *ninth= new Node(100);

    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;
    seventh->next=eighth;
    eighth->next=ninth;

    Node *middle=middleNode(head);

    cout<<"Middle node data of given Linked List is : "<<middle->data;
}

// Exact LeetCode Question :

// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:


// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.