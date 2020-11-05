#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    vector<int> V;
    int N;
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        int kg;
        cin >> kg;
        V.push_back(kg);
    }
    
    sort(V.begin(), V.end());
    
    int result = 0;
    for(int i=1; i<=N; i++) {
        result = max(result, V[N-i]*i);
    }
    
    cout << result << '\n';
    
    return 0;
}
