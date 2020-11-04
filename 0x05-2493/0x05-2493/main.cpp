#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int N;
    cin >> N;
    stack<pair<int, int>> S; //인덱스, 높이
    
    for (int i=1; i<=N; i++) {
        int height;
        cin >> height;
        
        while (!S.empty()) {
            if(S.top().second > height) {
                cout << S.top().first << ' ';
                break;
            }
            S.pop();
        }
        if(S.empty()) cout << 0 << ' ';
        S.push({i, height});
    }
}
