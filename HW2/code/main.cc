#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "counting_sort.h"
#include "insertion_sort.h"
#include "mapped_counting_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "radix_sort.h"
#include "utils.h"

using namespace std;

typedef vector<__int128> (*func_p)(vector<__int128> arr);
map<string, func_p> func_map;

int main(int argc, char* argv[]) {
  func_map.insert(make_pair("insertion", insertion_sort));
  func_map.insert(make_pair("merge", merge_sort));
  func_map.insert(make_pair("quick", quick_sort));
  func_map.insert(make_pair("counting", counting_sort));
  func_map.insert(make_pair("mapped_counting", mapped_counting_sort));

  string sort_name = argv[1], problem_no = argv[2];

  vector<__int128> arr, sorted_arr;
  string s;

  string input_file_name = "../data/Q3_" + problem_no;
  string output_file_name =
      "../result/" + sort_name + "_sort_" + problem_no + ".txt";

  ifstream input(input_file_name);

  if (input.is_open()) {
    while (input >> s) {
      arr.push_back(str_to_bigint(s));
    }
  }

  clock_t start, end;

  int radix_r = 4;
  if (sort_name == "radix" && argc == 4) {
    try {
      radix_r = stoi(argv[3]);
    } catch (const exception& expn) {
      cout << "please insert r as number!" << endl;
    }
  }

  start = clock();
  if (sort_name == "radix") {
    sorted_arr = radix_sort(arr, radix_r);
  } else {
    sorted_arr = func_map[sort_name](arr);
  }
  end = clock();

  cout << sort_name << ' ' << problem_no << " : " << (end - start) << endl;
  if (argc == 4 && string(argv[3]) == "compare") {
    cout << "compare count: " << get_compare_count() << endl;
  }

  file_output(sorted_arr, output_file_name);

  return 0;
}
