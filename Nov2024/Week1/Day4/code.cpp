#include <string>

class Solution {
public:
    std::string compressedString(std::string word) {
        std::string comp; // Initialize the compressed string result
        int n = word.size();
        int i = 0;

        while (i < n) {
            char currentChar = word[i];
            int count = 0;

            // Count the maximum length prefix with the same character up to 9 times
            while (i < n && word[i] == currentChar && count < 9) {
                count++;
                i++;
            }

            // Append the count followed by the character to the result
            comp += std::to_string(count) + currentChar;
        }

        return comp;
    }
};
