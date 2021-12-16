# Algorithms and Data-Structures
- [Home](/README.md#cps-500-programming-and-data-structures)
- [Sorting](#Sorting)
  - [Bubble Sort](#Bubble-Sort)
  - [Insertion Sort](#Insertion-Sort)
  - [Selection Sort](#Selection-Sort)
  - [Merge Sort](#Merge-Sort)
  - [Quick Sort](#Quick-Sort)
- [Searching](#Searching)
  - [Binary Search](#Binary-search)
- [Linked List](#Linked-List)
  - [Add Head](#add-head)
  - [Reverse Linked-List](#reverse-linked-list)
  - [Traverse Linked-List](#traverse-linked-list)
- [Queue](#queue)
- [Stack](#stack)
- [Binary Tree](#Binary-Tree)
  - [Depth-First Search](#depth-first-search)
    - [In-Order](#in-order)
    - [Pre-Order](#pre-order)
    - [Post-Order](#post-order)
  - [Breadth-First Search](#Breadth-first-search)
- [Binary Search Tree](#binary-search-tree)
  - [Search](#bst-search)
  - [Insertion](#bst-insertion)
  - [Deletion](#bst-deletion)
- [Heaps](#heaps)
  - [Heapify](#heapify)
  - [Heap Insert](#heap-insert)
- [Hash Tables](#hash-tables)
  - [Chained Hash Table](#chained-hash-table)
    - [Insertion](#chained-hash-table-insertion)
  - [Probed Hash Table](#probed-hash-table)
    - [Insertion](#probed-hash-table-insertion)
  - [Pair Sum Problem](#pair-sum-problem)
- [Graphs](#graphs)
  - [Adjacency List](#adjacency-list)
  - [Depth-First Search](#depth-first-search-graph)
  - [Breadth-First Search](#breadth-first-search-graph)
  - [Dijkstra's Algorithm](#dijkstras-algorithm)



## Sorting
[top](#Algorithms-and-Data-Structures)

### Bubble Sort
[top](#Algorithms-and-Data-Structures)
```C
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp1 = arr[j];
                int temp2 = arr[j + 1];
                arr[j] = temp2;
                arr[j + 1] = temp1;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}
```

### Insertion Sort
[top](#Algorithms-and-Data-Structures)
```C
void insertionSort(int *a, int N)
{
    for (int i = 1; i < N; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
```

### Selection Sort
[top](#Algorithms-and-Data-Structures)
```C
void selectionSort(int *a, int N)
{
    int minJ, minVal;
    for (int i = 0; i < N - 1; i++)
    {
        minJ = i;
        minVal = a[i];
        for (int j = i + 1; j <= N - 1; j++)
        {
            if (a[j] < minVal)
            {
                minJ = j;
                minVal = a[j];
            }
        }
        //swap the values of a[i] and a[minJ]
        a[minJ] = a[i];
        a[i] = minVal;
    }
}
```

### Merge Sort
[top](#Algorithms-and-Data-Structures)
```C
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        margeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

void merge(int array[], int left, int middle, int right)
{
    int temp[right - left];
    int i = left;
    int j = middle;
    int index = 0;
    while (i < middle && j < right)
    {
        if (array[i] < array[j])
        {
            temp[index] = array[i];
            i++;
        }
        else
        {
            temp[index] = array[j];
            j++;
        }
        index++;
    }
    while (i < middle)
    {
        temp[index] = array[i];
        i++;
        index++;
    }
    while (j < right)
    {
        temp[index] = array[j];
        j++;
        index++;
    }
    for (int k = 0; k < right - left; k++)
    {
        array[left + k] = temp[k];
    }
}
```

### Quick Sort
[top](#Algorithms-and-Data-Structures)
```C
void quickSort(int array[], int low, int high){
    if(low<high){
        int p = partition(array,low,high);
        quickSort(array,low,p-1);
        quickSort(array,p+1,high);
    }
}
int partition(int array[], int low, int high){
    int pivot = array[high];
    int i= low-1;
    for(int j=low;j<high;j++){
        if(array[j]<=pivot){
            i++;
            swap(array, i, j);
        }
    }
    swap(array,i+i,high);
    return i+1;
}
```

## Searching
[top](#Algorithms-and-Data-Structures)
### Binary Search
[top](#Algorithms-and-Data-Structures)
```C
int binarySearch(int *array, int value, int lo, int hi)
{
    if (lo > hi)
    {
        return -1;
    }
    int middle = lo + (hi - lo) / 2;
    if (array[middle] == value)
    {
        return middle;
    }
    else if (array[middle] < value)
    {
        return binarySearch(array, value, middle + 1, hi);
    }
    else
    {
        return binarySearch(array, value, lo, middle - 1);
    }
}
```

## Linked List
[top](#Algorithms-and-data-structures)
```C
typedef struct listNode
{
    int data;
    struct listNode *next;
} ListNode;

typedef struct list
{
    ListNode *head;
    ListNode *tail; //optional!
} List;

typedef struct doublyListNode
{
    int data;
    struct doublyListNode *next;
    struct doublyListNode *prev;
} DoublyListNode;
```
### Add Head
[top](#algorithms-and-data-structures)
```C
void addHead(List *list, int value)
{
    //Create a new node to hold value.
    ListNode *node = malloc(sizeof(ListNode));
    //Assign the data to the value
    node->data = value;
    //Assign the next element to what head points to.
    node->next = list->head; // whatever list->head points to, point node->next to the same thing
    //assign the head of the list to the node
    list->head = node;
}
```
### RemoveNode
[top](#algorithms-and-data-structures)
```C
void removeNode(ListNode *node)
{
    ListNode *next = node->next;
    node->next = next->next;
    free(next);
}
```
### Reverse Linked-List
[top](#algorithms-and-data-structures)
```C
void reverse(List *list)
{
    if (list->head == NULL)
        return;
    ListNode *prev = NULL;
    ListNode *ptr = list;
    while (ptr != NULL)
    {
        ListNode *tmp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = tmp;
    }
    list->head = prev;
}
```
### Traverse Linked-List
[top](#algorithms-and-data-structures)
```C
void traverse(List *list)
{
    ListNode *current = list->head; //this is a POINTER to a list node, not a new ListNode
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
```

## Queue
[top](#algorithms-and-data-structures)
```C
typedef struct queue
{
    ListNode *head;
    ListNode *tail;
} Queue;

void enqueue(Queue *queue, int value)
{

    //Create a new node to hold value.
    ListNode *node = malloc(sizeof(ListNode));
    //Assign the data to the value
    node->data = value;
    if (queue->head == NULL)
    {
        queue->head = node;
        queue->tail = node;
    }
    else
    {
        queue->tail->next = node; // point tail to node pointer
        queue->tail = node;       // point tail to node (which points to NULL)
    }
}

// just like list listPop - from the head
int dequeue(Queue *queue)
{
    if (queue->head != NULL)
    {
        ListNode *head = queue->head;
        ListNode *next = head->next;
        queue->head = next;
        int data = head->data;
        //free(head);
        return data;
    }
}
```
## Stack
[top](#algorithms-and-data-structures)
```C
typedef struct stack
{
    ListNode *head;
} Stack;

void push(Stack *stack, int value)
{
    //Create a new node to hold value.
    ListNode *node = malloc(sizeof(ListNode));
    //Assign the data to the value
    node->data = value;
    //Assign the next element to the head.
    node->next = stack->head; // whatever list->head points to, point node->next to the same thing
    //assign the head of the list to the node
    stack->head = node;
}

int pop(Stack *stack)
{
    if (stack->head != NULL)
    {
        ListNode *head = stack->head;
        ListNode *next = head->next;
        stack->head = next;
        int data = head->data;
        return data;
    }
}
```

## Binary Tree
[top](#algorithms-and-data-structures)
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

### Depth-First Search
[top](#algorithms-and-data-structures)
### In-Order
[top](#algorithms-and-data-structures)
```C
void inOrder (TreeNode* node){
    if(node==NULL) return;
    inOrder(node->left);
    visit(node);
    inOrder(node->right);
}
```

### Pre-Order
[top](#algorithms-and-data-structures)
```C
void preOrder (TreeNode* node){
    if(node==NULL) return;
    visit(node);
    preOrder(node->left);
    preOrder(node->right);
}
```

### Post-Order
[top](#algorithms-and-data-structures)
```C
void postOrder (TreeNode* node){
    if(node==NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    visit(node);
}
```

### Breadth-First Search
[top](#algorithms-and-data-structures)
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

## Binary Search Tree
[top](#algorithms-and-data-structures)
### BST Search
[top](#algorithms-and-data-structures)
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
### BST Insertion
[top](#algorithms-and-data-structures)
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
### BST Deletion
[top](#algorithms-and-data-structures)
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

## Heaps
[top](#algorithms-and-data-structures)
### Heapify
[top](#algorithms-and-data-structures)
```C
void buildHeap(int arr[], int n){
  for(int i=(n-1)/2; i>=0; i--){ //(n-1)/2 is the deepest parent node
    heapify(arr,n,i);
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
    maxHeapify(arr, n, largest); // Recursively heapify the sub-tree
  }
}

void minHeapify(int arr[], int n, int i) {
  int smallest=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left < n && arr[left] < arr[smallest]) { // if left is less than root
    smallest = left;
  }
  if(right < n && arr[right] < arr[smallest]) { // if right is less than smallest
    smallest = right;
  }
  if(smallest != i){ // if smallest is not root
    swap(arr[i], arr[smallest]);
    minHeapify(arr, n, smallest); // Recursively heapify the sub-tree
  }
}
```
### Heap Insert
[top](#algorithms-and-data-structures)
```C
void minHeapInsert(int arr[], int n, int x) {
  arr[n] = x;
  int p = (n-1)/2;
  while (n > 0 && arr[p] > arr[n]){// this operator determines min vs max heap
    swap(&arr[p], &arr[n]);
    n = p;
    p = (n - 1)/2
  }
}

void maxHeapInsert(int arr[], int n, int x) {
  arr[n] = x;
  int p = (n-1)/2;
  while (n > 0 && arr[p] < arr[n]){// this operator determines min vs max heap
    swap(&arr[p], &arr[n]);
    n = p;
    p = (n - 1)/2
  }
}
```

## Hash Tables
### Chained Hash Table
[top](#algorithms-and-data-structures)
```C
struct HashNode{
    int key;
    int value;
    struct HashNode* next;
};

struct ChainedHashTable{
    HashNode** array; // array of pointers to HashNode*
    int N; // size of table
};
```

### Chained Hash Table Insertion
[top](#algorithms-and-data-structures)
```C
int insert(ChainedHashTable* table, int key, int value){
    int index=h(key);
    HashNode* front = table->array[index];
    HashNode* prev = NULL;
    while(front!=NULL){
        if(fron->key==key){
            return 0;
        }
        prev=front;
        front=front->next;
    }
    HashNode* node=malloc(sizeof(HashNode));
    node->next=NULL;
    node->key=key;
    node->value=value;
    if(prev==NULL){
        table->array[index]=node;
        return 1;
    }
    prev->next=node;
    return 1;
}
```

### Probed Hash Table
[top](#algorithms-and-data-structures)
```C
typedef struct HashNode{
    int key;
    int value;
} HashNode;
typedef struct HashTable{
    HashNode** array;
    int size;
}
```

### Probed Hash Table Insertion
[top](#algorithms-and-data-structures)
```C
int insert(HashTable* table, int key, int value){
    for(int i=0; i<table->size; i++){
        int index = h(value,i);
        if(array[index]==NULL){
            array[index]=malloc(sizeof(HashNode));
            array[index]->key=key;
            array[index]->value=value;
            return 1;
        }else if(array[index]->key==key){
            return 0;
        }
    }
    return 0;
}
```

### Pair Sum Problem
[top](#algorithms-and-data-structures)
> Given an array of integers, A, and a value, X, determine if there is a pair of indices, i and j, in A such that A[i]+A[j]=X.
```C
HashTable h;
for(int i=0;i<N;i++){
    int left = x-A[i];
    if(contains(&h, left)){
        return 1;
    }
    insert(&h,A[i]);
}
```

## Graphs
[top](#algorithms-and-data-structures)
### Adjacency List
[top](#algorithms-and-data-structures)
```C
typedef struct Edge{
    int dest;
    struct Edge*next;
} Edge;
typedef struct Graph{
    int N;
    struct Edge** adj_ist;
}
```

### Depth First Search (Graph)
[top](#algorithms-and-data-structures)
```C
void dfs(Graph * graph){
    int visited[graph->N];
    for(int i =0; i<graph->N;i++){//need this loop for unconnected graphs
        if(!visited[i]){
            visited[i]=1;
            dfs_util(graph,i,visited);
        }
    }
}
```
```C
void dfs_util(Graph* graph, int node, int* visited){
    visit(node);
    GraphNode* front = graph->array[node];
    while (front!=NULL){
        if(!visited[front->dest]){
            visited[front->dest]=1;
            dfs_util(graph,front->dest,visited);
        }
        front = front->next;
    }
}
```

### Breadth First Search (Graph)
[top](#algorithms-and-data-structures)
```C
void bfs(Graph * graph){
    int visited[graph->N];
    for(int i =0; i<graph->N;i++){//need this loop for unconnected graphs
        if(!visited[i]){
            visited[i]=1;
            bfs_util(graph,i,visited);
        }
    }
}
```
```C
void bfs_util(Graph* graph, int node, int* visited){
    Queue q;
    enqueue(&q,node);
    while(!isEmpty(&q)){
        int node=dequeue(&q);
        GraphNode* front = graph->array[node];
        while(front!=NULL){
            if(!visited[front->dest]){
                visited[front->dest]=1;
                enqueue(&queue, front->dest);
            }
            front =front->next;
        }
    }
}
```

### Dijkstra's Algorithm
[top](#algorithms-and-data-structures)
```C
int * dijkstra(Graph* g, int source){
    int dist[g->N];
    for(int i = 0; i<N;++i){
        dist[i]=-1; //infinity
    }
    dist[source]=0;
    MinHeap *h=makeHeap(dist);
    while (!isEmpty(h)){
        int next=removeMin(h);
        GraphNode* front = g->adjList[next];
        while(front!=NULL){
            int adj = front->dest;
            int alt=dist[next]+front->weight;
            if(alt<dist[adj]||dist[adj]<0){
                dist[adj]=alt;
                decreaseValue(h,adj,alt);
            }
        }
    }
}
```

### Prim's Algorithm
[top](#algorithms-and-data-structures)
```C
void prims(Graph*g){
    int cost[g->N];
    for (int i =0; i< g->N;i++) cost[i]=-1;//infinity
    cost[0]=0;
    MinHeap * h = makeHeap(cost);
    while(!isEmpty(h)){
        int min = removeMin(h);
        GraphNode* front = g->adjList
        while(front!=NULL){
            int adj = front->dest;
            if(cost[adj]>front->weight){
                cost[adj]=front->weight;
                decreaseKey(h,adj,front->weight);// decrease the key in the heap
            }
        }
    }
    
}
```