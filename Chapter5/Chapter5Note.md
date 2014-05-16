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
