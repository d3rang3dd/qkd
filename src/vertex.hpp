#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>

#include "id.hpp"
#include "common.hpp"

class Vertex;

using VertexId = Id< Vertex, dclr::IdRep >;
//static VertexId VERTEX_INVALID {-1};

class Vertex
{
    friend class Edge;
    template <typename NetworkModel>
        friend class QKD_Topology;
    friend std::ostream& operator<< ( std::ostream&, const Vertex& );

    using id_type = VertexId;
    
    private:

        VertexId id;
        static inline VertexId last_vertex_id {0};
        // inline, т.к. запрещена инициализация static-полей

        int num_adj_edges = 0;
        
        Vertex(); 

    public:
    
        VertexId getVertexId();
        static VertexId getLastVertexId();
    
        bool operator== ( const Vertex& );
};

std::ostream& operator<< ( std::ostream&, const Vertex& );

#endif  // VERTEX_HPP
