////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef UDPSERVER_H_INCLUDE
#define UDPSERVER_H_INCLUDE

// For Vector Array 
#include <vector>
#include <iostream>
#include <string>

void *connection_handler(void *);

int runProcessing();

void *connection_handler(void *socket_desc);

#endif 