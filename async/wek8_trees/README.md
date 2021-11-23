# Week 8: Trees
- [Home](/README.md#cps-500-programming-and-data-structures)
- [8.1 Trees](#81-Trees)
- [8.2 Tree Traversals](#82-Tree-Traversals)

## 8.1 Trees
[top](#Week-8-Trees)

### Introduciton to Trees
- Similar to a list, a tree is based on a node.
- Tree nodes have:
  - Value: int, double, objets, and so on
  - Pointers to their children
- Tree edges point from parents to children
- A binary tree is a tree in which every node has at most **two** children

### Binary Tree
```C
typedef struct treeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

typedef struct tree{
    TreeNode *root;
} Tree;
```
- we use let and right to differentiate two children in a binary tree.

### Tree Constraints
- All trees must adhere to:
  1. Having a single root
  2. Being connected (path from root to all other nodes)
  3. No cycles (loops)
  4. Each node having a **single** parent

### Tree Terms
- **Leaf node**: a node with no children
- **Sub tree**: any node in a tree is the root of a valid tree if removed from the larger tree (a subset)
- **Path**: a sequence of connected nodes in a tree
- **Height of a tree**: the height of a tree is the longest path between the root and a leaf node
- **level**: a root node is on level 1; all other nodes have level measured by the number of edges between it and the root node.

## 8.2 Tree Traversals
[top](#Week-8-Trees)

### Tree Traversals
- The ordering a tree imposes is somewhat subjective.
- A list or an array has a well-defined ordering.
- How can we impose a strict ordering on trees?
  - 
- How can we visit all of the nodes in a disciplined way?
  - 

### Depth-First Search
```C
void inOrder (TreeNode* node){
    if(node==NULL) return;
    inOrder(node->left);
    visit(node);
    inOrder(node->right);
}
```
- Visit(node) can be complex, or simple as printf, depending on the problem domain
- might have:
```C
void inOrderTree(Tree* tree){
    inOrder(tree->root);
}
```

### Three Traversal Techniques
1. **In-order**: left, node, right
2. **Pre-order**: node, left, right
3. **Post-order**: left, right, node
```C
void preOrder (TreeNode* node){
    if(node==NULL) return;
    visit(node);
    inOrder(node->left);
    inOrder(node->right);
}
```

```C
void postOrder (TreeNode* node){
    if(node==NULL) return;
    inOrder(node->left);
    inOrder(node->right);
    visit(node);
}
```

### Runtime?
- each node is visited once: N times
- work done by each non-recursive call is O(1)
- N*O(1)=O(N)

### Breadth-First Seach
- in-order, pre-order, and post-order are all examples of **depth-first search** (DFS)
  - DFS dives into subtrees  before completing a level
  - often implemented using recursion
- **Breadth-first search** (BFS) explores a tree level by level

### BFS Algorithm
```C
void bfs(Tree* tree){
    Queue q;
    enqueue(&q,tree->root);
    while(!isEmpty(&q)){
        TreeNode *next = dequeue(&q);
        visit(next);
        if(next->left!=NULL){
            enqueue(&q, next->left);
        }
        if(next->right!=NULL){
            enqueue(&q, next->right);
        }
    }
}
```
- *queues are FIFO
### BFS Runtime
- while N times
- constant work inside while loop
- O(N) runtime

### Iterative DFS
- Simple
  - Use a stack!

### Recursive BFS
- Tricky