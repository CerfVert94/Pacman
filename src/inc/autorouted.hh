#pragma once
#include <vector>
#include <list>
#include "block.hh"
#include "vertex.hh"
#include "edge.hh"

class AutoRouted {
public:
    AutoRouted(){}
    ~AutoRouted(){}
    void set_path(std::vector<struct Vertex::Path> paths);
    const std::vector<sf::Vector2i>& get_path() const {return _paths;}
    
    bool prev();
    bool next();
    bool step(bool bUp, Block *&front, Block *&back);
    bool synchro(sf::Vector2i pos);
    bool synchro(int x, int y);
    bool is_on_front_intersection() const;
    bool is_on_back_intersection() const;
    //sf::Vector2i get_prev_pos() const {return prev_block->get_map_coordinate();}
    sf::Vector2i get_cur_pos() const {return _paths[_index];}
    //sf::Vector2i get_next_pos() const {return next_block->get_map_coordinate();}
    //sf::Vector2i get_prev_intersection() const {return prev_intersection->get_map_coordinate();}
    //sf::Vector2i get_cur_intersection() const {return cur_intersection->get_map_coordinate();}
    //sf::Vector2i get_next_intersection() const {return next_intersection->get_map_coordinate();}
private:
    int _index;
    std::vector<sf::Vector2i> _paths;/*
    //std::vector<struct Vertex::Path> _paths;
    //std::vector<struct Vertex::Path>::iterator _vertex_it;
    //std::vector<Block *>::iterator _edge_it;
    Edge *_cur_edge;
    bool _reversed;*/
    Block *prev_block;
    Block *prev_intersection;
    Block *cur_block;
    Block *cur_intersection;
    Block *next_block;
    Block *next_intersection;
};