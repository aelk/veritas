#include <cmath>
#include <ctime>
#include <iterator>
#include "compare_files.hpp"

/*
   TODO:
   -Settings:
     * set default_seq_len
     * only show papers with > n plagiarized phrases
     * set directory to save results
     * ability to save all these settings

   -Add a help button (maybe a question mark) that opens basic info

   -Make standalone program for Linux, Windows, and Mac OS X
 */


// source of flip_pair and flip_map:
// https://stackoverflow.com/a/5056797
template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B, template<class,class,class...> class M, class... Args>
std::multimap<B,A> flip_map(const M<A,B,Args...> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(),
                   std::inserter(dst, dst.begin()),
                   flip_pair<A,B>);
    return dst;
}

void write_results(const std::string path, std::map<string_pair, unsigned int> common_seqs)
{
    std::string filename = path + "/RESULTS-1.txt";

    int file_num = 2;
    while (boost::filesystem::exists(filename)) {
        filename = path + "/RESULTS" + "-" + std::to_string(file_num++) + ".txt";
    }

    std::ofstream file(filename);

    std::time_t t = std::time(0);
    file << "Date: " << std::asctime(std::localtime(&t));

    file << "Directory: " << path << "\n\n";

    for (auto it = common_seqs.begin(); it !=  common_seqs.end(); ++it) {
        file << "Files: " << (it->first).first << ", " << (it->first).second << "\n";
        file << "Number of common seqs: " << it->second << "\n";
        file << "\n";
    }
}

std::vector<size_t> get_common_files(const std::string file_name, std::vector<std::pair<std::string, unsigned int>> v)
{
    std::vector<size_t> results;

    std::vector<unsigned int> occurrences;

    // stackoverflow.com/questions/8443172/fastest-way-to-convert-from-vector-of-pairs-to-two-independent-vectors-in-c
    for (auto it = std::make_move_iterator(v.begin()),
         end = std::make_move_iterator(v.end()); it != end; ++it) {
        if (it->first != file_name) {
            occurrences.push_back(std::move(it->second));
        }
    }

    // stackoverflow.com/questions/12990148/get-all-positions-of-elements-in-stl-vector-that-are-greater-than-a-value
    auto it = std::find_if(std::begin(occurrences), std::end(occurrences), [](int i){return i > 0;});
    while (it != std::end(occurrences)) {
       results.emplace_back(std::distance(std::begin(occurrences), it));
       it = std::find_if(std::next(it), std::end(occurrences), [](int i){return i > 0;});
    }
    return results;
}

int calculate_progress(const int files_seen, const int total_files)
{
    return ceil(100*(static_cast<double>(files_seen)/total_files));
}

void start_comparisons(Veritas *dialog, string_list file_names, const std::string path)
{
    const int DEFAULT_SEQ_LENGTH = 6;
    const int NUM_FILES = file_names.size();

    if (NUM_FILES <= 1) {
        return;
    }

    unsigned int occurrences_threshold;
    if (NUM_FILES <= 10) {
        occurrences_threshold = 1;
    } else if (NUM_FILES <= 100) {
        occurrences_threshold = DEFAULT_SEQ_LENGTH/2;
    } else {
        occurrences_threshold = DEFAULT_SEQ_LENGTH;
    }


    /*
      BEGINNING OF NEW TECHNIQUE
      This is a new technique I came up with on Sunday, 7/19.
      -first test it extensively on (small) documents
      -if you can't get it to work, don't worry about it and just
      use the commented-out code below
    */
    /*
    std::map<std::string, std::vector<std::pair<std::string, unsigned int>>> seq_occurrences;

    for (int i = 0; i != NUM_FILES; ++i) {
        const std::string file_str = file_to_str(file_names[i]);
        string_list seqs = get_sequences(split_str(file_str), DEFAULT_SEQ_LENGTH);

        const std::string fname = clean_file_name(file_names[i]);

        for (auto seq : seqs) {
            if (seq_occurrences[seq].empty()) {
                std::vector<std::pair<std::string, unsigned int>> v;
                v.push_back(std::make_pair(fname, 1));
                seq_occurrences[seq] = v;
            } else {
                for (auto pair : seq_occurrences[seq]) {
                    if (pair.first == fname && pair.second >= 1) {
                        ++pair.second;
                    } else {
                        seq_occurrences[seq].push_back(std::make_pair(fname, 1));
                    }
                }
            }
        }
    }

    std::map<string_pair, unsigned int> num_common_seqs;

    for (int i = 0; i != NUM_FILES; ++i) {
        dialog->update_progress_bar(calculate_progress(i, NUM_FILES));

        const std::string file_str = file_to_str(file_names[i]);
        string_list seqs = get_sequences(split_str(file_str), DEFAULT_SEQ_LENGTH);

        const std::string fname = clean_file_name(file_names[i]);
        
        for (auto seq : seqs) {
            auto vec_pair = seq_occurrences[seq];
            std::vector<size_t> positions = get_common_files(fname, vec_pair);
            
            for (auto pos : positions) {
                ++num_common_seqs[std::make_pair(fname, vec_pair[pos].first)];
            }
        }
    }
    
    dialog->update_progress_bar(100);

    for (auto it = num_common_seqs.begin(); it != num_common_seqs.end(); ++it) {
        std::cout << "Files: " << (it->first).first << ", " << (it->first).second << std::endl;
        std::cout << "Number of common seqs: " << it->second << std::endl;
        std::cout << std::endl;
    }
    // END OF NEW TECHNIQUE
    */

    std::map<std::string, string_list> seq_map;

    for (int i = 0; i != NUM_FILES; ++i) {
        const std::string file_str = file_to_str(file_names[i]);
        string_list seqs = get_sequences(split_str(file_str), DEFAULT_SEQ_LENGTH);
        const std::string fname = clean_file_name(file_names[i]);

        for (auto seq : seqs) {
            if (std::find(seq_map[seq].begin(), seq_map[seq].end(), fname)
                    == seq_map[seq].end()) {
                seq_map[seq].push_back(fname);
            }
        }
    }

    std::map<string_pair, unsigned int> common_seqs;

    for (int i = 0; i != NUM_FILES; ++i) {
        dialog->update_progress_bar(calculate_progress(i, NUM_FILES));
        const std::string file_str = file_to_str(file_names[i]);
        string_list seqs = get_sequences(split_str(file_str), DEFAULT_SEQ_LENGTH);
        const std::string fname = clean_file_name(file_names[i]);

        for (auto seq : seqs) {
            for (auto fname_val : seq_map[seq]) {
                if (fname_val != fname &&
                    common_seqs.count(std::make_pair(fname_val, fname)) == 0) {
                    ++common_seqs[std::make_pair(fname, fname_val)];
                }
            }
        }
    }

    dialog->update_progress_bar(100);

    write_results(path, common_seqs);

    /*


    std::map<std::string, unsigned int> seq_occurrences;
    std::map<std::string, unsigned int> num_plagiarized_seqs;

    for (int i = 0; i != NUM_FILES; ++i) {
        const std::string file_str = file_to_str(file_names[i]);
        string_list seqs = get_sequences(split_str(file_str), DEFAULT_SEQ_LENGTH);
        
        for (auto seq : seqs) {
            ++seq_occurrences[seq];
        }
    }


    for (int i = 0; i != NUM_FILES; ++i) {
        dialog->update_progress_bar(calculate_progress(i, NUM_FILES));

        const std::string file_str = file_to_str(file_names[i]);
        string_list seqs = get_sequences(split_str(file_str), DEFAULT_SEQ_LENGTH);

        for (auto seq : seqs) {
            if (seq_occurrences[seq] > seq_file_name[seq].first) {
                const std::string fname = clean_file_name(file_names[i]);
                ++num_plagiarized_seqs[fname];
            }
        }
    }


    dialog->update_progress_bar(100);


    auto flipped_num_plagiarized_seqs = flip_map(num_plagiarized_seqs);

    // for testing:
    for (auto pair : flipped_num_plagiarized_seqs) {
        std::cout << "File name: " << pair.second << std::endl;
        std::cout << "Number of common sequences: " << pair.first << std::endl;
    }


    //write_results(path, flipped_num_plagiarized_seqs);

    */
}
