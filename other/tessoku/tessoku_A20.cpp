#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

void f(int i, int j, string &S, string &T, vector<vector<int>> &memo){
    if(i == 0 && j == 0){
        if(S.at(i) != T.at(j)){memo.at(i).at(j) = 0;}
        if(S.at(i) == T.at(j)){memo.at(i).at(j) = 1;}
        return;
    }
    if(j == 0){
        if(memo.at(i-1).at(j) == -1){f(i-1,j,S,T,memo);}
        if(S.at(i) != T.at(j)){memo.at(i).at(j) = memo.at(i-1).at(j);}
        if(S.at(i) == T.at(j)){memo.at(i).at(j) = 1;}
        return;
    }
    if(i == 0){
        if(memo.at(i).at(j-1) == -1){f(i,j-1,S,T,memo);}
        if(S.at(i) != T.at(j)){memo.at(i).at(j) = memo.at(i).at(j-1);}
        if(S.at(i) == T.at(j)){memo.at(i).at(j) = 1;}
        return;
    }
    if(S.at(i) == T.at(j)){
        if(memo.at(i-1).at(j-1) == -1){f(i-1,j-1,S,T,memo);}
        memo.at(i).at(j) = memo.at(i-1).at(j-1) + 1;
    }
    if(S.at(i) != T.at(j)){
        if(memo.at(i-1).at(j) == -1){f(i-1,j,S,T,memo);}
        if(memo.at(i).at(j-1) == -1){f(i,j-1,S,T,memo);}
        memo.at(i).at(j) = max(memo.at(i-1).at(j),memo.at(i).at(j-1));
    }
    return;
}

int main(){
    string S,T;
    cin >> S >> T;
    int s = S.size(), t = T.size();
    vector<vector<int>> memo(s,vector<int>(t,-1));
    f(s-1,t-1,S,T,memo);
    cout << memo.at(s-1).at(t-1) << endl;
}