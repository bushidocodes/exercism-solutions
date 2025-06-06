#include <stdexcept>

#include "circular_buffer.h"

namespace circular_buffer
{
    template <typename T>
    circular_buffer<T>::circular_buffer(std::size_t capacity)
    {
        this->capacity = capacity;
        low = 0;
        high = 0;
        is_empty = true;
        data = new T[capacity];
    };

    template <typename T>
    circular_buffer<T>::~circular_buffer()
    {
        delete[] data;
    };

    template <typename T>
    T circular_buffer<T>::read()
    {
        if (is_empty)
        {
            throw std::domain_error("buffer is empty!");
        }

        low = (low + 1) % capacity;

        if (low == high)
        {
            is_empty = true;
        }

        return data[low];
    };

    template <typename T>
    void circular_buffer<T>::write(T value)
    {
        if (low == high && !is_empty)
        {
            throw std::domain_error("buffer is full!");
        }

        is_empty = false;
        high = (high + 1) % capacity;

        data[high] = value;
    };

} // namespace circular_buffer
