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
g++ ABC/Contest/ABC435/ABC435_E.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}


int main(){
    int n,Q;
    cin >> n >> Q;
    int ans = n;
    vector<pair<int,int>> cells;
    rep(query,Q){
        int start = -1, end = cells.size(),t,L,R;
        int res = 0;
        cin >> L >> R;
        if(query == 0){
            cells.push_back(MP(L,R));
            res = R-L+1;
            ans -= res;
            cout << ans << endl;
            continue;
        }
        while(end-start > 1){
            t = (start+end)/2;
            if(cells[t].first <= L) start = t;
            if(cells[t].first > L) end = t;
        }
        int l = cells[t].first, save = t;
        start = -1, end = cells.size();
        while(end-start > 1){
            t = (start+end)/2;
            if(cells[t].second <= R) start = t;
            if(cells[t].second > R) end = t;
        }
        int r = cells[t].second;
        bool merged = false;
        if(L < l && l <= R){
            cells[save].first = L;
            merged = true;
            res += l-L;
        }
        if(L <= r && r < R){
            cells[t].second = R;
            merged = true;
            res += R-r;
        }
        if(!merged){
            cells.push_back(MP(L,R));
            SORT(cells);
            res += R-L+1;
        }
        cout << "(l,r) = (" << l << "," << r << ")" << endl;
        ans -= res;
        cout << ans << endl;
    }
}