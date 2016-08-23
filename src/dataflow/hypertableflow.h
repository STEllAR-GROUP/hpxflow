#ifndef HYPERTABLEFLOW_H
#define HYPERTABLEFLOW_H

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
#include <vector>
#include <tuple>

using namespace Hypertable;
using namespace Hypertable::ThriftGen;

class hypertableflow{

	void create_config(Thrift::Client *);
	std::vector<std::tuple<int, int, int, int>> retrieve_tuple(Thrift::Client *);
	void insert_tuple(Thrift::Client *, int, int, int, int, int);

};
#endif
