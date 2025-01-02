### **1422. Maximum Score After Splitting a String**  
**Difficulty:** Easy  
**Topics:** Strings, Greedy Algorithm  

---

### **Problem Statement**
You are given a binary string \( s \), consisting of characters `'0'` and `'1'`. You need to split this string into two **non-empty** substrings:
- The **left substring** contains the first \( i \) characters of \( s \).
- The **right substring** contains the remaining \( s.length - i \) characters.

The **score** of the split is defined as:
\[
\text{Score} = (\text{Number of '0's in the left substring}) + (\text{Number of '1's in the right substring}).
\]

Your task is to find the **maximum score** among all possible splits of the string.

---

### **Examples**

#### Example 1:
**Input:**  
\[
s = "011101"
\]  
**Output:**  
\[
5
\]  
**Explanation:**  
All possible splits are:
- Left = `"0"`, Right = `"11101"`, Score = \( 1 + 4 = 5 \).
- Left = `"01"`, Right = `"1101"`, Score = \( 1 + 3 = 4 \).
- Left = `"011"`, Right = `"101"`, Score = \( 1 + 2 = 3 \).
- Left = `"0111"`, Right = `"01"`, Score = \( 1 + 1 = 2 \).
- Left = `"01110"`, Right = `"1"`, Score = \( 2 + 1 = 3 \).

The maximum score is \( 5 \).

---

#### Example 2:
**Input:**  
\[
s = "00111"
\]  
**Output:**  
\[
5
\]  
**Explanation:**  
The split with the maximum score is:
- Left = `"00"`, Right = `"111"`, Score = \( 2 + 3 = 5 \).

---

#### Example 3:
**Input:**  
\[
s = "1111"
\]  
**Output:**  
\[
3
\]  
**Explanation:**  
The split with the maximum score is:
- Left = `"1"`, Right = `"111"`, Score = \( 0 + 3 = 3 \).

---

### **Constraints**
- \( 2 \leq s.length \leq 500 \)
- The string \( s \) consists of only `'0'` and `'1'`.

---