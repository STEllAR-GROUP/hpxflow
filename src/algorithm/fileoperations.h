////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////


#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <cstring>

//using namespace std;

class hpxflow{

    public:
    
			std::string buffer, inter_buffer;
        char c;

		std::vector<std::string> veco;

		std::vector<std::pair<std::string,std:: string>> buffer_pair;
		std::vector<std::pair<std::string, std::string>> buffer_pair_intermediate;

		std::map<std::string, std::string> inter_map;

        hpxflow(std::string filename);

        void toVector();

        hpxflow &character_operation(char character, char replace_with);

        hpxflow &write_to_file(std::string filename);

        hpxflow &dump() ;

        template <typename F, typename... Args>
        hpxflow &filter(int index, F fn, Args... args);

        template <typename L>
        hpxflow &reduce(L fn, int vl);

        template <typename T>
        hpxflow &mapper(T t);

};

#endif

