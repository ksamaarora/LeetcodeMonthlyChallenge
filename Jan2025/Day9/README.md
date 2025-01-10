### **Problem 2185: Counting Words With a Given Prefix**

**Difficulty:** Easy  
**Topics:** Strings  
**Companies:** N/A

#### **Problem Description:**
You are given an array of strings `words` and a string `pref`.

Your task is to return the number of strings in the `words` array that contain `pref` as a **prefix**.

A **prefix** of a string `s` is any leading contiguous substring of `s`.

#### **Example 1:**

**Input:**
```plaintext
words = ["pay","attention","practice","attend"]
pref = "at"
```

**Output:**
```plaintext
2
```

**Explanation:**
The two strings that contain `"at"` as a prefix are: `"attention"` and `"attend"`.

---

#### **Example 2:**

**Input:**
```plaintext
words = ["leetcode", "win", "loops", "success"]
pref = "code"
```

**Output:**
```plaintext
0
```

**Explanation:**
There are no strings in the `words` array that contain `"code"` as a prefix.

---

#### **Constraints:**
- `1 <= words.length <= 100`
- `1 <= words[i].length, pref.length <= 100`
- `words[i]` and `pref` consist of lowercase English letters.

---

#### **Solution:**
You can solve this problem by iterating over the `words` array and checking if each string starts with the given `pref` using the `find()` or `starts_with()` function.
