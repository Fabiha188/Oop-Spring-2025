#include <iostream>
#include <exception>

class QueueOverflowException : public std::exception {};
class QueueUnderflowException : public std::exception {};

template <typename T>
class Queue {
private:
    int capacity;
    int front;
    int rear;
    int size;
    T* data;

public:
    Queue(int cap) : capacity(cap), front(0), rear(-1), size(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(T value) {
        if (size == capacity)
            throw QueueOverflowException();
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
    }

    T dequeue() {
        if (size == 0)
            throw QueueUnderflowException();
        T value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }
};

int main() {
    Queue<int> q(3);

    try {
        std::cout << "for enqueue to a full queue...\n";
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);  
    }
    catch (const QueueOverflowException& e) {
        std::cout << "Que Overflow: " << e.what() << std::endl;
    }

    try {
        Queue<int> emptyQ(2);
        std::cout << " from an empty queue...\n";
        emptyQ.dequeue();  
    }
    catch (const QueueUnderflowException& e) {
        std::cout << "QueueUnderflowException : " << e.what() << std::endl;
    }

    return 0;
}
