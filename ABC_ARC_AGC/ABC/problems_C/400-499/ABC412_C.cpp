#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <cctype>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

/*
g++ ABC/problems_C/401-500/ABC412_C.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int T;
    cin >> T;
    rep(test,T){
        int n;
        cin >> n;
        vector<int> S;
        int start, end;
        cin >> start;
        for(int i = 1; i < n; i++){
            int s;
            cin >> s;
            if(i == n-1){
                end = s;
                continue;
            }
            if(s > start) S.push_back(s);
        }
        int m = S.size(), ans = -1;
        if(ans == -1){
            SORT(S);
            int back = start, cnt = 0;
            //cout << start << " ";
            for(int j = 0; j < m; j++){
                if(2*back >= end) break;
                
                int l = j, r = m, t;
                while(r-l > 1){
                    t = (r+l)/2;
                    if(2*back < S[t]) r = t;
                    if(2*back >= S[t]) l = t;
                }
                j = l;
                if(2*back >= S[j]){
                    cnt++;
                    back = S[j];
                    //cout << back << " ";
                }
            }
            //cout << end << endl;
            if(2*back >= end) ans = cnt+2;
        }
        cout << ans << endl;
    }
}