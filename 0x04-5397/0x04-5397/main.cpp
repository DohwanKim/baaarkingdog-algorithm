#include <iostream>
#include <list>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    while (testCase--) {
        string inputPW;
        list<char> L;
        list<char>::iterator it = L.begin();
        
        cin >> inputPW;

        for (char c: inputPW) {
            if(c == '-') {
                if(it != L.begin()) L.erase((--it)++);
            } else if (c == '<') {
                if(it != L.begin()) it--;
            } else if (c == '>') {
                if(it != L.end()) it++;
            } else {
                L.insert(it, c);
            }
        }
        
        for(auto x: L) {
            cout << x;
        }
        cout << '\n';
    }
    
    return 0;
}
