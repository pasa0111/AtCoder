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
g++ ABC/problems_C/401-500/ABC415_C.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

string S;
int n;
bool ans = false;
bool ok(bitset<18> x){
    int y = x.to_ullong();
    if(y == 0) return true;
    return S[y-1] == '0';
}

bitset<18> x;
vector<bool> memo((1 << n),true);
void exper(){
    if(memo[x.to_ullong()] == false) return;
    if(!ok(x)){
        memo[x.to_ullong()] = false;
        return;
    }
    if(x.count() == n){
        ans = true;
        return;
    }

    for(int i = 0; i < n; i++){
        if(!x.test(i)){
            x.set(i,1);
            exper();
            x.set(i,0);
        }
        if(ans) break;
    }
    if(!ans) memo[x.to_ullong()] = false;
    return;
}

int main(){
    int T;
    cin >> T;
    rep(test,T){
        cin >> n >> S;
        ans = false;
        x = 0;
        memo = vector<bool>((1 << n),true);
        exper();
        yesno(ans);
    }
}