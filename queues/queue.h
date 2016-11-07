#ifndef QUEUE_H_
#define QUEUE_H_

class Queue
{
private:
    Queue(const Queue& q):qsize(0) //preemtive definition
    {

    }
    Queue& operator=(const Queue& q)
    {
        return *this;
    }
    enum
    {
        Q_Size=10;
    };

    struct Node
    {
        Item item;
        Node* next;
    };

    Node* front;
    Node* rear;
    int items; // current no. of items in the queue
    const int qsize; //maximum no. of items in the queue

public:
    Queue(int qs);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    int Queuecount() const;
    bool enQueue(const Item& item);
    bool deQueue(Item& item);
};
#endif // QUEUE_H_
