// Method 1: Brute Force
// TC: O(n*m)
// SC: O(1)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int count=0;
        for(int i=0; i<n; i++){
            bool isPrefix=true;
            for(int j=0; j<pref.size(); j++){ // m is pref.size()
                // check if characters match and avoid out of bound error 
                if(words[i][j]!=pref[j] || j>words[i].size()){
                    isPrefix=false;
                    break;
                }
            }
            if(isPrefix==true){
                count++;
            }
        }
        return count;
    }
};

// Method 2: Better solution 
// TC: O(m*n)
// SC: O(1)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int m=pref.size();
        int count=0;
        for(int i=0; i<n; i++){ // O(n)
            // if(words[i].substr(0,m)==pref){ // O(m)
            //     count++;
            // }
            // if (words[i].starts_with(pref)) { // Method 2 in C++ 20 
            //     count++;
            // }
            if (words[i].find(pref) == 0) {  // Method 3 Check if 'pref' is found at position 0 (prefix match)
            count++;                 
            }
        }
        return count;
    }
};


// Method 3: Using Trie 
// TC: O(n*m+p)
// SC: O(n*m)
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


