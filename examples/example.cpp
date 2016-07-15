#include "example.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>

void count(int index, vector<pair<string, string>> buffer_pair_intermediate, map<string, string> inter_map){
    int count;
    for(int j = 0; j < buffer_pair_intermediate.size(); j++){
        if(index == 1) {
            if(inter_map.find(buffer_pair_intermediate[j].first) != inter_map.end() ){
                count = stoi(buffer_pair_intermediate[j].first);
                count = count + 1;
                inter_map.erase(buffer_pair_intermediate[j].first);
                inter_map[buffer_pair_intermediate[j].first] = to_string(count);
            } else {
                inter_map[buffer_pair_intermediate[j].first] = to_string(1);
            }
        }else if(index == 2) {
            if(inter_map.find(buffer_pair_intermediate[j].second) != inter_map.end() ){
                count = stoi(buffer_pair_intermediate[j].second);
                count = count + 1;
                inter_map.erase(buffer_pair_intermediate[j].second);
                inter_map[buffer_pair_intermediate[j].second] = to_string(count);
            } else {
                inter_map[buffer_pair_intermediate[j].second] = to_string(1);
            }
        }
    }

}

int main(){
   hpxflow("text.txt").character_operation(' ', '\n').write_to_file("output.txt");
   // hpxflow("text.txt").operate([](string x){ return std::make_pair (x, "1");}).dump();

   // std::function<(int)> x1 = [=](int index) -> int{return a + b;};

   cout << "Now the Filter Version \n\n\n" << endl;
   hpxflow("text.txt").map([](string x){ return std::make_pair (x, "1");}).filter(1, [](string u){ return u.size() > 3;}).reduce(count, 1).dump();
   return 0;
}