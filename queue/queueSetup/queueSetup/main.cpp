#include <iostream>
#include <vector>
using namespace std;
vector<long long> queue;
int front = - 1;
int rear = - 1;

void enqueue(long long x) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 1;
    } else {
        
        ++rear;
    }
    queue.push_back(x);
}

void dequeue() {
    if (front != rear) {
        ++front;
    }
}

int size() {
    return rear - front;
}

void display() {
    for (int i = front; i < rear; ++i) {
        cout << queue[i] << " ";
    }
}


int main() {
    long long n;
    long long temp;
    cin >> n;
    long long cnt = 1;
    temp = 5;
    while(n - temp > 0) {
        n -= temp;
        cnt *= 2;
        temp = cnt * 5;
    }
    long long res = n / cnt;
    if (n % cnt != 0)
        res += 1;
    cout << res << endl;
    return 0;
}
