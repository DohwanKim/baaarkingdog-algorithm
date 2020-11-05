#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int i=0; i<T; i++) {
        stack<char> s;
        string eachInput;
        cin >> eachInput;
        bool check = true;
        
        for(char c: eachInput) {
            if(c == '(')
                s.push('(');
            else if (!s.empty() && ')')
                s.pop();
            else
                check = false;
        }
        
        if(!s.empty() || !check) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    
    return 0;
}
