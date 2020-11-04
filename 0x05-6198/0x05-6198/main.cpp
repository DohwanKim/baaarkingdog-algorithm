#include <iostream>
#include <stack>
using namespace std;

const int MAX = 1e5 * 8;
int buildings[MAX];

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    stack<int> S;
    long long result = 0;
    int N;
    cin >> N;
    
    for (int i=0; i<N; i++) {
        cin >> buildings[i];
    }
    
    for (int i=0; i<N; i++) {
        while (!S.empty() && S.top() <= buildings[i]) {
            S.pop();
        }
        
        S.push(buildings[i]);
        result += S.size() - 1;
    }
    
    cout << result << '\n';
    
    return 0;
}
