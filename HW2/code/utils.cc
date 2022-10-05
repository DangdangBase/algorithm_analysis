#include <fstream>
#include <string>
#include <vector>
using namespace std;

long long compare_count = 0;

bool compare(__int128 a, __int128 b) {
  compare_count++;
  return a < b;
}

long long get_compare_count() {
  return compare_count;
}

__int128 str_to_bigint(string s) {
  __int128 x = 0;

  for (char ch : s) {
    x = x * 10 + ch - '0';
  }

  return x;
}

string bigint_to_str(__int128 bigint) {
  string s = "";

  while (bigint > 0) {
    s += bigint % 10 + '0';
    bigint /= 10;
  }

  reverse(s.begin(), s.end());

  return s == "" ? "0" : s;
}

void file_output(vector<__int128> sorted_arr, string file_path) {
  ofstream sorted_file;
  sorted_file.open(file_path);
  for (__int128 cur : sorted_arr) {
    sorted_file << bigint_to_str(cur) << '\n';
  }
  sorted_file.close();
}
