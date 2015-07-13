#ifndef COMPARE_FILES_HPP
#define COMPARE_FILES_HPP

#include <set>
#include "veritas_gui.hpp"
#include "utils.hpp"

class Duplicate
{
public:
    Duplicate() {}

private:
    std::map<std::string, std::set<std::string>> seq_file_names;
};

int calculate_progress(const int files_seen, const int total_files);
void start_comparisons(string_list file_names, Veritas *dialog);

#endif
