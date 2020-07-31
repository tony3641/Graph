//
// Created by tony3 on 5/25/2020.
//

#include "Graph.h"
#include <iostream>
#include <list>



Graph::Graph(int v) {
    this->numV=v;
    adj=new list<int>[v];
}


void Graph::add_edge(int v1, int v2) {
    adj[v1].push_back(v2);
}

void Graph::print_path(list<int> *path) {
    list<int>::iterator i;
    for(i = path->begin(); i!= path->end(); ++i){
        if(*i!=path->back())
            cout<<*i<<" -> ";
        else {
            cout << *i << endl;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
//////////////////////////////-----DFS-----//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
bool Graph::DFS_Internal(int v, int target, bool *visited, list<int> *path) {
    bool found = false;

    //cout << "Visiting " << v << endl;
    visited[v] = true;

    if(v==target){
        path->push_back(v);
        return true;
    }
    else{
        for(auto i = adj[v].begin(); i!=adj[v].end(); i++){
            if(!visited[*i]){
                //cout<<v<<"->"<<*i<<endl;
                path->push_back(v);
                found = DFS_Internal(*i, target, visited, path);
            }
            if(found){
                break;
            }
            else{
                path->pop_back();
            }
        }
        return found;
    }

}

bool Graph::DFS(int start, int target, list<int> *path) {
    bool *visited = new bool[numV];
    for(int i=0; i<numV; i++){
        visited[i]=false;
    }
    DFS_Internal(start, target, visited, path);
}

/////////////////////////////////////////////////////////////////////////////
//////////////////////////////-----BFS-----//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
bool Graph::BFS(int start, int target, list<int> *path){
    bool *visited = new bool[numV];
    for(int i=0; i<numV; i++){
        visited[i]=false;
    }

    bool state = false;

    list<int> q;
    visited[start]=true;
    q.push_back(start);
    while(!q.empty()) {
        if(q.front()==target) {
            return true;
        }
        start = q.front();
        q.pop_front();

        cout<<"Checking "<<start<<"adj list"<<endl;

        for (auto i = adj[start].begin(); i != adj[start].end(); ++i) {
            if (!visited[*i]) {
                cout<<"Visit and enqueue"<<*i<<endl;
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
    return state;
}