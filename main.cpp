#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    list<int> *path = new list<int>;
    //path->push_back(6);
    Graph graph(9);
    graph.add_edge(1,0);
    graph.add_edge(2,7);
    graph.add_edge(2,4);
    graph.add_edge(3,1);
    graph.add_edge(5,2);
    graph.add_edge(5,0);
    graph.add_edge(6,5);
    graph.add_edge(6,8);
    graph.add_edge(7,5);
    graph.add_edge(7,6);
    graph.add_edge(7,8);


    bool found_DFS = graph.DFS(7,3, path);
    bool found_BFS = graph.BFS(0,3);
    found_DFS?cout<<"Found by DFS!"<<endl:cout<<"Not Found by DFS!"<<endl;
    if(found_DFS){
        graph.print_path(path);
    }
    //found_BFS?cout<<"Found by BFS!"<<endl:cout<<"Not Found by BFS!"<<endl;
    return 0;
}
