#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>

// find all occurences of the anagrams of second string in first string
void find_all_anagrams(std::string first, std::string second) {
    size_t first_len  = first.length();
    size_t second_len = second.length();

    // invalid input, second string can never be greater than first in length,
    // would make no sense to check for anagram
    if (second_len > first_len) {
        return;
    }

    std::unordered_multiset<char> window_set;
    std::unordered_multiset<char> second_set;

    for (size_t i = 0; i < second_len; i++) {
        second_set.insert(second[i]);
    }

    size_t low, high;
    for (low = high = 0; high < first_len; high++) {
        if (window_set.size() != second_set.size()) {
            window_set.insert(first[high]);
        }
        if (window_set == second_set) {
            std::cout << "Anagram found at index: " << low + 1 << std::endl;
            window_set.clear();
            high = ++low;
        }
        if (window_set.size() == second_set.size()) {
            // not an anagram, window is shrinked
            window_set.clear();
            high = ++low;
        }
    }
}

int main() {
    std::string first  = "XYYZXZYZXXYZ";
    std::string second = "XYZ";

    find_all_anagrams(first, second);
}
