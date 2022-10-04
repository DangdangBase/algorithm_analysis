#include <vector>
using namespace std;

void sort_merge_arr(vector<__int128>& arr, int start, int end) {
  int sub_arr_size = end - start + 1;
  int mid = (start + end) / 2;

  if (sub_arr_size <= 1)
    return;

  sort_merge_arr(arr, start, mid);
  sort_merge_arr(arr, mid + 1, end);

  vector<__int128> sorted_arr;
  int arr1_size = mid - start + 1, arr2_size = sub_arr_size - arr1_size;
  int i = 0, j = 0;

  while (i + j < sub_arr_size) {
    if (i < arr1_size && j < arr2_size) {
      if (arr[start + i] < arr[mid + 1 + j]) {
        sorted_arr.push_back(arr[start + i++]);
      } else {
        sorted_arr.push_back(arr[mid + 1 + j++]);
      }
    } else {
      if (i < arr1_size) {
        sorted_arr.push_back(arr[start + i++]);
      } else {
        sorted_arr.push_back(arr[mid + 1 + j++]);
      }
    }
  }

  for (int i = 0; i < sub_arr_size; i++) {
    arr[start + i] = sorted_arr[i];
  }
}

vector<__int128> merge_sort(vector<__int128> arr) {
  sort_merge_arr(arr, 0, arr.size() - 1);

  return arr;
}
