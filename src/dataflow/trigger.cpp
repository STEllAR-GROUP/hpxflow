////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <unordered_map>
#include <vector>
#include <hpxflow_trigger.h>

using namespace std;


trigger::trigger(){
	
}
trigger::~trigger(){

}

template <typename F> //  Here Fn is watermark function
bool trigger(F fn) {

for (auto it = std::begin(hashmap); it!=std::end(hashmap); ++it){
	for (auto& x: hashmap[it]){
		if(fn(std::get<0>(x), std::get<1>(x), std::get<2>(x), std::get<3>(x) )){
			return true;
		}
	}
}
	return false;
}
