//
//  graph.cpp
//  Graphs_lecture
//
//  Created by Saransh Kalra on 11/2/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "graph.hpp"
#include <iostream>

Node::Node(int label) {
    this->label = label;
    this->next = 0;
    this->head = 0;
    this->visited = false;
}

AdjNode::AdjNode(Node *node) {
    this->next = 0;
    this->node = node;
    
}

Graph::Graph() {
    this->head = 0;
    this->queueTail = 0;
    this->visited = 0;
    this->stackQueue = 0;
}

Graph::~Graph() {
    destr_helper(this->head);
}

void Graph::destr_helper(Node *node) {
    if (node) {
        destr_helper(node->next);
        destr_helper2(node->head);
        delete node;
    }
}

void Graph::destr_helper2(AdjNode *node) {
    if (node) {
        destr_helper2(node->next);
        delete node;
    }
}

void Graph::add_node(int label) {
    Node *temp =this->head;
    while (temp) {
        if (temp->label == label) {
            throw "Duplicate node already exists. ";
        }
        else {
            temp = temp->next;
        }
    }
    
    Node *newNode = new Node(label);
    newNode->next = this->head;
    this->head = newNode;
}

void Graph::add_edge(int src, int dst) {
    Node *temp = this->head;
    Node *start, *end;
    while (temp && temp->label != src) {
        temp = temp->next;
    }
    
    if(temp == 0) {
        throw "Source does not exist";
    }
    
    else {
        start = temp;
        temp = this->head;
    }
    
    while (temp && temp->label!= dst) {
        temp =temp->next;
    }
    
    if(temp == 0) {
        throw "Source does not exist";
    }
    
    else {
        end = temp;
    }
    
    AdjNode *edge = new AdjNode(end);
    edge->next = start->head;
    start->head = edge;
}

void Graph::rem_edge(int src, int dst) {
    Node *temp = this->head;
    
    while (temp && temp->label != src) {
        temp = temp->next;
    }
    
    if(temp == 0) {
        throw "Edge doesn't exist";
    }
    else {
        AdjNode *aTemp = temp->head;
        AdjNode *prev = 0;
        
        while (aTemp && aTemp->node->label != dst) {
            prev = aTemp;
            aTemp = aTemp->next;
        }
        
        if (aTemp == 0) {
            throw "Edge doesn't exist";
        }
        else {
            if (prev == 0) {
                temp->head = aTemp->next;
            }
            else {
                prev->next = aTemp->next;
            }
            delete aTemp;
        }
    }
}

void Graph::rem_node(int src) {
    Node *temp = this->head;
    Node *prev = 0;
    Node *remNode = 0;
    while (temp) {
        if(this->search_adj(temp, src)) {
            throw "Cannot remove node";
        }
        if (temp->label == src) {
            remNode = temp;
        }
        if (!remNode) {
            prev = temp;
        }
        temp = temp->next;
    }
    
    if (!remNode) {
        throw "Node doesn't exist";
    }
    
    if (prev) {
        prev->next = remNode->next;
    }
    
    else {
        this->head = remNode->next;
    }
    
    delete remNode;
}

bool Graph::search_adj(Node * srcNode, int srcInt) {
    AdjNode *temp = srcNode->head;
    
    while (temp) {
        if(temp->node->label == srcInt) {
            return true;
        }
        temp =temp->next;
    }
    
    return false;
}

void Graph::push (Node *node) {
    if (node == head) {
        this->head = node->next;
    }
    else {
        //Node *temp = this->head->next;
        Node *prev = this->head;
        
        while (prev->next != node) {
            prev = prev->next;
        }
        
        prev->next = node->next;
    }
    
    if(this->stackQueue == 0) {
        this->queueTail = node;
    }
    node->next = this->stackQueue;
    this->stackQueue = node;
}

Node* Graph::pop (bool stack) {
    if(!stackQueue) {
        return 0;
    }
    Node *retNode;
    if(stack) {
        retNode = this->stackQueue;
        this->stackQueue = retNode->next;
        if (!stackQueue) {
            queueTail = 0;
        }
    }
    else {
        retNode = this->queueTail;
        if (stackQueue->next == 0) {
            this->stackQueue = 0;
            this->queueTail = 0;
        }
        else {
            Node *temp = this->stackQueue;
            while (temp->next != retNode) {
                temp = temp->next;
            }
            temp->next = 0;
        }
    }
    return retNode;
}

void Graph::BFT(int source) {
    Node *temp = this->head;
    while (temp && temp->label != source) {
        temp = temp->next;
    }
    
    if(!temp) {
        throw "Node not found";
    }
    
    push(temp);
    
    while (this->stackQueue) {
        temp = pop(false);
        std::cout<<temp->label<<std::endl;
        AdjNode *aTemp = temp->head;
        while(aTemp) {
            aTemp->node->visited = true;
            push(aTemp->node);
            aTemp = aTemp->next;
        }
    }
}

void Graph::DFT(int source) {
    Node *temp = this->head;
    while (temp && temp->label != source) {
        temp = temp->next;
    }
    
    if(!temp) {
        throw "Node not found";
    }
    
    push(temp);
    
    while (this->stackQueue) {
        temp = pop(true);
        std::cout<<temp->label<<std::endl;
        AdjNode *aTemp = temp->head;
        while(aTemp) {
            aTemp->node->visited = true;
            push(aTemp->node);
            aTemp = aTemp->next;
        }
    }
}

