#include "directed_graph.hpp"

int main() {        
    directed_graph<int> g;

	if(g.num_vertices() != 0) return 1;
    if(g.num_edges() != 0) return 1;

    // VERTICES
	// the vertex object v1 has an id (i.e., A) and a int-typed weight (i.e. 1.25)
	// A = 0; B = 1; C = 2; D = 3; E = 4;
	vertex<int> v1(0, 800); 
    vertex<int> v2(1, 3000); 
	vertex<int> v3(2, 400);
	vertex<int> v4(3, 710);
    vertex<int> v5(4, 221); 
	vertex<int> v6(5, 300);  
	vertex<int> v7(6, 570);
	vertex<int> v8(7, 2100);
	vertex<int> v9(8, 1300);
	vertex<int> v10(9, 471);

    // adding vertex
	g.add_vertex(v1);
	g.add_vertex(v2);
	g.add_vertex(v3);
    g.add_vertex(v4);
	g.add_vertex(v5);
	g.add_vertex(v6);
	g.add_vertex(v7);
	g.add_vertex(v8);
	g.add_vertex(v9);
	g.add_vertex(v10);

    // EDGE
    // A = 0; B = 1; C = 2; D = 3; E = 4;
	// adding edge 
	g.add_edge(6, 4, 6);
	g.add_edge(1, 4, 7);
	g.add_edge(4, 2, 6);
	g.add_edge(4, 5, 9);
	g.add_edge(2, 1, 7);
	g.add_edge(2, 3, 6);
    g.add_edge(6, 8, 7);
	g.add_edge(8, 7, 7);

	// ADJACENCCY
    cout << "Adjacency" << endl;
    cout << g.adjacent(0,2) << endl;
    cout << g.adjacent(2,0) << endl;

    // DEGREE
    cout << "IN-degree" << endl;
    cout << g.in_degree(1) << endl;
    cout << "OUT-degree" << endl;
    cout << g.out_degree(1) << endl;
    cout << "ALL-degree" << endl;
    cout << g.degree(1) << endl;

	// NEIGHBOURS
	cout << "Neighbours" << endl;
	vector<vertex<int>> neighbours = g.get_neighbours(1);
	for (vertex<int> v : neighbours) {
	 	cout << "(" << v.id << ", " << v.weight << ") ";
	}
	cout << endl;

    cout << "All 2nd-order neighbours of 1: ";
	vector<vertex<int>> second_neighbour_list1 = g.get_second_order_neighbours(1);
	for (vertex<int> snb : second_neighbour_list1) {
	 	cout << "(" << snb.id << ", " << snb.weight << ") ";
	}
	cout << endl;

    // DFS
    cout << "DFS" << endl;
	vector<vertex<int>> dfs = g.depth_first(1);
	for (vertex<int> v : dfs) {
	 	cout << "(" << v.id << ", " << v.weight << ") ";
    }
	cout << endl;

    // BFS
    cout << "BFS" << endl;
	vector<vertex<int>> bfs = g.breadth_first(1);
	for (vertex<int> v : bfs) {
	 	cout << "(" << v.id << ", " << v.weight << ") ";
    }
	cout << endl;

	// Reachable
	cout << "Reachable" << endl;
	cout << g.reachable(2,1) << endl;
	cout << g.reachable(1,2) << endl;
	cout << g.reachable(0,1) << endl;
	cout << g.reachable(1,0) << endl;

	// Cycles
	cout << "Contain Cycle" << endl;
	bool cycle_result = g.contain_cycles();
	cout << cycle_result << endl;

	// Sorting
	cout << "Sorting" << endl;
	vector<vertex<int>> sorted = g.significance_sorting();
    for (vertex<int> v : sorted) {
	 	cout << "(" << v.id << ", " << v.weight << ") ";
	}
	cout << endl;

	// Out_tree
	cout << "Out-tree" << endl;
	directed_graph<int> g_out = g.out_tree(6);
     for (vertex<int> v : g_out.get_vertices()) {
	 	cout << "(" << v.id << ", " << v.weight << ") ";
	}
	cout << endl;

	// Pre-order traversal
	cout << "Pre-order traversal" << endl;
	vector<vertex<int>> pre_order = g.pre_order_traversal(6,g_out);
	 for (vertex<int> v : pre_order) {
	 	cout << "(" << v.id << ", " << v.weight << ") ";
	}
	cout << endl;

	// In-order traversal
	cout << "In-order traversal" << endl;
	vector<vertex<int>> in_order = g.in_order_traversal(6,g_out);
	   for (vertex<int> v : in_order) {
	 	cout << "(" << v.id << ", " << v.weight << ") ";
	}
	cout << endl;

	// Post-order traversal
	cout << "Post-order traversal" << endl;
	vector<vertex<int>> post_order = g.post_order_traversal(6,g_out);
	   for (vertex<int> v : post_order) {
	 	cout << "(" << v.id << ", " << v.weight << ") ";
	}
	cout << endl;

    return 0;
}