////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <unordered_map>
#include <vector>
#include <hpxflow_window.h>

using namespace std;


window::window(){
	
}
window::~window(){

}

template <typename F>
void window::createWindow(int index, F fn){
	buffer_window = buffer_intermediate;
	// unordered_map
	// std::pair<,double> myshopping ("baking powder",0.3);
	for(int i = 0; i  < buffer_window.size(); i++) {
		// hashmap.insert(std::get<0>(buffer_window[0]), buffer_window[i]);
		hashmap.insert(std::make_pair<int, vector<tuple< int, int, int, int>>>(std::get<0>(buffer_window[0]), buffer_window[i]));
	}
	// hashmap.insert(std::get<index>(buffer_window), buffer_window);
	// return *this;
}

unordered_map<int, vector<tuple<int, int, int, int>> > window::retrieveWindow(){
	return hashmap;
}
int window::windowSize(){
	return hashmap.size();
}
