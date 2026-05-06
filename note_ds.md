# Note about data structure

### More advance linked list techniques
```
void delete(llnode **h, int target)
{
    llnode **cur = h; // pointing to the entire node
    while((*cur)->data != target)
        cur = &(*cur)->next; 
    llnode *temp = *cur;
    *cur = (*cur)->next;
    free(temp);
}
```

cur pointer isn't pointing at the entire node itself, but the ```next``` pointer inside the node, in other word, ```&(*cur)->next``` is the address of the variable that store the address of the next node  
(before entering the while loop, where ```cur = h```, it is indeed pointing to the first node)

therefore, ```*cur``` is the address store in the ```next``` pointer in the node, and ```(*cur)->data``` is actually the data in the next node

meanwhile ```free(temp);``` will free the entire next node instead of the pointer inside the node only



---
### Tree Traversal techniques
Depth First Traversal (DFT):  
Preorder, inorder, postorder  
Every nodes will be visited for three times  
Pre/in/post is just about the timing of reading the node  
ususal implementation: recursion

Breadth-First Traversal (BFT):  
Level order traversal  
ususal implementation:   
queue  
read a node and push its children into the queue

---


### Benefits of adjacency matrix
- Edges will be recored once only
- Easy to find all adjacent nodes for a single node
- Easy to find the degree of a node
- Efficient in saving dense graph

### Drawbacks
- Inefficient (in both time and space) in saving sparse graph

### Benefits of adjacency list
- Easy to find all adjacent nodes for a single node
- Efficient in saving sparse graph
- Easy to find the degree of a node of a undirected graph

---

### Tarjan
To find out all the strongly connected components in a graph. 
dfn[i], low[i]  
dfn: the time stamp when the vertex is visited  
low: the earlest time stamp the vertex can trace back through edges  
When low == dfn: its the oldest visited vertex in this SCC --> pop elements in stack until itself  
Implemented through DFS and stack

---
### Dijkstra
To find the shortest path from a vertex to other vertices.
Dijkstra is a kind of greedy algorithm, each time it will choose a vertex that is closest to the current vertex to make an update  
Time complexity: O(V*ElogV) (optimized with minimum heap)  
*cannot deal with negative side!  
let say there are 3 edges, A->B: 5, A->C: 10, C->B: -8, starting from A, it will visit B first and confirm that the shortest path from A to B will be A->B:5, ignoring the C

### Floyd
To find the shortest path from each vertex in the graph to all vertices.
Floyd is a kind of dynamic programming, which is different to doing n times of Dijkstra. It will simply go through all the vertices without determinating which one is closer to the current one.  
Time complexity: O(V^3)
*can deal with negative edges, as all vertices will be checked 

---
### Prim: Growing a tree from a node
To find the Minimum Spanning Tree of a graph.  
Visiting the vertex with shortest distance to the current MST.  
Similar to Dijkstra, it's also a kind of greedy algorithm.  
Time Complexity: O(V^2) (if not optimized)(optimizaion is usually about the way we traverse through the vertices) 

### Kruskal: Merging Trees
To find the MST of a graph.  
Visiting the shortest edge in the graph and union two sets.  
Greedy algorithm.  
Time Complexity: O(ElogE) (optimized with minimum heap)

---
### Topological Sort
To find a legal execution order when things have prerequisites constrains.  
BFS and topological sort (Kahn's algorithm) both process vertices level by level using a queue. However, BFS decides to enqueue a neighbor if it hasn't been visited yet, while topological sort enqueues a vertex only after all its predecessors have been processed — i.e., when its in-degree drops to zero.  
Time Complexity: O(V + E) (adjacency list), O(V^2) (adjacency matrix)

---
### Shell Sort
