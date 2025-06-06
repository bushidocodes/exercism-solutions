#pragma once

#include <memory>
#include <stack>

namespace binary_search_tree
{
    template <typename T>
    class binary_tree
    {
        T _value;
        std::unique_ptr<binary_tree<T>> _left;
        std::unique_ptr<binary_tree<T>> _right;

    public:
        binary_tree(T value) : _value{value}
        {
            _left = nullptr;
            _right = nullptr;
        }

        void insert(T value)
        {
            if (value <= _value)
            {
                if (_left == nullptr)
                {
                    _left = std::make_unique<binary_tree<T>>(value);
                }
                else
                {
                    _left->insert(value);
                }
            }
            else
            {
                if (_right == nullptr)
                {
                    _right = std::make_unique<binary_tree<T>>(value);
                }
                else
                {
                    _right->insert(value);
                }
            }
        }

        T data()
        {
            return this->_value;
        }

        std::unique_ptr<binary_tree<T>> &left()
        {
            return _left;
        }

        std::unique_ptr<binary_tree<T>> &right()
        {
            return _right;
        }
    };
} // namespace binary_search_tree
