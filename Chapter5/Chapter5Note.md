VietNH:
- It is recommended to use a well-designed graph data type as the foundation for your application: LEDA or Boost. 
- BFS uses two Boolean arrays: 'discovered' and 'processed'
- The exact behavior of BFS depends on the functions 'process_vertex_early()', 'process_vertex_late()' and 'process_edge()'
- DFS organzies vertices by entry/exit time, and edges into tree and back edges. This organization is what gives DFS its real power. 

HuyDX:
- While BFS based on parent arrays to solve problems related to path-finding, DFS based on exit_time and entry_time when access a node, to solve problem which needed to know traverse order (such as topology sort,...)
- DFS partitions the edges of an undirected graph into exactly two classes: *tree_edges* and *back_edges*. *back_edges* are edges which other endpoint is an parent of the vertex being expanded, to form a cycle.

Question:

Solutions
  - 5.1
  - 5.3: if exist two differences path bw 2 vertices in a tree, it will form a cycle
  - 5.5: ?? -> Problem of vertex coloring with low degree. Is NP complete, reference as from page 544. These methods vary in how the next vertex is selected and how it is assigned a color. -> just think about backtracking, maintain an arrays of color array
     ```
      int* colorarr[N];
      ...
      //traverse by BFS and testing all edge
      if(color[u] == color[v]) {
        coloarr[u].pop();
        backtrack; 
      }
     ```
  - 5.7:

  - 5.6 (a) A tree with v as root and n-1 remaining nodes as leaves. 
        (b) A linked-list-like chain of nodes, starting from v 
        (c) 
  - 5.8 (a) Convert from an adjacency matrix to adjacency lists 
            For each row i
                If M[i,j]=1
                    Insert a new edge for the list of node i
            Time complexity: O(n^2)
        (b) Convert from an adjacency list to an incidence matrix 
            An incidence matrix M has a row for each vertex and a column for each edge, such that M[i,j]=1 if vertex i is part of edge j, otherwise M[i,j]=0.
            Algorithm:
            - Init the matrix M with n rows for n vertices
            - col = 0
            - For each row i in adjacency list
                For each edge (to k) in this list {
                  M[i, col] = 1
                  M[k, col] = 1
                  Remove this edge from the list of vertex k 
                  col ++ 
                }
            Time complexity: O(mn)
        (c) Convert from an incident matrix to adjacency lists 
            - Init the adjacency list A with n rows for n vertices 
            - For j from 1 to number of edges  
                    Find i, k such that M[i,j] = M[k,j] = 1
                    Add edge (i,k) to adjacency list of vertex i
                    Add edge (k,i) to adjacency list of vertex k
           Time complexity O(m)
