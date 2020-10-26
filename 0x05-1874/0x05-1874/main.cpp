#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    stack<int> S;
    vector<char> C;
    int count, j = 0;
    
    cin >> count;
    
    int arr[count];
    
    for (int i = 0; i < count; i++) cin >> arr[i];
    
    for (int i = 0; i <= count; i++) {
        S.push(i);
        C.push_back('+');
        
        while (!S.empty() && S.top() == arr[j]) {
            S.pop();
            C.push_back('-');
            j++;
        }
    }
    
    if (!S.empty()) printf("NO\n");
    else {
        for (int i = 0; i < C.size(); i++) cout << C[i];
    }
    
    return 0;
}
