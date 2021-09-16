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
 * Module with checks required by algorithms
 */

#pragma once

#include <type_traits>

/**
 * General library namespace
 */
namespace alg {

/**
 * Namespace with sorting algorithms
 */
namespace core {

    /**
     * Function to check if value has unsigned integral type
     * @param item value to check
     */
    template <typename T>
    T is_unsigned_integral(T item)
    {
        static_assert(std::is_integral<T>::value && !std::is_signed<T>::value,
            "Unsigned integral required");

        return item;
    }
};

};