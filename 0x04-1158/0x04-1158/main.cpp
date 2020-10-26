#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m;
    list<int> L;
    vector<int> result;
    
    cin >> n >> m;
    
    for(int i=0; i < n; i++) {
        L.push_back(i+1);
    }
    
    list<int>::iterator kPointer = L.begin();
    
    while (n > 0) {
        for(int i=0; i < m-1; i++) {
            if (kPointer == L.end()) kPointer = L.begin();
            kPointer++;
            if (kPointer == L.end()) kPointer = L.begin();
        }
        result.push_back(*kPointer);
        kPointer = L.erase(kPointer);
        n--;
    }
    
    cout << '<';
    for(int i=0; i < result.size(); i++) {
        cout << result[i];
        
        if(i != result.size()-1) {
            cout << ", ";
        }
    }
    cout << '>' << '\n';
    
    return 0;
}
