
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <cstring>
/*#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/parallel_algorithm.hpp>

#include <boost/range/functions.hpp>
*/
#include "fileoperations.h"

using namespace std;


hpxflow::hpxflow(string filename) { //This constructor simply reades file input
    ifstream inf(filename);

// Although and expensive operation, I appened buffer char by char to have new line or tab space character included.
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
    // for(int i = 0; i < veco.size(); i++){
    //     cout << "Dump: " << veco[i] << endl;
    // }
    // return *this;
}
/*
hpxflow &hpxflow::character_operation(char character, char replace_with){
    using hpx::util::unwrapped;
    using hpx::lcos::local::dataflow;
    using hpx::parallel::for_each;
    using hpx::parallel::par;
    string app;
    std::vector<char> data(buffer.begin(), buffer.end());
    for_each(par, data.begin(), data.end(),
        [&app, &character, &replace_with](char b)
        {
            if(to_string(b).c_str() == to_string(character).c_str()){

                app = app + replace_with;

            } else{

                app = app + b;

            }
    });
    // }
    buffer = app;
    return *this;
}
*/
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
        // auto v = t(value);
        // cout << "First: " << v.first << " Second: " << v.second << endl;
    }
    buffer_pair_intermediate = buffer_pair;
    return *this;
    // return std::make_pair (10,20)
}


