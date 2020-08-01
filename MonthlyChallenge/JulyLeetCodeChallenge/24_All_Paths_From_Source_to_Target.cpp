Given a directed acyclic graph of N nodes. Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

 

Constraints:

    The number of nodes in the graph will be in the range [2, 15].
    You can print different paths in any order, but you should keep the order of nodes inside one path.

Solutions:

class Solution {

    void dfs(vector<vector<int>>& graph ,
             vector<vector<int>>& paths ,
             vector<int>& path,
             int src,
             int dest) {
        
        path.push_back(src) ;
        
        if(src == dest){
            paths.push_back(path) ;
            return ;
        }
        
        for(int node : graph[src]){
            dfs(graph , paths , path , node , dest) ;
            path.pop_back() ;
        }
        
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int src = 0 ;
        int dest = graph.size()-1 ;
        vector<vector<int>> paths ;
        vector<int>path ;
        
        
        if(dest == 0) {
            //no nodes are present 
            return paths ;
        }
        
        dfs(graph , paths , path , src , dest) ;
        
        return paths ;
        
    }
};

Time Complexity - O(nodes)
Space Complexity - O(n)[vector]
