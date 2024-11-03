// Method 2: Optimal Soln 
// TC: O(N) SC:O(1)
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();
        if(sentence[0]!=sentence[n-1]){
            return false;
        }
        for(int i=0; i<n; i++){
            if(sentence[i]==' '){ // use single quotes 
                if(sentence[i-1]!=sentence[i+1]) return false;
            }
            else{
                continue;
            }
        }
        return true;
    }
};

// Method 1: Brute Force
// See img for TC SC analysis
class Solution{
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0]!=sentence[(sentence.size())-1]){
            return false;
        }
        vector<string> words;
        stringstream  ss(sentence);
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        int n=words.size();
        for(int i=0; i<n; i++){
            char lastChar=words[i].back();
            char firstChar=words[(i+1)%n].front();
            if(lastChar!=firstChar) return false;
        }
        return true;
    }
};


