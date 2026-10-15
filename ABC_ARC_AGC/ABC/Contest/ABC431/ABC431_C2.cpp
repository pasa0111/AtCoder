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

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> H(n),B(m);
    vecin(H);
    vecin(B);
    sort(vecall(H));
    sort(vecall(B));
    int j = m-1, b = 0, h = n-1;
    bool ans = false;
    while(b < k){
        if(j == -1 || h == -1){break;}
        if(B.at(j) >= H.at(h)){
            h--;
            b++;
            j--;
            continue;
        }
        if(B.at(j) < H.at(h)){
            h--;
        }
    }
    if(b == k){ans = true;}
    yesno(ans);
}