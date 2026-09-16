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

Node *reverseBetween(Node *head, int left, int right)
{
    if (head == nullptr || left == right)
    {
        return head;
    }

    Node *t = head;
    int pos = 1;
    Node *before = nullptr;

    while (pos < left)
    {
        before = t;
        t = t->next;
        pos++;
    }

    Node *curr = t;
    Node *prev = nullptr;
    int times = right - left + 1;

    while (times--)
    {
        Node *nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }

    t->next = curr;

    if (before==nullptr)
    {
        return prev;
    }
    
    before->next = prev;
    return head;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    head->next = second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    Node *result = reverseBetween(head, 1, 2);
    while (result != nullptr)
    {
        cout << result->data << ", ";
        result = result->next;
    }
}