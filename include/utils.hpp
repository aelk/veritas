#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <boost/tokenizer.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/join.hpp>

const std::string RESULT_FILE_NAME = "VERITAS_RESULTS";

typedef std::vector<std::string> string_list;
typedef std::pair<std::string, std::string> string_pair;

const std::string get_filename(const std::string path);
string_list split_str(const std::string file_str);
bool not_alnum(const char c);
const std::string file_to_str(const std::string file_name);
string_list get_sequences(const string_list words, const int seq_len);
const std::string clean_file_name(const std::string file_name);

#endif
