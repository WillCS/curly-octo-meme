#ifndef QUEUE
#define QUEUE

#include <iostream>
using namespace std;

#define EMPTY_DEQUEUE_MSG "Attempt to dequeue from an empty queue"

template <class T>
class QueueNode {
    public:
        virtual ~QueueNode(void);
        QueueNode(T* element);
        virtual QueueNode<T>* getNext(void);
        virtual void setNext(QueueNode<T>* next);
        virtual T* get(void);
    private:
        QueueNode<T>* next;
        T* element;
};

template <class T>
class Queue {
    public:
        virtual void enqueue(T* element);
        virtual T* dequeue(void);
        virtual T* peek(void);
        virtual int getLength(void);
        virtual bool isEmpty(void);
    private:
        QueueNode<T>* front;
        QueueNode<T>* back;
        int length = 0;
};

/* Queue Definitions */

template <class T>
void Queue<T>::enqueue(T* element) {
    QueueNode<T>* newNode = new QueueNode<T>(element);
    if(this->isEmpty()) {
        this->front = newNode;
    } else {
        this->back->setNext(newNode);
    }

    this->length++;
    this->back = newNode;
}

template <class T>
T* Queue<T>::dequeue(void) {
    if(this->isEmpty()) {
        throw EMPTY_DEQUEUE_MSG;
    } else {
        this->length--;
        QueueNode<T>* newfront = this->front->getNext();
        T* element = this->front->get();
        delete this->front;
        this->front = newfront;
        
        if(this->isEmpty()) {
            this->back = nullptr;
        } else if(this->getLength() == 1) {
            this->back = newfront;
        }

        return element;
    }
}

template <class T>
T* Queue<T>::peek(void) {
    if(this->isEmpty()) {
        throw EMPTY_DEQUEUE_MSG;
    } else {
        return this->front->get();
    }
}

template <class T>
int Queue<T>::getLength(void) {
    return this->length;
}

template <class T>
bool Queue<T>::isEmpty(void) {
    return this->getLength() == 0;
}

/* QueueNode Definitions */

template <class T>
QueueNode<T>::~QueueNode() {

}

template <class T>
QueueNode<T>::QueueNode(T* element) {
    this->element = element;
}

template <class T>
QueueNode<T>* QueueNode<T>::getNext(void) {
    return this->next;
}

template <class T>
void QueueNode<T>::setNext(QueueNode<T>* next) {
    this->next = next;
}

template <class T>
T* QueueNode<T>::get(void) {
    return this->element;
}

#endif