#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }

    void print() {
        struct Node* temp = head;
        while (temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    void push(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main() {
    LinkedList ll;
    ll.push(20);
    ll.push(21);
    ll.push(22);
    ll.push(23);
    ll.push(24);

    ll.print();
}
