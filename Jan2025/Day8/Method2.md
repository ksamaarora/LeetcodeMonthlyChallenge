### **Understanding the Code: Counting Prefix-Suffix Pairs Using Trie**

This code solves the problem of counting prefix-suffix pairs using a **Trie** data structure. Let me explain the basic concepts of a Trie before going into the code.

---

### **What is a Trie?**
A **Trie** (pronounced as "try") is a tree-like data structure used for storing strings efficiently. It is often used for tasks like:
- **Autocomplete**
- **Spell Checking**
- **Prefix Matching**

#### **Key Properties:**
1. Each node represents a character.  
2. The root node is empty and branches out for each character.  
3. A word can be stored by inserting characters level by level.  
4. Searching is efficient for prefixes since characters are stored hierarchically.

---

### **Example of a Trie:**
If you insert `"apple"` and `"app"` into a Trie, it would look like:

```
(root)
 |
 a
 |
 p
 |
 p  -> isEndOfWord (for "app")
 |
 l
 |
 e -> isEndOfWord (for "apple")
```

---

### **Breaking Down the Code:**
#### **1. Node Class (Trie Node)**
```cpp
class Node {
public:
    Node* links[26] = {};

    bool contains(char c) { return links[c - 'a'] != NULL; }
    void put(char c, Node* node) { links[c - 'a'] = node; }
    Node* next(char c) { return links[c - 'a']; }
};
```
- **`links[26]`**: Each node stores an array of 26 pointers (for lowercase English letters).  
- **`contains(char c)`**: Checks if a node for a character exists.  
- **`put(char c, Node* node)`**: Inserts a new node for a character.  
- **`next(char c)`**: Moves to the next node for the given character.

---

#### **2. Trie Class**
```cpp
class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->contains(c)) {
                node->put(c, new Node());
            }
            node = node->next(c);
        }
    }

    bool startsWith(string& prefix) {
        Node* node = root;
        for (char c : prefix) {
            if (!node->contains(c)) {
                return false;
            }
            node = node->next(c);
        }
        return true;
    }
};
```
- **`insert`**: Inserts a word by creating nodes level by level for each character.  
- **`startsWith`**: Checks if a prefix exists in the Trie by traversing level by level.  

---

#### **3. Main Function: Counting Prefix-Suffix Pairs**
```cpp
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            Trie prefixTrie, suffixTrie;

            prefixTrie.insert(words[i]);

            string revWord = words[i];
            reverse(revWord.begin(), revWord.end());
            suffixTrie.insert(revWord);

            for (int j = 0; j < i; j++) {
                if (words[j].size() > words[i].size()) continue;

                string prefixWord = words[j];
                string revPrefixWord = prefixWord;
                reverse(revPrefixWord.begin(), revPrefixWord.end());

                if (prefixTrie.startsWith(prefixWord) && 
                    suffixTrie.startsWith(revPrefixWord)) {
                    count++;
                }
            }
        }
        return count;
    }
};
```

---

### **Explanation (Step by Step):**
1. **Initialize:** Loop through each word.  
2. **Create Tries:** Initialize two tries – one for normal words and one for reversed words.  
3. **Insert Word:**  
   - Insert the word in the **prefix trie**.  
   - Insert the reversed word in the **suffix trie**.  
4. **Check Pairs:** Compare the current word with all previous words to check if the current word starts and ends with a previous word.  
5. **Count Matching Pairs:** If both conditions hold, increase the count.  
6. **Return Count:** Return the total number of valid pairs.

---

### ✅ **Example Walkthrough:**
```cpp
words = {"abc", "abcabc", "cba"}
```
- `i = 1`, `word[i] = "abcabc"`  
   - `prefixTrie.insert("abcabc")`  
   - `suffixTrie.insert("cbacba")`  

   Now checking previous words:  
   - `"abc"` → prefix match ✔, suffix match ✔ → count++  

**Final count:** 1  

---

### **Time Complexity (TC):**
- **Insertion:** Each word takes `O(m)` time to insert into the Trie, where `m` is the length of the word.  
- **Checking Prefix and Suffix:** `O(m)` for each word since we traverse each character once.  
- **Looping through all pairs:** `O(n^2 * m)` (since two loops are nested and each operation inside is `O(m)`).

### **Overall TC:**  
**`O(n^2 * m)`**, where `n` is the number of words and `m` is the maximum length of a word.  

---

### **Space Complexity (SC):**
- **Trie Storage:** Each character requires space proportional to the alphabet size (26 for lowercase English).  
- Each word could create up to `m` nodes.  
- **Overall SC:** `O(n * m)` (storing all words and their reversed versions).

---

### **Key Takeaways:**
- **Trie is useful for prefix matching.**  
- **Two Tries** were used to check both prefix and reversed suffix efficiently.  
- The complexity is quadratic due to the nested loops.

Would you like me to further simplify the code or explain other optimizations? 😊