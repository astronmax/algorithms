/*
Copyright [2021] [Max A. Jurankov]
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/**
 * Author: astronmax
 * 
 * Realization of sorting algorithm using bit array. Sorting containers with negative 
 * or non-integer numbers are not allowed. Duplicate values will be lost after 
 * sorting if they were present.
 * 
 * The algorithm creates a bit array. The algorithm then checks each value from the container 
 * that needs to be sorted. The main task is to set true those bits in the bit array, the 
 * indexes of which match with the elements of the container.
 * Bit array needs only for saving information which elements were in container before sort.
 * 
 * For example, container to sort: [7, 5, 3, 1, 0];
 * Bit array looks like this: [00000000] (7 bits in array)
 * After sort bit array will look like this: [11010101]
 * Indexing starts from the right bit. Zero bit is true --> container has zero, we need to 
 * put zero at the zero index...
 */

#pragma once

#include <core/check.hpp>

#include <bitset>
#include <cstddef>
#include <vector>

/**
 * General library namespace
 */
namespace alg {

/**
 * Namespace with sorting algorithms
 */
namespace sort {

    /**
    * Sorting algorithm that using bit array
    * @param begin First iterator
    * @param end Last iterator
    */
    template <typename Iter>
    void bitsort(Iter begin, Iter end)
    {
        const auto bits = 64; // size of each block (in bits)
        std::size_t block = 0; // number of current block (we use this as index of bit array)
        std::vector<std::bitset<bits>> bitarray { { 0x00 } };
        for (auto i = begin; i != end; ++i) {
            alg::core::is_unsigned_integral(*i);
            block = *i / bits; // compute needed block (item / size of one block)
            // allocate memory if it isn't enought
            for (std::size_t j = bitarray.size(); j <= block; ++j)
                bitarray.push_back({ 0x00 });

            // calculate index inside bit set (not bit array!)
            // "bits - 1" operation needs because bitset in STL count bits from right
            // This means that bitset.set(2) if bitset = 0x000 make it looks like 0x100
            bitarray.at(block).set(bits - 1 - (*i - bits * block));
        }

        // change values in container by using string of bits as flags
        // that show existense of element with value equals to it's index
        auto it = begin;
        for (std::size_t i = 0; i < bitarray.size(); ++i) {
            for (auto j = 0; j < bits; ++j) {
                if (bitarray.at(i).test(bits - 1 - j)) {
                    *it = (bits * i) + j;
                    it++;
                }
            }
        }
    }

}; // namespace sort

}; // namespace alg