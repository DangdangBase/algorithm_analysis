#include <vector>
#include "utils.h"
using namespace std;

vector<__int128> insertion_sort(vector<__int128> arr) {
  vector<__int128> sorted_arr;
  sorted_arr.push_back(arr[0]);

  for (int i = 1; i < arr.size(); i++) {
    __int128 cur = arr[i];
    bool inserted = false;

    for (int j = 0; j < sorted_arr.size(); j++) {
      if (compare(cur, sorted_arr[j])) {
        sorted_arr.insert(sorted_arr.begin() + j, cur);
        inserted = true;
        break;
      }
    }

    if (!inserted) {
      sorted_arr.push_back(cur);
    }
  }

  return sorted_arr;
}
