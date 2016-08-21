#ifndef HYPERTABLEFLOW_H
#define HYPERTABLEFLOW_H

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

using namespace Hypertable;
using namespace Hypertable::ThriftGen;
using namespace std;

class hypertableflow{

  void test_basic(Thrift::Client);
};
#endif