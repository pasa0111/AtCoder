#include <iostream>
#include <vector>
using namespace std;

int64_t nt(int64_t T, int64_t M, vector<int64_t> B){
    int64_t X = 0;
    for(int i = 0; i < M; i++){
        X += T / B.at(i);
    }
    return X;
}

int main(){
  int64_t N, K, start, end, t, x, y;
  bool a = true;
  cin >> N >> K;
  start = 0;
  end = 1000000000;
  vector<int64_t> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }

  for(int i = 0; i < 50; i++){
    t = (start + end) / 2;
    x = nt(t, N, A);
    y = nt(t-1, N, A);
    cout <<  "t:" << t << " x:" << x << " y:"  << y << " start:" << start << " end:" << end << endl;

    if((x > K)){
      end = t-1;
    }

    if(x < K){
      start = t+1;
    }

    if(x == K){
        int64_t u = t;
        while(x == K){
            u--;
            x = nt(u, N, A);
            cout << u << " " << endl;
        }
      cout << u+1 << endl;
      a = false;
      break;
    }

    if((x > K) && (y < K)){
      cout << t << endl;
      a = false;
      break;
    }

  }

  if(a == true){
    for(int64_t i = start; i < end; i++){
      x = nt(i, N, A);
      y = nt(i-1, N, A);
      if((x >= K) && (y < K)){
        cout << i << endl;
        break;
      }
    }
  }

}