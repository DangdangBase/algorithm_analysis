#include <vector>
using namespace std;

void bucket_sort(vector<__int128>& arr, __int128 exp, __int128 bucket_size) {
  vector<vector<__int128>> bucket(bucket_size);

  for (__int128 cur : arr) {
    __int128 cur_digit = (cur / exp) % bucket_size;
    bucket[cur_digit].push_back(cur);
  }

  int start = 0;
  for (vector<__int128> cur_arr : bucket) {
    for (int i = 0; i < cur_arr.size(); i++) {
      arr[start + i] = cur_arr[i];
    }

    start += cur_arr.size();
  }
}

vector<__int128> radix_sort(vector<__int128> arr, int r) {
  __int128 max_val = *max_element(arr.begin(), arr.end());
  __int128 bucket_size = 2 << r;

  for (__int128 exp = 1; max_val / exp > 0; exp <<= r) {
    bucket_sort(arr, exp, bucket_size);
  }

  return arr;
}