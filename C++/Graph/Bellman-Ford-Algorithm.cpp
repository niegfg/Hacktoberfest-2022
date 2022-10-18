#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int first,int second,int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int no_nodes,no_edges;

    cin>>no_nodes>>no_edges;
    vector<node> nodes;

    for(int i=0;i<no_edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        nodes.push_back(node(u,v,wt));
    }

    int source,flag = 1;
    cin>>source;

    //Bellman Ford starts here
    vector<int> minDist(no_edges+1,INT_MAX);//Stores minimum distance from source to that node
    minDist[source] = 0;

    //Number of iteration is number-of-nodes - 1 because longest path that is needed to connect all the nodes is   number-of-nodes - 1 edges.
    //In every iteration, for each node relaxation is done and the edges needed to connect all the nodes with minimum distance is done.
    for(int i=1;i<=no_nodes-1;i++){
        for(auto it:nodes){
            if(minDist[it.u] + it.wt < minDist[it.v]){
                minDist[it.v] = minDist[it.u] + it.wt;
            }
        }
    }

    //After doing number-of-nodes - 1 iteration if again the minimum distance decreases then it indicates that there is a negative cycle.
    for(auto it:nodes){
        if(minDist[it.u] + it.wt < minDist[it.v]){
            cout<<"Negative Cycle\n";
            flag = 0;
        }
    }

    if(flag){
        cout<<"Minimum distance from source to each node\nSource => Node : Distance\n";
        for(int i=0;i<no_nodes;i++){
            cout<<source<<" =>  "<<i<<"  :  "<<minDist[i]<<'\n';
        }
    }

    return 0;
}