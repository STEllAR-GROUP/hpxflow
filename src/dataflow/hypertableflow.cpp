#include "hypertableflow.h"

using namespace Hypertable;
using namespace Hypertable::ThriftGen;
// using namespace std;

void hypertableflow::create_config(Thrift::Client *client) {

  // cout << "[basic]" << endl;

  try {

    if (!client->namespace_exists("test"))
      client->namespace_create("test");

    ThriftGen::Namespace ns = client->namespace_open("test");

    bool if_exists = true;
    client->table_drop(ns, "Fruits", if_exists);

    ThriftGen::Schema schema;
    std::map<std::string, ThriftGen::ColumnFamilySpec> cf_specs;
    ThriftGen::ColumnFamilySpec cf;

    cf.__set_name("one");
    cf_specs["one"] = cf;
    cf.__set_name("two");
    cf_specs["two"] = cf;
    cf.__set_name("three");
    cf_specs["three"] = cf;
    cf.__set_name("four");
    cf_specs["four"] = cf;
    cf.__set_name("five");
    cf_specs["five"] = cf;
    schema.__set_column_families(cf_specs);

    client->table_create(ns, "HPXFLOW", schema);

    client->namespace_create("/test/sub");

    std::vector<ThriftGen::NamespaceListing> listing;

    client->namespace_get_listing(listing, ns);

    for (auto entry : listing)
      // cout << entry.name << (entry.is_namespace ? "\t(dir)" : "") << endl;

    client->namespace_close(ns);
  }
  catch (ClientException &e) {
    // cout << e.message << endl;
    exit(1);
  }
  
}

std::vector<std::tuple<int, int, int, int>> hypertableflow::retrieve_tuple(Thrift::Client *client){
    std::tuple<int, int, int, int> inter_hyper;
    std::vector<std::tuple<int, int, int, int>> inter_final;
    try {
      HqlResult result;
      ThriftGen::Namespace ns = client->namespace_open("test");
      Hypertable::ThriftGen::Key key;
      client->hql_query(result, ns, "SELECT * from HPXFLOW");

      for (auto & cell : result.cells){
	//#key.row = "one";
        //#inter_hyper = std::make_tuple(cell.key.row, cell.key.row2, cell["three"], cell["four"], cell["five"]);
        inter_final.push_back(inter_hyper);
      }


      client->namespace_close(ns);
    } catch (ClientException &e) {
      std::cout << e.message << "\n";
      exit(1);
    }
    return inter_final;
}

void hypertableflow::insert_tuple(Thrift::Client *client, int first, int second, int third, int fourth, int five) {
    try {
      std::string query = "INSERT INTO HPXFLOW VALUES ('" + std::to_string(first) + "', '" + std::to_string(second) + "', '" + std::to_string(third)  + "', '" + std::to_string(fourth)  +"', '" + std::to_string(five)  +"')";
      ThriftGen::Namespace ns = client->namespace_open("test");
      ThriftGen::HqlResult result;
      client->hql_query(result, ns, query);
      client->namespace_close(ns);
    }
  catch (ClientException &e) {
    std::cout << e.message << "\n";
    exit(1);
  }
}
