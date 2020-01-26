#include <iostream>
#include <queue>
#include <utility>
using namespace std;
long n, m;

void solve() {
    int cnt = 0;
    int a[10];
    for (int i = 0; i <= 9; ++i) {
        a[i] = 0;
    }
    queue<pair<int, int>> myQueue;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        pair<int, int> myPair(i, temp);
        ++a[temp];
        myQueue.push(myPair);
    }
    int j = 9;
    while (a[j] == 0) {
        --j;
    }
    while(j > 0) {
        if (myQueue.front().second < j) {
            myQueue.push(myQueue.front());
            myQueue.pop();
        } else {
            ++cnt;
            if (myQueue.front().first == m) {
                cout << cnt << endl;
                return ;
            }
            myQueue.pop();
            --a[j];
            while (a[j] == 0) {
                --j;
            }
        }
    }
}


int main() {
    long t;
    cin >> t;
    while(t --) {
        cin >> n;
        cin >> m;
        solve();
    }
    
    return 0;
}
