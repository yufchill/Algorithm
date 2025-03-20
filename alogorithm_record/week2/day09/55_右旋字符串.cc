#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  reverse(s.begin(), s.end());
  reverse(s.begin(), s.begin() + n);
  reverse(s.begin() + n, s.end());
  cout << s << endl;
}