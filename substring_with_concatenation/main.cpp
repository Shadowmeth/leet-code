#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<size_t> find_substring(const string &, const vector<string> &);
bool str_contains_words(const string &, const vector<string>);

bool str_contains_words(string &window, vector<string> words) {
    // make sure each word occurs
    // remove word from array as we find it and also shrink the window
    for (size_t i = 0; i < words.size(); i++) {
        if (window.find(words[i]) != std::string::npos) {
            string word = words[i];
            words.erase(words.begin() + i);
            size_t start_pos = window.find(word);
            window.erase(start_pos, word.length());
            i--;
        }
    }

    return words.size() == 0;
}

// assuming each word in words has same length
vector<size_t> find_substring(const string &s, const vector<string> &words) {
    vector<size_t> indicies = {};

    if (words.size() < 1) {
        return indicies;
    }

    const size_t sub_str_len = words[0].length() * words.size();

    if (s.length() < sub_str_len) {
        return indicies;
    }

    for (size_t window_start = 0; window_start <= s.length() - sub_str_len;
         window_start++) {
        string window = s.substr(window_start, sub_str_len);
        if (str_contains_words(window, words)) {
            indicies.push_back(window_start);
        }
    }

    return indicies;
}

int main() {
    const vector<string> words = {"foo", "bar"};
    const string s             = "barfoothefoobarman";
    // const vector<string> words = {"word", "good", "best", "word"};
    // const string s             = "wordgoodgoodgoodbestword";

    vector<size_t> indices;
    indices = find_substring(s, words);

    cout << "Indexes: ";
    for (size_t i = 0; i < indices.size(); i++) {
        cout << indices[i] << " ";
    }
    cout << endl;
}
