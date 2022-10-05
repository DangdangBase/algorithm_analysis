#ifndef __UTILS_H__
#define __UTILS_H__

#include <fstream>
#include <string>
#include <vector>
using namespace std;

__int128 str_to_bigint(string s);
string bigint_to_str(__int128 bigint);
void file_output(vector<__int128> sorted_arr, string file_path);

#endif