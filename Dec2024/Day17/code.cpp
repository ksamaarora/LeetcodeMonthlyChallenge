// see explanation.md
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;
        int currentCharIndex = 25;  // Start from the largest character
        while (currentCharIndex >= 0) {
            if (freq[currentCharIndex] == 0) {
                currentCharIndex--;
                continue;
            }

            int use = min(freq[currentCharIndex], repeatLimit);
            result.append(use, 'a' + currentCharIndex);
            freq[currentCharIndex] -= use;

            if (freq[currentCharIndex] >
                0) {  // Need to add a smaller character
                int smallerCharIndex = currentCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }
                if (smallerCharIndex < 0) {
                    break;
                }
                result.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }

        return result;
    }
};


class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> freq;

        // Step 1: Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        string result = ""; // To store the final answer

        // Step 2: Use a reverse iterator to go from largest to smallest character
        auto it = freq.rbegin(); // Points to the largest character
        auto next_it = it;       // To switch to the next largest character when needed

        while (it != freq.rend()) {
            char curr_char = it->first;     // Current character (largest available)
            int& curr_count = it->second;   // Frequency of the current character
            int use_count = min(curr_count, repeatLimit); // Add up to repeatLimit times

            // Step 3: Add the current character to the result
            result += string(use_count, curr_char);
            curr_count -= use_count;

            // Step 4: Check if we hit the repeat limit
            if (curr_count > 0) { 
                // Find the next largest character
                next_it = it;
                next_it++;
                if (next_it == freq.rend()) {
                    // No other characters left; stop
                    break;
                }

                // Add one instance of the next largest character to "break" the repeat limit
                result += next_it->first;
                next_it->second--; // Reduce its count

                // If the next character's count becomes zero, skip it
                if (next_it->second == 0) {
                    freq.erase(next_it->first);
                }
            } else {
                // If the current character is exhausted, move to the next largest
                it++;
            }
        }

        return result;
    }
};


class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<char> maxHeap;
        for (auto& [ch, count] : freq) {
            maxHeap.push(ch);
        }

        string result;

        while (!maxHeap.empty()) {
            char ch = maxHeap.top();
            maxHeap.pop();
            int count = freq[ch];

            int use = min(count, repeatLimit);
            result.append(use, ch);

            freq[ch] -= use;

            if (freq[ch] > 0 && !maxHeap.empty()) {
                char nextCh = maxHeap.top();
                maxHeap.pop();

                result.push_back(nextCh);
                freq[nextCh]--;

                if (freq[nextCh] > 0) {
                    maxHeap.push(nextCh);
                }

                maxHeap.push(ch);
            }
        }

        return result;
    }
};