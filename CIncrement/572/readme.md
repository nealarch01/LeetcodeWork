## Subtree of another tree

https://leetcode.com/problems/subtree-of-another-tree/

## How it works:

- The "match" function traverses the entire "root" tree and check if the value of the first node of the subroot tree's matches the current node of the "root" tree currently being traversed

- If it matches, then check the entire subtree (call checkFullTree) to do a "side-by-side" traversal and comparison of the values of each node
- If it does not match, then return false and try to find the next node in the "root" tree whose value is that to the root node of the "subroot" tree