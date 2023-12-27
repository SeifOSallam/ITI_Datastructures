#include <iostream>

using namespace std;
template <class T>
struct Node {
    Node* next;
    T data;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
    Node() {
        next = NULL;
    }
};
template <class T>
class Stack {
public:
    Node<T>* head;
    Stack() {
        head = NULL;
    }
    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }
    T pop() {
        if (head != NULL) {
            Node<T>* tempNode = head;
            head = head->next;
            T poppedData = tempNode->data;
            delete tempNode;
            return poppedData;
        }
        else {
            cout<<"Empty Stack"<<endl;
            return -1;
        }
    }
    void printStack() {
        Node<T>* currNode = head;
        while (currNode != NULL) {
            cout<<currNode->data<<"  ";
            currNode = currNode->next;
        }
        cout<<endl;
    }
    void clearStack() {
        Node<T>* currNode = head;
        while (currNode != NULL) {
            Node<T>* tempNode = currNode;
            currNode = currNode->next;
            delete tempNode;
        }
    }
    ~Stack() {
        clearStack();
    }
};

template <class T>
class Queue {
public:
    Node<T>* head;
    Node<T>* tail;

    Queue() {
        head = NULL;
        tail = NULL;
    }
    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    void dequeue() {
        if (head == NULL) {
            cout<<"Queue is empty!"<<endl;
            return;
        }
        else {
            Node<T>* tempNode = head;
            head = head->next;
            delete tempNode;
        }
    }
    void queuePrint() {
        Node<T>* currNode = head;
        while (currNode != NULL) {
            cout<<currNode->data<<"  ";
            currNode = currNode->next;
        }
        cout<<endl;
    }
    void clearQueue() {
        Node<T>* currNode = head;
        while (currNode != NULL) {
            Node<T>* tempNode = currNode;
            currNode = currNode->next;
            delete tempNode;
        }
    }
    ~Queue() {
        clearQueue();
    }
};
template <class T>
void reverseStack(Stack<T>* myStack) {
    Node<T>* currNode = myStack->head;
    Node<T>* prevNode = NULL;
    while(currNode != NULL) {
        Node<T>* tempNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = tempNode;
    }
    myStack->head = prevNode;
}

template <class T>
void reverseQueue(Queue<T>* myQueue) {
    Node<T>* currNode = myQueue->head;
    myQueue->tail = myQueue->head;
    Node<T>* prevNode = NULL;
    while(currNode != NULL) {
        Node<T>* tempNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = tempNode;
    }
    myQueue->head = prevNode;
}
template <class T>
Stack<T> mergeStacks(Stack<T>* firstStack, Stack<T>* secondStack) {
    Stack<T> mergedStack;
    Node<T>* firstHeader = firstStack->head;
    Node<T>* secondHeader = secondStack->head;
    while (firstHeader != NULL) {
        mergedStack.push(firstHeader->data);
        firstHeader = firstHeader->next;
    }
    while (secondHeader != NULL) {
        mergedStack.push(secondHeader->data);
        secondHeader = secondHeader->next;
    }
    return mergedStack;
}

template <class T>
Queue<T> mergeQueues(Queue<T>* firstQueue, Queue<T>* secondQueue) {
    Queue<T> mergedQueue;
    Node<T>* firstHeader = firstQueue->head;
    Node<T>* secondHeader = secondQueue->head;
    while (firstHeader != NULL) {
        mergedQueue.enqueue(firstHeader->data);
        firstHeader = firstHeader->next;
    }
    while (secondHeader != NULL) {
        mergedQueue.enqueue(secondHeader->data);
        secondHeader = secondHeader->next;
    }
    return mergedQueue;
}

int main()
{
    Stack<int>* myStack = new Stack<int>();
    myStack->push(3);
    myStack->push(5);
    myStack->push(7);
    myStack->printStack();
    cout<<myStack->pop()<<endl;
    myStack->printStack();
    cout<<endl<<endl<<endl;
    Queue<int>* myQueue = new Queue<int>();
    myQueue->enqueue(10);
    myQueue->enqueue(20);
    myQueue->enqueue(30);
    myQueue->queuePrint();
    myQueue->dequeue();
    myQueue->queuePrint();
    cout<<endl<<endl<<endl;
    myStack->push(10);
    myStack->push(20);
    myStack->printStack();
    reverseStack(myStack);
    myStack->printStack();
    cout<<endl<<endl<<endl;
    myQueue->enqueue(50);
    myQueue->enqueue(60);
    myQueue->enqueue(70);
    myQueue->queuePrint();
    reverseQueue(myQueue);
    myQueue->queuePrint();
    cout<<endl<<endl<<endl;
    Stack<int>* myStack2 = new Stack<int>();
    myStack2->push(50);
    myStack2->push(100);
    myStack2->push(150);
    cout<<"Stack 1: ";myStack->printStack();
    cout<<"Stack 2: ";myStack2->printStack();
    cout<<"Merged: ";mergeStacks(myStack, myStack2).printStack();
    cout<<endl<<endl<<endl;
    Queue<int>* myQueue2 = new Queue<int>();
    myQueue2->enqueue(300);
    myQueue2->enqueue(400);
    myQueue2->enqueue(500);
    cout<<"Queue 1: ";myQueue->queuePrint();
    cout<<"Queue 2: ";myQueue2->queuePrint();
    cout<<"Merged: ";mergeQueues(myQueue, myQueue2).queuePrint();

}
