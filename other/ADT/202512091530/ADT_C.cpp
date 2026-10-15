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
g++ path -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n,'.'));
    for(int i = 0; i <= n/2; i++){
        if(i % 2 == 0){
            for(int j = i; j < n-i; j++){
                grid[i][j] = '#';
            }
        }
            for(int k = 0; k < (i+1)/2; k++){
                grid[i][2*k] ='#';
                grid[i][n-2*k-1] = '#';
            }
    }
    if(n % 2 == 0){
        for(int i = n/2; i < n; i++){
            grid[i] = grid[n-i-1];
        }
    }
    if(n % 2 == 1){
        for(int i = n/2+1; i < n; i++){
            grid[i] = grid[n-i-1];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}