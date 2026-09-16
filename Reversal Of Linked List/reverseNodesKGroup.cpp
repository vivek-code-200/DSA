// LeetCode - Hard : 25. Reverse Nodes in k-Group

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

Nodes *swapNodes(Nodes *head, int k){
    if(head==nullptr){
        return head;
    }

    Nodes *res=nullptr;

    Nodes *left=head;
    Nodes *prevLeft=nullptr;
    Nodes *right;

    while (true)
    {
        right=left;
        for(int i=0;i<k-1;i++){
            if(right==nullptr){
                break;
            }
            right=right->next;
        }

        if(right){
            Nodes *nextLeft = right->next;
            reverse(left,k);
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

    Nodes *result = swapNodes(head,3);

    cout<<"Nodes after reversing k groups : ";
    while(result!=nullptr){
        cout<<result->data<<", ";
        result=result->next;
    }
}

// Exact LeetCode Question :

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]