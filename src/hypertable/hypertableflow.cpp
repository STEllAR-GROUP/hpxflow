#include </opt/hypertable/current/include/Common/Compat.h>
#include </opt/hypertable/current/include/Common/Logger.h>
#include </opt/hypertable/current/include/Common/System.h>

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

#include "hypertableflow.h"

using namespace Hypertable;
using namespace Hypertable::ThriftGen;
using namespace std;

void hypertableflow::test_basic(Thrift::Client *client) {

  // cout << "[basic]" << endl;

  try {

    if (!client->namespace_exists("test"))
      client->namespace_create("test");

    ThriftGen::Namespace ns = client->namespace_open("test");

    bool if_exists = true;
    client->table_drop(ns, "Fruits", if_exists);

    ThriftGen::Schema schema;
    map<string, ThriftGen::ColumnFamilySpec> cf_specs;
    ThriftGen::ColumnFamilySpec cf;

    cf.__set_name("genus");
    cf_specs["genus"] = cf;
    cf.__set_name("description");
    cf_specs["description"] = cf;
    cf.__set_name("tag");
    cf_specs["tag"] = cf;
    schema.__set_column_families(cf_specs);

    client->table_create(ns, "Fruits", schema);

    client->namespace_create("/test/sub");

    vector<ThriftGen::NamespaceListing> listing;

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
