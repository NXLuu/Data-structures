// 2 3 4 + * 5 - 2 2 * +

// = (3 + 4) * 2  - 5 + 2 * 2
#include <iostream>
#include <vector>
using namespace std;
string s;
vector<long long> stacks;

void solve() {
    for (int i = 0; i < s.size(); ++i) {
        long long temp = s[i] - '0';
        if (temp <= 9 && temp >= 0)
            stacks.push_back(temp);
        else {
            long long x1 = stacks[stacks.size() - 1];
            stacks.pop_back();
            long long x2 = stacks[stacks.size() - 1];
            stacks.pop_back();
            cout << s[i] << endl;
            switch(s[i]) {
                case '+':stacks.push_back(x1 + x2);
                    break;
                case '-':stacks.push_back(x2 - x1);
                    break;
                case '*':stacks.push_back(x1 * x2);
                    break;
            }
        }
    }
    cout << stacks[0] << endl;
}

int main() {
    cin >> s;
    solve();
    
    return 0;
}
