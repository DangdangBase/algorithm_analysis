#include <vector>
using namespace std;

vector<__int128> counting_sort(vector<__int128> arr) {
  vector<int> counting_arr;
  vector<__int128> sorted_arr(arr.size(), -1);

  for (__int128 cur : arr) {
    if (counting_arr.size() + 1 <= cur) {
      counting_arr.resize(cur + 1, 0);
    }

    counting_arr[cur]++;
  }

  int next_idx = 0;
  for (int i = 0; i < counting_arr.size() + 1; i++) {
    for (int j = 0; j < counting_arr[i]; j++) {
      sorted_arr[j + next_idx] = i;
    }

    next_idx += counting_arr[i];
  }

  return sorted_arr;
}