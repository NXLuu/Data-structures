#include <iostream>
#include <vector>
#define N 1000001
using namespace std;

vector<int> dequeue;
int f = -1; // front
int b = -1; // back
int checkRe = 0;

void toFront(int x) {
    if (f == b && f == -1) {
        f = 0;
        b = 0;
        dequeue[f] = x;
    } else if (f == 0) {
        f = N - 1;
        dequeue[f] = x;
    } else {
        --f;
        dequeue[f] = x;
    }
}

void toBack(int x) {
    if (f == b && f == -1) {
        f = 0;
        b = 0;
        dequeue[b] = x;
    
    } else if(b == N - 1) {
        b = 0;
        dequeue[b] = x;
    } else {
        ++b;
        dequeue[b] = x;
    }

}

void front() {
    if(f == -1 && b == -1) {
        printf("No job for Ada?\n");
    } else if (f == b) {
        printf("%d\n", dequeue[f]);
        f = b = -1;
    } else if (f == N - 1) {
        printf("%d\n", dequeue[f]);
        f = 0;
    } else {
        printf("%d\n", dequeue[f]);
        ++f;
    }
}

void back() {
    if(f == -1 && b == -1) {
        printf("No job for Ada?\n");
    } else if (f == b) {
        printf("%d\n", dequeue[b]);
        f = b = -1;
    } else if (b == 0) {
        printf("%d\n", dequeue[b]);
        b = N - 1;
    } else {
        printf("%d\n", dequeue[b]);
        --b;
    }
   
    
}

void solve() {
    char s[20];
    scanf("%s", &s);
    if (s[0] == 't')  {      // toFront
        int x;
        scanf("%d", &x);
        if (checkRe == 0)
            toFront(x);
        else toBack(x);
    } else if (s[0] == 'p') { // push_back
        int x;
        scanf("%d", &x);
        if (checkRe == 0)
            toBack(x);
        else toFront(x);
    } else if (s[0] == 'f') { // front
        if (checkRe == 0)
            front();
        else back();
    } else if (s[0] == 'b') { // back
        if (checkRe == 0)
            back();
        else front();
    } else {
        checkRe = 1 - checkRe;
    }
}


int main() {
    int q;
    cin >> q;
    dequeue.resize(N,-1);
    while (q --) {
        solve();
    }
    
    return 0;
}
