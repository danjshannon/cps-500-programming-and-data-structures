# Week 8: Trees
- [Home](/README.md#cps-500-programming-and-data-structures)
- [8.1 Trees](#81-Trees)
- [8.2 Tree Traversals](#82-Tree-Traversals)
- [8.3 Binary Search Trees](#83-Binary-Search-Trees)
- [8.4 Self-Balancing Binary Tree](#84-Self-Balancing-Binary-Tree)
- [8.5 Heaps](#85-Heaps)

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

## 8.3 Binary Search Trees
[top](#week-8-trees)

- A binary search tree is a binary tree where for all nodes:
  - All values stored in the left **subtree** are less than or equal to the value stored in the parent.
  - All values stored in the right **subtree** are greater than or equal to the value stored in the parent.
- The smallest element is always the leftmost node in the tree.
- The largest element is always the rightmost node in the tree.

```C
// Returns true (1) if value is found beneath
// this node. returns false(0) otherwise
int search(TreeNode* node, int value){
    if(node==NULL){
        return 0;
    } else if(node->data<value){
        return search(node->right,value);
    } else{ 
        return search(node-left,value);
    }
}
```
- log(N) runtime
  - unballanced (linked list) O(N) runtime

## BST Insertion
- same algo as search, but insert when NULL
```C
int insert(TreeNode* node, int value){
    if(node == NULL || node->data == value){
        return 0;
    }
    else if(node->data > value){
        if(node->left==NULL){
            node->left = makeNode(value);
            return 1;
        }
        return insert(node->left,value);
    }else{
        if(node->right==NULL){
            node->right = makeNode(value);
            return 1;
        }
        return insert(node->right, value);
    }
}
```

### Runtime Analysis
- Worst Case?
  - **Degenerated** to a list - O(N)
- Best Case?
  - **Balanced** perfectly - O(log(N))

### Balanced Binary Tree
- Generally a **balanced** tree has a minimum height for the given number of nodes in the tree.

## BST Deletion
### Deletion
- Must maintain the BST constraint
- There are three scenarios based on the number of children of the node to be deleted.
  1. No children
  2. One child
  3. Two children

### Case 1: No Children
- Simply remove the node.

### Case 2: One Child
- Remove the node and replace it with its one child.

### Case 3: Two Children
1. Call the node to delete *x*. Find the next highest node *y*
2. If *y* has no children, replace *x*'s data with *y*'s and delete *y*
3. If *y* has a child, *w* it **must be a right child**. Replace *x*'s data with *y*'s and then replace *y* with *w*
  - (Why? Because this was the next highest node after x.)
### Deletion Algorithm
```C
void removeNode(int value, TreeNode* node, TreeNode* parent) {
    if (node->left != NULL && node->right != NULL) {
        TreeNode* min = minNode(node->right);
        node->value = min->value;
        remove(min->key, node-<right, node);
    } else if (parent->left == node) {
        parent->left = (node->left != NULL) ? node->left : node->right;
    } else if (parent->right == node) {
        parent->right = (node->left != NULL) ? node->left : node->right;
    }
}
```

## 8.4 Self-Balancing Binary Tree
[top](#week-8-trees)

### Self-Balancing Trees
- Searching a BST takes O(log(N)) on average, but due to degenerative cases, can take O(N) in the worst-case scenario.
  - Can we improve this by avoiding degenerative cases through more complex udpate operations?
- We saw in heaps that inserting or removing a node became more complex, aas we required it to always be a complete binary tree.

### AVL Trees
- AVL Trees are BSTs that relax this requirement with the following conditions:
  - For every node, the height of its left and right subtrees differ by at most 1.
  - This ensures that the depth of the tree with n nodes is O(log(N))
  - a depth of O(log(n)) ensures that search takes only O(log(N))
- Can we design insert and delete to adhere to this property and only take O(log(N))?

### Reassert the Constraint
- how do we fix the tree to meet the AVL constraint?
- There are four scenarios for the bottommost unbalanced node **S**:
  1. The extra node is in the left child of the left child of S.
  2. The extra node is in the right child of the left child of S.
  3. The extra node is in the left child of the right child of S.
  4. The extra node is in the right child of the right child of S.
- We can fix it by doing tree rotations.

### Single Tree Rotations
- For case 1 (LL) and case 4 (RR), we do a single tree rotation.
- A,B,C are sub trees.
```
            s
    x               C
A       B
```
rotation...
```
            x
    A               s
                B       C
```
```
s->left=x->right;
x->right=s;
```
### Double Tree Rotations
- For case 2 (LR) and case 3 (RL), we need to do a double rotation
- Here we have case 3 (case 2 is symmetric to this)
```
            s
    x           c
A       y
    z
```
rotation...
```
            s
        y       c
    x
A       z
```
rotation...
```
            y
        x       s
    A       z       c
```

### Other self-balancing trees
- Splay tree
- red-black tree
- 2-3 trees
- AA trees


## 8.5 Heaps
[top](#week-8-trees)

### Binary Heap
- **min heap**: a parent node's key is always less than its children
- **max heap**: a parent node's key is always greater than its children
- There is no relationship between nodes on the same level

### Complete Binary Tree
- A binary tree in which every level, except the lsat, is completely filled
- The last level is filled in from the left

### Heap Implementation
- Heaps are often implemented using arrays
- Any complete binary tree can be represented this way.

- Parent(i) = (i-1)/2
- Left(i) = 2*i+1
- Right(i) = 2*i+2
**constant time lookup**

### Building a Binary Heap
### Heapification
- Inserting a node into a heapp is log(N)
- To build a heap of N nodes would then take N insertions: N log(N)
- It turns out that we can build a heap in linear time

### Heapify Algorithm
```C
void buildHeap(int arr[], int n){
  for(int i=(n-1)/2; i>=0; i--){ //(n-1)/2 is the deepest parent node
    heapify(arr,n,2);
  }
}

void maxHeapify(int arr[], int n, int i) {
  int largest=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left < n && arr[left] > arr[largest]) { // if left is larger than root
    largest = left;
  }
  if(right < n && arr[right] > arr[largest]) { // if right is larger than largest
    largest = right;
  }
  if(largest != i){ // if largest is not root
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest); // Recursively heapify the sub-tree
  }
}
```

### Runtime?
- The nodes in the second to last layer (7 and 6) could be swapped at most once
- The nodes in the lest layer above  (9 and 8) could be swapped at most twice
- The top node (10) could be swapped at most three times

- Each height, h in a binary heaps has n/2<sup>h+1</sup> nodes.
- A node at height h can do at most level h swaps.
- There are log(N) many heights, so we get the summation:

> &sum;<sub>h=0</sub><sup>log(N)</sup>[n/2<sup>h+1</sup> \* O(h)]\
> n\*&sum;<sub>h=0</sub><sup>log(N)</sup>[h/2h]\
> n*(1/2 + 2/4 + 3/8 + 4/16 + ... +)=\
> n*2=O(N)