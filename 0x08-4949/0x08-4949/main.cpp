#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    while (1) {
        string input;
        getline(cin, input);
        if(input == ".") break;
        
        stack<char> s;
        bool check = true;
        
        for(char c: input) {
            if(c == '[' || c == '(') {
                s.push(c);
            } else if (c == ']') {
                if(!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    check = false;
                    break;
                }
            } else if (c == ')') {
                if(!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    check = false;
                    break;
                }
            }
        }
        
        if(!s.empty()) check = false;
        
        if(check)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    
    return 0;
}
