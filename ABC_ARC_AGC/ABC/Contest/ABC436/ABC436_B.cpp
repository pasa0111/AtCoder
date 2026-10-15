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
/*
#include <atcoder/all>
using namespace atcoder;
*/
using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define REVERSE(vec) reverse(vecall(vec))
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec); REVERSE(vec)
#define MP make_pair
#define MT make_tuple

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}

constexpr char el = '\n';

/*
g++acl path -o a.out && ./a.out < ./input.txt
g++ ABC/Contest/ABC436/ABC436_B.cpp -o a.out && ./a.out < ./input.txt
*/


void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

int main(){
    int n;
    cin >> n;
    pair<int,int> pre = MP(0,(n-1)/2);
    int k = 1;
    vector<vector<int>> grid(n,vector<int>(n,-1));
    grid[0][(n-1)/2] = 1;
    for(int i = 0; i < n*n-1; i++){
        int r = pre.first, c = pre.second;
        if(grid[(n+r-1)%n][(c+1)%n] == -1){
            pre = MP((n+r-1)%n,(c+1)%n);
            k++;
            grid[(n+r-1)%n][(c+1)%n] = k;
            continue;
        }
        if(grid[(n+r-1)%n][(c+1)%n] != -1){
            k++;
            grid[(r+1)%n][c] = k;
            pre = MP((r+1)%n,c);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)cout << grid[i][j] << " ";
        cout << el;
    }
}