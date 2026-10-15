#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


//c.at(i).first == X かつc.at(i).second == "x" を満たすiを返す
//見つからなかったら-1を返す
//さらに c.at(i).second = "o"　にする
int Search(int X, int N, vector<pair<int, string>> &c){
    cout << "Searching " << X << " ..." << endl;
  int start, end, t, T;
  t = -100;
  start = 0;
  end = N-1;
  for(int i = 0; i < N+1; i++){
    T = t;
    t = (start + end) / 2;
    if(T == t){
        cout << "T == t" << endl;
        return -1;
    }
    if(c.at(t).first > X){
      end = t-1;
      continue;
    }
    if(c.at(t).first < X){
      start = t+1;
      continue;
    }
    if(c.at(t).first == X){
        if(c.at(t).second == "x"){
            c.at(t).second = "o";
            cout << "found!" << endl;
            return t;
        }

        if(c.at(t).second == "o"){
            int u = t;
            while(c.at(u).first == X){
                if(c.at(u).second == "x"){
                    c.at(u).second = "o";
                    cout << "found!" << endl;
                    return u;
                }
                u--;
                if(u < 0){
                  break;
                }
            }
            u = t;
            while(c.at(u).first == X){
                if(c.at(u).second == "x"){
                    c.at(u).second = "o";
                    cout << "found" << endl;
                    return u;
                }
                u++;
                if(u >= N){
                  break;
                }
            }
        }
        continue;
    }
  }
  return -1;
}

//X == ΣA + A(t)の時、ΣAの値を返す
//存在しなかったら-1を返す
int CardSum(int X, int N, int J, vector<pair<int, string>> &c, vector<pair<int, string>> &C){
    for(int j = J; j <= X; j++){
        if(Search(X-j, N, c) != -1){
          C = c;
          return j;
        }
        c = C;
    }
    return -1;
}

int main(){
    int N, S, max, x = 0, J = 1;
    bool ans = false;
    cin >> N >> S;
    vector<int> A(N);
    vector<pair<int, string>> card_origin(N);
    vector<pair<int, string>> card(N);
    vector<pair<int, string>> card_copy(N);
    stack<tuple<int, int, vector<pair<int, string>>>> U;

    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());

    for(int i = 0; i < N; i++){
        card_origin.at(i) = make_pair(A.at(i), "x");
        x += A.at(i);
        if(x <= S){
            max = i+1;
        }
    }
    
  
    //q枚のカードを選ぶ
    for(int q = 1; q <= max; q++){
        card = card_origin;
        card_copy = card_origin;
        int u = S;
        for(int t = q; t > 0; t--){ //u = ΣA(1~t-1) + A(t);
          cout << "q:" << q << " t:" << t << " u:" << u << endl;
            if(t == 1){
                if(Search(u, N, card) != -1){
                    cout << "Yes" << endl;
                    q = max;
                    ans = true;
                    break;
                }
                if(U.empty() == false){
                u = get<0>(U.top());
                t = get<1>(U.top())+1;
                card = get<2>(U.top());
                J = u+1;
                U.pop();
                }
            }
            
            if(t > 1){
              if(u != -1){
                U.push(make_tuple(u, t, card));
                cout << "push (" << u << ", " << t << ", card)" << endl;
              u = CardSum(u, N, J, card, card_copy);
              J = card.at(0).first;
              cout << "u = " << u << endl;
              }

              if(u == -1){
                u = get<0>(U.top());
                t = get<1>(U.top());
                card = get<2>(U.top());
                J = u+1;
                U.pop();
                cout << "back u:" << u << " t:" << t << endl;
              }
            }
        }
        while(U.empty() == false){
            U.pop();
        }
    }

    if(ans == false){
        cout << "No" << endl;
    }

}