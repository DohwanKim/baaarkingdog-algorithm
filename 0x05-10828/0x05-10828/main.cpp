#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    stack<int> s;
    int count;
    
    cin >> count;
    
    while (count) {
        string command;
        cin >> command;
        
        if (command == "push") {
            int input;
            cin >> input;
            s.push(input);
        } else if (command == "pop") {
            if(s.empty()) {
                cout << -1 << '\n';
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (command == "size") {
            cout << s.size() << '\n';
        } else if (command == "empty") {
            cout << (int)s.empty() << '\n';
        } else if (command == "top") {
            if(s.empty()) {
                cout << -1 << '\n';
            } else {
                cout << s.top() << '\n';
            }
        }
        count--;
    }
    
    return 0;
}
