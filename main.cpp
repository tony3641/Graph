#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    list<int> *path = new list<int>;
    //path->push_back(6);
    Graph graph(10);
    graph.add_edge(1,2);
    graph.add_edge(1,3);
    graph.add_edge(1,4);
    graph.add_edge(2,5);
    graph.add_edge(3,6);
    graph.add_edge(4,0);
    graph.add_edge(6,7);
    graph.add_edge(7,8);
    graph.add_edge(7,9);


    //bool found = graph.DFS(1,9,path);
    //if(found) graph.print_path(path);
    bool found_BFS = graph.BFS(1,3, path);
    found_BFS?cout<<"Found by BFS!"<<endl:cout<<"Not Found by BFS!"<<endl;
    return 0;
}
