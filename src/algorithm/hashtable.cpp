////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

/**
 * @file hashtable.cpp
 * @author Aalekh Nigam, Patrick Diehl
 * @brief This file contains some fundamental mechanism over key/value pair. This hashmap is used in various pats of our program.
*/

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

            /**
             * @brief Used to insert item into hashmap
             * @param key
             * @param value
            */

            template <typename T, typename V>
            void insert_Item( T key, V value ) {

                // Implement hpx::atomic
                hashmap.insert(make_pair(key, V(value)));

            }

            /**
             * @brief Used to remove item from hashmap
             * @param key
            */

            template <typename T>
            void remove_Item( T key ) {
                hashmap.erase(key);
            }

            /**
             * @brief Used to retrieve value from hashmap
             * @param key
            */

            template <typename T, typename V>            
            V get_Item( T key ) {
                // template<typename T, typename V> // Check for some work around
                std::unordered_map<int, int>::const_iterator got = hashmap.find(key);
                return got->second;
            }

        };
    }
}
