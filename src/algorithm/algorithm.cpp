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

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits> 
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>


// HPX header's
#include <hpx/parallel/algorithms/for_each.hpp>

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
			Test(std::string strm) {
				// std::string strm_(std::istreambuf_iterator<char>(strm), {});
				ifstream infile; 
				infile.open(strm);
				std::getline(infile, strm_);
				// data >> infile;
				// std::getline(strm, strm_);
			}

			template <typename T>
			Test &map(T fn) {
				buffer = fn(strm_);
			}

			template <typename T>
			Test &reduce(T fn) {
				fn(buffer);
			}	

			template<typename T>
			bool equal(const T &s, const T &c) {
				return s == c;
			}

			// Checks for the greater value, for ex: s > c
			template<typename T>
			bool grt(const T &s, const T &c) {
				return s > c;
			}

			// Checks for the greater value, for ex: s < c
			template<typename T>
			bool lst(const T &s, const T &c) {
				return s < c;
			}

			// Checks for the greater value, for ex: s >= c
			template<typename T>
			bool grt_equal(const T &s, const T &c) {
				return s >= c;
			}

			// Checks for the greater value, for ex: s =< c
			template<typename T>
			bool lst_equal(const T &s, const T &c) {
				return s <= c;
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

			public class kmean_point {
			    public int Id { get; set; }
			    public double X { get; set; }
			    public double Y { get; set; }
			};

			public class kmean_collection : List<kmean_point> {
			    public kmean_point Centroid { get; set; }
			};

			public static List<kmean_collection> DoKMeans(kmean_collection kpoints, int clusterCount) {

			    List<kmean_collection> allClusters = new List<kmean_collection>();
			    List<List<kmean_point>> allGroups = ListUtility.SplitList<kmean_point>(kpoints, clusterCount);

			    hpx::parallel::for_each(
				    hpx::parallel::par,
				    std::begin(allGroups), std::end(allGroups),
				    [&](kmean_point group) {
				   		kmean_collection cluster = new kmean_collection();
			        	cluster.AddRange(group);
			        	allClusters.Add(cluster);
				});

			    //start k-means clustering
			    int movements = 1;
			    while (movements > 0)
			    {
			        movements = 0;

		        hpx::parallel::for_each(
			    	hpx::parallel::par,
			    	std::begin(allClusters), std::end(allClusters),
			    	[&](kmean_collection cluster) {
			   			for (int pointIndex = 0; pointIndex < cluster.Count; pointIndex++)
			            {
			                kmean_point point = cluster[pointIndex];

			                int nearestCluster = FindNearestCluster(allClusters, point);
			                if (nearestCluster != allClusters.IndexOf(cluster))
			                {
			                    if (cluster.Count > 1)
			                    {
			                        kmean_point removedPoint = cluster.RemovePoint(point);
			                        allClusters[nearestCluster].AddPoint(removedPoint);
			                        movements += 1;
			                    }
			                }
			            }
				});

			    }

			    return allClusters;
			}

			public static double Eucledian_Distance(kmean_point pt1, kmean_point pt2) {
			    double x1 = pt1.X, y1 = pt1.Y;
			    double x2 = pt2.X, y2 = pt2.Y;

			    //find euclidean distance
			    double distance = Math.Sqrt(Math.Pow(x2 - x1, 2.0) + Math.Pow(y2 - y1, 2.0));
			    return (distance);
			}

			vector<vector<KeyPoint>> density_based_clustering(vector<KeyPoint> *keypoints, float eps, int minPts) {
				vector<vector<KeyPoint>> clusters;
				vector<bool> clustered;
				vector<int> noise;
				vector<bool> visited;
				vector<int> neighborPts;
				vector<int> neighborPts_;
				int c;

				int noKeys = keypoints->size();

				//init clustered and visited
				for(int k = 0; k < noKeys; k++)
				{
				    clustered.push_back(false);
				    visited.push_back(false);
				}

				c = 0;
				clusters.push_back(vector<KeyPoint>()); //will stay empty?

				for(int i = 0; i < noKeys; i++)
				{
				    if(!visited[i])
				    {
				        //Mark P as visited
				        visited[i] = true;
				        neighborPts = regionQuery(keypoints,&keypoints->at(i),eps);
				        if(neighborPts.size() < minPts)
				            //Mark P as Noise
				            noise.push_back(i);
				        else
				        {
				            clusters.push_back(vector<KeyPoint>());
				            c++;

				            clusters[c].push_back(keypoints->at(i));

							hpx::parallel::for_each(
						        hpx::parallel::par,
						        std::begin(neighborPts), std::end(neighborPts),
						        [&](int element) {
						        	/////////
					                if(!visited[element])
					                {

					                    visited[element] = true;
					                    neighborPts_ = regionQuery(keypoints,&keypoints->at(element),eps);
					                    if(neighborPts_.size() >= minPts)
					                    {
					                        neighborPts.insert(neighborPts.end(),neighborPts_.begin(),neighborPts_.end());
					                    }
					                }

					                if(!clustered[element])
					                    clusters[c].push_back(keypoints->at(element));
							});

				        }

				    }
				}
				return clusters;
			}

			vector<int> regionQuery(vector<KeyPoint> *keypoints, KeyPoint *keypoint, float eps) {
				float dist;
				vector<int> retKeys;
				for(int i = 0; i< keypoints->size(); i++)
				{
				    dist = sqrt(pow((keypoint->pt.x - keypoints->at(i).pt.x),2)+pow((keypoint->pt.y - keypoints->at(i).pt.y),2));
				    if(dist <= eps && dist != 0.0f)
				    {
				        retKeys.push_back(i);
				    }
				}
				return retKeys;
			}


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
			 
			 
			void Dijkstra_Compute(vertex_t source, const adjacency_list_t &adjacency_list, std::vector<weight_t> &min_distance, std::vector<vertex_t> &previous) {
			    int n = adjacency_list.size();
			    min_distance.clear();
			    min_distance.resize(n, max_weight);
			    min_distance[source] = 0;
			    previous.clear();
			    previous.resize(n, -1);
			    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
			    vertex_queue.insert(std::make_pair(min_distance[source], source));
			 
			    while (!vertex_queue.empty()) 
			    {
			        weight_t dist = vertex_queue.begin()->first;
			        vertex_t u = vertex_queue.begin()->second;
			        vertex_queue.erase(vertex_queue.begin());
			 
			        // Visit each edge exiting u
				const std::vector<neighbor> &neighbors = adjacency_list[u];
			        for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
			             neighbor_iter != neighbors.end();
			             neighbor_iter++)
			        {
			            vertex_t v = neighbor_iter->target;
			            weight_t weight = neighbor_iter->weight;
			            weight_t distance_through_u = dist + weight;
				    if (distance_through_u < min_distance[v]) {
				        vertex_queue.erase(std::make_pair(min_distance[v], v));
			 
				        min_distance[v] = distance_through_u;
				        previous[v] = u;
				        vertex_queue.insert(std::make_pair(min_distance[v], v));
			 
				    }
			 
			        }
			    }
			}
			 
			 
			std::list<vertex_t> Dijkstra( vertex_t vertex, const std::vector<vertex_t> &previous ) {
			    std::list<vertex_t> path;
			    for ( ; vertex != -1; vertex = previous[vertex])
			        path.push_front(vertex);
			    return path;
			}


		};

		
		
	}
}

// int main(){
// 	// ifstream stream1("test.txt");
// 	// ifstream infile; 
// 	// infile.open("test.txt"); 
// 	Test t("test.txt");
// 	t.map([](std::string i) { return std::stoi(i)*2; }).reduce([](std::string i) { std::cout << i << " "; });	
// }
