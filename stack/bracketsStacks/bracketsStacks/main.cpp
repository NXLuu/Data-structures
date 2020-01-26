// Bai Brackets
// ()()() - isTrue
// ()()( - isFalse

#include <iostream>
#include <vector>
using namespace std;
string bs;

long long sizeOfStacks(vector<char> s) {
    return s.size() - 1;
}

bool isCorrectBrackets() {
    vector<char> stacks;
    for (int i = 0; i < bs.size() ; ++i) {
        if (bs[i] == '(')
            stacks.push_back(bs[i]);
        else {
            if (sizeOfStacks(stacks) == -1)
                return false;
            stacks.pop_back();
        }
    }
    if (sizeOfStacks(stacks) == -1)
        return true;
    return false;
}


int main() {
    cin >> bs;
    cout << isCorrectBrackets() << endl;
    return 0;
}
