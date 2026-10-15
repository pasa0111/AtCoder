#include <iostream>
#include <vector>
using namespace std;


int main(){
  int64_t N, K, start, end, t, x, y, ans = 0;
  cin >> N >> K;
  vector<int64_t> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }

  for(int64_t i = N-1; i > 0; i--){
    cout << "ans:" << ans << endl;
    start = 0;
    end = i;
    if((i == 1) && (A.at(1) - A.at(0) <= K)){
        ans++;
    }
    if(i != 1){
      for(int j = 0; j < N; j++){
      t = (start + end) / 2;

      if(t == 0){
        if((A.at(i) - A.at(1) <= K) && (A.at(i) - A.at(0) > K)){
          ans += i - 1;
          break;
        }
        if(A.at(i) - A.at(0) <= K){
          ans += i;
          break;
        }
      }

      else{
      x = A.at(i) - A.at(t);
      y = A.at(i) - A.at(t-1);
      cout << "i:" << i << " t:" << t << " x:" << x << " y:" << y << " start:" << start << " end:" << end << endl;
      
      if((x < K) && (y > K)){
        ans += i - t;
        break;
      }

      if(x == K){
        ans += i - t;
        break;
      }      

      if(x < K){
        end = t-1;
      }

      if(x > K){
        start = t+1;
      }

  }
}
}
}
cout << ans << endl;
}