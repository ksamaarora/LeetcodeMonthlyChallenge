The expression:

```cpp
if(words[i].substr(0, pref.size()) == pref)
```

### **Explanation:**
This line checks if the word `words[i]` **starts with** the string `pref`. Here's how it works step by step:

---

### **Key Components:**
1. **`words[i]`:**  
   - Refers to the current word in the list.  
   - Example: If `words = {"apple", "banana", "apricot"}`, `words[0]` is `"apple"`.  

2. **`.substr(0, pref.size())`:**  
   - `.substr(start_index, length)` extracts a substring from the string.  
   - `start_index = 0` means the substring starts from the **first character**.  
   - `length = pref.size()` extracts characters up to the length of `pref`.  

   **Example:**  
   - If `words[i] = "apple"` and `pref = "app"`,  
   - `words[i].substr(0, 3)` → `"app"`.  

3. **`== pref`:**  
   - Compares the extracted substring with the prefix `pref`.  
   - If the substring matches the prefix, the condition is true.  

---

### Method 3 Optimal Solution Explanation - TRIES

### **Explanation of the Code:**

This code implements a **Trie (prefix tree)** data structure to efficiently store and count words with a given prefix.

#### **What is a Trie?**
- A **Trie** is a tree-like data structure that stores strings in a way that allows for fast retrieval of words and prefixes. It is especially useful for problems involving string matching or prefix searches.
- In a Trie, each node represents a character in the string, and paths from the root to the leaf nodes represent words. If two words share a common prefix, they will share the same path up to the point where the words differ.

Let's break down the code in detail.

---

### **Classes and Their Roles:**

1. **Main Solution Class:**
   - The `Solution` class is where the main logic resides. It has the function `prefixCount` which takes in a list of words and a prefix. It uses a `Trie` to store the words and then counts how many words start with the given prefix.

2. **Trie Class:**
   - The `Trie` class is the core part of this solution. It handles the insertion of words and counting how many words start with a given prefix.
   
   **Key Functions in `Trie`:**
   - `addWord`: Adds a word to the Trie.
   - `countPrefix`: Counts how many words start with a given prefix.

3. **Node Class:**
   - The `Node` class represents each node in the Trie.
   - Each node contains:
     - `links`: An array of size 26 (for each lowercase English letter), where each element points to a child node. For example, `links[0]` will point to the child node representing `'a'`.
     - `count`: Tracks how many words pass through this node (or how many words share this prefix).

---

### **Step-by-Step Breakdown:**

#### 1. **Trie Node Initialization:**
```cpp
struct Node {
    vector<Node*> links; // 26 possible links, one for each letter
    int count; // tracks how many words pass through this node
    Node() : links(26, nullptr), count(0) {}
};
```
- Each node has a vector `links` of size 26 (corresponding to the 26 lowercase English letters). Initially, the `links` are set to `nullptr`.
- The `count` keeps track of how many words share the prefix that ends at this node.

#### 2. **Trie Constructor:**
```cpp
Trie() {
    root = new Node();  // Initialize root node
}
```
- The `Trie` constructor initializes the `root` node.

#### 3. **Inserting Words into the Trie (`addWord`):**
```cpp
void addWord(string& word) {
    Node* curr = root;  // Start at the root node
    for (char c : word) {
        // Convert the character to an index (e.g., 'a' -> 0, 'b' -> 1, etc.)
        if (curr->links[c - 'a'] == nullptr) {
            curr->links[c - 'a'] = new Node();  // Create a new node if it doesn't exist
        }
        curr = curr->links[c - 'a'];  // Move to the next node
        curr->count++;  // Increment the count for the current node
    }
}
```
- For each word, we iterate through its characters:
  - For each character, we calculate its index (`c - 'a'`).
  - If the corresponding child node does not exist, we create a new node for that character.
  - We move to the child node and increment the `count` at that node. This keeps track of how many words share that prefix up to that point.

#### 4. **Counting Words with a Given Prefix (`countPrefix`):**
```cpp
int countPrefix(string& pref) {
    Node* curr = root;  // Start at the root node
    for (char c : pref) {
        // Convert the character to an index (e.g., 'a' -> 0, 'b' -> 1, etc.)
        if (curr->links[c - 'a'] == nullptr) {
            return 0;  // If no node exists for the current character in the prefix
        }
        curr = curr->links[c - 'a'];  // Move to the next node
    }
    return curr->count;  // Return the count at the last node of the prefix
}
```
- For the given prefix, we iterate through each character:
  - We check if the node corresponding to the current character exists in the Trie.
  - If any character in the prefix does not have a corresponding node, the prefix does not exist in the Trie, and we return `0`.
  - Otherwise, we continue traversing the Trie, and once we reach the last node of the prefix, we return the `count` stored in that node. This `count` represents the number of words in the Trie that share the given prefix.

---

### **Main Logic in the Solution Class:**
```cpp
int prefixCount(vector<string>& words, string pref) {
    Trie trie;
    // Add all words to the trie
    for (string& word : words) {
        trie.addWord(word);
    }
    // Count how many words have the prefix 'pref'
    return trie.countPrefix(pref);
}
```
- We initialize a `Trie` object.
- Then we add each word from the `words` list to the Trie using the `addWord` function.
- Finally, we call `countPrefix` to get the number of words that share the given prefix and return the result.

---

### **Time Complexity:**
- **Inserting a Word (`addWord`)**: Each word is processed character by character, and for each character, we perform a constant-time operation (either moving to the next node or creating a new one). The time complexity to insert a word is **O(m)**, where `m` is the length of the word.
- **Counting Prefix (`countPrefix`)**: To count the words with a given prefix, we again process each character of the prefix, which takes **O(p)** time, where `p` is the length of the prefix.
- **Total Time Complexity**: If there are `n` words and each word has a maximum length of `m`, the total time complexity for the insertions is **O(n * m)**. Counting the prefix takes **O(p)** time. Thus, the overall time complexity is **O(n * m + p)**.

### **Space Complexity:**
- The space complexity is primarily determined by the Trie structure. Since we store nodes for each character in each word, the space complexity is **O(n * m)** in the worst case (if all words are distinct and do not share common prefixes).

---

```c++
// Method 3: Using Trie 
// TC:
// SC:
#include<vector>
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;
        // add all words to trie
        for(string& word: words){
            trie.addWord(word);
        }
        return trie.countPrefix(pref);
    }

private:
    class Trie{
        // node class represents each character in Trie;
        struct Node{
            // Links to child nodes
            vector<Node*> links;
            int count;
            Node():links(26,nullptr), count(0) {}
        };
        Node* root;

    public:
        Trie() {root=new Node(); }
        void addWord(string& word){
            Node* curr=root;
            for(char c:word){
                if(curr->links[c-'a']==nullptr){
                    curr->links[c-'a']=new Node();
                }
                curr=curr->links[c-'a'];
                curr->count++;
            }
        }

        // Return count of strings having pref as prefix
        int countPrefix(string& pref) {
            Node* curr = root;
            for (char c : pref) {
                if (curr->links[c - 'a'] == nullptr) {
                    return 0;  // Prefix not found
                }
                curr = curr->links[c - 'a'];
            }
            return curr->count;  // Return count at last node
        }
    };
};
```