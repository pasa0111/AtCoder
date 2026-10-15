#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

void solve(int n, int k, int x, vector<string> s, string &ans){
  if(x == 1){
    for(int i = 0; i < k; i++){
        ans += s.at(0);
    }
    return;
  }
  
  if(x >= 2){
    int t = 1, u = 0;
    while(t+1 > x || x > t*n){
      t *= n;
      u++;
    }
    for(int i = 0; i < k-u-1; i++){
      ans += s.at(0);
    }
    int y = x / t;
    int z = x % t;
    if(z == 0){
      ans += s.at(y-1);
      for(int i=0; i<u; i++){
        ans += s.at(n-1);
      }
      return;
    }
    if(z > 0){
      ans += s.at(y);
      solve(n,u,z,s,ans);
      return;
    }
  }
}

int main(){
  int N,K,X;
  string ans = "";
  cin >> N >> K >> X;
  vector<string> S(N);
  for(int i = 0; i < N; i++){
    cin >> S.at(i);
  }
  sort(S.begin(), S.end());
  solve(N,K,X,S,ans);
  cout << ans << endl;
}