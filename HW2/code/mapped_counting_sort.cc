#include <map>
#include <vector>
using namespace std;

vector<__int128> mapped_counting_sort(vector<__int128> arr) {
  map<__int128, int> counting_map;
  vector<__int128> sorted_arr(arr.size(), -1);

  for (__int128 cur : arr) {
    counting_map[cur]++;
  }

  int next_idx = 0;
  for (auto it = counting_map.begin(); it != counting_map.end(); it++) {
    for (int i = 0; i < it->second; i++) {
      sorted_arr[i + next_idx] = it->first;
    }

    next_idx += it->second;
  }

  return sorted_arr;
}