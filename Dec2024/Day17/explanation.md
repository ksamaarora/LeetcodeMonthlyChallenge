### 1. **Brute Force: Using `map` with Reverse Iteration**  
```cpp
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> freq;

        // Step 1: Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        string result = ""; // Final result string

        // Step 2: Use reverse iterator to go from largest to smallest character
        auto it = freq.rbegin();
        auto next_it = it;

        while (it != freq.rend()) {
            char curr_char = it->first;
            int& curr_count = it->second;
            int use_count = min(curr_count, repeatLimit);
            
            result += string(use_count, curr_char);
            curr_count -= use_count;

            if (curr_count > 0) { // Need to switch to next largest character
                next_it = it;
                next_it++;
                if (next_it == freq.rend()) break;

                result += next_it->first;
                next_it->second--;

                if (next_it->second == 0) freq.erase(next_it->first);
            } else {
                it++;
            }
        }

        return result;
    }
};
```

**Explanation**:
- Uses a `map` to count frequencies and reverse iteration (`rbegin`) to start from the largest character.
- Handles repeat limits by temporarily switching to the next largest character when required.

**Time Complexity**: \(O(n \log k)\), where \(n\) is the length of the string and \(k\) is the number of unique characters.  
   - `map` operations (insertion, iteration) are \(O(\log k)\).  
**Space Complexity**: \(O(k)\), where \(k\) is the number of unique characters.

**Brute Force** because:
- `map` incurs extra overhead with ordered storage.
- Switching between characters is managed less efficiently.

---

### 2. **Better Approach: Using `vector` for Frequencies**  
```cpp
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0); // Frequency array for characters a-z
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;
        int currentCharIndex = 25; // Start from the largest character (z)

        while (currentCharIndex >= 0) {
            if (freq[currentCharIndex] == 0) {
                currentCharIndex--;
                continue;
            }

            int use = min(freq[currentCharIndex], repeatLimit);
            result.append(use, 'a' + currentCharIndex);
            freq[currentCharIndex] -= use;

            if (freq[currentCharIndex] > 0) { // Need to switch to smaller character
                int smallerCharIndex = currentCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }

                if (smallerCharIndex < 0) break; // No smaller character left
                result.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }

        return result;
    }
};
```

**Explanation**:
- Uses a frequency vector of size 26 for counting characters efficiently.
- Iterates in reverse to start with the largest character (`z`).
- Switches to the next smallest character if the current one hits the `repeatLimit`.

**Time Complexity**: \(O(n + 26)\), where \(n\) is the string length.  
   - Building the frequency vector is \(O(n)\).  
   - Traversing the 26 possible characters is \(O(26)\).  
**Space Complexity**: \(O(26) = O(1)\) for the fixed-size frequency array.

**Better** because:
- The frequency array is faster than `map` for counting and accessing characters.
- Reduces sorting overhead from `map`.

---

### 3. **Optimal Approach: Using `priority_queue` (Max Heap)**  
```cpp
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;

        // Step 1: Count the frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Use max-heap to always get the largest available character
        priority_queue<char> maxHeap;
        for (auto& [ch, count] : freq) {
            maxHeap.push(ch);
        }

        string result;

        while (!maxHeap.empty()) {
            char ch = maxHeap.top(); maxHeap.pop();
            int count = freq[ch];

            int use = min(count, repeatLimit);
            result.append(use, ch);

            freq[ch] -= use;

            if (freq[ch] > 0 && !maxHeap.empty()) { 
                char nextCh = maxHeap.top(); maxHeap.pop();

                result.push_back(nextCh);
                freq[nextCh]--;

                if (freq[nextCh] > 0) maxHeap.push(nextCh);
                maxHeap.push(ch);
            }
        }

        return result;
    }
};
```

**Explanation**:
- Uses a **max-heap** (priority queue) to always get the largest character efficiently.
- Adds the largest character up to `repeatLimit` times.
- Temporarily switches to the next largest character to "break" the repeat limit, then reuses the current character.

**Time Complexity**: \(O(n + k \log k)\), where \(n\) is the string length and \(k\) is the number of unique characters.  
   - Building the frequency map takes \(O(n)\).  
   - Each heap operation (push/pop) is \(O(\log k)\).  
**Space Complexity**: \(O(k)\), for the frequency map and heap.

**Optimal** because:
- `priority_queue` directly handles ordering and retrieval of the largest character efficiently.
- Balances switching between characters without unnecessary overhead.

---

### Summary Table
| **Approach**       | **Time Complexity** | **Space Complexity** | **Key Method**         | **Efficiency**      |
|---------------------|---------------------|-----------------------|-------------------------|---------------------|
| Brute Force         | \(O(n \log k)\)     | \(O(k)\)              | Map + Reverse Iterator | Slowest             |
| Better              | \(O(n + 26)\)       | \(O(1)\)              | Frequency Vector       | Faster              |
| Optimal             | \(O(n + k \log k)\) | \(O(k)\)              | Priority Queue (Heap)  | Fastest & Cleanest  |

---

### Recommendation:
- Use the **Optimal Approach** with `priority_queue` for larger inputs where efficiency matters.
- The **Better Approach** with a frequency vector is simpler and faster for small inputs or constrained problems.