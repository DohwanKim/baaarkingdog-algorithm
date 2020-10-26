#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    stack<int> S;
    int count;
    
    cin >> count;
    
    while (count) {
        int input;
        cin >> input;
        
        if(input == 0) {
            S.pop();
        } else {
            S.push(input);
        }
        
        count--;
    }
    
    int total = 0;
    while (S.size()) {
        total += S.top();
        S.pop();
    }
    
    cout << total;
    
    return 0;
}
