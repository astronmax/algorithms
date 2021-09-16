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
 * Test for alg::bitsort() function
 */

#include <algorithm>
#include <gtest/gtest.h>
#include <sort/bitsort.hpp>
#include <vector>

TEST(bitsort_test, upper_lower)
{
    std::vector<unsigned int> v {};
    for (auto i = 0; i < 10000; ++i)
        v.push_back(10000 - i);

    EXPECT_FALSE(std::is_sorted(v.begin(), v.end()));
    alg::sort::bitsort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(bitsort_test, lower_upper)
{
    std::vector<unsigned int> v {};
    for (auto i = 0; i < 10000; ++i)
        v.push_back(i);

    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
    alg::sort::bitsort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(bitsort_test, random_values)
{
    std::vector<unsigned int> v { 17386, 2534, 243, 234, 12, 56, 29, 45, 32, 59, 31, 1, 5, 3, 8, 6, 23, 454 };

    EXPECT_FALSE(std::is_sorted(v.begin(), v.end()));
    alg::sort::bitsort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(bitsort, single_element)
{
    std::vector<unsigned int> v { 0 };

    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
    alg::sort::bitsort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}