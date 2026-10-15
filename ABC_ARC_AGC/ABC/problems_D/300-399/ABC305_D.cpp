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

template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}

/*
g++ ABC/problems_D/301-400/ABC305_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n),sleep(n);
    rep(i,n){
        cin >> A[i];
        if(i > 0) sleep[i] = sleep[i-1];
        if(i > 0 && i % 2 == 0){
            sleep[i] += A[i]-A[i-1];
        }
        //cout << sleep[i] << " ";
    }
    //cout << endl;
    int Q,l,r,ans,save,start,end,mid;
    cin >> Q;
    rep(question,Q){
        cin >> l >> r;
        ans = 0; start = -1; end = n; mid = (start+end)/2;
        while(end-start>1){
            if(A[mid] <= l) start = mid;
            if(A[mid] > l) end = mid;
            mid = (start+end)/2;
        }
        save = mid;
        start = -1; end = n;
        while(end-start>1){
            mid = (start+end)/2;
            if(A[mid] <= r) start = mid;
            if(A[mid] > r) end = mid;
            mid = (start+end)/2;
        }
        //pair<int,int> test = MP(save,mid);
        //cout << test << endl;
        if(save%2 == 0){
            if(mid%2 == 0){
                ans = sleep[mid]-sleep[save];
            }
            if(mid%2 == 1){
                ans = sleep[mid]-sleep[save] + r-A[mid];
            }
        }
        if(save%2 == 1){
            if(mid%2 == 0){
                ans = sleep[mid]-sleep[save] - (l-A[save]);
            }
            if(mid%2 == 1){
                ans = sleep[mid]-sleep[save] + r-A[mid] - (l-A[save]);
            }
        }
        cout << ans << endl;
    }
}