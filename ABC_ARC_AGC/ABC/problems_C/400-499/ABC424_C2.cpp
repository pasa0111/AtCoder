#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <deque>
using namespace std;

int main(){
        int N, a, b;
        cin >> N;
        vector<stack<int>> acquire(N+1); //スキルiを獲得するとacquire.at(i)に保存されている番号のスキルも獲得できる
        set<int> learned;
        deque<int> learning;
        stack<int> x;
        for(int i = 1; i <= N; i++){
            cin >> a >> b;
            if(a == 0 && b == 0){
                learned.insert(i);
                learning.push_front(i);
            }

            else if(a == b){
                acquire.at(a).push(i);
            }

            else{
                acquire.at(a).push(i);
                acquire.at(b).push(i);
            }
        }

        while(learning.empty() == false){
            x = acquire.at(learning.front());
            while(x.empty() == false){
                if(learned.count(x.top()) == false){
                    learned.insert(x.top());
                    learning.push_back(x.top());
                }
                x.pop();
            }
            learning.pop_front();
        }

        cout << learned.size() << endl;
}