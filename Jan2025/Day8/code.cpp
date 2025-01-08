// // Method 1: Brute force
// // TC: O(n^2 * m) and SC: O(1)
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0; i<n; i++){ // O(n*n)
            for(int j=i+1; j<n; j++){
                string word1=words[i];
                string word2=words[j];
                if(word1.size()>word2.size()) continue;
                else if(word2.find(word1)==0 && word2.rfind(word1)==word2.size()-word1.size()){ // O(m) Find function 
                // word2.find(word1)==0: word1 found at start of word2
                // word2.rfind(word1)==word2.size()-word1.size(): calculates the starting index where word1 would fit as a suffix.
                    count++;
                }
            }
        }
        return count;
    }
};


// Method 2: Trie implementation
// TC: O(n^2 * m)
// SC: O(n*m)
class Node {
public:
    Node* links[26] = {};

    // Check if the character is present in the current node
    bool contains(char c) { return links[c - 'a'] != NULL; }

    // Insert a new node for the character
    void put(char c, Node* node) { links[c - 'a'] = node; }

    // Get the next node for the character
    Node* next(char c) { return links[c - 'a']; }
};

class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }

    // Insert a word into the Trie
    void insert(string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->contains(c)) {
                node->put(c, new Node());
            }
            node = node->next(c);
        }
    }

    // Check if the Trie contains a given prefix
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

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        // Step 1: Iterate over each word
        for (int i = 0; i < n; i++) {
            Trie prefixTrie, suffixTrie;

            // Step 2: Insert the current word into the prefix Trie
            prefixTrie.insert(words[i]);

            // Step 3: Reverse the word and insert it into the suffix Trie
            string revWord = words[i];
            reverse(revWord.begin(), revWord.end());
            suffixTrie.insert(revWord);

            // Step 4: Iterate over all previous words
            for (int j = 0; j < i; j++) {
                // Step 5: Skip words[j] if it is longer than words[i]
                if (words[j].size() > words[i].size()) continue;

                // Step 6: Extract the prefix and reversed prefix of words[j]
                string prefixWord = words[j];
                string revPrefixWord = prefixWord;
                reverse(revPrefixWord.begin(), revPrefixWord.end());

                // Step 7: Check if words[j] is both a prefix and suffix of
                // words[i]
                if (prefixTrie.startsWith(prefixWord) &&
                    suffixTrie.startsWith(revPrefixWord)) {
                    count++;
                }
            }
        }

        // Step 8: Return the total count of valid pairs
        return count;
    }
};