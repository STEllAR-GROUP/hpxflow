#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <cstring>

using namespace std;

class hpxflow{

    public:
    
        string buffer, inter_buffer;
        // string iss;
        char c;

        // template<typename T>
        vector<string> veco;

        vector<pair<string, string>> buffer_pair;
        vector<pair<string, string>> buffer_pair_intermediate;

        map<string, string> inter_map;

        hpxflow(string filename) {}

        void toVector(){}

        hpxflow &character_operation(char character, char replace_with){}

        hpxflow &write_to_file(string filename){}

        hpxflow &dump() {}

        template <typename F, typename... Args>
        hpxflow &filter(int index, F fn, Args... args){}

        template <typename L>
        hpxflow &reduce(L fn, int vl){}

        template <typename T>
        hpxflow &mapper(T t){}

};

#endif

