/**
    Md Mahmudul Hasan
    Gainesville, Fl

    Breadth First Search (BFS)
**/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    vector<vector <int> > adj_list;
    vector<bool> visited;
    vector<int> distance;
    int n, e;

    public:
        Graph(int nn, int ee)
        {
            n = nn;
            e = ee;
            adj_list.resize(n);
            visited.resize(n, false);   // allocate n elements, initialize by false
            distance.resize(n, 0);      // allocate n elements, initialize by 0
        }

        void read_graph(void)
        {
            // Read the rest of the input (i.e., Read the network)
            for (int i=0; i<e; i++)
            {
                int u, v;
                cin >> u >> v;

                adj_list[u].push_back(v);  // There is an edge between u and v
                adj_list[v].push_back(u);  // Omit this line for directed network
            }
        }
        void print_graph(void)
        {
            cout << endl << "Adjacency List (using STL vector) :" << endl << endl;
            for (int i=0; i<n; i++)
            {
                cout << "[ " << i << " ]\t";
                for (int j=0; j<(int)adj_list[i].size(); j++)
                    cout << adj_list[i][j] << " ";
                cout << endl;
            }
        }
        // Breadth First Search  (_ BFS _) starting from node s
        void bfs(int s)
        {
            queue<int> Q;       // using STL FIFO queue
            distance[s] = 0;    // distance(s, s) = 0
            Q.push(s);
            visited[s] = true;

            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();

                for (int i=0; i<(int)adj_list[u].size(); i++)
                {
                    int v = adj_list[u][i];
                    if (!visited[v])    // If still NOT explored
                    {
                        Q.push(v);
                        visited[v] = true;
                        distance[v] = distance[u] + 1;  // assuming cost c = 1 in each edge
                    }
                }
            }
        }
        // Print the distance vector from source s
        void print_distance(int s)
        {
            cout << endl << "Distance Vector: " << endl << endl;
            cout << "source = " << s << endl;
            for (int i=0; i<n; i++)
                cout << "d[ " << i << " ] = " << distance[i] << endl;
        }
};

int main()
{
    int n;  // Number of nodes
    int e;  // Number of edges

    // Read the number of nodes and edges
    cin >> n >> e;
    cout << "Node: " << n << " Edge: " << e << endl;

    Graph g(n, e);
    g.read_graph();     // read the topology
    g.print_graph();    // Check if the topology is read correctly

    int source = 0;     // Assume that node-0 is the source node for this search
    g.bfs(source);      // Run a bfs from source node-0
    g.print_distance(source);   // print the distance matrix having source = node-0

    return 0;
}
