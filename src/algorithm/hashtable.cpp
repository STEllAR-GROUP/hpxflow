////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

//#include "HashTable.h"

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

namespace hpx{
    namespace flow{
        class HashTable{
            public:


            unordered_map<int, int> hashmap;

            int length;

            public: 

            HashTable() {}


            // De-allocates all memory used for the Hash Table.
            ~HashTable(){
                hashmap.clear();
            }

            template <typename T, typename V>
            void insert_Item( T key, V value ) {

                // Implement hpx::atomic
                hashmap.insert(make_pair(key, V(value)));

            }

            template <typename T>
            void remove_Item( T key ) {
                hashmap.erase(key);
            }

            template <typename T, typename V>            
            V get_Item( T key ) {
                // template<typename T, typename V> // Check for some work around
                std::unordered_map<int, int>::const_iterator got = hashmap.find(key);
                return got->second;
            }


            // Returns the number of Items in the Hash Table.
            int getNumberOfItems()
            {
                return 0;
            }

        };
    }
}
