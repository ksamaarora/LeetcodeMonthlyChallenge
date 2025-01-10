**LeetCode Problem 916: Word Subsets (Medium)**

You are given two string arrays, `words1` and `words2`.

A string `b` is considered a **subset** of string `a` if every letter in `b` occurs in `a` with at least the same frequency, including multiplicity.

- For example, `"wrr"` is a subset of `"warrior"` but not a subset of `"world"`.

A string `a` from `words1` is called **universal** if **every** string `b` in `words2` is a subset of `a`.

### Task:
Return an array of all universal strings in `words1`. The answer can be returned in any order.

---

### **Example 1:**
```plaintext
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
```

### **Example 2:**
```plaintext
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
```

---

### **Constraints:**
- `1 <= words1.length, words2.length <= 10^4`
- `1 <= words1[i].length, words2[i].length <= 10`
- `words1[i]` and `words2[i]` consist only of lowercase English letters.
- All strings in `words1` are unique.

---