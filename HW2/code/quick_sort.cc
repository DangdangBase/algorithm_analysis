#include <cstdlib>
#include <vector>
using namespace std;

vector<__int128> quick_sort(vector<__int128> arr) {
  if (arr.size() == 1 || arr.size() == 0)
    return arr;

  vector<__int128> arr1, arr2, sorted_arr;
  int pivot_idx = rand() % arr.size();
  __int128 pivot = arr[pivot_idx];

  for (int i = 0; i < arr.size(); i++) {
    if (i == pivot_idx)
      continue;

    if (arr[i] < pivot) {
      arr1.push_back(arr[i]);
    } else {
      arr2.push_back(arr[i]);
    }
  }

  arr1 = quick_sort(arr1);
  arr2 = quick_sort(arr2);

  sorted_arr.insert(sorted_arr.end(), arr1.begin(), arr1.end());
  sorted_arr.push_back(pivot);
  sorted_arr.insert(sorted_arr.end(), arr2.begin(), arr2.end());

  return sorted_arr;
}