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

cur pointer isn't pointing at the entire node itself, but the ```next``` pointer inside the node, in other word, ```&(*cur)->next``` is the address of the variable that store the address of the next node\
(before entering the while loop, where ```cur = h```, it is indeed pointing to the first node)

therefore, ```*cur``` is the address store in the ```next``` pointer in the node, and ```(*cur)->data``` is actually the data in the next node

meanwhile ```free(temp);``` will free the entire next node instead of the pointer inside the node only



---
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

---


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