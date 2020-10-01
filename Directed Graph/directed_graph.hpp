#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

/*
	the vertex class
*/
template <typename T>
class vertex {

public:
	int id; // the unique id of the vertex
	T weight; // the weight of the vertex

	vertex(int v_id, T v_weight) : id(v_id), weight(v_weight) {} 
};

/*
	the edge class
*/
template <typename T>
class edge {
 
public:
	T weight; // the weight of the vertex
	int first; // the start of vertex (directed graph.)
	int second; // the end of other vertex (directed graph.)

	edge(int e_first, int e_second, T e_weight) : first(e_first), second(e_second), weight(e_weight) {}
};

/*
	the graph class
*/
template <typename T>
class directed_graph {

private:

	vector<vertex<T>> vertice_list; // store all the vertex
	vector<edge<T>> edge_list; // store all the connected vertex 
	map<int, map<int, int> > matrix; // matrix to determine which vertex are connected by edges`

public:

	directed_graph(); //A constructor for directed_graph. The graph should start empty.
	~directed_graph(); //A destructor. Depending on how you do things, this may not be necessary.

	bool contains(const int&) const; //Returns true if the graph contains the given vertex_id, false otherwise.
	bool adjacent(const int&, const int&) const; //Returns true if the first vertex is adjacent to the second, false otherwise.

	void add_vertex(const vertex<T>&); //Adds the passed in vertex to the graph (with no edges).
	void add_edge(const int&, const int&, const T&); //Adds a weighted edge from the first vertex to the second.

	void remove_vertex(const int&); //Removes the given vertex. Should also clear any incident edges.
	void remove_edge(const int&, const int&); //Removes the edge between the two vertices, if it exists.

	size_t in_degree(const int&) const; //Returns number of edges coming in to a vertex.
	size_t out_degree(const int&) const; //Returns the number of edges leaving a vertex.
	size_t degree(const int&) const; //Returns the degree of the vertex (both in edges and out edges).

	size_t num_vertices() const; //Returns the total number of vertices in the graph.
	size_t num_edges() const; //Returns the total number of edges in the graph.

	vector<vertex<T>> get_vertices(); //Returns a vector containing all the vertices.
	vector<edge<T>> get_edges();  //Returns a vector containing all the edges.
	vector<vertex<T>> get_neighbours(const int&); //Returns a vector containing all the vertices reachable from the given vertex. The vertex is not considered a neighbour of itself.
	vector<vertex<T>> get_second_order_neighbours(const int&); // Returns a vector containing all the second_order_neighbours (i.e., neighbours of neighbours) of the given vertex.
															  // A vector cannot be considered a second_order_neighbour of itself.
	bool reachable(const int&, const int&); //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.
	bool contain_cycles(); // Return true if the graph contains cycles (there is a path from any vertices directly/indirectly to itself), false otherwise.

	vector<vertex<T>> depth_first(const int&); //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
	vector<vertex<T>> breadth_first(const int&); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.

	directed_graph<T> out_tree(const int&); //Returns a spanning tree of the graph starting at the given vertex using the out-edges. This means every vertex in the tree is reachable from the root.

	vector<vertex<T>> pre_order_traversal(const int&, directed_graph<T>); // returns the vertices in the visiting order of a pre-order traversal of the minimum spanning tree starting at the given vertex.
	vector<vertex<T>> in_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of an in-order traversal of the minimum spanning tree starting at the given vertex.
	void in_order_helper(vertex<T>&, directed_graph<T>&, vector<vertex<T>>&); // function to perform recursion on in-order traversal
	vector<vertex<T>> post_order_traversal(const int&, directed_graph<T>&); // returns the vertices in ther visitig order of a post-order traversal of the minimum spanning tree starting at the given vertex.
	void post_order_helper(vertex<T>&, directed_graph<T>&, vector<vertex<T>>&); // function to perform recursion on post-order traversal

	vector<vertex<T>> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.

};

// Define all your methods down here (or move them up into the header, but be careful you don't double up). If you want to move this into another file, you can, but you should #include the file here.
// Although these are just the same names copied from above, you may find a few more clues in the full method headers.
// Note also that C++ is sensitive to the order you declare and define things in - you have to have it available before you use it.

template <typename T>
directed_graph<T>::directed_graph() {}

template <typename T>
directed_graph<T>::~directed_graph() {}

template <typename T>
bool directed_graph<T>::contains(const int& u_id) const {
	// iterate on vertice_list and find the matching id with u_id, if found return true otherwise false
	for(vertex <T> v : vertice_list){
		if(v.id == u_id){
			return true;
		}
	}
	return false;
}

template <typename T>
bool directed_graph<T>::adjacent(const int& u_id, const int& v_id) const {
	// MUST DELETE const to prevent initialising matrix again (deleting it cause the test results to be wrong.)
	// the matrix size depends on the number of vertex in vertice_list
	int matrixSize = vertice_list.size()+1;
    vector<vector<int>> matrix(matrixSize, vector<int>(matrixSize));   

	// if there's edge connected between a vertex and other vertex that matrix index will be 1, otherwise 0
	for(edge <T> e : edge_list){
		int first = e.first;
		int second = e.second;
		int weight = e.weight;
		matrix[first][second] = 1;
	}

    // adjacency only consider outgoing edges, if it's incoming edges and not connected return false
	if(matrix[u_id][v_id] == 1){
		return true; 
	}
	return false;
 }

template <typename T>
void directed_graph<T>::add_vertex(const vertex<T>& u) {
	vertice_list.push_back(u);
}

template <typename T>
void directed_graph<T>::add_edge(const int& u_id, const int& v_id, const T& weight) {
	edge <T> e(u_id,v_id,weight); // initialise the edge object
	edge_list.push_back(e); // push the edge object to edge_list
	matrix[u_id][v_id] = 1; // automatically make the matrix[u_id][v_id] = 1 because it is connected by edge
}

template <typename T>
void directed_graph<T>::remove_vertex(const int& u_id) {
	// iterate on the vertice_list and find the matching id to u_id
	for (int i = 0; i < vertice_list.size()+1; i++) {
		if (vertice_list[i].id == u_id){
			vertice_list.erase(vertice_list.begin() + i); // delete the i-th vertex from the vector
			break;
		}
	}
}

template <typename T>
void directed_graph<T>::remove_edge(const int& u_id, const int& v_id) {
	// iterate on the edge_list;find the matching u_id with the first vertex and v_id with the second vertex
	for (int i = 0; i < edge_list.size(); i++){
		if(edge_list[i].first == u_id && edge_list[i].second == v_id){
			edge_list.erase(edge_list.begin() + i); // delete the i-th edge from the vector
			break;
		}
	}
}

template <typename T>
size_t directed_graph<T>::in_degree(const int& u_id) const {
	int in_degree_count = 0;
	for(int i=0; i < edge_list.size();i++){
		if(edge_list[i].second == u_id){ // if the edge's second (destination) is the u_id means there's incoming edges into u_id
			in_degree_count++;
		}
	}
	return in_degree_count;
 }

template <typename T>
size_t directed_graph<T>::out_degree(const int& u_id) const {
	int out_degree_count = 0;
	for(int i=0; i < edge_list.size();i++){
		if(edge_list[i].first == u_id){ // if the edge's first (start) is the u_id means there's outgoing edges out of u_id
			out_degree_count++;
		}
	}
	return out_degree_count;
}

template <typename T>
size_t directed_graph<T>::degree(const int& u_id) const {
	// Don't do in_degree(u_id) + out_degree(u_id) because it is 2 for loops
	int all_degree_count = 0;
	for(int i=0; i < edge_list.size();i++){
		if(edge_list[i].first == u_id || edge_list[i].second == u_id){ // if the start or destination is u_id means there's outgoing and incoming edges from u_id
			all_degree_count++;
		}
	}
	return all_degree_count;
 }

template <typename T>
size_t directed_graph<T>::num_vertices() const {
	return vertice_list.size();
 }

template <typename T>
size_t directed_graph<T>::num_edges() const {
	return edge_list.size();
 }

template <typename T>
vector<vertex<T>> directed_graph<T>::get_vertices() { 
	return vertice_list;
}

template <typename T>
vector<edge<T>> directed_graph<T>::get_edges() { 
	return edge_list;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::get_neighbours(const int& u_id) { 
	vector<vertex<T>> neighbours; // store the u_id neighbours

	// if we have the vertex
	if(contains(u_id)){
		// iterate on all the vertice_list
	     for(vertex <T> v : vertice_list){
			// neighbours only consider out-going edges
			// if u_id are connected with other vertex (u_id as a first vertex, v.id as second vertex)
			if(matrix[u_id][v.id] == 1){
				// push the other vertex as u_id neighbours
				neighbours.push_back(vertex<T>(v.id, vertice_list[v.id].weight));
			 }
		 }
	 }
	return neighbours; 
}

template <typename T>
vector<vertex<T>> directed_graph<T>::get_second_order_neighbours(const int& u_id) { 
	vector<vertex<T>> neighbours; // store the u_id neighbours
	vector<vertex<T>> second_neighbours; // store the u_id neighbours second neighbours
	vector<bool> visited(vertice_list.size()+1, false); // initialise all visited to false

	// if we have the vertex
	if(contains(u_id)){   
	  // get the u_id neighbours
	  neighbours = get_neighbours(u_id);
	    // iterate on u_id neighbours
	    for (vertex<T> v : neighbours) {
		   // iterate all the u_id neighbours' neighbours
		   for(int j=0; j < vertice_list.size()+1; j++){
		      // if there are connected edges, not the same node as itself and not visited
			  if(matrix[v.id][j] == 1 && j != u_id && !visited[j]){ 
				 second_neighbours.push_back(vertex<T>(j, vertice_list[j].weight)); // push all the second neighbours 
				 visited[j] = true; // mark as visited
			   }
		    }
	     }
      }
	return second_neighbours; 
 }

template <typename T>
bool directed_graph<T>::reachable(const int& u_id, const int& v_id) {
	// a tree starting from u_id 
	directed_graph<T> tree = out_tree(u_id);
	// check if the vertex exist 
	if(contains(u_id) && contains(v_id)){
		// if the tree contains v_id it means it is reachable since the out_tree starts from u_id and check all vertex that are reachable
		if(tree.contains(v_id)){
			return true;
		}
	}
	return false; 
 }

template <typename T>
bool directed_graph<T>::contain_cycles() {
	for(int i=0; i < vertice_list.size()+1; i++){
	  for(int j=0; j < vertice_list.size()+1; j++){
		  // if it is reachable from the first/second vertex to second/first vertex and it's not a self-loop return true 
		  // Note: need to have i != j because or else the vertice itself is the cycle (self-loop)
		  if(reachable(i,j) && reachable(j,i) && i != j){
			  return true;
		  }
	   }
	}
	  return false;
 }

template <typename T>
vector<vertex<T>> directed_graph<T>::depth_first(const int& u_id) {
	// Visited vector so that  a vertex is not visited more than once 
	// Initializing the vector to false as all is not visited at beginning
	int matrixSize = vertice_list.size()+1;
	vector<bool> visited(matrixSize, false); 

	// to keep track on DFS
	stack<int> DFS_stack;
	// the final result of DFS
	vector<vertex<T>> result;

	visited[u_id] = 1; // firstly mark the u_id as visited as that is the first vertex we gonna visit
	DFS_stack.push(u_id); // push u_id to the stack
	int to_visit = DFS_stack.top(); // get the top stack for next visit
	result.push_back(vertex<T>(to_visit, vertice_list[to_visit].weight)); // push the visited to result
	DFS_stack.pop(); // pop it because we already add it in the result

	while (true){ 
		for(int i=0; i < matrixSize; i++){
			// if it's connected and the second vertex is not visited, mark the second vertex as visited and push it to the stack
			if(matrix[to_visit][i] == 1 && !visited[i]){
				visited[i] = 1;
				DFS_stack.push(i);
			}
		}
		// if all are visited, stack will be empty
		if(DFS_stack.empty()){
			break;
		} else {
			to_visit = DFS_stack.top(); // next to visit is the connected vertex
			result.push_back(vertex<T>(to_visit, vertice_list[to_visit].weight)); // push the visited to result
			DFS_stack.pop();
		}
	}

	return result;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::breadth_first(const int& u_id) {
    // Visited vector so that  a vertex is not visited more than once 
	// Initializing the vector to false as all is not visited at beginning
	int matrixSize = vertice_list.size()+1;
	vector<bool> visited(matrixSize, false); 

	// to keep track on BFS
    vector<int> BFS_queue; 
	// the final result of BFS
	vector<vertex<T>> result;

	visited[u_id] = 1; // firstly mark the u_id as visited as that is the first vertex we gonna visit
    BFS_queue.push_back(u_id); // push u_id to the stack
	result.push_back(vertex<T>(u_id,vertice_list[u_id].weight)); // push the visited to result
    int to_visit;  // next node to visit

    while (!BFS_queue.empty()) { 
        to_visit = BFS_queue.front(); // BFS_queue[0]
        BFS_queue.erase(BFS_queue.begin()); // remove the to_visit from queue
  
        // for every connected vertex
        for (int i = 0; i < matrixSize; i++) { 
            if (matrix[to_visit][i] == 1 && (!visited[i])) { 
                BFS_queue.push_back(i); // Push the second vertex to the BFS_queue
				visited[i] = true; // mark the second vertex as visited
				result.push_back(vertex<T>(i,vertice_list[i].weight)); // push the visited to result
			} 
         } 
      } 

	return result;
 }

template <typename T>
directed_graph<T> directed_graph<T>::out_tree(const int& u_id) {
	// Visited vector so that  a vertex is not visited more than once 
	// Initializing the vector to false as all is not visited at beginning
    int matrixSize = vertice_list.size()+1;
	vector<bool> visited(matrixSize, false);

	directed_graph<T> tree; // new graph 
	queue<vertex<T>> out_tree; // create the queue to store the out_tree
	tree.add_vertex(vertex<T>(u_id,vertice_list[u_id].weight)); // add the first vertex, as that is the first to visit
	out_tree.push(vertex<T>(u_id,vertice_list[u_id].weight));  // push the visited to out_tree

	while(!out_tree.empty()){
		// get the next vertex to visit and remove it from the out_tree
		vertex <T> to_visit = out_tree.front();
		out_tree.pop();

		// if the vertex is not visited yet keep going
		if(!visited[to_visit.id]){
			visited[to_visit.id] = true; // mark it as visited
			for(vertex <T> n : get_neighbours(to_visit.id)){  // find the neighbours of the current vertex
			    // if the vertex is adjacent and n.id exist (just in case.)
				if(!tree.contains(n.id) && adjacent(to_visit.id, n.id)){
					 tree.add_vertex(vertex<T>(n.id, vertice_list[u_id].weight)); // add the vertex
					 tree.add_edge(to_visit.id, n.id, vertice_list[u_id].weight); // add the edges 
					 out_tree.push(n); // push it to the out_tree 
				}
			}
		}
	}
	return tree; 
}

// https://edstem.org/courses/3890/discussion/228585
template <typename T>
vector<vertex<T>> directed_graph<T>::pre_order_traversal(const int& u_id, directed_graph<T> mst) {
	// Visited vector so that  a vertex is not visited more than once 
	// Initializing the vector to false as all is not visited at beginning
	int matrixSize = mst.vertice_list.size()+1;
	vector<bool> visited(matrixSize, false);

	vector<vertex<T>> mst_vertices = mst.get_vertices(); // get the mst vertice_list
	vector<vertex<T>> result; // final result

	map<int, map<int, int> > mst_matrix; // we can't use the class matrix, we need to use the mst matrix
	stack<T> s; // to keep track on pre-order
	bool has_children = 0; // the counter so that in the end we know there's no more children to visit

    // initialise the mst matrix
	for (edge<T> e : mst.get_edges()) {
		mst_matrix[e.first][e.second] = 1;
    }

	visited[u_id] = true; // firstly mark the u_id as visited as that is the first vertex we gonna visit
	s.push(u_id); // push u_id to the stack
	int to_visit = u_id; // variable used to keep track on which node are we in, next to visit
	result.push_back(vertex<T>(to_visit, mst_vertices[to_visit].weight));

     while (true){ 
		// iterate and check if it's visited
		for(int i=0; i < matrixSize; i++){
			// cout << to_visit << " visit " << i << endl;
			// if it is not visited and connected, mark the second vertex as visited, push it to stack for next to-visit and has_children true
			if(mst_matrix[to_visit][i] == 1 && !visited[i]){
				visited[i] = 1;
				s.push(i);
				has_children = true;
				break;
			}
		}

		// if we reach the u_id (parent) and all the children is visited
		if(to_visit == u_id && !has_children){
			break;
		} 
		// if we reach to a node that doesn't have children and it's not the u_id (starting point) go back up one level 
		else if(!has_children && to_visit != u_id){
			s.pop();
			to_visit = s.top();
			continue;
		} else { // if the node has children go to the children' childrens
			to_visit = s.top();
			result.push_back(vertex<T>(to_visit, vertice_list[to_visit].weight));
		}
		// initialise the has_children back to false on every iteration
		has_children = false;
	}

	 return result;   
}

template <typename T>
vector<vertex<T>> directed_graph<T>::in_order_traversal(const int& u_id, directed_graph<T>& mst) {
	vector<vertex<T>> result; // the final in-order result 
	vector<vertex<T>> mst_vertices = mst.get_vertices(); // get mst vertices

	vertex<T> to_visit(u_id, mst_vertices[u_id].weight); // start from the parent first
	in_order_helper(to_visit, mst, result); // perform recursion with in-order helper function

	return result;
}

template <typename T>
void directed_graph<T>::in_order_helper(vertex<T>& to_visit, directed_graph<T>& mst, vector<vertex<T>>& in_order_list){

	// if there's no more children to visit, program finished return result
	if (&to_visit == NULL){
		return;
	}

	// get neighbours of the current to visit node
	vector<vertex<T>> neighbours = mst.get_neighbours(to_visit.id);

	// if no more children push the current node, push the current to visit to result and go back up one level
	if (neighbours.empty()){
		in_order_list.push_back(to_visit);
		return;
	}

	vertex <T> left = neighbours.at(0);
	// if it's lesser than 2 neighbours, assume that all is on the left side 
	if (neighbours.size() < 2){
		in_order_helper(left, mst, in_order_list);
		in_order_list.push_back(to_visit);
	}
	// otherwise we go from Left, Data (to-visit) and Right (In-order traversal)
	else {
		vertex <T> right = neighbours.at(1);
		in_order_helper(left, mst, in_order_list); // push left-node
		in_order_list.push_back(to_visit); // push data (to-visit)
		in_order_helper(right, mst, in_order_list); // push right-node
	}
}


template <typename T>
vector<vertex<T>> directed_graph<T>::post_order_traversal(const int& u_id, directed_graph<T>& mst) { 
	vector<vertex<T>> result; // the final in-order result 
	vector<vertex<T>> mst_vertices = mst.get_vertices(); // get mst vertices

    vertex<T> to_visit(u_id, mst_vertices[u_id].weight); // start from the parent first
	post_order_helper(to_visit, mst, result); // perform recursion with post-order helper function

	return result;
}

template <typename T>
void directed_graph<T>::post_order_helper(vertex<T>& to_visit, directed_graph<T>& mst, vector<vertex<T>>& post_order_list)
{
	// if there's no more children to visit, program finished return result
	if (&to_visit == NULL){
		return;
	}
	
	// get neighbours of the current to visit node
	vector<vertex<T>> neighbours = mst.get_neighbours(to_visit.id);

	// if no more children push the current node, push the current to visit to result and go back up one level
	if (neighbours.empty()){
		post_order_list.push_back(to_visit);
		return;
	}

	vertex <T> left = neighbours.at(0);
	// if it's lesser than 2 neighbours, assume that all is on the left side 
	if (neighbours.size() < 2){
		post_order_helper(left, mst, post_order_list);
		post_order_list.push_back(to_visit);
	}
	// otherwise we go from Left, Right and Data (to-visit) (Post-order traversal)
	else {
		vertex <T> right = neighbours.at(1);
		post_order_helper(left, mst, post_order_list); // push left-node
		post_order_helper(right, mst, post_order_list); // push right-node 
		post_order_list.push_back(to_visit); // push data (to-visit)
	}
}

// https://edstem.org/courses/3890/discussion/233596
template <typename T>
vector<vertex<T>> directed_graph<T>::significance_sorting() { 
	// Bubble-sort
    vector<vertex<T>> sorted_vertices = vertice_list;
	for(int i=0; i < sorted_vertices.size();i++){		
		for(int j=i+1; j < sorted_vertices.size(); j++){
			// descending order
			if(sorted_vertices[i].weight < sorted_vertices[j].weight){
				vertex <T> temp  = sorted_vertices[i];
				sorted_vertices[i] = sorted_vertices[j];
				sorted_vertices[j] = temp;
			}
		}
	}	
	return sorted_vertices; 
}

#endif