#include "utils.hpp"

const std::string get_filename(const std::string path)
{
    std::string filename = path + "/" + RESULT_FILE_NAME + "-1.txt";

    int file_num = 2;
    while (boost::filesystem::exists(filename)) {
        filename = path + "/" + RESULT_FILE_NAME + "-" + std::to_string(file_num++) + ".txt";
    }
    return filename;
}

string_list split_str(const std::string file_str)
{
    string_list words;
    boost::tokenizer<> tok(file_str);
    for (auto it = tok.begin(); it != tok.end(); ++it) {
        words.push_back(static_cast<std::string>(*it));
    }
    return words;
}

bool not_alnum(const char c)
{
    // predicate used in file_to_str function
    // keeps spaces and alphanumeric characters; removes everything else
    if (isspace(c)) {
        return false;
    } else {
        return !std::isalnum(c);
    }
}

const std::string file_to_str(const std::string file_name)
{
    std::ifstream file(file_name);
    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string file_str = buffer.str();
    // remove all non-alphanumeric characters from file_str:
    file_str.erase(std::remove_if(file_str.begin(), file_str.end(),
        not_alnum), file_str.end());

    return file_str;
}

string_list get_sequences(const string_list words, const int seq_len)
{
    string_list seqs;
    std::string seq = "";
    size_t start = 0, end = seq_len;
    while (end < words.size() + 1) {
        for (size_t i = start; i < end; ++i) {
            seq += words[i] + " ";
        }
        seq.pop_back();
        seqs.push_back(seq);
        seq = "";
        ++start;
        ++end;
    }
    return seqs;
}

const std::string clean_file_name(const std::string file_name)
{
    boost::filesystem::path p(file_name);
    return p.filename().string();
}
