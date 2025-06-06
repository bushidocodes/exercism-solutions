#pragma once

#include <cstddef>
#include <stdexcept>

namespace circular_buffer
{

    template <typename T>
    class circular_buffer
    {
    private:
        std::size_t capacity;
        std::size_t low;
        std::size_t high;
        bool is_empty;
        T *data;

    public:
        circular_buffer(std::size_t capacity)
        {
            this->capacity = capacity;
            low = 0;
            high = 0;
            is_empty = true;
            data = new T[capacity];
        };

        ~circular_buffer()
        {
            delete[] data;
        };

        T read()
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

        void write(T value)
        {
            if (low == high && !is_empty)
            {
                throw std::domain_error("buffer is full!");
            }

            is_empty = false;
            high = (high + 1) % capacity;

            data[high] = value;
        };

        void overwrite(T value)
        {
            if (low == high && !is_empty)
            {
                low = (low + 1) % capacity;
            }

            is_empty = false;
            high = (high + 1) % capacity;

            data[high] = value;
        };

        void clear()
        {
            if (!is_empty)
            {
                low = 0;
                high = 0;
                is_empty = true;
            }
        }
    };

} // namespace circular_buffer
