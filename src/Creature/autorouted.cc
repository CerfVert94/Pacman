#include "autorouted.hh"

void AutoRouted::set_path(std::vector<struct Vertex::Path> paths) {
	_paths.clear();
	for(const auto &iter_path : paths) {
		if (iter_path.reversed) {
			_paths.push_back(iter_path.edge->get_vertices().back()->get_map_coordinate());
			for(int i = iter_path.edge->get_route().size() - 1; i >=0 ; i--)
				_paths.push_back(iter_path.edge->get_route()[i]->get_map_coordinate());
			_paths.push_back(iter_path.edge->get_vertices().front()->get_map_coordinate());
		}
		else {
			_paths.push_back(iter_path.edge->get_vertices().front()->get_map_coordinate());
			for(int i = 0; i < static_cast<int>(iter_path.edge->get_route().size()); i++)
				_paths.push_back(iter_path.edge->get_route()[i]->get_map_coordinate());
			_paths.push_back(iter_path.edge->get_vertices().back()->get_map_coordinate());
		}
	}
	
	//for(const auto &iter : _paths) 
	//	std::cerr << "(" << iter.x << "," << iter.y << ")" << "->";
	//std::cerr << "(end)" << std::endl;
	_index = 0;
}

bool AutoRouted::next() {
	//prev_block = cur_block;
	//cur_block = next_block;
	if(_index < static_cast<int>(_paths.size()))
	_index++;
	/*if(_reversed) 
		step(false, next_intersection, prev_intersection);
	else
		step(true, prev_intersection, next_intersection);
	//std::cerr << "==" << std::endl;
	*/
	return true;
}