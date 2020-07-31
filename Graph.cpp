//
// Created by tony3 on 5/25/2020.
//

#include "Graph.h"
#include <iostream>
#include <bits/stdc++.h>

Graph::Graph(int v) {
    this->numV=v;
    adj=new list<int>[v];
    visited_init();
}

void Graph::visited_init() {
    visited = new bool[numV];
    for(int i=0; i<numV; i++){
        visited[numV]=false;
    }
}

void Graph::add_edge(int v1, int v2) {
    adj[v1].push_back(v2);
}

bool Graph::DFS_Internal(int v, int target, bool visited[], list<int> *path) {
    bool state = false;
    visited[v]= true;
    if(target==v) {
        state = true;
        path->push_back(v);
    }
    else {
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]){
                state = DFS_Internal(*i, target, visited, path);
                path->push_back(v);
            }
        }
    }
    return state;
}

bool Graph::DFS(int start, int target, list<int> *path) {
    visited_init();
    bool found = DFS_Internal(start, target, visited, path);
    path->reverse();
    return found;
}

bool Graph::BFS(int start, int target){
    visited_init();
    bool state = false;

    list<int> q;
    visited[start]=true;

    q.push_back(start);
    list<int>::iterator i;
    while(!q.empty()) {
        if(q.back()==target) {
            state = true;
            break;
        }
        q.pop_front();

        for (i = adj[start].begin(); i != adj[start].end(); ++i) {
            if(*i==target){
                state = true;
                visited[*i] = true;
                break;
            }
            if (!visited[*i]) {
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
    return state;
}

void Graph::print_path(list<int> *path) {
    list<int>::iterator i;
    for(i = path->begin(); i!= path->end(); ++i){
        if(*i!=path->back())
            cout<<*i<<"->";
        else {
            cout << *i << endl;
        }
    }
}