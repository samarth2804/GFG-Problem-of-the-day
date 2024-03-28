# City With the Smallest Number of Neighbors at a Threshold Distance #
# Problem Link: https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

class Solution {
  public:
    // Function to implement Dijkstra's algorithm to find the shortest distance
    // from source node to all other nodes
    int dijkstra(int n, vector<vector<pair<int, int>>>& graph, int k, int src) {

        // Initializing a queue for BFS traversal
        priority_queue<int> q;
        q.push(src);

        // Initializing a vector to store the minimum distance from the source
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // BFS traversal
        while (!q.empty()) {
            int node = q.top();
            q.pop();

            // Updating the minimum distance for each neighbor node
            for (auto x : graph[node]) {
                int nbr = x.first;
                int wt = x.second;
                if (dist[nbr] > dist[node] + wt) {
                    dist[nbr] = dist[node] + wt;
                    q.push(nbr);
                }
            }
        }

        // Counting the number of cities within the distance threshold
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= k)
                c++;
        }
        return c;
    }

    // Function to find the city with the minimum number of cities within
    // the distance threshold
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Initializing a graph using adjacency list representation
        vector<vector<pair<int, int>>> graph(n);

        // Adding the edges to the graph
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        // Initializing a vector to store the number of cities within the distance
        // threshold
        vector<int> dis(n, 0);

        // Finding the number of cities within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            dis[i] = dijkstra(n, graph, distanceThreshold, i);
        }

        // Finding the city with the minimum number of cities within the distance
        // threshold
        int ans = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (ans >= dis[i]) {
                ans = dis[i];
                idx = i;
            }
        }
        return idx;
    }
};
