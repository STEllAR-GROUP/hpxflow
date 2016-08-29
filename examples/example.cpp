#include <Common/Compat.h>
#include <Common/Logger.h>
#include <Common/System.h>

#include <Hypertable/Lib/Key.h>
#include <Hypertable/Lib/KeySpec.h>

#include <ThriftBroker/Client.h>
#include <ThriftBroker/gen-cpp/Client_types.h>
#include <ThriftBroker/gen-cpp/HqlService.h>
#include <ThriftBroker/ThriftHelper.h>
#include <ThriftBroker/SerializedCellsReader.h>
#include <ThriftBroker/SerializedCellsWriter.h>

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace Hypertable;
using namespace Hypertable::ThriftGen;
using namespace std;

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>

//#include "../src/hpxflow.h"
#include "../src/dataflow/hypertableflow.h"

void counte(int index, std::vector<std::pair<std::string, std::string> > buf, std::map<std::string, std::string> inte){
    int count;
    for(int j = 0; j < buf.size(); j++){
        if(index == 1) {
            if(inte.find(buf[j].first) != inte.end() ){
                count = stoi(buf[j].first);
                count = count + 1;
                inte.erase(buf[j].first);
                inte[buf[j].first] = std::to_string(count);
            } else {
                inte[buf[j].first] = std::to_string(1);
            }
        }else if(index == 2) {
            if(inte.find(buf[j].second) != inte.end() ){
                count = stoi(buf[j].second);
                count = count + 1;
                inte.erase(buf[j].second);
                inte[buf[j].second] = std::to_string(count);
            } else {
                inte[buf[j].second] = std::to_string(1);
            }
        }
    }

}

int main(){

    Thrift::Client *client = nullptr;

    try {
      client = new Thrift::Client("localhost", 15867);
    }
    catch (ClientException &e) {
      cout << e.message << endl;
      exit(1);
    }
   // hpxflow("text.txt").character_operation(' ', '\n').write_to_file("output.txt");
   // hpxflow("text.txt").operate([](string x){ return std::make_pair (x, "1");}).dump();

   // std::function<(int)> x1 = [=](int index) -> int{return a + b;};
   std::cout << "Now the Filter Version" << std::endl;
   // hpxflow("text.txt").mapper([](std::string x){ return std::make_pair (x, "1");}).filter(1, [](std::string u){ return u.size() > 3;}).reduce(counte, 1).dump();
   return 0;
}
