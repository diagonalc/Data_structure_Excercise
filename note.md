# Note about data structure

### Tree Traversal techniques
Depth First Traversal (DFT):\
Preorder, inorder, postorder\
Every nodes will be visited for three times\
Pre/in/post is just about the timing of reading the node\
ususal implementation: recursion

Breadth-First Traversal (BFT):\
Level order traversal\
ususal implementation: \
queue\
read a node and push its children into the queue

  


### Benefits of adjacency matrix:
- Edges will be recored once only
- Easy to find all adjacent nodes for a single node
- Easy to find the degree of a node
- Efficient in saving dense graph

### Drawbacks:
- Inefficient (in both time and space) in saving sparse graph

### Benefits of adjacency list:
- Easy to find all adjacent nodes for a single node
- Efficient in saving sparse graph
- Easy to find the degree of a node of a undirected graph