#include <cmath> // for ceil
#include "compare_files.hpp"

inline int calculate_progress(const int files_seen, const int total_files)
{
    return ceil(100*(static_cast<double>(files_seen)/total_files));
}

void start_comparisons(string_list file_names, Veritas *dialog)
{
    const int DEFAULT_SEQ_LENGTH = 6; // allow the user to set this (maybe)
    const int NUM_FILES = file_names.size();

    if (NUM_FILES <= 1) {
        return;
    }

    std::map<string_pair, unsigned int> common_seqs;
    std::map<std::string, bool> seq_occurred;
    std::map<std::string, string_list> seq_file_names;

    for (int i = 0; i != NUM_FILES; ++i) {
        const std::string file_str = file_to_str(file_names[i]);
        string_list seqs = get_sequences(find_words(file_str), DEFAULT_SEQ_LENGTH);

        for (auto seq : seqs) {
            for (auto file_name : file_names) {
                if (contains_seq(file_to_str(file_name), seq)) {
                    seq_file_names[seq].push_back(file_name);
                }
            }
            seq_occurred[seq] = true;
        }
    }

    for (int i = 0; i != NUM_FILES; ++i) {
        dialog->update_progress_bar(calculate_progress(i, NUM_FILES));
        const std::string file_str = file_to_str(file_names[i]);
        string_list seqs = get_sequences(find_words(file_str), DEFAULT_SEQ_LENGTH);

        for (auto seq : seqs) {
            if (seq_occurred[seq]) {
                for (auto file_name : seq_file_names[seq]) {
                    common_seqs[std::make_pair(file_names[i], file_name)]++;
                }
            }
        }
    }


    dialog->update_progress_bar(100);

    for (auto it = common_seqs.begin(); it != common_seqs.end(); ++it) {
        std::cout << "Files: " << (it->first).first << ", " << (it->first).second;
        std::cout << std::endl << "Number of common phrases: " << it->second << std::endl;
        std::cout << std::endl;
    }
}
