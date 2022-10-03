#include <vector>
using namespace std;

vector<__int128> counting_sort_10(vector<__int128> arr, __int128 exp) {
  vector<vector<__int128>> counting_arr(10);
  vector<__int128> sorted_arr;

  for (__int128 cur : arr) {
    __int128 cur_digit = (cur / exp) % 10;
    counting_arr[cur_digit].push_back(cur);
  }

  for (int i = 0; i < 10; i++) {
    sorted_arr.insert(sorted_arr.end(), counting_arr[i].begin(),
                      counting_arr[i].end());
  }

  return sorted_arr;
}

vector<__int128> radix_sort(vector<__int128> arr) {
  __int128 max_val = *max_element(arr.begin(), arr.end());
  vector<__int128> sorted_arr = arr;

  for (__int128 exp = 1; max_val / exp > 0; exp *= 10)
    sorted_arr = counting_sort_10(sorted_arr, exp);

  return sorted_arr;
}