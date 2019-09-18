//
//  graph.hpp
//  Graphs_lecture
//
//  Created by Saransh Kalra on 11/2/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>

class AdjNode;

class Node {
public:
    int label;
    bool visited;
    Node *next;
    AdjNode *head;
    Node(int);
};

class AdjNode {
public:
    Node *node;
    AdjNode *next;
    AdjNode(Node*);
};

class Graph {
    Node *head, *visited, *stackQueue, *queueTail;
    void destr_helper(Node*);
    void destr_helper2(AdjNode*);
    void push(Node*);
    Node* pop(bool);
public:
    Graph();
    ~Graph();
    void add_node(int);
    void add_edge(int, int);
    void rem_node(int);
    void rem_edge(int, int);
    bool search_adj(Node*, int);
    void BFT(int);
    void DFT(int);
};
#endif /* graph_hpp */
