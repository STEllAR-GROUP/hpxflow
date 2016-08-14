////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef HPXFLOWWINDOW_H
#define HPXFLOWWINDOW_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace hpx{
	namespace flow{
		class window{
			window(){
				
			}
			~window(){

			}

			template <typename F>
            void createWindow(int index, F fn){
			}

			unordered_map<int, vector<tuple<int, int, int, int>> > retrieveWindow(){}
			
			int windowSize(){}
		};
	}
}

#endif