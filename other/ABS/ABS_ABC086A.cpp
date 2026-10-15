#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  if((a * b) % 2 == 1){cout << "Odd" << endl;}
  if((a * b) % 2 == 0){cout << "Even" << endl;}
}