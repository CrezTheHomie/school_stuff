/**
    Md Mahmudul Hasan
    Gainesville, Fl

    Graph representation
        - Adjacency Matrix
        - Adjacency List (with array)
        - Adjacency List (with vector)
**/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;  // Number of nodes/ vertices
    int e;  // Number of edges

    // Read the number of nodes and edges
    cin >> n >> e;
    cout << "Node: " << n << " Edge: " << e << endl;

    //*******************************************
    // Graph representation: Adjacency Matrix
    //*******************************************
    /*
    int adj_mat[n][n];  // Assuming nodes from 0 ... (n - 1)

    // adj_mat[i][j] = 1 means that there is an edge between node-i and node-j
    // adj_mat[i][j] = 0 means that there is NO edge between node-i and node-j

    // Initialize the graph (i.e., NO edge initially)
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            adj_mat[i][j] = 0;

    // Read the rest of the input (i.e., Read the network)
    for (int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_mat[u][v] = 1;  // There is an edge between u and v
        adj_mat[v][u] = 1;  // Omit this line for directed network
    }

    // Print adjacency matrix
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << adj_mat[i][j] << " ";
        cout << endl;
    }

    // Complexity: ?
    cout << endl << "Adjacency Matrix :" << endl << endl;
    for (int i=0; i<n; i++)
    {
        cout << "[ " << i << " ]\t";
        for (int j=0; j<n; j++)
            if (adj_mat[i][j] == 1)
                cout << j << " ";
        cout << endl;
    }
    */
    //****************************************************
    // Graph representation: Adjacency List using array
    //****************************************************
    /*
    int adj_list[n][n];  // Assuming nodes from 0 ... (n - 1)
    int size[n];

    for (int i=0; i<n; i++) size[i] = 0;

    // adj_list[i][j] = v means that there is an edge between node-i and node-v

    // Read the rest of the input (i.e., Read the network)
    for (int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u][size[u] ++] = v;  // There is an edge between u and v
        adj_list[v][size[v] ++] = u;  // Omit this line for directed network
    }

    // Note the difference in the printing loop (compared to adj_mat)
    // Complexity: ?
    cout << endl << "Adjacency List (using array) :" << endl << endl;
    for (int i=0; i<n; i++)
    {
        cout << "[ " << i << " ]\t";
        for (int j=0; j<size[i]; j++)
            cout << adj_list[i][j] << " ";
        cout << endl;
    }
    */

    //********************************************************
    // Graph representation: Adjacency List using STL vector
    //********************************************************

    vector<vector <int> > adj_list(n);

    // Read the rest of the input (i.e., Read the network)
    for (int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);  // There is an edge between u and v
        adj_list[v].push_back(u);  // Omit this line for directed network
    }

    // Note the difference in the printing loop (compared to the previous two)
    // Complexity: ?
    cout << endl << "Adjacency List (using STL vector) :" << endl << endl;
    for (int i=0; i<n; i++)
    {
        cout << "[ " << i << " ]\t";
        for (int j=0; j<(int)adj_list[i].size(); j++)
            cout << adj_list[i][j] << " ";
        cout << endl;
    }

    return 0;
}
