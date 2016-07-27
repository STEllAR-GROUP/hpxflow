////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef HPX_FLOW_ALGORITHM_H
#define HPX_FLOW_ALGORITHM_H

#include <regex>
#include <map>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits> 
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>

using namespace std;

namespace hpx
{
	namespace flow{


		class Test{

			// std::string buffer;
			std::string strm_;
			std::string buffer;
			std::string data;
		 // std::string t;
		 // std::getline(file, temp);
		public:
			Test(std::string strm) {}

			template <typename T>
			Test &map(T fn) {
			}

			template <typename T>
			Test &reduce(T fn) {

			}	

			template<typename T>
			bool equal(const T &s, const T &c) {

			}

			// Checks for the greater value, for ex: s > c
			template<typename T>
			bool grt(const T &s, const T &c) {

			}

			// Checks for the greater value, for ex: s < c
			template<typename T>
			bool lst(const T &s, const T &c) {

			}

			// Checks for the greater value, for ex: s >= c
			template<typename T>
			bool grt_equal(const T &s, const T &c) {

			}

			// Checks for the greater value, for ex: s =< c
			template<typename T>
			bool lst_equal(const T &s, const T &c) {

			}

			// Summation of two values
			template<typename T>
			T const& summation(T &s, T &c) {

			}

			// Applies an operation to each and every entries for a given algorithm (less than, greater than, equal to, etc)
			template<typename V>
			V const& each(V &v1, V &v2){

			}

			public class kmean_point {
			    public int Id { get; set; }
			    public double X { get; set; }
			    public double Y { get; set; }
			};

			public class kmean_collection : List<kmean_point> {
			    public kmean_point Centroid { get; set; }
			};

			public static List<kmean_collection> DoKMeans(kmean_collection kpoints, int clusterCount) {}

			public static double Eucledian_Distance(kmean_point pt1, kmean_point pt2) {}

			vector<vector<KeyPoint>> density_based_clustering(vector<KeyPoint> *keypoints, float eps, int minPts) {}

			vector<int> regionQuery(vector<KeyPoint> *keypoints, KeyPoint *keypoint, float eps) {}


			/// Djikstra Algorithm

			typedef int vertex_t;
			typedef double weight_t;
			 
			const weight_t max_weight = std::numeric_limits<double>::infinity();
			 
			struct neighbor {
			    vertex_t target;
			    weight_t weight;
			    neighbor(vertex_t arg_target, weight_t arg_weight)
			        : target(arg_target), weight(arg_weight) { }
			};
			 
			typedef std::vector<std::vector<neighbor> > adjacency_list_t;
			 
			 
			void Dijkstra_Compute(vertex_t source, const adjacency_list_t &adjacency_list, std::vector<weight_t> &min_distance, std::vector<vertex_t> &previous) {}
			 
			 
			std::list<vertex_t> Dijkstra( vertex_t vertex, const std::vector<vertex_t> &previous ) {}


		};

		
		
	}
}

#endif

