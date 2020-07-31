//
// Created by tony3 on 5/25/2020.
//
#include <iostream>
#include <bits/stdc++.h>

#ifndef SEARCH_GRAPH_H
#define SEARCH_GRAPH_H

using namespace std;

class Graph {
    int numV;
    list<int> *adj;
    bool *visited;
    bool DFS_Internal(int v, int target, bool visited[], list<int> *path);
public:
    Graph(int v);
    void visited_init();
    void add_edge(int v1, int v2);
    bool DFS(int start, int target, list<int> *path);
    bool BFS(int start, int target);
    void print_path(list<int> *path);
};


#endif //SEARCH_GRAPH_H
