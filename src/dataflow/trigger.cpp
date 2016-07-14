////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>
// #include <hpxflow_trigger.h>

using namespace std;

class trigger{
	
	std::unordered_map<int, std::vector<std::tuple< int, int, int, int>> > hashmap;

	trigger(){
	
	}
	
	~trigger(){

	}

	template <typename F> //  Here Fn is watermark function
	bool run_trigger(F fn) {

	for (auto it = std::begin(hashmap); it!=std::end(hashmap); ++it){

		// Make it wright

		// for (auto& x: hashmap[it]){
		// 	if(fn(std::get<0>(x), std::get<1>(x), std::get<2>(x), std::get<3>(x) )){
		// 		return true;
		// 	}
		// }
	}
		return false;
	}
};

