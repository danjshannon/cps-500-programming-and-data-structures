# Week 10 Graphs
- [Home](/README.md#cps-500-programming-and-data-structures)
- [10.1 Introduction to Graphs](#101-Introduction-To-Graphs)


## 10.1 Introduction to Graphs
[top](#week-10-graphs)

### Graphs
[top](#week-10-graphs)

- Graphs are a mathematical construct that are widely used in every day computer science.
- They model:
  - Social networks
  - computer communications
  - protein interactoin networks
  - route planning
  - goal planning
- They are common strudied in mathematics under graph theory (some overlap here)

### Graph Definitions
[top](#week-10-graphs)
- A graph has two components:
  1. **vertex set** (entities, people, computers, events)
  2. **edges** (interactions between vertices) - take the form of (v<sub>1</sub>, v<sub>2</sub>), where v<sub>1</sub> and v<sub>2</sub> are verices
    - v1 and v2 called **neighbors/adjacent** when an edge exists between them
- A **directed graph** is one in which edges have a direction.
- An **undirected graph**  is one in which edges have no direction so (v<sub>1</sub>,v<sub>2</sub>) automatically implies (v<sub>2</sub>,v<sub>1</sub>) 

- A **weighted graph** is one in which edges have a real number weight associated with them.
  - weights can represent cost, distance, capacity, and so on.

### Graph Terms
[top](#week-10-graphs)
- **path** a series of vertices such that they are pairwise connected by edges
  - {e,d,c,a} is a path on the right
  - {b,e,d} is not a path on the right
```
a<--->c    
|     ^     |--|
V     |     V  |
b---->d<----e--|
```
![Graph 1](./graph1.png)
- **cycle** a path that returns to its starting node.
  - {a,b,d,c,a} is a cycle
- node e has a **reflexive** edge