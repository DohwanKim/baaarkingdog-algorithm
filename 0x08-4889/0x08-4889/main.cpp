#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    int testNo = 0;
    
    while (1) {
        testNo++;
        stack<char> s;
        vector<char> v;
        int result = 0;
        string str;
        cin >> str;
        
        if (str.find("-") != string::npos) break;
        
        for(char c: str) {
            if(c == '{')
                s.push(c);
            else if (!s.empty() && c == '}')
                s.pop();
            else
                v.push_back(c);
        }
        
        
        for (auto i=0; i<v.size(); i++)
            s.push(v[i]);
        
        while (!s.empty()) {
            char res = s.top(); s.pop();
            
            if(res == '{') {
                if(s.top() == '{')
                    result++;
                else
                    result += 2;
            } else if (res == '}') {
                if(s.top() == '}')
                    result++;
                else
                    result += 2;
            }
            
            s.pop();
        }
        
        cout << testNo << ". " << result << '\n';
    }

    return 0;
}
