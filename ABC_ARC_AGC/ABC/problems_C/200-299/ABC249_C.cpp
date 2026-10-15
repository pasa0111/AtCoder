#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adjrep(i,s,e) for(ll i = s; i <= e; i++)
#define vall(vec) vec.begin(),vec.end()
#define vin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

void solve(int n, int N, int &ans, int res, int K, map<char,int> &A, map<int,set<char>> &B){
    
    if(n == N){
        ans = max(ans,res);
        return;
    }
    
    
    for(char i:B.at(n)){
        A.at(i)++;
        if(A.at(i) == K){res++;}
        if(A.at(i) == K+1){res--;}
    }
    solve(n+1,N,ans,res,K,A,B);
    for(char i:B.at(n)){
        A.at(i)--;
        if(A.at(i) == K){res++;}
        if(A.at(i) == K-1){res--;}
    }
    solve(n+1,N,ans,res,K,A,B);
    return;
}

int main(){
    int N,K;
    cin >> N >> K;
    string S;
    map<char,int> A; //選んだ文字列に含まれる[アルファベット]の数を保存
    map<int,set<char>> B; //文字列[i]に登場するアルファベットを保存
    set<char> C;
    rep(i,N){
        cin >> S;
        B[i] = C;
        int size = S.size();
        rep(j,size){
            B.at(i).insert(S.at(j));
            A[S.at(j)] = 0;
        }
    }
    int ans = 0, res = 0;
    solve(0,N,ans,res,K,A,B);
    cout << ans << endl;
}