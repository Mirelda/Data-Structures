#include <iostream>
#include <cstdlib>

template<typename T>
class Queue{
    T arr[1000];
    int front = -1;
    int rear = 0;
    bool enqueue(T data);
    T dequeue();
    T front();
    T rear();
};

template<typename T>
bool Queue<T>::enqueue(T data){
    arr[++front] = data;
    return true;
}

template<typename T>
T Queue<T>::dequeue(){
    if(rear > front){
        std::cout << "Queue Overflow\n";
        return -1;
    }
    else{
        return arr[rear++];
    }
}

template<typename T>
T Queue<T>::front(){
    return arr[front];
}

template<typename T>
T Queue<T>::rear(){
    return arr[rear];
}


int main(){

    return 0;
}