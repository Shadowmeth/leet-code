#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::unordered_multimap;

void uppify(string &s, string &t) {
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
    }

    for (size_t i = 0; i < t.length(); i++) {
        if (t[i] >= 'a' && t[i] <= 'z')
            t[i] -= 32;
    }
}

bool found_all_chars(const unordered_multimap<char, int> &found_chars) {
    for (auto i = found_chars.begin(); i != found_chars.end(); i++) {
        if (i->second == 0) {
            return false;
        }
    }
    return true;
}

void reset_all_chars(unordered_multimap<char, int> &found_chars) {
    for (auto i = found_chars.begin(); i != found_chars.end(); i++) {
        i->second = 0;
    }
}

string min_window(const string &s, const string &t) {
    string min_window_substr = "";
    unordered_multimap<char, int> found_chars;

    for (auto c : t) {
        found_chars.insert(pair<char, int>(c, 0));
    }

    size_t window_size = std::numeric_limits<size_t>::max();

    size_t window_start, window_end;
    window_start = window_end = 0;

    for (; window_end < s.length(); window_end++) {
        char c = s[window_end];
        auto i = found_chars.find(c);
        if (i != found_chars.end())
            i->second++;

        while (found_all_chars(found_chars)) {
            char char_to_remove = s[window_start];
            // see if removing this char still keeps the window valid
            auto i = found_chars.find(char_to_remove);
            if (i == found_chars.end()) {
                // not part of t
                window_start++;
            } else {
                // part of t
                if (i->second > 1) {
                    window_start++;
                    i->second--;
                } else {
                    size_t new_win_size = window_end - window_start + 1;
                    if (new_win_size < window_size) {
                        window_size       = new_win_size;
                        min_window_substr = s.substr(window_start, window_size);
                    }
                    // we found a new minimum substring
                    window_start = window_end + 1;
                    reset_all_chars(found_chars);
                    break;
                }
            }
        }
    }

    return min_window_substr;
}

int main(int argc, char *argv[]) {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    uppify(s, t);
    cout << min_window(s, t) << endl;

    return 0;
}
