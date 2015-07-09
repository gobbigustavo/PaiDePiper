# PaiDePiper

## Description

This repo contains an implementation of Huffman Coding with schorlaly purpose.

## Steps

**Encoding**
  1. Count the frequency of each symbol in the given file;
  2. Make a queue with the symbols and their corresponding frequency;
  3. While there's more than one node in the queue:
      1. Take the elements with the two lowest frequencies and turn them into leaves;
      2. The parent node contains the sum of the two lower symbols frequencies;
      3. The remaining node will be the root node;
  4. Create the encoding map;
      1. Traverse the tree;
      2. If you're visiting a node's left child, you must assign with 0;
      3. If you're visiting a node's right child, you must assign with 1;
  5. Often, we don't have lenghts that are multiples of 8. So, we fill the remaining
  digits with '0's.
  6. Something that involves bit shift operators; (TO BE SOLVED) 
  
**Decoding**
  >Right now, it's not a priority; (TO BE SOLVED)

## Resourceful links

1. A Method for the Construction of Minimum-Redundancy Codes. (HUFFMAN, DAVID A., 1952)
  http://compression.ru/download/articles/huff/huffman_1952_minimum-redundancy-codes.pdf
2. On the Construction of Huffman Trees. (LEEUWEN, Jan Van, 1991)
  http://www.staff.science.uu.nl/~leeuw112/huffman.pdf
