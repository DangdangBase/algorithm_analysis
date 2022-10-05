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

using namespace std;

__int128 str_to_bigint(string s) {
  __int128 x = 0;

  for (char ch : s) {
    x = x * 10 + ch - '0';
  }

  return x;
}

string bigint_to_str(__int128 bigint) {
  string s = "";

  while (bigint > 0) {
    s += bigint % 10 + '0';
    bigint /= 10;
  }

  reverse(s.begin(), s.end());

  return s == "" ? "0" : s;
}

void file_output(vector<__int128> sorted_arr, string file_path) {
  ofstream sorted_file;
  sorted_file.open(file_path);
  for (__int128 cur : sorted_arr) {
    sorted_file << bigint_to_str(cur) << '\n';
  }
  sorted_file.close();
}

string sort_name = "merge";
int problem_no = 5;

typedef vector<__int128> (*func_p)(vector<__int128> arr);
map<string, func_p> func_map;

int main(int argc, char* argv[]) {
  func_map.insert(make_pair("insertion", insertion_sort));
  func_map.insert(make_pair("merge", merge_sort));
  func_map.insert(make_pair("quick", quick_sort));
  func_map.insert(make_pair("counting", counting_sort));
  func_map.insert(make_pair("mapped_counting", mapped_counting_sort));
  func_map.insert(make_pair("radix", radix_sort));

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

  start = clock();
  sorted_arr = func_map[sort_name](arr);
  end = clock();

  cout << sort_name << ' ' << problem_no << " : " << (end - start) << endl;

  file_output(sorted_arr, output_file_name);

  return 0;
}
