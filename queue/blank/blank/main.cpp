#include <iostream>
#include <queue>
using namespace std;
long n1, n2, Max = 0;
queue<int> queue1;
queue<int> queue2;

void input(long n, queue<int> &q) {
    for (int i = 1; i <= n ; ++ i) {
        int temp;
        cin >> temp;
        if (temp > Max)
            Max = temp;
        q.push(temp);
    }
    
}


void solve() {
    long time = 1;
    int a[10];
    for (int i = 0 ; i <= Max; ++i)
        a[i] = 0;
    while(!queue1.empty() || !queue2.empty()) {
        if (!queue1.empty()) {
            while(a[queue1.front()] != 0) {
                queue1.pop();
            }
            a[queue1.front()] = time;
            queue1.pop();
        }
        if (!queue2.empty()) {
            while(a[queue2.front()] != 0) {
                queue2.pop();
            }
            a[queue2.front()] = time;
            queue2.pop();
        }
        ++time;
    }
    for (int i = 1; i <= Max; ++i) {
        if (a[i] != 0)
            cout << a[i] << " ";
    }
}

int main() {
    cin >> n1;
    cin >> n2;
    input(n1, queue1);
    input(n2, queue2);
    solve();
    return 0;
}
