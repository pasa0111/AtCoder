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


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define rerep(i,s,e,k) for(int i = s; i >= e; i-=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int x;
    cin >> x;
    vector<int> A;
    while(x > 0){
        A.push_back(x%10);
        x /= 10;
    }
    int ans = 0, s = A.size();
    sort(vecall(A));
    for(int i = 0; i < s; i++){
        if(A.at(i) != 0){
            ans += A.at(i);
            A.at(i) = -1;
            break;
        }
    }
    rep(i,s){
        if(A.at(i) != -1){
            ans *= 10;
            ans += A.at(i);
        }
    }
    cout << ans << endl;
}