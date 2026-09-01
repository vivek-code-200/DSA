// LeetCode - Easy : 141. Linked List Cycle

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

bool checkCycle(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=nullptr and fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }

    return false;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;

    bool isCycle = checkCycle(head);

    cout<<"Given Linked List is Cycle : "<<isCycle;
}

// Exact LeetCode Question : 

// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

 

// Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
// Example 2:


// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
// Example 3:


// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.