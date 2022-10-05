#include <vector>
#include "utils.h"
using namespace std;

vector<__int128> insertion_sort(vector<__int128> arr) {
  for (int i = 1; i < arr.size(); i++) {
    __int128 cur = arr[i];

    int j = i - 1;
    while (j >= 0 && !compare(arr[j], cur)) {
      swap(arr[j + 1], arr[j]);
      j--;
    }
  }

  return arr;
}
