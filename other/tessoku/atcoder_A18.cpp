#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//X:見つけたい値
//N:検索するベクトルの要素数
//c:検索するベクトル
//c.at(i).first == X かつc.at(i).second == "x" を満たすiを返す
//見つからなかったら-1を返す
//さらに c.at(i).second = "o"　にする
int Search(int X, int N, vector<pair<int, string>> &c){
  cout << "search";
  int start, end, t, T;
  t = -100;
  start = 0;
  end = N-1;
  for(int i = 0; i < N+1; i++){
    T = t;
    t = (start + end) / 2;
    if(T == t){
      cout << " T == t. return:" << -1 << endl;
        return -1;
    }
    if(c.at(t).first > X){
      end = t-1;
      //cout << " end:" << end << endl;
      continue;
    }
    if(c.at(t).first < X){
      start = t+1;
      //cout << " start:" << start << endl;
      continue;
    }
    if(c.at(t).first == X){
      cout << "==X!!" << endl;
        if(c.at(t).second == "x"){
          cout << "x" << endl;
            c.at(t).second = "o";
            cout << " return1:" << t << endl;
            return t;
        }

        if(c.at(t).second == "o"){
          cout << "o" << endl;
            int u = t;
            for(int j = 0; j < N; j++){
            if(c.at(u).first == X){
                if(c.at(u).second == "x"){
                    c.at(u).second = "o";
                    cout << " return2:" << u << endl;
                    return u;
                }
                u--;
                if(u < 0){
                  break;
                }
            }
            }
            u = t;
            for(int j = 0; j < N; j++){
            if(c.at(u).first == X){
                if(c.at(u).second == "x"){
                    c.at(u).second = "o";
                    cout << " return3:" << u << endl;
                    return u;
                }
                u++;
                if(u >= N){
                  break;
                }
            }
            }
        }
        continue;
    }
  }
    cout << " return4:" << -1 << endl;
    return -1;
}


//X == ΣA + A(t)の時、ΣAの値を返す
//存在しなかったら-1を返す
int CardSum(int X, int N, int K, vector<pair<int, string>> &c, vector<pair<int, string>> &C){
  cout << "cardsum:" << X << endl;

    for(int j = K; j < X; j++){
      cout << "j+1:" << j+1 << endl;

        if(Search(X-j-1, N, c) != -1){
          cout << "sum exist."  << " return:" << j+1 << endl;
          C = c;
          return j+1;
        }

        c = C;

    }

    return -1;
}

int main(){
    int N, S, max, x = 0;
    bool ans = false;
    cin >> N >> S;
    vector<int> A(N);
    vector<pair<int, string>> card_origin(N);
    vector<pair<int, string>> card(N);
    vector<pair<int, string>> card_copy(N);
    stack<tuple<int, int, vector<pair<int, string>>>> U; //(部分和,その時のt, ベクトル)

    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());

    for(int i = 0; i < N; i++){
         x += A.at(i);
         if(x <= S){
            max = i+1;
         }
    }
    cout << "max:" << max << endl;
    cout << "sort" << endl;

    for(int i = 0; i < N; i++){
        card_origin.at(i) = make_pair(A.at(i), "x");
    }

    int k = 0;
    //q枚のカードを選ぶ
    for(int q = 1; q <= max; q++){
        k = card.at(0).first-1;
      cout << "q:" << q << endl;
        card = card_origin;
        card_copy = card_origin;
        int u = S; //uはSの部分和
        for(int t = q; t > 0; t--){ //u = ΣA(1~t-1) + A(t);
            U.push(make_tuple(u,t, card));
          cout << " t:" << t << " u:" << u << endl;
          
            if(t == 1){
                if(Search(u, N, card) != -1){
                    cout << "Yes" << endl;
                    q = max;
                    ans = true;
                    break;
                }
            }
            
            if(t > 1){
              if(u != -1){
              u = CardSum(u, N, k, card, card_copy);
              k = card.at(0).first;
              cout << "u:" << u << endl;
              }
              if(u == -1){
                u = get<0>(U.top());
                t = get<1>(U.top());
                card = get<2>(U.top());
                card_copy = get<2>(U.top());
                k = u+1;
                cout << "back u:" << u << endl;
              }
            }
        }
    cout << endl;
    }
    if(ans == false){
        cout << "No" << endl;
    }
}