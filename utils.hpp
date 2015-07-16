#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <cctype> // for isalnum
#include <libgen.h> // for basename
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/join.hpp>

typedef std::vector<std::string> string_list;
typedef std::pair<std::string, std::string> string_pair;

string_list find_words(const std::string file_str);
bool not_alnum(const char c);
const std::string file_to_str(const std::string file_name);
bool contains_seq(const std::string file_str, const std::string seq);
string_list get_sequences(const string_list words, const int seq_len);
std::string clean_file_name(const char *file_name);

#endif
