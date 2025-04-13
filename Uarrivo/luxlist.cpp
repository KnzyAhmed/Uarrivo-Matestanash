#include "luxlist.h"

luxlist::luxlist(){
    head = nullptr;
    count = 0;
}

void luxlist::insert(luxurious l, personal_info p, int location){
    luxNode* newnode = new luxNode;
    newnode->car = l;
    newnode->driver = p;
    newnode->location = location;
    if(head == nullptr){
        head = newnode;
        count++;
    }else{
        luxNode* curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        curr->next = newnode;
        count++;
    }
};

void luxlist::deletecar(string driversname){
    luxNode* curr = head;
    luxNode* prev;
    if(head->driver.getname() == driversname){
        head = head->next;
        delete curr;
        count--;
        return;
    }else{
        while(curr->driver.getname() != driversname && curr->next !=nullptr){
            if(curr->driver.getname() == driversname){
                prev->next = curr->next;
                delete curr;
                count--;
            }
            prev = curr;
            curr = curr->next;
        }
        if(curr->driver.getname() == driversname){
            prev->next = curr->next;
            delete curr;
            count--;
        }
    }
    return;
};

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int luxlist:: minDistance(int shortest_dist[], bool visited[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < 6; v++)
        if (visited[v] == false && shortest_dist[v] <= min)
            min = shortest_dist[v], min_index = v;

    return min_index;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
int luxlist::dijkstra(int graph[6][6], int location, int destination)
{
    int shortest_dist[6]; // The output array. dist[i] will hold the shortest
    // distance from src to i

    bool visited[6]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < 6; i++)
        shortest_dist[i] = INT_MAX, visited[i] = false;

    // Distance of source vertex from itself is always 0
    shortest_dist[location] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < 6 - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(shortest_dist, visited);

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < 6; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && shortest_dist[u] != INT_MAX
                && shortest_dist[u] + graph[u][v] < shortest_dist[v])
                shortest_dist[v] = shortest_dist[u] + graph[u][v];
    }

    // print the constructed distance array
    //printSolution(dist, V);
    return shortest_dist[destination];
}

luxurious luxlist::returnnearest(int location, int graph[6][6]){
    luxNode* curr = head;
    int index = 0;
    int locationlist[2];
    int loca;
    int pathslist[2];
    while(curr!=nullptr){
        loca = curr->location;
        locationlist[index] = curr->location;
        curr = curr->next;
        index++;
    }
    for(int i = 0;i<count;i++){
       pathslist[i] = dijkstra(graph,location,locationlist[i]);
       cout << pathslist[i] <<" ";
    }
    int min = 100;
    for(int i = 0;i<count;i++){
        if(pathslist[i] < min){
            min = pathslist[i];
        }
    }
    curr = head;
    while(curr!=nullptr){//MISTAKE; COMPARING DISTANCE TO LOCATION
        if(dijkstra(graph,location,curr->location) == min){
            return curr->car;
        }
        curr = curr->next;
    }
    luxurious empty;
    return empty;
}

personal_info luxlist:: returndriver(int location, int graph[6][6]){
    luxNode* curr = head;
    int index = 0;
    int locationlist[2];
    int loca;
    int pathslist[2];
    while(curr!=nullptr){
        loca = curr->location;
        locationlist[index] = curr->location;
        curr = curr->next;
        index++;
    }
    for(int i = 0;i<count;i++){
       pathslist[i] = dijkstra(graph,location,locationlist[i]);
       cout << pathslist[i] <<" ";
    }
    int min = 100;
    for(int i = 0;i<count;i++){
        if(pathslist[i] < min){
            min = pathslist[i];
        }
    }
    curr = head;
    while(curr!=nullptr){//MISTAKE; COMPARING DISTANCE TO LOCATION
        if(dijkstra(graph,location,curr->location) == min){
            return curr->driver;
        }
        curr = curr->next;
    }

    personal_info empty;
    return empty;
}

int luxlist::returlocation(int location, int (*graph)[6]){
    luxNode* curr = head;
    int index = 0;
    int locationlist[2];
    int loca;
    int pathslist[2];
    while(curr!=nullptr){
        loca = curr->location;
        locationlist[index] = curr->location;
        curr = curr->next;
        index++;
    }
    for(int i = 0;i<count;i++){
       pathslist[i] = dijkstra(graph,location,locationlist[i]);
       cout << pathslist[i] <<" ";
    }
    int min = 100;
    for(int i = 0;i<count;i++){
        if(pathslist[i] < min){
            min = pathslist[i];
        }
    }
    curr = head;
    while(curr!=nullptr){//MISTAKE; COMPARING DISTANCE TO LOCATION
        if(dijkstra(graph,location,curr->location) == min){
            return curr->location;
        }
        curr = curr->next;
    }
    return 7;
}
