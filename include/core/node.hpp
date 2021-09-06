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
 * This module defines a node class. Each node contains some data and 
 * pointer to the next node. Also exists double-linked node that contains
 * two pointers: at the previous node and at the next.
 */

#pragma once

#include <memory>

// General algorithms namespace
namespace alg {

/**
 * Class of node that contains only one pointer (to the next node)
 */
template <typename T>
class s_node {

    T m_data; // stored data
    std::shared_ptr<s_node<T>> m_next; // pointer to the next node

public:
    // Constructs node that not linked with another
    s_node(T data)
        : m_data { data }
        , m_next { nullptr }
    {
    }

    // Constructs node with shared pointer as pointer to the next node
    s_node(T data, std::shared_ptr<s_node<T>> next)
        : m_data { data }
        , m_next { next }
    {
    }

    // Destructs node object
    ~s_node()
    {
        m_next.reset();
    }

public:
    // Copy semantics
    s_node(s_node<T>& other) noexcept
    {
        m_data = other.m_data;
        m_next = other.m_next;
    }
    s_node<T>& operator=(s_node<T>& other) noexcept
    {
        m_data = other.m_data;
        m_next = other.m_next;
        return *this;
    }

    // Movement semantics
    s_node(s_node<T>&& other)
    {
        m_data = other.m_data;
        if (other.m_next)
            m_next = other.m_next;
        else
            m_next = nullptr;
        
        other.m_next.reset();
    }
    s_node<T>& operator=(s_node<T>&& other)
    {
        m_data = other.m_data;
        if (other.m_next)
            m_next = other.m_next;
        else
            m_next = nullptr;
        
        other.m_next.reset();
        return *this;
    }

    // Compare operator
    bool operator==(s_node<T>& other) noexcept
    {
        return ((m_data == other.m_data) && (m_next == other.m_next));
    }

public:
    /**
     * Method to get data that stored at the node
     */
    T& data() noexcept
    {
        return m_data;
    }

    /**
     * Method to get pointer to the next node
     */
    std::shared_ptr<s_node<T>>& next() noexcept
    {
        return m_next;
    }

}; // class s_node

}; // namespace alg