////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef HPX_FLOW_trigger_H
#define HPX_FLOW_trigger_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace hpx
{
  namespace flow
  {
    class trigger
    {
      trigger ()
      {

      }
       ~trigger ()
      {

      }

      template < typename F >	//  Here Fn is watermark function
        bool trigger (F fn)
      {
      }
    };
  }
}

#endif
