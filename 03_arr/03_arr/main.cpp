#include <iostream>

using namespace std;



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string word;
    int aFreq[25] = {};
    
    cin >> word;
    
    for(int e: word) {
        aFreq[e-97]++;
    }
    
    for(int b: aFreq) {
        cout << b << ' ';
    }
}
