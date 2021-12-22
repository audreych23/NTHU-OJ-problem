// C++ program for Kruskal's algorithm to find Minimum
// Spanning Tree of a given connected, undirected and
// weighted graph
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;

// Structure to represent a graph
class Graph
{
    int V, E;
    vector< pair<int, iPair> > edges;
public:

    // Constructor
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    // Utility function to add an edge
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    // Function to find MST using Kruskal's
    // MST algorithm
    int kruskalMST();
};

// To represent Disjoint Sets
class DisjointSets
{
    //Array used to indicate the parent and rank,size or height of each vertex
    int *parent, *rnkorsize;
    int n;
    friend Graph;

    // Constructor.
    //n is the number of vertices in the graph given by the user
    DisjointSets(int n)
    {
        // Allocate memory
        //TODO
        this->n = n;

        parent = new int[n+1];
        rnkorsize = new int[n+1];
        // Initially, all vertices are in
        // different sets and have rank 0.
        //TODO
        for(int i=0;i<n+1;i++){
            parent[i] = i;
            rnkorsize[i] = 0;
        }
    }

    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path
        from u--> parent[u] point to parent[u] */
        //TODO
        if(u != parent[u]){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Union by rank,size or height
    void merge(int x, int y)
    {
        //merge
        x = find(x);
        y = find(y);
        if(rnkorsize[x] > rnkorsize[y]){
            parent[y] = x;
        } else {
            parent[x] = y;
        }

        /*if(rnkorsize[x] == rnkorsize[y]){
            //rnkorsize[y]++;
        }*/

        //TODO
    }
};

/* Functions returns weight of the MST*/

int Graph::kruskalMST()
{
    //TODO
    int mst_weight = 0;

    // sort from the smallest weight
    sort(edges.begin(), edges.end());
    DisjointSets dj(V);

    vector<int>::iterator it;

    //iterate through the whole vector
    for(auto it = edges.begin(); it!= edges.end(); it++){

        int u = it->second.first;
        int v = it->second.second;

        int set_u = dj.find(u);
        int set_v = dj.find(v);

        //no cycle
        if(set_u != set_v){
            mst_weight += it->first;
            dj.merge(set_u, set_v);
        }
    }
    return mst_weight;
}

// Driver program to test above functions
int main()
{
    string cmd;
    int V ;
    int E ;
    cin >> cmd;
    //You should create the graph first!!!
    if (cmd == "creategraph"){
        cin >> V;
        cin >> E;
    }
    Graph g(V,E);


    while(cin >> cmd){
        if(cmd == "addEdge"){
            int u;
            int v;
            int w;
            cin >> u;
            cin >> v;
            cin >> w;
            g.addEdge(u,v,w);
        }else if(cmd == "kruskalMST"){
            cout<<g.kruskalMST()<<endl;
        }else if(cmd == "exit"){
            return 0;
        }
    }

    return 0;

}
