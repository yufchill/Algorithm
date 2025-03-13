#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<int> prefix(n + 1);
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + arr[i - 1];
  }
  int a, b;
  while (cin >> a >> b) {
    cout << prefix[b + 1] - prefix[a] << endl;
  }
}