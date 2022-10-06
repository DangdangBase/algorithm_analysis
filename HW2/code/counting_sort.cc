#include <vector>
using namespace std;

vector<__int128> counting_sort(vector<__int128> arr) {
  __int128 max_val = *max_element(arr.begin(), arr.end());

  vector<int> count(max_val + 1);
  vector<__int128> sorted_arr(arr.size());

  for (__int128 cur : arr) {
    count[cur]++;
  }

  for (int i = 0; i < max_val; i++) {
    count[i + 1] += count[i];
  }

  for (int i = arr.size() - 1; i >= 0; i--) {
    sorted_arr[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  return sorted_arr;
}