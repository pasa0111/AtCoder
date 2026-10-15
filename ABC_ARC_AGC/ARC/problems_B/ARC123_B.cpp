#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int N, ans = 0;
    cin >> N;
    vector<long long> A(N), B(N), C(N);
    for(int i = 0; i < N; i++){cin >> A.at(i);}
    for(int i = 0; i < N; i++){cin >> B.at(i);}
    for(int i = 0; i < N; i++){cin >> C.at(i);}
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int a = 0, b = 0, c = 0;
    while(a < N && b < N && c < N){
        if(A.at(a) < B.at(b)){
            if(B.at(b) < C.at(c)){
                ans++;
                a++;
                b++;
                c++;
                continue;
            }
            if(B.at(b) >= C.at(c)){
                c++;
                continue;
            }
        }
        
        if(A.at(a) >= B.at(b)){b++;}
    }
    cout << ans << endl;
}