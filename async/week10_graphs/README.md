# Week 10 Graphs
- [Home](/README.md#cps-500-programming-and-data-structures)
- [10.1 Introduction to Graphs](#101-Introduction-To-Graphs)
- [10.2 Graph Representations](#102-graph-representations)


## 10.1 Introduction to Graphs
[top](#week-10-graphs)

### Graphs

- Graphs are a mathematical construct that are widely used in every day computer science.
- They model:
  - Social networks
  - computer communications
  - protein interactoin networks
  - route planning
  - goal planning
- They are common strudied in mathematics under graph theory (some overlap here)

### Graph Definitions
- A graph has two components:
  1. **vertex set** (entities, people, computers, events)
  2. **edges** (interactions between vertices) - take the form of (v<sub>1</sub>, v<sub>2</sub>), where v<sub>1</sub> and v<sub>2</sub> are verices
    - v1 and v2 called **neighbors/adjacent** when an edge exists between them
- A **directed graph** is one in which edges have a direction.
- An **undirected graph**  is one in which edges have no direction so (v<sub>1</sub>,v<sub>2</sub>) automatically implies (v<sub>2</sub>,v<sub>1</sub>) 

- A **weighted graph** is one in which edges have a real number weight associated with them.
  - weights can represent cost, distance, capacity, and so on.

### Graph Terms
- **path** a series of vertices such that they are pairwise connected by edges
  - {e,d,c,a} is a path on the right
  - {b,e,d} is not a path on the right
  <img src="./graph1.png" alt="graph 1" width="200"/>
- **cycle** a path that returns to its starting node.
  - {a,b,d,c,a} is a cycle
- node e has a **reflexive** edge

### More Definitions
- **subgraph** a subset of the vertices (and their associated edges)
  - considered a valid graph in its own right
- All edges do not have to be connected for a graph to be valid
  - in particular, a graph can be divided into one or more **connected components**
  - there can be a single graph with vertices {a,b,c,d,e,f} and two connected components {a,b,c,d} and {e,f}
  <img src="./graph2.png" alt="graph 2" width="200"/>

## 10.2 Graph Representations
[top](#week-10-graphs)

### Two main data representations
1. Adjacency matrix
2. Adjacency list

### Adjacency Matrix
- all nodes are assigned an ID between [0:N-1]
- we create the NxN matric (double array)
  - the value in matrix[i,j]=1 if there is an edge from i to j, 0 otherwise
  - alternatively, we can store a real number indicating the weight of the edge between i and j
    - with 0 or infinity representing no edge
### Example
  <img src="./graph3.png" alt="graph 3" width="400"/>
- notice that memory usage is O(N<sup>2</sup>)
- a **sparse** graph is mostly 0s
- A **dense** graph  is mostly 1s

### Performance
- most real-world graph are **sparse**, so they wast too much memory: O(N<sup>2</sup>)
- checking if an edge exists from i to j is O(1)
- to iterate over all edges of node i takes O(N)
- looking up the incoming edges for edge i takes O(N)
- certain graph calculations are easiest in the form of matrix calculations

### 
