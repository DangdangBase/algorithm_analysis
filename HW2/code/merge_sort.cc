#include <vector>
using namespace std;

vector<__int128> merge_sort(vector<__int128> arr) {
  if (arr.size() == 1)
    return arr;

  vector<__int128> arr1, arr2, sorted_arr;
  int mid = arr.size() / 2;

  arr1 = merge_sort(vector<__int128>(arr.begin(), arr.begin() + mid));
  arr2 = merge_sort(vector<__int128>(arr.begin() + mid, arr.end()));

  int i = 0, j = 0;
  while (i < arr1.size() || j < arr2.size()) {
    __int128 push;

    if (i < arr1.size() && j < arr2.size()) {
      (arr1[i] < arr2[j]) ? push = arr1[i++] : push = arr2[j++];
    } else {
      (i < arr1.size()) ? push = arr1[i++] : push = arr2[j++];
    }

    sorted_arr.push_back(push);
  }

  return sorted_arr;
}