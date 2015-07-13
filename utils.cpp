#include "utils.hpp"

string_list find_words(const std::string file_str)
{
    string_list words;
    boost::tokenizer<> tok(file_str);
    for (auto it = tok.begin(); it != tok.end(); ++it) {
        words.push_back(static_cast<std::string>(*it));
    }
    return words;
}

const std::string file_to_str(const std::string file_name)
{
    std::ifstream file(file_name);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

bool contains_seq(const std::string file_str, const std::string seq)
{
    return (file_str.find(seq) != std::string::npos);
}

string_list get_sequences(const string_list words, const int seq_len)
{
    /*
        Given a file like this:
        "Hi everybody, my name is Andrew. How are you doing today?"
        with seq_len = 5, this commented-out code would return

        Hi everybody, my name is
        everybody, my name is Andrew
        my name is Andrew. How

        etc.

        But the code below would return
        Hi everybody, my name is
        Andrew. How are you doing?

    string_list seqs;
    std::string seq = "";
    int start = 0, end = seq_len;
    while (end < words.size() + 1) {
        for (int i = start; i < end; ++i) {
            seq += words[i] + " ";
        }
        seq.pop_back();
        seqs.push_back(seq);
        seq = "";
        ++start;
        ++end;
    }
    return seqs;
    */

    /*
     * Input: words: vector of strings
     * Output: seqs: vector of strings, each of length seq_len
     *
     * Algorithm:
     * start = 0
     * merge seq_len elements from words into a single string seq
     *      -begin at start, end at start+seq_len
     * push seq to seqs
     * start += seq_len
     */
    string_list seqs;
    std::string seq = "";
    size_t start = 0;

    while (start < words.size()) {
        for (size_t i = start; i != start+seq_len; ++i) {
            if (i < words.size()) {
                seq += words[i] + " ";
            } else {
                break;
            }
        }
        seq.pop_back();
        seqs.push_back(seq);
        start += seq_len;
        seq = "";
    }
    return seqs;
}

std::string clean_file_name(const char *file_name)
{
    return std::string(basename(const_cast<char*>(file_name)));
}
