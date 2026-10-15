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


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll H1,W1,H2,W2;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1,vector<int>(W1));
    rep(i,H1){
        rep(j,W1){
            cin >> A[i][j];
        }
    }
    cin >> H2 >> W2;
    vector<vector<int>> B(H2,vector<int>(W2));
    vector<vector<int>> C(H2,vector<int>(W2));
    rep(i,H2){
        rep(j,W2){
            cin >> B[i][j];
        }
    }
    bitset<32> row = 0,col = 0;
    bool ans = false;
    while(row.to_ullong() < (1 << H1)){
        row = bitset<32>(row.to_ullong()+1);
        col.reset();
       //cout << "row:" << row << "   count:" << row.count() << endl;
        if(row.count() != H2) continue;
        while(col.to_ullong() < (1 << W1)){
            col = bitset<32>(col.to_ullong()+1);
            //cout << "col:" << col << "   count:" << col.count() << endl;
            if(col.count() != W2) continue;
            int r = 0, c = 0;
            rep(i,H1){
                c = 0;
                if(row[i] == 0) continue;
                rep(j,W1){
                    if(row.test(i) && col.test(j)){
                        //cout << "(r,c) = (" << r << "," << c << ")" << endl;
                        C[r][c] = A[i][j];
                        c++;
                    }
                }
                r++;
            }
            if(B == C) ans = true;
        }
    }
    yesno(ans);
}