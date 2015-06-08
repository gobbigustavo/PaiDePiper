Projeto de P2 - Huffman Coding
==============================

Huffman Coding: Data Structures - UFAL (2014.2): Final project of the course

Students: Carla Nicole, Eduardo Gabriel, Filipe Falcão, Gustavo Gobbi e Rodolfo Mathias

Teacher: Marcio Ribeiro

Huffman Coding - Steps
==============================
1 - Create a simple binary tree

2 - For each given symbol, create a leaf node in the tree and add it to the priority queue.

3 - While the is more than one element in the queue

3.1 - Remove the node of highest priority (dequeue) twice to get two nodes with the lowest probabilities in the tree

3.2 - Create a new internal node in the tree with these nodes as children and with probability equal to the sum of             these nodes probabilities

3.3 - Add the new node to the queue (enqueue)

4 - Transverse the tree with '0's for left nodes and '1's for right nodes

5 - The binary code accumulated is the Huffman encoding for each given symbol
