#include <iostream>
#include <cstdlib>

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
public:
    static int len;
    Node* first = NULL;
    Node* last = NULL;
    void createList(int data);
    void append(int data);
    void push(int data);
    void insert(int index, int data);
    Node* findNode(int index);
    Node* findData(int data);
    void deleteIndex(int index);
    void deleteData(int data);
    bool isEmpty();
    void traverse();
};

int LinkedList::len = 0;

bool LinkedList::isEmpty(){
    return first == NULL;
}

void LinkedList::createList(int data){
    Node* pNode = new Node;
    pNode -> data = data;
    first = pNode;
    first->next = NULL;
    last = first;
    len++;
}

Node* LinkedList::findNode(int index){
    Node* temp = first;
    int count = 0;
    while(temp != NULL && count < index - 1){
        temp = temp -> next;
        count++;
    }
    return temp;
}

Node* LinkedList::findData(int data){
    Node* temp = first;
    while(temp != NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void LinkedList::append(int data){
    if(isEmpty()){
        createList(data);
    }else{
        Node* pNode = new Node;
        pNode->data = data;
        last->next = pNode;
        pNode->next = NULL;
        last = pNode;
        len++;
    } 
}

void LinkedList::push(int data){
    if(isEmpty()){
        createList(data);
    }else{
        Node* pNode = new Node;
        pNode->data = data;
        pNode->next = first;
        first = pNode;
        len++;
    }
}

void LinkedList::insert(int index, int data){
    Node* pNode = new Node;
    pNode->data = data;

    if(index == 1){
            push(data);
        }
    try{
        len++;
        if(index > len){
            throw "Enter a valid index\n";
        }
        else{
            Node* bNode = findNode(index - 1);
            pNode->next = bNode->next;
            bNode->next = pNode;
        }
    }
    catch(const char* exp){
            std::cout << "Index Error: " << exp;
    }
}

void LinkedList::deleteData(int data){
    Node* temp = NULL;
    Node* prev = NULL;
    if(first->data == data){
        temp = first;
        first = first->next;
        delete temp;
    }else{
        temp = first->next;
        prev = first;
        while(temp != NULL){
            if(temp->data == data){
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = prev->next;
            temp = temp->next;
        }
    }
    len--;
}

void LinkedList::deleteIndex(int index){
    Node* temp = NULL;
    Node* prev = NULL;
    if(index == 1){
        temp = first;
        first = first->next;
        delete temp;
    }else{
        temp = first->next;
        prev = first;
        int count = 2;
        while(temp != NULL && count < index){
            prev = temp;
            temp = temp->next;
            count++;
        }
        prev->next = temp->next;
        delete temp;
    }
}

void LinkedList::traverse(){
    Node* temp = first;
    int count = 1;
    while(temp != NULL){
        std::cout << count << ".Node: " << temp->data << std::endl;
        count++;
        temp=temp->next;
    }
}

int main(){

    return 0;
}