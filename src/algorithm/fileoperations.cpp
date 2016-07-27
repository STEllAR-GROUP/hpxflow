////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////


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

using namespace std;


hpxflow::hpxflow(string filename) { 
    ifstream inf(filename);

    while (inf.get(c))
        buffer += c;

    toVector();
}

void hpxflow::toVector(){
    istringstream iss(buffer);
    string word;
    while(iss >> word) {
        veco.push_back(word);
    }

}

hpxflow &hpxflow::write_to_file(string filename){
    std::ofstream out(filename);
    out << buffer;
    out.close();
    return *this;
}

hpxflow &hpxflow::dump() {
    for (map<string, string>::iterator it=inter_map.begin(); it!=inter_map.end(); ++it)
        cout << "First :"<< it->first << " Second: " << it->second << '\n' << endl;
    return *this;
}

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

template <typename L>
hpxflow &hpxflow::reduce(L fn, int vl){
    fn(vl, buffer_pair_intermediate, inter_map);
    return *this;  
}

template <typename T>
hpxflow &hpxflow::mapper(T t){
    for (auto const &value : veco) {
        buffer_pair.push_back(make_pair(t(value).first, t(value).second));

    }
    buffer_pair_intermediate = buffer_pair;
    return *this;
}


