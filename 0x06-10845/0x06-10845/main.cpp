#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    queue<int> Q;
    int count;
    cin >> count;
    
    while (count) {
        string command;
        cin >> command;
        
        if(command == "push") {
            int input;
            cin >> input;
            Q.push(input);
        } else if (command == "pop") {
            if(Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        } else if (command == "size") {
            cout << Q.size() << '\n';
        } else if (command == "empty") {
            cout << (int)Q.empty() << '\n';
        } else if (command == "front") {
            if(Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
            }
        } else if (command == "back") {
            if(Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.back() << '\n';
            }
        }
        
        count--;
    }
    
    return 0;
}
