#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include <cstddef>

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
        circular_buffer(std::size_t capacity);
        ~circular_buffer();
        T read();
        void write(T value);
    };

} // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H
