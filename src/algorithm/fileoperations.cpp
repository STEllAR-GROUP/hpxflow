////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

/**
 * @file algorithm.cpp
 * @author Aalekh Nigam, Patrick Diehl
 * @brief This file contains some fundamental mechanism for file read/write operations. Parallelization in read/write operation is in work
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <cstring>

#include "fileoperations.h"

/**
 * @brief Basically append as a string
 * returns fluent interface onject, used insert file elements to tuple
 * @param filename
*/

hpxflow::hpxflow(std::string filename) { 
    std::ifstream inf(filename);

    while (inf.get(c))
        buffer += c;

    toVector();
    return *this;
}

/**
 * @brief Each string to a word vector
 *
*/

void hpxflow::toVector(){
    std::istringstream iss(buffer);
    std::string word;
    while(iss >> word) {
        veco.push_back(word);
    }
}

/**
 * @brief Used to output a final result to the file
 * returns fluent interface onject, used write to file object.
 * @param filename
*/

hpxflow &hpxflow::write_to_file(std::string filename){
    std::ofstream out(filename);
    out << buffer;
    out.close();
    return *this;
}

/**
 * @brief Prints the final output (currently in console) 
 * returns fluent interface onject, used output processed tuple.
*/

hpxflow &hpxflow::dump() {
    for (std::map<std::string, std::string>::iterator it=inter_map.begin(); it!=inter_map.end(); ++it)
        std::cout << "First :"<< it->first << " Second: " << it->second << '\n' << "\n";
    return *this;
}

/**
 * @brief Used to implement some filter mechansim based on some lambda function
 * returns fluent interface onject, used to apply some filter mechanism.
 * @param index
 * @param fn
 * @param args 
*/

template <typename F, typename... Args>
hpxflow &hpxflow::filter(int index, F fn, Args... args){
    for(size_t i = 0; i < buffer_pair_intermediate.size(); i++) {
        if(index == 1){
            if(!fn(buffer_pair_intermediate[i].first, args...)){
                buffer_pair_intermediate.erase(buffer_pair_intermediate.begin() + i);
            }
        }else if(index == 2){
            if(!fn(buffer_pair_intermediate[i].second, args...)){
                buffer_pair_intermediate.erase(buffer_pair_intermediate.begin() + i);
            }
        }
    }
    return *this;
}

/**
 * @brief Proposed reducer operations when dumping files. 
 * returns fluent interface onject, used to apply paralelization over reducer file write.
 * @param fn
 * @param vl 
*/

template <typename L>
hpxflow &hpxflow::reducerFile(L fn, int vl){
    fn(vl, buffer_pair_intermediate, inter_map);
    return *this;  
}

/**
 * @brief Proposed Mapper operation when reading file in parallel 
 * returns fluent interface onject, used to apply paralelization over mapper file read.
 * @param t
*/ 

template <typename T>
hpxflow &hpxflow::mapperFile(T t){
    for (auto const &value : veco) {
        buffer_pair.push_back(make_pair(t(value).first, t(value).second));

    }
    buffer_pair_intermediate = buffer_pair;
    return *this;
}


