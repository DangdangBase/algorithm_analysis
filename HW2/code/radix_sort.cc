#include <vector>
using namespace std;

void arged_counting_sort(vector<__int128>& arr, __int128 exp, __int128 key) {
  __int128 sorted_arr[arr.size()];
  vector<int> count(key, 0);

  for (__int128 cur : arr) {
    count[(cur / exp) % key]++;
  }

  for (int i = 1; i < key; i++) {
    count[i] += count[i - 1];
  }

  for (int i = arr.size() - 1; i >= 0; i--) {
    sorted_arr[count[(arr[i] / exp) % key] - 1] = arr[i];
    count[(arr[i] / exp) % key]--;
  }

  for (int i = 0; i < arr.size(); i++) {
    arr[i] = sorted_arr[i];
  }
}

vector<__int128> radix_sort(vector<__int128> arr, int r) {
  __int128 max_val = *max_element(arr.begin(), arr.end());
  __int128 key = 1 << r;

  for (__int128 exp = 1; max_val / exp > 0; exp <<= r) {
    arged_counting_sort(arr, exp, key);
  }

  return arr;
}