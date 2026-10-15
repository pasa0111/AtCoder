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

char int_char(int x){
    char res;
    if(x == 0){res = '0';}
    if(x == 1){res = '1';}
    if(x == 2){res = '2';}
    if(x == 3){res = '3';}
    if(x == 4){res = '4';}
    if(x == 5){res = '5';}
    if(x == 6){res = '6';}
    if(x == 7){res = '7';}
    if(x == 8){res = '8';}
    if(x == 9){res = '9';}
    return res;
}

int char_int(char x){
    int res = 0;
    if(x == '0'){res = 0;}
    if(x == '1'){res = 1;}
    if(x == '2'){res = 2;}
    if(x == '3'){res = 3;}
    if(x == '4'){res = 4;}
    if(x == '5'){res = 5;}
    if(x == '6'){res = 6;}
    if(x == '7'){res = 7;}
    if(x == '8'){res = 8;}
    if(x == '9'){res = 9;}
    return res;
}

int main(){
    int m;
    cin >> m;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    map<char,vector<int>> ans;
    vector<int> v = {100001,100002,100003};
    rep(i,10){ans[int_char(i)] = v;}
    rep(i,m){
    ans.at(s1.at(i)).at(0) = min(i,ans.at(s1.at(i)).at(0));
    ans.at(s2.at(i)).at(1) = min(i,ans.at(s2.at(i)).at(1));
    ans.at(s3.at(i)).at(2) = min(i,ans.at(s3.at(i)).at(2));

    if(ans.at(s1.at(i)).at(1) == ans.at(s1.at(i)).at(2) && ans.at(s1.at(i)).at(0) == ans.at(s1.at(i)).at(1)){
        ans.at(s1.at(i)).at(1) += m;
        ans.at(s1.at(i)).at(2) += 2*m;
    }
    if(ans.at(s2.at(i)).at(1) == ans.at(s2.at(i)).at(2) && ans.at(s2.at(i)).at(0) == ans.at(s2.at(i)).at(1)){
        ans.at(s2.at(i)).at(1) += m;
        ans.at(s2.at(i)).at(2) += 2*m;
    }
    if(ans.at(s3.at(i)).at(1) == ans.at(s3.at(i)).at(2) && ans.at(s3.at(i)).at(0) == ans.at(s3.at(i)).at(1)){
        ans.at(s3.at(i)).at(1) += m;
        ans.at(s3.at(i)).at(2) += 2*m;
    }

    if(ans.at(s1.at(i)).at(1) == ans.at(s1.at(i)).at(2)){ans.at(s1.at(i)).at(2) = min(ans.at(s1.at(i)).at(0),ans.at(s1.at(i)).at(1))+m;}
    if(ans.at(s1.at(i)).at(0) == ans.at(s1.at(i)).at(1)){ans.at(s1.at(i)).at(1) = min(ans.at(s1.at(i)).at(0),ans.at(s1.at(i)).at(2))+m;}
    if(ans.at(s1.at(i)).at(1) == ans.at(s1.at(i)).at(2)){ans.at(s1.at(i)).at(2) = min(ans.at(s1.at(i)).at(0),ans.at(s1.at(i)).at(1))+m;}

    if(ans.at(s2.at(i)).at(1) == ans.at(s2.at(i)).at(2)){ans.at(s2.at(i)).at(2) = min(ans.at(s2.at(i)).at(0),ans.at(s2.at(i)).at(1))+m;}
    if(ans.at(s2.at(i)).at(0) == ans.at(s2.at(i)).at(1)){ans.at(s2.at(i)).at(1) = min(ans.at(s2.at(i)).at(0),ans.at(s2.at(i)).at(2))+m;}
    if(ans.at(s2.at(i)).at(1) == ans.at(s2.at(i)).at(2)){ans.at(s2.at(i)).at(2) = min(ans.at(s2.at(i)).at(0),ans.at(s2.at(i)).at(1))+m;}

    if(ans.at(s3.at(i)).at(1) == ans.at(s3.at(i)).at(2)){ans.at(s3.at(i)).at(2) = min(ans.at(s3.at(i)).at(0),ans.at(s3.at(i)).at(1))+m;}
    if(ans.at(s3.at(i)).at(0) == ans.at(s3.at(i)).at(1)){ans.at(s3.at(i)).at(1) = min(ans.at(s3.at(i)).at(0),ans.at(s3.at(i)).at(2))+m;}
    if(ans.at(s3.at(i)).at(1) == ans.at(s3.at(i)).at(2)){ans.at(s3.at(i)).at(2) = min(ans.at(s3.at(i)).at(0),ans.at(s3.at(i)).at(1))+m;}

    }
    //cout << ans.at('8').at(0) << ans.at('8').at(1) << ans.at('8').at(2) << endl;
    int res = 1000000;
    rep(i,10){
        //cout << "i: " << i << "   res: " << res << endl;
        if(ans.at(int_char(i)).at(0) == 100001 || ans.at(int_char(i)).at(1) == 100002 || ans.at(int_char(i)).at(2) == 100003){continue;}
        res = min(res,max(max(ans.at(int_char(i)).at(0),ans.at(int_char(i)).at(1)),ans.at(int_char(i)).at(2)));
    }
    if(res == 1000000){cout << -1 << endl;}
    else{cout << res << endl;}
}