#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    vector<pair<int, int>> V;
    int N, t=0, result=0;
    
    cin >> N;
    
    while (N--) {
        int a, b;
        cin >> a >> b;
        V.push_back({b, a});
    }
    
    sort(V.begin(), V.end());
    
    for (auto i=0; i<V.size(); i++) {
        if(t > V[i].second) continue;
        result++;
        t = V[i].first;
    }
    
    cout << result << '\n';
    
    return 0;
}
