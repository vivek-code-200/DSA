#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val){
        data=val;
        next=nullptr;
    }
};

Node *rotateList(Node *head, int k){
    if(head==nullptr){
        return head;
    }
    Node *res;
    Node *last = head;
    int n=1;

    while (last->next!=nullptr)
    {
        n++;
        last=last->next;
    }

    k=k%n;

    if(k==0){
        return head;
    }

    int count=1;
    Node *t=head;
    while (count<n-k)
    {
        // if(count==(n-k)){
        //     break;
        // }
        count++;
        t=t->next;
    }

    res=t->next;
    t->next=nullptr;
    last->next=head;

    return res;    
}

int main(){
    Node *head=new Node(10);
    Node *second=new Node(20);
    Node *third=new Node(30);
    Node *fourth=new Node(40);

    head->next=second;
    second->next=third;
    third->next=fourth;

    Node *result = rotateList(head,2);

    cout<<"Nodes after rotating k times : ";
    while(result!=nullptr){
        cout<<result->data<<", ";
        result=result->next;
    }
}