// setup dynamic linked list
// addHead, addTail

#include <iostream>


//
using namespace std;

struct List {
    int data;
    List *next;
};

typedef struct List *node;

node createNode(int x) {
    node temp;
    temp = new List;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

node addHead(node head, int x) {
    node temp = createNode(x);
    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
    return head;
}

node addTail(node head, int x) {
    node temp = createNode(x);
    node p;
    if(head == NULL) {
        head = temp;
    } else {
        p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

node pop(node head, int x) {
    node temp1;
    node temp2;
    if (head == NULL)
        return head;
    temp1 = head;
    temp2 = temp1->next;
    if (temp1->data == x) {
        head = temp2;
        return head;
    }
    while(temp2->data != x) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp2->next == NULL) {
        temp1->next = NULL;
    } else
    if (temp2->data == x) {
        temp2 = temp2->next;
        temp1->next = temp2;
    }
    return head;
}

void display(node head) {
    node temp = head;
    while(temp->next != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << temp->data << endl;
}


int main() {
    node head = createNode(1);
    head = addHead(head, 2);
    head = addHead(head, 3);
    head = addTail(head, 4);
    head = addHead(head, 5);
    head = addHead(head, 6);
    head = pop(head,6);
    display(head);
    return 0;
}
