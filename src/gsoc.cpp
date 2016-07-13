////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

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

using namespace std;

// namespace hpx
// {
// 	namespace flow{

		class hpxflow{

			// std::string buffer;
			std::string strm_;
			std::string data;
			string buffer, inter_buffer;
			// std::map<std::string, std::string> buffer_test;
			// std::map<std::string, std::string> buffer_intermediate;
			vector<tuple<int, int, int, int>> buffer_test;
			vector<tuple<int, int, int, int>> buffer_intermediate;

            char c;

			unordered_map<int, vector<tuple< int, int, int, int>> > hashmap;
			vector<tuple<int, int, int, int>> buffer_window;

            int length;

		public:
			
            hpxflow(vector<tuple< int, int, int, int>> f) { //This constructor simply reades file input
            	buffer_test = f;
            	buffer_intermediate = buffer_test;
			}

            hpxflow &characterOperation(char character, char replace_with){
                string app;
                for(int i = 0; i < strlen(buffer.c_str()); i++){
                    if(buffer[i] == character){

                        app = app + replace_with;

                    } else{

                        app = app + buffer[i];

                    }
                }
                // }
                buffer = app;
                return *this;
            }

            hpxflow &write_to_file(string filename){
                std::ofstream out(filename);
                out << buffer;
                out.close();
                return *this;
            }

            template <typename T, typename V>
            void insert_Item( T key, V value ) {

                // Implement hpx::atomic
                hashmap.insert(make_pair(key, V(value)));

            }

            template <typename T>
            bool remove_Item( T key ) {
                hashmap.erase(key);
            }

            template <typename T, typename V>            
            V get_Item( T key ) {
                // template<typename T, typename V> // Check for some work around
                std::unordered_map<int, int>::const_iterator got = hashmap.find(key);
                return got->second;
            }

            template <typename F>
            void window(int index, F fn){
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

			template <typename V, typename X>
			hpxflow &apply(V fn, X xn){
				while(xn()){
					fn();
				}
				return *this;
			}


    //         // template< typename F >
    //         // Optimize this thing !! Dirty Code !!
    //         hpxflow &filter(string f, int value, int index){
    //         	std::map<std::string, std::string> mp;
    //         	switch(f.size()) {
				//    case 3 :
				//       if(f[0] == 'g'){
				//       	for (std::map<string, string>::iterator it = buffer_intermediate.begin(); it != buffer_intermediate.end(); ++it) {
    // 						if(index == 0) {
    // 							if(grt(std::stoi(it->first), value)){
    // 								mp[it->first] = it->second;
    // 							}
    // 						} else if(index == 1){
    // 							if(grt(std::stoi(it->second), value)){
    // 								mp[it->first] = it->second;
    // 							}
    // 						}
    // 					}
    // 					buffer_intermediate.clear();
    // 					buffer_intermediate = mp;

				//       } else if(f[0] == 'l') {

				//       	for (std::map<string, string>::iterator it = buffer_intermediate.begin(); it != buffer_intermediate.end(); ++it) {
    // 						if(index == 0) {
    // 							if(lst(std::stoi(it->first), value)){
    // 								mp[it->first] = it->second;
    // 							}
    // 						} else if(index == 1){
    // 							if(lst(std::stoi(it->second), value)){
    // 								mp[it->first] = it->second;
    // 							}
    // 						}
    // 					}
    // 					buffer_intermediate.clear();
    // 					buffer_intermediate = mp;

				//       } else {
				//       	cout << "Wrong Function passed" << endl;
				//       }
				//       break;
				//    case 5 :
				//    	  	for (std::map<string, string>::iterator it = buffer_intermediate.begin(); it != buffer_intermediate.end(); ++it) {
    // 						if(index == 0) {
    // 							if(equal(std::stoi(it->first), value)){
    // 								mp[it->first] = it->second;
    // 							}
    // 						} else if(index == 1){
    // 							if(equal(std::stoi(it->second), value)){
    // 								mp[it->first] = it->second;
    // 							}
    // 						}
    // 					}
    // 					buffer_intermediate.clear();
    // 					buffer_intermediate = mp;
				//       break;
				//    case 9 :
				//       if(f[0] == 'g'){
				//       	for (std::map<string, string>::iterator it = buffer_intermediate.begin(); it != buffer_intermediate.end(); ++it) {
    // 						if(index == 0) {
    // 							if(grt_equal(std::stoi(it->first), value)){
    // 								mp[it->first] = it->second;
    // 							}
    // 						} else if(index == 1){
    // 							if(grt_equal(std::stoi(it->second), value)){
    // 								mp[it->first] = it->second;
    // 							}
    // 						}
    // 					}
    // 					buffer_intermediate.clear();
    // 					buffer_intermediate = mp;

				//       } else if(f[0] == 'l') {
				//       	for (std::map<string, string>::iterator it = buffer_intermediate.begin(); it != buffer_intermediate.end(); ++it) {
    // 						if(index == 0) {
    // 							if(lst_equal(std::stoi(it->first), value)){
    // 								mp[it->first] = it->second;
    // 							}
    // 						} else if(index == 1){
    // 							if(lst_equal(std::stoi(it->second), value)){
    // 								mp[it->first] = it->second;
    // 							}
    // 						}
    // 					}
    // 					buffer_intermediate.clear();
    // 					buffer_intermediate = mp;

				//       } else {
				//       	cout << "Wrong Function passed" << endl;
				//       }
				//       break;
				//    default :
				//       cout << "Wrong Function passed" << endl;
				// }	
    //         	return *this;
    //         }

            hpxflow &dump(){
				// for (std::map<string, string>::iterator it = buffer_intermediate.begin(); it != buffer_intermediate.end(); ++it) {
    // 				cout << "Key: " << it->first << " Value: " << it->second;
    // 			}
    			// for(auto &x: hashmap){
/*    				for (auto it = std::begin(buffer_intermediate); it!=std::end(buffer_intermediate); ++it){
    					for(auto &x: buffer_intermediate[it])
    						cout << "Key: " << std::get<0>(x) << "Value: " << std::get<1>(x) << "Event Time" << std::get<2>(x) << "Processing Time Start" << std::get<3>(x) << "Processing Time End" << endl;
    				}
*/    				
    			// }

				for(auto &x: buffer_intermediate)
					cout << "Key: " << std::get<0>(x) << "Value: " << std::get<1>(x) << "Event Time" << std::get<2>(x) << "Processing Time Start" << std::get<3>(x) << "Processing Time End" << endl;

            }


			template <typename T>
			hpxflow &map(T fn) {
				// for (std::map<std::string, std::string>::iterator it = buffer_intermediate.begin(); it != buffer_intermediate.end(); ++it) {
				// 	fn(it->first, it->second);
				// }
/*				for (auto it = std::begin(buffer_intermediate); it!=std::end(buffer_intermediate); ++it){
    					for(auto &x: buffer_intermediate[it])
    						fn(std::get<0>(x), std::get<1>(x), std::get<2>(x), std::get<3>(x));
    			}
*/

    			// for(auto &x: buffer_intermediate)
    			// 	fn(std::get<0>(x), std::get<1>(x), std::get<2>(x), std::get<3>(x));


			}

			template <typename T>
			hpxflow &reduce(T fn) {

				sort(buffer_intermediate.begin(), buffer_intermediate.end(), [](tuple<int, int, int, int> &lhs, tuple<int, int, int, int> &rhs ){ return get<1>(lhs) < get<1>(rhs);});
				// for (auto it = std::begin(buffer_intermediate); it!=std::end(buffer_intermediate); ++it){
    // 					for(auto &x: buffer_intermediate[it])
    // 						fn(std::get<0>(x), std::get<1>(x), std::get<2>(x), std::get<3>(x));
    // 			}

    			for(auto &x: buffer_intermediate)
    				fn(std::get<0>(x), std::get<1>(x), std::get<2>(x), std::get<3>(x));
			}	

			template<typename T>
			bool equal(T &s, T &c) {
				return s == c;
			}

			bool equal(int s, int c) {
				return s == c;
			}

			// Checks for the greater value, for ex: s > c
			template<typename T>
			bool grt(T &s, T &c) {
				return s > c;
			}

						// template<typename T>
			bool grt(int s, int c) {
				return s > c;
			}

			// Checks for the greater value, for ex: s < c
			template<typename T>
			bool lst(const T &s, const T &c) {
				return s < c;
			}

			bool lst(int s, int c) {
				return s < c;
			}

			// Checks for the greater value, for ex: s >= c
			template<typename T>
			bool grt_equal(const T &s, const T &c) {
				return s >= c;
			}

			bool grt_equal(int s, int c) {
				return s >= c;
			}

			// Checks for the greater value, for ex: s =< c
			template<typename T>
			bool lst_equal(const T &s, const T &c) {
				return s <= c;
			}

			bool lst_equal(int s, int c) {
				return s <= c;
			}

			bool not_equal(int s, int c){
				return s != c;
			}
			// Summation of two values
			template<typename T>
			T const& summation(T &s, T &c) {
				return s+c;
			}

			// Applies an operation to each and every entries for a given algorithm (less than, greater than, equal to, etc)
			template<typename V>
			V const& each(V &v1, V &v2){

			}
	};		
				
// 	}
// }


int main(){
	// std::map<string, string> mp;
	// mp["1"] = "12";
	// mp["2"] = "13";
	// mp["3"] = "14";
	vector<tuple<int, int, int, int>> mp;
	tuple<int, int, int, int> mi(1, 3, 5, 7);
	tuple<int, int, int, int> mo(1, 3, 5, 7);
	mp.push_back(mi);
	mp.push_back(mo);

// for (auto it = std::begin(buffer_intermediate); it!=std::end(buffer_intermediate); ++it){ for(auto &x: buffer_intermediate[it]) cout << "Key: " << std::get<0>(x) << "Value: " << std::get<1>(x) << "Event Time" << std::get<2>(x) << "Processing Time Start" << std::get<3>(x) << "Processing Time End" << endl;

	auto fn = []()-> void {   cout << "Hey" << endl; };
	// hpxflow(mp).filter("grt", 1, 0).map(fn).dump();
	hpxflow(mp).map(fn).dump();
	return 0;
}