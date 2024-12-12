### **2558. Take Gifts From the Richest Pile**

**Difficulty**: Easy

---

### **Problem Description**
You are given an integer array `gifts`, where each element represents the number of gifts in a pile. Every second, you perform the following operation:

1. Choose the pile with the maximum number of gifts.
   - If there is more than one pile with the maximum number of gifts, choose any one of them.
2. Leave behind the **floor of the square root** of the number of gifts in that pile.
   - Take the rest of the gifts.

Return the **total number of gifts remaining** in all piles after `k` seconds.

---

### **Examples**

#### **Example 1**:
**Input**:  
```cpp
gifts = [25, 64, 9, 4, 100], k = 4
```
**Output**:  
```cpp
29
```

**Explanation**:  
- In the first second, choose the last pile (100 gifts). Leave behind \( \lfloor \sqrt{100} \rfloor = 10 \). Gifts become: `[25, 64, 9, 4, 10]`.
- In the second second, choose the second pile (64 gifts). Leave behind \( \lfloor \sqrt{64} \rfloor = 8 \). Gifts become: `[25, 8, 9, 4, 10]`.
- In the third second, choose the first pile (25 gifts). Leave behind \( \lfloor \sqrt{25} \rfloor = 5 \). Gifts become: `[5, 8, 9, 4, 10]`.
- In the fourth second, choose the last pile (10 gifts). Leave behind \( \lfloor \sqrt{10} \rfloor = 3 \). Gifts become: `[5, 8, 9, 4, 3]`.

Final sum of gifts: \( 5 + 8 + 9 + 4 + 3 = 29 \).

---

#### **Example 2**:
**Input**:  
```cpp
gifts = [1, 1, 1, 1], k = 4
```
**Output**:  
```cpp
4
```

**Explanation**:  
- No matter which pile you choose, \( \lfloor \sqrt{1} \rfloor = 1 \), so no gifts can be taken from any pile.
- The total gifts remaining are \( 1 + 1 + 1 + 1 = 4 \).

---

### **Constraints**
- \( 1 \leq \text{gifts.length} \leq 10^3 \)
- \( 1 \leq \text{gifts}[i] \leq 10^9 \)
- \( 1 \leq k \leq 10^3 \)

---