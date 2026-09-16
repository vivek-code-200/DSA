// LeetCode - Easy : 206. Reverse Linked List

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

Node *reverseLinkedList(Node *head){
    Node *curr=head;
    Node *prev=nullptr;

    while (curr!=nullptr)
    {
       Node *nex=curr->next;
       curr->next=prev;
       prev=curr;
       curr=nex;
    }

    return prev;   
}

int main(){
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    head->next=second;
    second->next=third;
    third->next=fourth;

    Node *result = reverseLinkedList(head);

    cout<<"Reverse of given Linked List is : ";
    while(result!=nullptr){
        cout<<result->data<<", ";
        result=result->next;
    }
}

// Exact LeetCode Question :

// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:

// Input: head = [1,2]
// Output: [2,1]

// Example 3:

// Input: head = []
// Output: []