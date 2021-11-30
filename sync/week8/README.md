# Week 8 Trees
- Really good way to store data.

## Binary Tree
- each node has at most two childre
- every node has a single parent
- the tree will have a single root
- no cycles
- Connected- there is a path from any node to any other node.

### Terms
- leaf
- subtree
- path
- height of tree
- level

### Traversals
- DFS Depth First Search
  - In order traversal (DFS)
  - Pre-order traversal (DFS)
  - Post-order traversal (DFS)
- BFS Beadth First Search

- **generally binary search tree will give you in order search*

### Characteristics
- Organized by data
  - left child is always less than parent
    - everything in the left subtree is less than the parent
  - right child is always greater than parent
    - everything in the right subtree is greater than the parent
- O(log(n))
- Better for searching than moving things around

## AVL Tree
- self ballancing binary search tree
- heights of left subtree must be within 1 of right subtree

### Heaps
- min heap - parent node is awlays less than its children
- max heap - parent node is always greater than its children
- not necessarily ordered
- heaps are always complete trees

- heaps are often implemented as arrays
  - parent(i) = (i-1)/2
  - left(i)   = (2*i)+1
  - right(i)  = (2*i)+2

## HW 8

## Quiz 2
- Week 5
  - runtime analysis - no
- Week 6
  - recursion
- Week 7
  - Array, lists, stacks, queues

### Extra Red-Black Trees

### 2-4 Trees
- Do trees have dimentionality similar to arrays? Like 2d arrays, if you have mutiple pointers in a tree, is there a way to measure the dimensionality, or is that just runtime analysis.