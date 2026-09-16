// LeetCode - Medium : 24. Swap Nodes in Pairs

#include<iostream>
using namespace std;

struct Nodes
{
    int data;
    Nodes *next;

    Nodes(int val){
        data=val;
        next=nullptr;
    }
};

void reverse(Nodes *head,int size){
    Nodes *curr=head;
    Nodes *prev=nullptr;

    while (size--)
    {
        Nodes *nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
  
}

Nodes *swapNodes(Nodes *head){
    if(head==nullptr){
        return head;
    }

    Nodes *res=nullptr;

    Nodes *left=head;
    Nodes *prevLeft=nullptr;
    Nodes *right;
    int size=2;

    while (true)
    {
        right=left;
        for(int i=0;i<size-1;i++){
            if(right==nullptr){
                break;
            }
            right=right->next;
        }

        if(right){
            Nodes *nextLeft = right->next;
            reverse(left,2);
            if(res==nullptr){
                res=right;
            }
            if(prevLeft){
                prevLeft->next=right;
            }
            prevLeft=left;
            left=nextLeft;
        }
        else{
            if(prevLeft){
                prevLeft->next=left;
            }
            if(res==nullptr){
                res=left;
            }
            break;
        }
    }
    return res;

}

int main(){
    Nodes *head=new Nodes(10);
    Nodes *second=new Nodes(20);
    Nodes *third=new Nodes(30);
    Nodes *fourth=new Nodes(40);

    head->next=second;
    second->next=third;
    third->next=fourth;

    Nodes *result = swapNodes(head);

    cout<<"Nodes after swaping the pairs : ";
    while(result!=nullptr){
        cout<<result->data<<", ";
        result=result->next;
    }
}


// Exact LeetCode Question :

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

// Example 1:

// Input: head = [1,2,3,4]

// Output: [2,1,4,3]

// Explanation:


// Example 2:

// Input: head = []

// Output: []


// Example 3:

// Input: head = [1]

// Output: [1]


// Example 4:

// Input: head = [1,2,3]

// Output: [2,1,3]