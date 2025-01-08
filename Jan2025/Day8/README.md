### **LeetCode Problem: 3042. Count Prefix and Suffix Pairs I**

**Difficulty:** Easy  
**Topics:** Strings, Prefix, Suffix, Trie  

---

### **Problem Statement:**
You are given a **0-indexed** string array `words`.

Define a boolean function `isPrefixAndSuffix` as:  

- `isPrefixAndSuffix(str1, str2)` returns `true` if **`str1`** is both a **prefix** and a **suffix** of **`str2`**.  
- Otherwise, it returns `false`.  

**Example:**  
- `isPrefixAndSuffix("aba", "ababa") → true`  
- `isPrefixAndSuffix("abc", "abcd") → false`  

---

### **Task:**  
Return the number of index pairs **(i, j)** such that:  
- `i < j`  
- `isPrefixAndSuffix(words[i], words[j])` is **true**.  

---

### **Example 1:**
```plaintext
Input: words = ["a","aba","ababa","aa"]
Output: 4
```
**Explanation:**
- `(0,1)` → `isPrefixAndSuffix("a", "aba") = true`  
- `(0,2)` → `isPrefixAndSuffix("a", "ababa") = true`  
- `(0,3)` → `isPrefixAndSuffix("a", "aa") = true`  
- `(1,2)` → `isPrefixAndSuffix("aba", "ababa") = true`  

**Total pairs:** `4`  

---

### **Example 2:**
```plaintext
Input: words = ["pa","papa","ma","mama"]
Output: 2
```
**Explanation:**
- `(0,1)` → `isPrefixAndSuffix("pa", "papa") = true`  
- `(2,3)` → `isPrefixAndSuffix("ma", "mama") = true`  

**Total pairs:** `2`  

---

### **Example 3:**
```plaintext
Input: words = ["abab","ab"]
Output: 0
```
**Explanation:**  
No valid pairs where `isPrefixAndSuffix` is true.  

**Total pairs:** `0`  

---

### **Constraints:**
- `1 <= words.length <= 50`  
- `1 <= words[i].length <= 10`  
- `words[i]` consists only of lowercase English letters.  

---

### **Approach:**
1. **Trie Data Structure:** Efficiently checks prefixes and suffixes.  
2. **Brute Force:** Compare each pair with simple prefix and suffix checking.  

Would you like me to provide a simplified solution or a more optimized one using a Trie? 😊