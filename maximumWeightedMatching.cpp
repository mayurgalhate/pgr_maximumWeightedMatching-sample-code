//=======================================================================
// Maximum Weighted Matching Example using Boost Graph Library
//=======================================================================

#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/maximum_weighted_matching.hpp>

using namespace boost;

// Edge property with weight
typedef property<edge_weight_t, float> EdgeProperty;

// Undirected graph with weighted edges
typedef adjacency_list<vecS, vecS, undirectedS, no_property, EdgeProperty> Graph;

int main() {
    const int n_vertices = 18;
    Graph g(n_vertices);

    // Add weighted edges
    add_edge(1, 2, EdgeProperty(5), g);
    add_edge(0, 4, EdgeProperty(1), g);
    add_edge(1, 5, EdgeProperty(4), g);
    add_edge(2, 6, EdgeProperty(1), g);
    add_edge(3, 7, EdgeProperty(4), g);
    add_edge(4, 5, EdgeProperty(7), g);
    add_edge(6, 7, EdgeProperty(5), g);
    add_edge(4, 8, EdgeProperty(2), g);
    add_edge(5, 9, EdgeProperty(5), g);
    add_edge(6, 10, EdgeProperty(6), g);
    add_edge(7, 11, EdgeProperty(5), g);
    add_edge(10, 11, EdgeProperty(4), g);
    add_edge(8, 13, EdgeProperty(4), g);
    add_edge(9, 14, EdgeProperty(4), g);
    add_edge(10, 15, EdgeProperty(7), g);
    add_edge(11, 16, EdgeProperty(6), g);
    add_edge(14, 15, EdgeProperty(6), g);
    add_edge(12, 13, EdgeProperty(2), g);
    add_edge(16, 17, EdgeProperty(5), g);

    // Vector to store matching result
    std::vector<graph_traits<Graph>::vertex_descriptor> mate(n_vertices);

    // Compute maximum weighted matching
    maximum_weighted_matching(g, &mate[0]);

    std::cout << "Matching size: "
              << matching_size(g, &mate[0]) << std::endl;

    std::cout << "Total weight: "
              << matching_weight_sum(g, &mate[0]) << std::endl;

    std::cout << "Matched pairs:\n";

    graph_traits<Graph>::vertex_iterator vi, vi_end;
    for (tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi) {
        if (mate[*vi] != graph_traits<Graph>::null_vertex()
            && *vi < mate[*vi]) {
            std::cout << *vi << " - "
                      << mate[*vi] << std::endl;
        }
    }

    return 0;
}
