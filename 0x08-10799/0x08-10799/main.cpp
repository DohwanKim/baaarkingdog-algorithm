#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    stack<char> s;
    int barCount = 0;
    string input;
    getline(cin, input);
    
    for(int i=0; i < input.length(); i++) {
        if(input[i] == '(') {
            s.push(input[i]);
        } else {
            s.pop();
            
            if(input[i-1] == '(') {
                barCount += s.size();
            } else {
                barCount++;
            }
        }
    }
    cout << barCount << '\n';
    
    return 0;
}
