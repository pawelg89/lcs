#include "lcs_algorithms.h"
#include <vector>

namespace lcs {
/* Utility function to get max of 2 integers */
int max(int a, int b) { return (a > b) ? a : b; }

/*
 * Implementation based on
 * https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
 */
int LCS(std::string &a, std::string &b) {
  const int m = static_cast<int>(a.size());
  const int n = static_cast<int>(b.size());
  std::vector<std::vector<int>> L(m + 1, std::vector<int>(n + 1));

  /* Following steps build L[m+1][n+1] in bottom up fashion. Note
     that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        L[i][j] = 0;

      else if (a[i - 1] == b[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;

      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }

  /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
  return L[m][n];
}

}  // namespace lcs