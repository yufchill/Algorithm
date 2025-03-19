#include <ctype.h>

#include <iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (isdigit(s[i])) {
      cnt++;
    }
  }
  s.resize(n + 5 * cnt);
  int char_index = n - 1;
  n = s.size();
  int real_index = n - 1;
  while (real_index >= 0) {
    if (isdigit(s[char_index])) {
      s[real_index--] = 'r';
      s[real_index--] = 'e';
      s[real_index--] = 'b';
      s[real_index--] = 'm';
      s[real_index--] = 'u';
      s[real_index--] = 'n';
      char_index--;
    } else {
      s[real_index--] = s[char_index--];
    }
  }
  cout << s << endl;
}