# DSA CLA-2 PROJECT REPORT

## Student Record Search System using BST, AVL Tree and Hashing

**Student Name:** ______________________________  
**Register Number:** ___________________________  
**Programme / Section:** _______________________  
**Course:** Data Structures and Algorithms  
**Faculty:** ___________________________________  
**Academic Year:** _____________________________  

## 1. Abstract
This project implements a Student Record Search System using three data structures: Binary Search Tree (BST), AVL Tree and Hash Table with Linear Probing. Each student record contains an ID, name and CGPA. The same records are inserted into all structures and searched using the student ID.

## 2. Problem statement
Searching for a student in an unsorted collection can require examining many records. This project compares three data structures that support efficient record retrieval.

## 3. Objectives
1. Implement insertion and searching using BST.
2. Implement AVL insertion with self-balancing rotations.
3. Implement hashing with linear probing for collision resolution.
4. Compare search comparisons, tree heights and collisions.
5. Test successful search, unsuccessful search and insertion.

## 4. Requirements
- Language: C
- Compiler: GCC / Code::Blocks / Dev-C++ / VS Code with GCC
- OS: Windows, Linux or macOS
- Hardware: Computer or laptop

## 5. Data structures

### 5.1 Binary Search Tree
For each node, smaller IDs are placed in the left subtree and larger IDs in the right subtree. Average search complexity is O(log n); worst case is O(n).

### 5.2 AVL Tree
An AVL Tree is a self-balancing BST. Its balance factor is:
**Balance Factor = height(left subtree) − height(right subtree)**

The balance factor is maintained between -1 and +1. LL, RR, LR and RL rotations restore balance. Search and insertion are O(log n).

### 5.3 Hashing with Linear Probing
The hash function used is **h(key) = key mod 53**. When a slot is occupied, the next slot is checked. Average search is O(1) under a suitable load factor; worst case is O(n).

## 6. Algorithm
1. Load the 40 sample records.
2. Insert every record into BST, AVL and hash table.
3. Search for ID 1025 (successful search).
4. Search for ID 1099 (unsuccessful search).
5. Insert a new record with ID 1041.
6. Search for ID 1041 to verify insertion.
7. Display inorder traversals and tree heights.
8. Test additional IDs using interactive search.

## 7. Experimental results
Run the program and copy the actual figures printed by your execution.

| Test | BST comparisons | AVL comparisons | Hash slots checked |
|---|---:|---:|---:|
| Successful search — 1025 | ______ | ______ | ______ |
| Unsuccessful search — 1099 | ______ | ______ | ______ |
| Search inserted ID — 1041 | ______ | ______ | ______ |

**BST height (levels):** ______  
**AVL height (levels):** ______  
**Hash insertion collisions:** ______  

Do not guess these values. Use the output produced by your own run.

## 8. Complexity comparison

| Operation | BST average / worst | AVL | Hashing average / worst |
|---|---|---|---|
| Search | O(log n) / O(n) | O(log n) | O(1) / O(n) |
| Insert | O(log n) / O(n) | O(log n) | O(1) / O(n) |
| Ordered traversal | O(n) | O(n) | Not naturally ordered |

## 9. Screenshots
Paste your own screenshots in these spaces:
- Screenshot 1: Program start and number of records loaded.
- Screenshot 2: Successful and unsuccessful search results.
- Screenshot 3: Insertion verification and comparison counts.
- Screenshot 4: Inorder traversal and tree heights.

## 10. Result
The program demonstrates insertion and searching of student records using BST, AVL Tree and hashing. The actual comparison counts, heights and collision count are to be recorded from the student's own execution.

## 11. Conclusion
BST supports ordered searching but may become unbalanced. AVL maintains balance through rotations and guarantees logarithmic search. Hashing offers fast average lookup, while linear probing handles collisions. The project demonstrates the practical differences between these structures.

## 12. Viva questions and answers
1. **What is a BST?** A binary tree where left keys are smaller and right keys are larger than the node key.
2. **What is an AVL Tree?** A self-balancing binary search tree.
3. **What is balance factor?** Left subtree height minus right subtree height.
4. **Name AVL rotations.** LL, RR, LR and RL.
5. **What is hashing?** Mapping a key to a table index using a hash function.
6. **What is collision?** Two different keys map to the same table slot.
7. **What is linear probing?** Checking subsequent slots until an empty slot is found.
8. **Which structures provide sorted inorder traversal?** BST and AVL Tree.
9. **BST worst-case search complexity?** O(n).
10. **AVL search complexity?** O(log n).
11. **Average hash search complexity?** O(1), assuming a good hash function and controlled load factor.
12. **Why compare these structures?** To understand differences in searching, balancing, ordering and collision handling.
