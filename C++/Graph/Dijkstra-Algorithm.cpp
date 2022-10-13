#include<bits/stdc++.h>
using namespace std;

int main(){
    int no_nodes,no_edges,source;

    cin>>no_nodes>>no_edges;

    vector<pair<int,int>> g_edge[no_edges+1];
    int from,to,wt;
    for(int i=0;i<no_edges;i++){
        cin>>from>>to>>wt;
        g_edge[from].push_back(make_pair(to,wt));
        g_edge[to].push_back(make_pair(from,wt));
    }

    cin>>source;

    //Dijkstra program starts from here
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > min_heap;//min-heap to store pairs according to minimum distance from source. [pair => (distance , node)]

    vector<int> distTo(no_nodes+1,INT_MAX); //Stores minimum distance from source to that node

    //First initialise source node to 0 as distance from source to source is 0
    //And push the same to min_heap as pair of minimum distance from source to the destination node and destination node.
    distTo[source] = 0;
    min_heap.push(make_pair(0,source));


    //Repeat the above step till their is element in min_heap.
    while(min_heap.size()){
        int dist = min_heap.top().first;
        int prev = min_heap.top().second;
        min_heap.pop();

        //Traverse to all edges connected to the previous node and check if distance to next node is less then previous 
        //distance to the next node then it is stored in the vector and same is push into min_heap. 
        //At last vector contains minimum distance of nodes from the source.
        for(auto it=g_edge[prev].begin();it!=g_edge[prev].end();it++){
            int next = it->first;
            int nextdist = it->second;

            if(distTo[next] > dist+nextdist){
                distTo[next] = distTo[prev] + nextdist;
                min_heap.push(make_pair(distTo[next],next));
            }
        }
    }

    cout<<"Minimum distance from source to each node\nSource => Node : Distance\n";

    for(int i=0;i<no_nodes;i++){
        cout<<source<<" =>  "<<i<<"  :  "<<distTo[i]<<'\n';
    }


    return 0;
}