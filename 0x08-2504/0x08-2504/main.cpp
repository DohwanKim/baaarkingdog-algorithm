#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    stack<char> s;
    long long result = 0;
    int computed = 1;
    bool verify = true;
    string input;
    getline(cin, input);
    
    for(int i=0; i < input.length(); i++) {
        if(input[i] == '[') {
            computed *= 3;
            s.push(input[i]);
        } else if (input[i] == '(') {
            computed *= 2;
            s.push(input[i]);
        } else if (input[i] == ')' && (s.empty() || s.top() != '(')) {
            verify = false;
            break;
        } else if (input[i] == ']' && (s.empty() || s.top() != '[')) {
            verify = false;
            break;
        } else if (input[i] == ']') {
            if(input[i-1] == '[') result += computed;
            s.pop();
            computed /= 3;
        } else if (input[i] == ')') {
            if(input[i-1] == '(') result += computed;
            s.pop();
            computed /= 2;
        }
    }
   
    if(!s.empty()) verify = false;
    
    if(verify) cout << result << '\n';
    else cout << 0 << '\n';
    
    return 0;
}
