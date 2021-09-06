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
 * Test for alg::s_node class
 */

#include <core/node.hpp>
#include <gtest/gtest.h>

#include <iostream>

TEST (init, only_data)
{
    alg::s_node<int> n {1024};

    EXPECT_EQ(n.data(), 1024);
    EXPECT_EQ(n.next(), nullptr);
}

TEST (init, shared_ptr)
{
    alg::s_node<int> n2 {2};
    auto ptr = std::make_shared<alg::s_node<int>>(n2);
    alg::s_node<int> n1 {1, ptr};

    EXPECT_EQ(n1.data(), 1);
    EXPECT_EQ(n1.next(), ptr);
    EXPECT_EQ(n1.next()->data(), 2);
}

TEST (init, compare)
{
    alg::s_node<int> n1 {2};
    alg::s_node<int> n2 {2};
    
    alg::s_node<int> n4 {100};
    auto ptr = std::make_shared<alg::s_node<int>>(n4);
    alg::s_node<int> n3 {99, ptr};
    alg::s_node<int> n5 {99, ptr};

    EXPECT_TRUE(n1 == n2);
    EXPECT_TRUE(n3 == n5);
}

TEST (init, copy_semantics)
{
    alg::s_node<int> n1 {1024};
    alg::s_node<int> n2 {n1};
    alg::s_node<int> n3 = n2;

    EXPECT_EQ(n2.data(), n1.data());
    EXPECT_EQ(n3.data(), n1.data());
}

TEST (init, move_semantics)
{
    alg::s_node<int> n = {1024};
    EXPECT_EQ(n.data(), 1024);

    alg::s_node<int> n2 {std::move(n)};
    EXPECT_EQ(n2.data(), 1024);
}