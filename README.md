# Leetcode
solved leetcode problems

**1**.
[Two Sum](https://leetcode.com/problems/two-sum/)

**2**.
[Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

**3**.
[Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

**4**.
[Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
[Explanation](https://leetcode.com/problems/linked-list-cycle/solution/)

**5**.
[Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
[Explanation](https://leetcode.com/problems/reverse-linked-list/solution)

**6**.
[Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)
[Explanation](https://leetcode.com/problems/reverse-linked-list-ii/discuss/30709/Talk-is-cheap-show-me-the-code-(and-DRAWING))<br/>
It has 3 solutions, 2 solutions are explained [here](https://leetcode.com/articles/reverse-linked-list-ii/#) and 3rd solution can be explained using a dummy variable [here](https://leetcode.com/problems/reverse-linked-list-ii/discuss/30668/C%2B%2B-simple)

**7**.
[Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
[Explanation](https://leetcode.com/articles/longest-substring-without-repeating-characters/#)

**8**.
[Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
[Explanation](https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/C%2B%2B-Iterative-Recursive-and-Morris)

**9**.
[Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
[Explanation](https://leetcode.com/articles/validate-binary-search-tree/)

**10**.
[Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
[Explanation](https://leetcode.com/articles/kth-smallest-element-in-a-bst/)<br/>

[Must Read](https://medium.com/leetcode-patterns/leetcode-pattern-0-iterative-traversals-on-trees-d373568eb0ec)


**11**.
[Next Permutation](https://leetcode.com/problems/next-permutation/)
[Explanation](https://leetcode.com/problems/next-permutation/solution/)

**12**.
[Permutations](https://leetcode.com/problems/permutations/)
[Explanation](https://leetcode.com/problems/permutations/discuss/18360/C%2B%2B-backtracking-and-nextPermutation)<br>
  * Next Permutation algorithm can also be used to find permutation of an array iteratively.
  * [**Johnson Trotter algorithm**](https://www.geeksforgeeks.org/johnson-trotter-algorithm/) can also be used to find permutation of an array iteratively.

**13**.
[Find Permutation](https://leetcode.com/problems/find-permutation/)
[Explanation](https://leetcode.com/articles/find-permutation/)

**14**.
[Permutations II](https://leetcode.com/problems/permutations-ii/)
[Explanation](https://leetcode.com/problems/permutations-ii/discuss/18669/C%2B%2B-backtracking-and-nextPermutation)

**15**.
[Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
[Explanation](https://leetcode.com/articles/remove-duplicates-from-sorted-array/#)

**16**.
[Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)
[Explanation](https://leetcode.com/articles/longest-consecutive-sequence/#)

**17**.
[Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
[Explanation](https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort)

   * **[Blum-Floyd-Pratt-Rivest-Tarjan algorithm](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/)**

    Algorithm to find kth largest element from an unsorted array in linear time.

     (1) If the number of elements in an array is large .Divide the array into arrays each with 5 elements. n/5 arrays.

     (2) Compute Median of these 5 elements. 
       This you can do by sorting each group. as there are 5 elements in Each group sorting takes 5log5. 
       For n/5 groups in total time taken is , n/5*5log5 ~ O(n)

     (3) Collect Median of all in array .

     (4) Recursively compute median of this array.

     (5) Use this Median as Pivot in QuickSelect

     Median > half of these n/5 group medians. So median > n/10 , 
     also each median in respective group is greater then half element so in total median is greater then 3n/10 element.
     So in total median is greater then 3n/10 and lesser then 3n/10 element 

     So worst case of algorithm will obey T(n) O(n)+ T(n/5)+ T(7n/10).
     Resulting in T(n) = O(n)

**18**.
[Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)
[Explanation](https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/12022/Short-and-Simple-Java-solution-(easy-to-understand))

**19**.
[Remove Element](https://leetcode.com/problems/remove-element/)<br/>
Vector can be resized if there is memory constraint using resize function.

**20**.
[Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
[Explanation](https://leetcode.com/articles/remove-nth-node-from-end-of-list/)

**21**.
[Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)
[Explanation](https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description)

**22**.
[Single Number](https://leetcode.com/problems/single-number/)
[Explanation](https://leetcode.com/articles/single-number/)


.**23**.
[Happy Number](https://leetcode.com/problems/happy-number/)
[Exlanation 1](https://leetcode.com/problems/happy-number/discuss/57092/4-C%2B%2B-Solutions-with-Explanations)
[Exlanation 2](https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-))

**24**.
[Add Digits](https://leetcode.com/problems/add-digits/)
[Explanation](https://leetcode.com/problems/add-digits/discuss/68580/Accepted-C%2B%2B-O(1)-time-O(1)-space-1-Line-Solution-with-Detail-Explanations)

**25**.
[Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
[Explanation](https://leetcode.com/problems/maximum-subarray/discuss/20452/C%2B%2B-DP-and-Divide-and-Conquer)

**26**.
[Move Zeroes](https://leetcode.com/problems/move-zeroes/)
[Explanation](https://leetcode.com/problems/move-zeroes/solution/)

**27**.
[First Missing Positive](https://leetcode.com/problems/first-missing-positive/)
[Explanation](https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c%2B%2B-solution-O(1)-space-and-O(n)-time)

**28**.
[Merge Intervals](https://leetcode.com/problems/merge-intervals/)
[Explanation](https://leetcode.com/articles/merge-intervals/)

**29**.
[Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) 
[Explanation](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/48499/4ms-simple-C%2B%2B-code-with-explanation)

**30**.
[Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)
[Explanation](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/48883/C%2B%2B-binary-%2B-linear-search)

**31**.
[Power of Four](https://leetcode.com/problems/power-of-four/)
[Explanation](https://leetcode.com/problems/power-of-four/discuss/772428/C%2B%2B-Four-Solution-or-Explain-or-Naive-or-One-Liner-orBit-Manipulation)

**32**.
[XOR operation in an Array](https://leetcode.com/problems/xor-operation-in-an-array/)

**33**.
[Multiply Strings](https://leetcode.com/problems/multiply-strings/)
[Explanation](https://leetcode.com/problems/multiply-strings/discuss/17646/Brief-C++-solution-using-only-strings-and-without-reversal/158637)

**34**.
[Plus One](https://leetcode.com/problems/add-two-numbers/)

**35**.
[Add Strings](https://leetcode.com/problems/add-strings/)
[Explanation](https://leetcode.com/problems/add-strings/discuss/90453/C%2B%2B_Accepted_13ms)

**36**.
[Add Binary](https://leetcode.com/problems/add-binary/)

**37**.
[Sort List](https://leetcode.com/problems/sort-list/submissions/)
[Explanation](https://leetcode.com/problems/sort-list/solution/)

**38**.
[Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)
[Explanation](https://leetcode.com/problems/middle-of-the-linked-list/solution)

**39**
[Reorder List](https://leetcode.com/problems/reorder-list/)
[Explanation 1](https://leetcode.com/problems/reorder-list/discuss/44992/Java-solution-with-3-steps)
[Explanation 2](https://leetcode.com/problems/reorder-list/discuss/45003/A-concise-O(n)-time-O(1)-in-place-solution)

**40**
[Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)
[Explanation](https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation)

**41**
[Missing Number](https://leetcode.com/problems/missing-number/)
[Explanation](https://leetcode.com/problems/missing-number/solution/)

**42**
[Single NUmber II](https://leetcode.com/problems/single-number-ii/)
[Explanation 1](https://stackoverflow.com/a/59867358/7283174)
[Explanation 2](https://leetcode.com/problems/single-number-ii/discuss/43294/Challenge-me-thx/176039)
[Explanation 3](https://leetcode.com/problems/single-number-ii/discuss/43294/Challenge-me-thx/42094)

**43**
[Single Number III](https://leetcode.com/problems/single-number-iii/)
[Explanation 1](https://leetcode.com/problems/single-number-iii/discuss/68901/Sharing-explanation-of-the-solution/263808)
[Explanation 2](https://leetcode.com/problems/single-number-iii/discuss/68901/Sharing-explanation-of-the-solution/70763)

**44**
[Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)
[Explanation](https://leetcode.com/problems/find-the-duplicate-number/solution/)

**45**
[Find the Difference](https://leetcode.com/problems/find-the-difference/)

**46**
[Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/)

**47**
[Rotate Image](https://leetcode.com/problems/rotate-image/)
[Explanation 1](https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image)
[Explanation 2](https://stackoverflow.com/a/35438327/7283174)

**48**
[Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/)

**49**
[Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/)

**50**
[Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

**51**
[Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
[O(n2) Explanation](https://medium.com/@bhprtk/longest-palindromic-substring-a8190fab03ff)
 * This question can be solved in O(n) time using [Manachar's Algorithm](https://leetcode.com/problems/longest-palindromic-substring/discuss/872849/manachers-algorithm-with-explanation-on-solution-in-c)

**52**
[Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
[Explanation](https://leetcode.com/problems/fibonacci-number/solution/)

**53**
[Ugly Number](https://leetcode.com/problems/ugly-number/)
   
**54**
[Ugly Number II](https://leetcode.com/problems/ugly-number-ii/)
[Explanation](https://www.geeksforgeeks.org/ugly-numbers/)

**55**
[ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)
[Explanation](https://leetcode.com/problems/zigzag-conversion/discuss/872940/Very-Simple-C%2B%2B-solution-with-explanation)

**56**
[Reverse Integer](https://leetcode.com/problems/reverse-integer/)
[Explanation](https://leetcode.com/problems/reverse-integer/discuss/873093/C%2B%2B-solution-beatss-100-with-explanation)

**57**
[String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)
[Explanation](https://leetcode.com/problems/string-to-integer-atoi/solution/)

**58**
[Palindrome Number](https://leetcode.com/problems/palindrome-number/)
[Explanation](https://leetcode.com/problems/palindrome-number/solution/)

**58**
[Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)
[Recursive and Easy DP solution](https://leetcode.com/problems/regular-expression-matching/discuss/5665/My-concise-recursive-and-DP-solutions-with-full-explanation-in-C%2B%2B)
   * [Concise solution with space optimization](https://leetcode.com/problems/regular-expression-matching/discuss/5684/C%2B%2B-O(n)-space-DP)
      * Solution can be optimized to use O(n) space.
      
**59**
[Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)

**60**
[Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
[Expalantion](https://leetcode.com/problems/container-with-most-water/solution/)
[Better Explanation](https://leetcode.com/problems/container-with-most-water/discuss/6100/Simple-and-clear-proofexplanation)
   * The widest container (using first and last line) is a good candidate, because of its width. Its water level is the height of the smaller one of first and last line.
   * All other containers are less wide and thus would need a higher water level in order to hold more water.
   * The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.

**61**
[Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)
[Explanation](https://leetcode.com/problems/trapping-rain-water/solution/)
   * **Brute force**
     * For each element in the array, we find the maximum level of water it can trap after the rain, which is equal to the minimum of maximum height of bars on both the sides minus its own height.

**62**
[Roman to Integer](https://leetcode.com/problems/roman-to-integer/)
[Explanation](https://leetcode.com/problems/roman-to-integer/discuss/886101/very-easy-solution-with-explanation-with-one-loop)

**63**
[Integer to Roman](https://leetcode.com/problems/integer-to-roman/)

**64**
[Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)
[Explanation](https://leetcode.com/problems/longest-common-prefix/solution/)
[Efficient solution and also using Trie Data structure](https://leetcode.com/problems/longest-common-prefix/discuss/561757/C%2B%2B-Memory-and-Runtime-Efficient-greater-2-Solutions%3A-1-Greedy-1-Trie-Implementation)

**65**
[3 Sum](https://leetcode.com/problems/3sum/)

**66**
[3Sum Closest](https://leetcode.com/problems/3sum-closest/)
[Explanation](https://leetcode.com/problems/3sum-closest/solution/)

**67**
[Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
[Explanation](https://leetcode.com/problems/letter-combinations-of-a-phone-number/solution/)
[BFS Explanation](https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/900295/Iterative-C%2B%2B-solution-using-queue-%3A-BFS-with-explanation)
