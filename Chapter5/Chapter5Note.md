VietNH:
- It is recommended to use a well-designed graph data type as the foundation for your application: LEDA or Boost. 
- BFS uses two Boolean arrays: 'discovered' and 'processed'
- The exact behavior of BFS depends on the functions 'process_vertex_early()', 'process_vertex_late()' and 'process_edge()'

HuyDX:
- While BFS based on parent arrays to solve problems related to path-finding, DFS based on exit_time and entry_time when access a node, to solve problem which needed to know traverse order (such as topology sort,...)
- DFS partitions the edges of an undirected graph into exactly two classes: *tree_edges* and *back_edges*. *back_edges* are edges which other endpoint is an parent of the vertex being expanded, to form a cycle.
