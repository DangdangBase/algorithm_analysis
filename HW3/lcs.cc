#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a, b;

int main() {
  ifstream input("./Q1");
  input >> a >> b;

  int lcs[2][b.size() + 1];
  int cur;

  memset(lcs[0], 0, sizeof(lcs[0]));

  cout << a.size() << ' ' << b.size() << endl;

  for (int i = 1; i <= a.size(); i++) {
    cur = i % 2;
    lcs[cur][0] = 0;

    if (i % 100 == 0) {
      cout << i << endl;
    }

    for (int j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        lcs[cur][j] = lcs[1 - cur][j - 1] + 1;
      } else {
        lcs[cur][j] = max(lcs[1 - cur][j], lcs[cur][j - 1]);
      }
    }
  }

  cout << lcs[cur][b.size()] << endl;

  return 0;
}