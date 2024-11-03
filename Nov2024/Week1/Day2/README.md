### Problem 2490: Circular Sentence

**Difficulty**: Easy

---

A *sentence* is a sequence of words separated by single spaces, with no leading or trailing spaces.

- Examples of sentences: `"Hello World"`, `"HELLO"`, `"hello world hello world"`.

Each word consists of only uppercase and lowercase English letters, and uppercase and lowercase letters are considered different.

A sentence is **circular** if:
1. The last character of each word is the same as the first character of the next word.
2. The last character of the last word is the same as the first character of the first word.

### Examples

1. **Example 1**

    - **Input**: `sentence = "leetcode exercises sound delightful"`
    - **Output**: `true`
    - **Explanation**:
      - The words in the sentence are `["leetcode", "exercises", "sound", "delightful"]`.
      - Each word’s last character matches the first character of the next word:
        - `"leetcode"` ends with `e`, which is the first character of `"exercises"`.
        - `"exercises"` ends with `s`, which is the first character of `"sound"`.
        - `"sound"` ends with `d`, which is the first character of `"delightful"`.
        - `"delightful"` ends with `l`, which is the first character of `"leetcode"`.
      - The sentence meets the circular condition.

2. **Example 2**

    - **Input**: `sentence = "eetcode"`
    - **Output**: `true`
    - **Explanation**:
      - The sentence has only one word `["eetcode"]`.
      - The last character of `"eetcode"` is `e`, which matches its first character `e`.
      - The sentence is circular.

3. **Example 3**

    - **Input**: `sentence = "Leetcode is cool"`
    - **Output**: `false`
    - **Explanation**:
      - The words in the sentence are `["Leetcode", "is", "cool"]`.
      - `"Leetcode"` ends with `e`, but `"is"` starts with `i`, which does not match.
      - The sentence does not meet the circular condition.

### Constraints

- \(1 \leq \text{sentence.length} \leq 500\)
- The sentence contains only lowercase and uppercase English letters and spaces.
- Words are separated by a single space with no leading or trailing spaces.

--- 

The time complexity (TC) and space complexity (SC) of the **Brute force approach** function can be analyzed as follows:

### Time Complexity (TC)
1. **Splitting the sentence into words**: This step involves iterating through each character of the sentence to extract words. If the length of the sentence is \( n \), this operation takes \( O(n) \) time.
2. **Checking circular conditions**: After extracting the words, you check the last character of each word against the first character of the next word in a loop that runs \( k \) times, where \( k \) is the number of words. The maximum number of words will be \( O(n) \) in the worst case (if the sentence is all single-character words), so this part also takes \( O(k) \) time.

Overall, the time complexity is:
\[ \text{TC} = O(n) + O(k) = O(n) \]
since \( k \) can be at most \( n \).

### Space Complexity (SC)
1. **Storing words**: The space required to store the words in the `vector<string> words` is proportional to the number of words extracted from the sentence. In the worst case, this could also be \( O(n) \) (again, if the sentence is made of single-character words).
2. **Additional space**: A few additional variables are used (`word`, `lastChar`, `firstChar`), but they occupy constant space, which can be considered \( O(1) \).

Overall, the space complexity is:
\[ \text{SC} = O(k) \]
In the worst case, \( k \) can be \( O(n) \), so:
\[ \text{SC} = O(n) \]

### Summary
- **Time Complexity**: \( O(n) \)
- **Space Complexity**: \( O(n) \)
