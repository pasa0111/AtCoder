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
g++ ABC/problems_D/401-500/ABC426_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int T;
    cin >> T;
    rep(testcase,T){
        ll n;
        string S;
        cin >> n >> S;
        ll zero = 0, one = 0, cnt = 0;
        map<char,ll> M;
        rep(i,n)M[S[i]]++;
        int i = 0, j = n-1;
        //"0000000..."にする
        while(i <= j){
            while(i <= j && S[i] == '1') {zero++; cnt++; i++;}
            while(i <= j && S[j] == '1') {zero++; cnt++; j--;}
            if(cnt == M['1']) break;
            int k = 0, l = 0;
            while(i+k <= j && S[i+k] == '0')k++;
            while(i <= j-l && S[j-l] == '0')l++;
            if(k <= l) {zero += 2*k; i += k;}
            if(k > l) {zero += 2*l; j -= l;}
        }
        cnt = 0;
        //"111111..."にする
        string copy = S;
        i = 0; j = n-1;
        while(i <= j){
            while(i <= j && S[i] == '0'){one++; i++; cnt++;}
            while(i <= j && S[j] == '0') {one++; j--; cnt++;}
            if(cnt == M['0']) break;
            int k = 0, l = 0;
            while(i+k <= j && S[i+k] == '1') k++;
            while(i <= j-l && S[j-l] == '1') l++;
            if(k <= l) {one += 2*k; i += k;}
            if(k > l) {one += 2*l; j -= l;}
        }
        cout << min(zero,one) << endl;
    }
}