#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> arr(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  vector<vector<int>> prefix(m + 1, vector<int>(n + 1));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                     prefix[i - 1][j - 1] + arr[i - 1][j - 1];
    }
  }
  int total_cnt = prefix[m][n];
  int ans = INT_MAX;
  // row
  for (int i = 1; i < m; i++) {
    int top_cnt = prefix[i][n];
    ans = min(ans, abs(total_cnt - top_cnt - top_cnt));
  }
  // Column
  for (int i = 1; i < n; i++) {
    int left_cnt = prefix[m][i];
    ans = min(ans, abs(total_cnt - left_cnt - left_cnt));
  }
  cout << ans << endl;
}
