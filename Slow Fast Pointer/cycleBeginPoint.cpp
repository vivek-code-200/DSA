// LeetCode - Medium : 142. Linked List Cycle II

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

Node *cycleBeginPoint(Node *head){
    Node *slow=head;
    Node*fast=head;

    while(fast!=nullptr and fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }

    return nullptr;
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
    ninth->next=third;

    Node *cycleBegin =  cycleBeginPoint(head);

    if(cycleBegin!=nullptr){
        cout<<"Cycle begin point data is : "<<cycleBegin->data;
    }
    else{
        cout<<"No Cycle";
    }
}


// Exact LeetCode Question :
// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.

 

// Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.
// Example 2:


// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.
// Example 3:


// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.