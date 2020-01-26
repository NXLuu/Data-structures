#include <iostream>
#include <vector>
#define ll long long
using namespace std;
class stacks
{
public:
    int top = -1;
    vector<ll> s;
    void push(ll);
    void pop();
    void print();
    bool isEmpty() {
        if (top == -1 ) return true;
        else return false;
    };
};

void stacks::push(ll x) {
    s.push_back(x);
    top++;
}

void stacks::pop() {
    if (!this->isEmpty())
        s.pop_back();
    top--;
};

void stacks::print() {
    for (int i = top; i >= 0; --i) {
        cout << s[i] << endl;
    }
}

int main() {
    stacks s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top;
    s.pop();
    s.print();
    
    return 0;
}
