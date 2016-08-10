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
#include <utility>



#include <regex>
#include <map>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <string>

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits> 
#include <set>
#include <tuple>
#include <functional>
#include <utility>
#include <algorithm>
#include <iterator>
#include <functional>
#include <unordered_map>
// #include <hpxflow_window.h>

using namespace std;

class window{

	// vector<tuple<int, int, int, int>> buffer_intermediate;
	// vector<tuple<int, int, int, int>> buffer_window;
	// unordered_map<int, vector<tuple< int, int, int, int>> > hashmap;

	vector<tuple<int, int, int, int>> window_intermediate;
	vector<vector<tuple<int, int, int, int>>> fixed_window;
	vector<int> ifpresent;

	window(vector<tuple<int, int, int, int>> buffer){
		window_intermediate = buffer;
	}
	~window(){
	}

	void sortBuffer(){
		sort(window_intermediate.begin(), window_intermediate.end(),
       		[](const tuple<int, int, int, int>& a,
       		const tuple<int,int, int, int>& b) -> bool
       		{
        		return std::get<2>(a) > std::get<2>(b);
       		});
	}

	vector<vector<tuple<int, int, int, int>>> fixedWindow(){
		vector<tuple<int, int, int, int>> intermediate;
		vector<vector<tuple<int, int, int, int>>> output;
		vector<int> ifpresent;
		int ele;
		for (int i = 0; i < 100; i++) {
			ele = std::get<2>(window_intermediate[i]);
			intermediate.push_back(window_intermediate[i]);
			if(!(std::find(ifpresent.begin(), ifpresent.end(), ele) != ifpresent.end())) {
				ifpresent.push_back(ele);
				cout << "Element is: " << ele << endl;
				for(int n = i+1; n < 100; n++){
					if(ele == std::get<2>(window_intermediate[n])) {
						intermediate.push_back(window_intermediate[n]);
					}
				}
				output.push_back(intermediate);
				intermediate.clear();
			}
		}
		return output;
	}

	// unordered_map<int, vector<tuple<int, int, int, int>> > retrieveWindow(){
	// 	return hashmap;
	// }
	int windowSize(){
		return fixed_window.size();
	}
};


