#include <iostream>

using namespace std;

template <class T>
struct Node {
    Node* next;
    Node* prev;
    T data;
    Node(){
        next=NULL;
        prev=NULL;
    }
    Node(T data) {
        this->data = data;
        next=NULL;
        prev=NULL;
    }
};

template <class T>
class LinkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    int size;
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    LinkedList(const LinkedList<T>& secondList) {

        Node<T>* scndPtr = secondList.head;
        if (scndPtr != NULL) {
            head = new Node<T>(scndPtr->data);
            Node<T>* firstPtr = this->head;
            scndPtr = scndPtr->next;
            while (scndPtr != NULL) {
                firstPtr->next = new Node<T>(scndPtr->data);
                scndPtr = scndPtr->next;
                firstPtr = firstPtr->next;
            }
            tail = firstPtr;
        }
        size = secondList.size;
    }
    void insertNode(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
            tail = head;
            size++;
            return;
        }
        else {
            Node<T>* currNode = head;
            while (currNode->next != NULL) {
                currNode = currNode->next;
            }
            currNode->next = newNode;
            tail = currNode->next;
            size++;
        }
    }
    void insertNode(T data, int index) {
        if (index > size) {
            cout<<"Error, index out of bounds!"<<endl;
            return;
        }
        else if(index == size){
            tail->next = new Node<T>(data);
            tail = tail->next;
        }
        else {
            Node<T>* currNode = head;
            int i=1;
            while (i != index) {
                currNode = currNode->next;
                i++;
            }
            Node<T>* tempNode = currNode->next;
            currNode->next = new Node<T>(data);
            currNode->next->next = tempNode;
        }
        size++;
    }
    void deleteNode(T data) {
        if (head->data == data) {
            head = head->next;
        }
        else {
            Node<T>* currNode = head;
            int i=1;
            while (currNode->next->data != data) {
                currNode = currNode->next;
                i++;
                if (i == size) {
                    cout<<"Element not found!"<<endl;
                    return;
                }
            }
            Node<T>* tempNode = currNode->next->next;
            currNode->next = NULL;
            currNode->next = tempNode;
        }
        size--;
    }
    int searchNode(T data) {
        Node<T>* tempNode = head;
        int ctr=0;
        if (tempNode == NULL) {
            return -1;
        }
        else if(tail->data == data) {
            return size-1;
        }
        else {
            while (tempNode != NULL) {
                if (tempNode->data == data) {
                    return ctr;
                }
                ctr++;
                tempNode = tempNode->next;
            }
        }
        return -1;
    }
    Node<T>* getNodeAtIndex(int index) {
        if (index >= size) {
            return NULL;
        }
        else if (index == 0) {
            return head;
        }
        else if (index == size-1) {
            return tail;
        }
        else {

            Node<T>* currNode = head;
            int i=0;
            while (i != index) {
                currNode = currNode->next;
                i++;
            }
            return currNode;
        }
    }
    bool isEmpty() {
        return (head == NULL);
    }
    void printList() {
        Node<T>* currNode = head;
        while (currNode != NULL) {
            cout<<currNode->data<<"  ";
            currNode = currNode->next;
        }
        cout<<endl;
    }
    void clearList() {
        delete head;
    }
};

template <class T>
LinkedList<T> sortList(LinkedList<T>* myList) {
    LinkedList<T>* sortedList = new LinkedList<T>(*myList);
    for (int i = 0; i < sortedList->size - 1; i++) {
        for (int j = 0; j < sortedList->size - i - 1; j++) {
            if (sortedList->getNodeAtIndex(j)->data > sortedList->getNodeAtIndex(j+1)->data) {
                if (j == 0) {
                    Node<T>* frstNode = sortedList->getNodeAtIndex(j);
                    Node<T>* scndNode = sortedList->getNodeAtIndex(j+1);
                    frstNode->next = scndNode->next;
                    scndNode->next = frstNode;
                    sortedList->head = scndNode;
                }
                else {
                    Node<T>* frstNode = sortedList->getNodeAtIndex(j);
                    Node<T>* scndNode = sortedList->getNodeAtIndex(j+1);
                    frstNode->next = scndNode->next;
                    scndNode->next = frstNode;
                    sortedList->getNodeAtIndex(j-1)->next = scndNode;
                    if (j == sortedList->size-2) {
                        sortedList->tail = frstNode;
                    }
                }

            }
        }
    }
    return *sortedList;
}

int main()
{
    LinkedList<int>* myList = new LinkedList<int>();
    myList->insertNode(5);
    myList->insertNode(15);
    myList->insertNode(25);
    cout<<"Value 25 is at index: "<<myList->searchNode(25)<<endl<<endl<<endl;
    LinkedList<int>* scndList = new LinkedList<int>(*myList);
    myList->insertNode(35);
    cout<<"List 1: ";myList->printList();
    cout<<"List 2: ";scndList->printList();
    cout<<endl<<endl<<endl;
    myList->insertNode(100, 4);
    cout<<"List 1: ";myList->printList();
    myList->insertNode(100, 2);
    cout<<"List 1: ";myList->printList();
    cout<<endl<<endl<<endl;
    myList->deleteNode(15);
    cout<<"List 1: ";myList->printList();
    myList->deleteNode(5);
    cout<<"List 1: ";myList->printList();
    myList->deleteNode(100);
    cout<<"List 1: ";myList->printList();
    myList->deleteNode(100);
    cout<<"List 1: ";myList->printList();
    cout<<endl<<endl<<endl;
    scndList->insertNode(3);
    scndList->insertNode(19);
    scndList->insertNode(16);
    scndList->insertNode(8);
    cout<<"BEFORE SORT: ";scndList->printList();
    cout<<"AFTER SORT: ";sortList(scndList).printList();
}
