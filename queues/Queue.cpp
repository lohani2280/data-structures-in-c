#include"queue.h"

Queue::Queue(int qs): qsize(qs)
{
    front=null;
    rear=null;
    items=0;
}

bool Queue::isFull() const
{
    return items==qsize;
}

bool Queue::isEmpty() const
{
    return items==0;
}

int Queue::Queuecount()const
{
    return items;
}

bool Queue::enQueue(const Item& item)
{
    if(isFull())
        return false;
    Node* add=new Node;
    if(add==NULL)       //terminate if it cant create a new node,for eample-if the request for more memory fails
        return false;
    add->item=item;
    add->next=NULL;
    if(front==NULL)
        front=add;
    else
        rear->next=add;
    rear=add;
    return true;
}

bool Queue::deQueue(Item& item)
{
    if(isEmpty)
        return false;
    item=front->item;
    items--;
    node* temp=front;
    front=front->next
    delete temp;
    if(items==0)
        rear=NULL;
    return true;

}

Queue::~Queue()
{
    Node* temp;
    while(front!=NULL)
    {
        temp=front;
        front=front->next;
        delete temp;
    }
}
