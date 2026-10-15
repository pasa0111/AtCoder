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
g++ ABC/problems_C/301-400/ABC312_C.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> A(n),B(m),C(n+m);
    vecin(A); vecin(B);
    rep(i,n) C[i] = A[i];
    rep(i,m) C[n+i] = B[i]+1;
    SORT(A); RSORT(B); SORT(C);
    int a = 0,b = m-1,c = 0,ans = 200000000;
    bool hantei = true;

    //売り手が0人
    if(A[0] > B[0]+1){
        ans = B[0]+1;
        c = n+m;
        hantei = false;
    }

    //売り手が存在
    for(c = 0; hantei && c < n+m; c++){
        if(C[c] < A[0]) continue;
        while(a < n && C[c] >= A[a])a++;
        if(a > 0)a--;
        while(b >= 0 && C[c] > B[b])b--;
        //cout << "X = " << C[c] << "   (a,b) = (" << a << "," << b << ")" << endl;
        if(a >= b){
            ans = C[c];
            break;
        }
    }
    cout << ans << endl;
}