#include<bits/stdc++.h>
using namespace std;


int main(){
    int no_nodes,no_edges;
    int inf = INT_MAX;

    cin>>no_nodes>>no_edges;
    vector<vector<int>> edg(no_nodes,vector<int>(no_nodes,inf));

    vector<vector<int>> dist(no_nodes,vector<int>(no_nodes,inf));

    for(int i=0;i<no_edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edg[u][v] = wt;
    }
    
    //Floyd-Warshall ALgorithm starts here.
    //First all the edges are copied to the distance matrix.
    for(int i=0;i<no_nodes;i++)
        for(int j=0;j<no_nodes;j++)
            dist[i][j] = edg[i][j];


    //First iteration is to consider all the intermediate vertices.
    for(int k = 0; k < no_nodes; k++){
        //Second iteration is to take every vertex as source.
        for(int i = 0; i < no_nodes; i++){
            //Third iteration is to take every vertex as destination.
            for(int j = 0; j < no_nodes; j++){
                //If vertex k lies in the shortest path from i to j then the distance is updated.
                if(dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != inf
                        && dist[i][k] != inf))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    cout<<"Minimumm distance between all pair of vertices\n";
    for(int i=0;i<no_nodes;i++){
        for(int j=0;j<no_nodes;j++){
            if (dist[i][j] == inf)
                cout << "INF"<<"     ";
            else
                cout << dist[i][j]<<"     ";
        }
        cout<<"\n";
    }

    return 0;
}