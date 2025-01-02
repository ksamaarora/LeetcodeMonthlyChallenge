### **2559. Count Vowel Strings in Ranges**  
**Difficulty:** Medium  

---

### **Problem Statement**
You are given a 0-indexed array of strings \( \text{words} \) and a 2D array of integers \( \text{queries} \).  
Each query \( \text{queries[i]} = [l_i, r_i] \) asks to find the number of strings present in the range \( l_i \) to \( r_i \) (both inclusive) in \( \text{words} \) that **start and end with a vowel**.

Return an array \( \text{ans} \) of size \( \text{queries.length} \), where \( \text{ans[i]} \) is the answer to the \( i^{th} \) query.

**Note:**  
The vowel letters are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

---

### **Examples**

#### Example 1:
**Input:**  
\[
\text{words} = ["aba", "bcb", "ece", "aa", "e"], \quad \text{queries} = [[0,2], [1,4], [1,1]]
\]  
**Output:**  
\[
[2, 3, 0]
\]  
**Explanation:**  
Strings that start and end with a vowel are:  
- `"aba"`, `"ece"`, `"aa"`, and `"e"`.  

Queries:  
1. For \([0, 2]\): Strings `"aba"` and `"ece"` satisfy the condition → Answer = \( 2 \).  
2. For \([1, 4]\): Strings `"ece"`, `"aa"`, and `"e"` satisfy the condition → Answer = \( 3 \).  
3. For \([1, 1]\): No strings satisfy the condition → Answer = \( 0 \).  

---

#### Example 2:
**Input:**  
\[
\text{words} = ["a", "e", "i"], \quad \text{queries} = [[0,2], [0,1], [2,2]]
\]  
**Output:**  
\[
[3, 2, 1]
\]  
**Explanation:**  
All strings satisfy the condition.  
1. For \([0, 2]\): Strings `"a"`, `"e"`, and `"i"` → Answer = \( 3 \).  
2. For \([0, 1]\): Strings `"a"` and `"e"` → Answer = \( 2 \).  
3. For \([2, 2]\): String `"i"` → Answer = \( 1 \).  

---

### **Constraints**
- \( 1 \leq \text{words.length} \leq 10^5 \)
- \( 1 \leq \text{words[i].length} \leq 40 \)
- \( \text{words[i]} \) consists only of lowercase English letters.
- \( \sum(\text{words[i].length}) \leq 3 \times 10^5 \)
- \( 1 \leq \text{queries.length} \leq 10^5 \)
- \( 0 \leq l_i \leq r_i < \text{words.length} \)

---