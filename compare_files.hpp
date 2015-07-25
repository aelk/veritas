#ifndef COMPARE_FILES_HPP
#define COMPARE_FILES_HPP

#include "veritas_gui.hpp"

int calculate_progress(const int files_seen, const int total_files);
template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p);
template<typename A, typename B, template<class,class,class...> class M, class... Args>
std::multimap<B,A> flip_map(const M<A,B,Args...> &src);
void write_results(const std::string path, std::map<string_pair, unsigned int> common_seqs);
void start_comparisons(Veritas *dialog, string_list file_names, const std::string path);

#endif
