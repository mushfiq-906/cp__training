# π³ Trees
- The tree cannot contain cycles, and tree with (n)-nodes has (n-1)-edges
- They may or may not have links back to their parent nodes
- A very simple class definition for Node is as following:
- Balanced tree enough to ensure O(log n) times for **insert** and **find** operations
- Two common types of **balanced trees** are **red-black** trees and **AVL** trees

```cpp
class Node {
  string name;
  Node children [N];
}
```
### π΄ Complete Binary Trees
- A complete binary tree is a binary tree in which every level of the tree is fully filled
- To the extent that the last level is filled, it is filled left to right

![Screenshot 2021-05-22 141808](https://user-images.githubusercontent.com/40190772/119226327-c7bb3780-bb08-11eb-9124-2aad961243e0.png)


### πΆ Full Binary Trees
- A full binary tree is a binary tree in which every node has either zero or two children
- no nodes have only one child

![image](https://user-images.githubusercontent.com/40190772/119226530-e4a43a80-bb09-11eb-92d8-43f12dc454d6.png)


### β‘ Perfect Binary Trees
- A perfect binary tree is one that is both full and complete
- As a perfect tree must have exactly (2^k - 1) nodes (where k is the number of levels)

![image](https://user-images.githubusercontent.com/40190772/119226577-1ddcaa80-bb0a-11eb-840f-bae31c63148c.png)



## π¦ Questions to ask about trees
- [x] Tree Vs. Binary Tree
- [x] Binary Tree Vs. Binary Search Tree
- [x] Balanced vs. Unbalanced


## πΆββοΈ Binary Tree Traversal
- We have 3 ways for traversing a binary tree:
    1. In-Order Traversal
    2. Pre-Order Traversal
    3. Post-Order Traversal
- The name of the traversal method is respect to the current

```cpp
#include <iostream>
using namespace std;

class BST {
  int data;
  BST *left, *right;

 public:
  BST();
  BST(int);
  BST* Insert(BST*, int);
  void Inorder(BST*);
};

BST ::BST() : data(0), left(NULL), right(NULL) {}

BST ::BST(int value) {
  data = value;
  left = right = NULL;
}

BST* BST ::Insert(BST* root, int value) {
  if (!root) {
    return new BST(value);
  }

  if (value > root->data) {
    root->right = Insert(root->right, value);
  } else {
    root->left = Insert(root->left, value);
  }

  return root;
}

void BST ::Inorder(BST* root) {
  if (!root) {
    return;
  }

  Inorder(root->left);
  cout << root->data << endl;
  Inorder(root->right);
}
```

### πβπ In-Order Traversal
- Visit the **left** branch, then the **current** node, and finally, the **right** branch.

```cpp
void inOrderTraversal(TreeNode node) {
  if (node != nUll) {
    inOrderTraversal(node.left);
    visit(node);
    inOrderTraversal(node.right);
  }
}
```

### βππ Pre-Order Traversal
- Visit the **current** node, then the **left** branch, and finally, the **right** branch.

```cpp
void preOrderTraversal(TreeNode node) {
  if (node != nUll) {
    visit(node);
    preOrderTraversal(node.left);
    preOrderTraversal(node.right);
  }
}
```


### ππβ Post-Order Traversal
- Visit the **left** branch, the **right** branch, then finally the **current** node

```cpp
void postOrderTraversal(TreeNode node) {
  if (node != nUll) {
    postOrderTraversal(node.left);
    postOrderTraversal(node.right);
    visit(node);
  }
}
```


## π© Binary Heaps (Min-Heaps and Max-Heaps)
- We'll just discuss min-heaps here. Max-heaps are essentially equivalent
- A min-heap is a **complete binary tree**
- Each node is **smaller** than its children
- **The root**, therefore, is the **minimum element** in the tree

![image](https://user-images.githubusercontent.com/40190772/119228416-39987e80-bb13-11eb-813c-473c5aa376fa.png)

### π¬ Binary Heaps operations
1. Insert
2. Extract min/max

#### π Insert
1. Insert the element at the bottom (rightmost spot so as to maintain the complete tree property)
2. Then, we Fix (swapping the new element with its parent until min heap property full satisfied)
3. This algorithm will also take **O(log n) time**

![image](https://user-images.githubusercontent.com/40190772/119228974-eb38af00-bb15-11eb-8f19-5bb3c8e9d240.png)

#### πͺ Extract Minimum Element
1. Min-heap is always **at the top**, The trickier part is how to remove it
2. **Remove the minimum** element and **swap it with the last element** in the heap
3. **Bubble down** this element, **swapping it with one of its children** until the min-heap property is restored
4. This algorithm will also take **O(log n) time**

![image](https://user-images.githubusercontent.com/40190772/119229220-343d3300-bb17-11eb-8bd8-8e158c74289b.png)

```cpp
#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
 private:
  vector<int> pq;
  int Parent(int x) { return (x - 1) / 2; }
  int Left_Child(int x) { return 2 * x + 1; }
  int Right_Child(int x) { return 2 * x + 2; }

  void Heapify_Down(int i) {
    int left = Left_Child(i);
    int right = Right_Child(i);

    int Smallest = i;

    if (left < pq.size()) {
      if (pq[left] < pq[Smallest]) {
        Smallest = left;
      }
    }

    if (right < pq.size()) {
      if (pq[right] < pq[Smallest]) {
        Smallest = right;
      }
    }

    if (Smallest != i) {
      swap(pq[Smallest], pq[i]);
      Heapify_Down(Smallest);
    }
  }

  void Heapify_Up(int i) {
    int parent = Parent(i);
    if (i && pq[parent] > pq[i]) {
      swap(pq[parent], pq[i]);
      Heapify_Up(parent);
    }
  }

 public:
  int Size() { return pq.size(); }
  bool Empty() { return Size() == 0; }

  void Push(int key) {
    pq.push_back(key);
    int index = Size() - 1;
    Heapify_Up(index);
  }

  void Pop() {
    try {
      if (Empty()) {
        throw out_of_range(
            "Vector<X>::at() : "
            "index is out of range(Heap underflow)");
      }

      pq[0] = pq.back();
      pq.pop_back();
      Heapify_Down(0);
    } catch (const std::exception& error) {
      cout << error.what() << endl;
    }
  }

  int Top() {
    try {
      if (Empty()) {
        throw out_of_range(
            "Vector<X>::at() : "
            "index is out of range(Heap underflow)");
      }
      return pq[0];
    } catch (const std::exception& error) {
      cout << error.what() << endl;
    }
  }
};
int main() {
  PriorityQueue pq;

  pq.Push(3);
  pq.Push(2);
  pq.Push(15);

  cout << "Size is " << pq.Size() << endl;

  cout << pq.Top() << " ";
  pq.Pop();

  cout << pq.Top() << " ";
  pq.Pop();

  pq.Push(5);
  pq.Push(4);
  pq.Push(45);

  cout << endl << "Size is " << pq.Size() << endl;

  cout << pq.Top() << " ";
  pq.Pop();

  cout << pq.Top() << " ";
  pq.Pop();

  cout << pq.Top() << " ";
  pq.Pop();

  cout << pq.Top() << " ";
  pq.Pop();

  cout << endl << std::boolalpha << pq.Empty() << endl;

  pq.Top();  // top operation on an empty heap
  pq.Pop();  // pop operation on an empty heap
}
```

## π§ Tries (Prefix Trees)
- A trie (sometimes called a **prefix tree**) which is a variant of an **n-ary tree**
- Characters are stored at each node, Each path down the tree may represent a word
- The * nodes (sometimes called "**null nodes**") are often used to **indicate complete words**
- A node in a trie could have anywhere from **1** through **ALPHABET_SIZE + 1**
- A trie can check if a string is a valid prefix in **O(K) time**, where K is the length of the string.

![image](https://user-images.githubusercontent.com/40190772/119230134-2f7a7e00-bb1b-11eb-9897-47d187583430.png)
