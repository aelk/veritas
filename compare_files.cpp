#include <cmath> // for ceil
#include "compare_files.hpp"

void pr(const std::string s, const std::string pre="") {
    std::cout << pre << s << std::endl;
}

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

    // Too slow:
    /*
    for (int i = 0; i != NUM_FILES; ++i) {
        dialog->update_progress_bar(calculate_progress(i, NUM_FILES));
        std::string file1_str = file_to_str(file_names[i]);

        for (int j = i+1; j != NUM_FILES; ++j) {
            string_list words = find_words(file_to_str(file_names[j]));
            string_list seqs = get_sequences(words, DEFAULT_SEQ_LENGTH);

            for (auto seq : seqs) {
                if (contains_seq(file1_str, seq)) {
                    std::string fname1 = clean_file_name(file_names[i].c_str());
                    std::string fname2 = clean_file_name(file_names[j].c_str());
                    std::cout << "Files: " << fname1 << ", " << fname2 << std::endl;
                    std::cout << "Seq: " << seq << std::endl;
                    ++common_seqs[std::make_pair(fname1, fname2)];
                }
            }
        }
    }
    */



    std::map<std::string, bool> seq_occurred;
    // associates  sequence with file names:
    std::multimap<std::string, string_list> seq_file_name;
    string_list file_name_vec;

    /*
     * Idea:
     * -Associate each sequence with the file name where it occurs.
     * -Mark sequences which have occurred before as duplicates.
     * -If a duplicate sequence is encountered and it is
     * also in the current file, increment common_seqs.
     */

    for (int i = 0; i != NUM_FILES; ++i) {
        dialog->update_progress_bar(calculate_progress(i, NUM_FILES));

        std::string file_str = file_to_str(file_names[i]);
        string_list words = find_words(file_str);
        string_list seqs = get_sequences(words, DEFAULT_SEQ_LENGTH);

        file_str = boost::algorithm::join(words, " ");

        const std::string current_fname = clean_file_name(file_names[i].c_str());
        file_name_vec.push_back(current_fname);

        for (auto seq : seqs) {
            seq_file_name.insert(std::make_pair(seq, file_name_vec));
        }

        int iterations = 0;

        for (auto it = seq_file_name.begin(); it != seq_file_name.end(); ++it) {
            ++iterations;
            if (seq_occurred[it->first] && contains_seq(file_str, it->first)) {
                for (auto other_fname : it->second) {
                    if (current_fname != other_fname) {
                        ++common_seqs[std::make_pair(current_fname, other_fname)];
                    }
                }
            }
            seq_occurred[it->first] = true;
        }

        std::cout << "Iterations: " << iterations << std::endl;

        /*
        for (auto seq : seqs) {
            if (seq_occurred[seq]) {
                for (auto other_fname : seq_file_name[seq]) {
                    if (current_fname != other_fname) {
                        ++common_seqs[std::make_pair(current_fname, other_fname)];
                    }
                }
            }

            seq_occurred[seq] = true;
        }
        */
    }

    dialog->update_progress_bar(100);

    for (auto it = common_seqs.begin(); it != common_seqs.end(); ++it) {
        std::cout << "Files: " << (it->first).first << ", " << (it->first).second;
        std::cout << std::endl << "Number of common phrases: " << it->second << std::endl;
        std::cout << std::endl;
    }
}
