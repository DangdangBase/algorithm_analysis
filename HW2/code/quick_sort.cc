#include <cstdlib>
#include <vector>
#include "utils.h"
using namespace std;

void sort_quick_arr(vector<__int128>& arr, int start, int end) {
  int sub_arr_size = end - start + 1;

  if (sub_arr_size <= 1)
    return;

  int pivot_idx = rand() % (sub_arr_size) + start;
  int bigger_idx = start + 1;

  swap(arr[start], arr[pivot_idx]);

  for (int i = start + 1; i <= end; i++) {
    if (compare(arr[i], arr[start])) {
      swap(arr[i], arr[bigger_idx++]);
    }
  }

  sort_quick_arr(arr, start + 1, bigger_idx - 1);
  sort_quick_arr(arr, bigger_idx, end);

  for (int i = start; i < bigger_idx - 1; i++) {
    swap(arr[i], arr[i + 1]);
  }
}

vector<__int128> quick_sort(vector<__int128> arr) {
  sort_quick_arr(arr, 0, arr.size() - 1);

  return arr;
}
