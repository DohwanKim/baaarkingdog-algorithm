#include <iostream>
#include <deque>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        deque<int> d;
        string p, numline;
        int arrSize;
        bool errorStatus = false, reverseD = false;
        
        cin >> p >> arrSize >> numline;
        
        //배열 입력 파싱
        int i = 1;
        while (numline[i]!='\0'){
            int x = 0;
            while (numline[i] >= '0' and numline[i] <= '9') {
                x *= 10;
                x += int(numline[i] - '0');
                i++;
            }
            if (x != 0) {
                d.push_back(x);
            }
            i++;
        }
        
        //명령어 수행
        for(char c: p) {
            if(c == 'R') { //뒤집기
                reverseD = !reverseD;
            } else { //빼기
                if(d.empty()) {
                    cout << "error" << '\n';
                    errorStatus = 1;
                    break;
                }
                if(reverseD) {
                    d.pop_back();
                } else {
                    d.pop_front();
                }
            }
        }
        
        //덱 출력
        if(!errorStatus) {
            cout << '[';
            if(!reverseD) {
                for(int i=0; i < d.size(); i++) {
                    cout << d[i];
                    if(i != d.size()-1) cout << ',';
                }
            } else {
                for(int i=0; i < d.size(); i++) {
                    cout << d[d.size()-i-1];
                    if(i != d.size()-1) cout << ',';
                }
            }
            cout << ']' << '\n';
        }
    }
    
    return 0;
}
