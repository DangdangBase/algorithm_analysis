#include <vector>
using namespace std;

void counting_sort_10(vector<__int128>& arr, __int128 exp) {
  vector<vector<__int128>> counting_arr(10);

  for (__int128 cur : arr) {
    __int128 cur_digit = (cur / exp) % 10;
    counting_arr[cur_digit].push_back(cur);
  }

  int start = 0;
  for (vector<__int128> cur_arr : counting_arr) {
    for (int i = 0; i < cur_arr.size(); i++) {
      arr[start + i] = cur_arr[i];
    }

    start += cur_arr.size();
  }
}

vector<__int128> radix_sort(vector<__int128> arr) {
  __int128 max_val = *max_element(arr.begin(), arr.end());

  for (__int128 exp = 1; max_val / exp > 0; exp *= 10)
    counting_sort_10(arr, exp);

  return arr;
}