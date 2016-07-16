#include "example.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>

void counte(int index, vector<pair<string, string>> buf, map<string, string> inte){
    int count;
    for(int j = 0; j < buf.size(); j++){
        if(index == 1) {
            if(inte.find(buf[j].first) != inte.end() ){
                count = stoi(buf[j].first);
                count = count + 1;
                inte.erase(buf[j].first);
                inte[buf[j].first] = to_string(count);
            } else {
                inte[buf[j].first] = to_string(1);
            }
        }else if(index == 2) {
            if(inte.find(buf[j].second) != inte.end() ){
                count = stoi(buf[j].second);
                count = count + 1;
                inte.erase(buf[j].second);
                inte[buf[j].second] = to_string(count);
            } else {
                inte[buf[j].second] = to_string(1);
            }
        }
    }

}

int main(){
   hpxflow("text.txt").character_operation(' ', '\n').write_to_file("output.txt");
   // hpxflow("text.txt").operate([](string x){ return std::make_pair (x, "1");}).dump();

   // std::function<(int)> x1 = [=](int index) -> int{return a + b;};

   cout << "Now the Filter Version \n\n\n" << endl;
   hpxflow("text.txt").mapper([](string x){ return std::make_pair (x, "1");}).filter(1, [](string u){ return u.size() > 3;}).reduce(counte, 1).dump();
   return 0;
}