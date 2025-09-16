class BufferFullException(BufferError):
    """Exception raised when CircularBuffer is full.

    message: explanation of the error.

    """

    def __init__(self, message):
        super().__init__(message)


class BufferEmptyException(BufferError):
    """Exception raised when CircularBuffer is empty.

    message: explanation of the error.

    """

    def __init__(self, message):
        super().__init__(message)


class CircularBuffer:
    def __init__(self, capacity: int):
        self.data: list[str | None] = [None] * (capacity + 1)
        self._capacity = capacity + 1
        self.begin: int = 0
        self.end: int = 0

    @property
    def capacity(self):
        return self._capacity

    def read(self):
        if self.begin == self.end:
            raise BufferEmptyException("Circular buffer is empty")
        result = self.data[self.begin]
        self.begin = (self.begin + 1) % self._capacity
        return result

    def write(self, data):
        next = (self.end + 1) % self._capacity
        if self.begin == next:
            raise BufferFullException("Circular buffer is full")
        self.data[self.end] = data
        self.end = next

    def overwrite(self, data):
        self.data[self.end] = data
        self.end = (self.end + 1) % self._capacity
        if self.begin == self.end:
            self.begin = (self.begin + 1) % self._capacity

    def clear(self):
        self.begin = self.end
