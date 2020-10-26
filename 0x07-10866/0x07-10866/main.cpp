#include <iostream>
#include <deque>
using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x) {
    dat[--head] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

int pop_front() {
    if (tail - head == 0) {
        return -1;
    } else {
        head++;
        return dat[head-1];
    }
}

int pop_back() {
    if (tail - head == 0) {
        return -1;
    } else {
        tail--;
        return dat[tail];
    }
}

int front() {
    if(tail - head == 0) {
        return -1;
    } else {
        return dat[head];
    }
}

int back() {
    if(tail - head == 0) {
        return -1;
    } else {
        return dat[tail-1];
    }
}

int size() {
    return tail - head;
}

int empty() {
    if (tail - head > 0) {
        return 0;
    } else {
        return 1;
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int input;
    cin >> input;
    
    while (input) {
        string command;
        cin >> command;
        
        if (command == "push_front") {
            int n;
            cin >> n;
            push_front(n);
        } else if (command == "push_back") {
            int n;
            cin >> n;
            push_back(n);
        } else if (command == "pop_front") {
            cout << pop_front() << '\n';
        } else if (command == "pop_back") {
            cout << pop_back() << '\n';
        } else if (command == "size") {
            cout << size() << '\n';
        } else if (command == "empty") {
            cout << empty() << '\n';
        } else if (command == "front") {
            cout << front() << '\n';
        } else if (command == "back") {
            cout << back() << '\n';
        }
        
        input--;
    }
    
    
    return 0;
}
