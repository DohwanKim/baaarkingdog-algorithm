#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int input;
    
    cin >> input;
    
    queue<int> q;
    
    for (int i = 0; i < input; i++) {
        q.push(i+1);
    }
    
    while (q.size() > 1) {
        q.pop();
        int front = q.front();
        q.push(front);
        q.pop();
    }
    
    cout << q.front();
    
    return 0;
}
