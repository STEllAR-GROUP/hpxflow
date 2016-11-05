#include "../src/hpxflow.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <tuple>

std::tuple<int, int, int, int, int> counte(std::tuple<int, int, int, int, int> element){
  std::tuple<int, int, int, int, int> intermediate{std::get<0>(element) + 1, std::get<0>(element) + 7, std::get<0>(element) + 8, std::get<0>(element) + 0, std::get<0>(element) + 3};
  return intermediate;
}

int main(){
   // hpxflow("text.txt").character_operation(' ', '\n').write_to_file("output.txt");
   // hpxflow("text.txt").operate([](string x){ return std::make_pair (x, "1");}).dump();

   // std::function<(int)> x1 = [=](int index) -> int{return a + b;};

   std::cout << "Now the Filter Version \n\n\n" << std::endl;
   mapper().mapperSingle(counte);
   return 0;
}
