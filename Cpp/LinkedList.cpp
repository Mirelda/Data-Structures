#include <iostream>
#include <cstdlib>

//Node Class for List itself
class Node{
public:
    int data;
    Node* next;
};

//List Class itself and necessary functions
class LinkedList{
public:
    static int len; //Static int variable to keep track of the number of nodes
    Node* first = NULL; // First and last points of the list itself to keep track of adress
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

int LinkedList::len = 0; //Initial value of nodes

bool LinkedList::isEmpty(){ //To control if list is empty
    return first == NULL;
}

void LinkedList::createList(int data){
    Node* pNode = new Node; //Creation of new node
    pNode->data = data;   
    first = pNode;
    first->next = NULL; //Because this is the first node of the list I created the list itself with one node
    last = first;
    len++;  //I will increase len everytime I create a node
}

Node* LinkedList::findNode(int index){  //Function to get the Node from its index
    Node* temp = first;                 //I used this function just for the sake of insert function
    int count = 0;
    while(temp != NULL && count < index - 1){
        temp = temp -> next;            //It gets to the next node everytime count is less than index itself
        count++;                        //This make function to stop its index point
    }
    return temp;
}

Node* LinkedList::findData(int data){   //Made this function just for to get the data on the list
    Node* temp = first;
    while(temp != NULL){
        if(temp->data == data){
            return temp;                //Searches data by looping through list
        }
        temp = temp->next;
    }
    return NULL;
}

void LinkedList::append(int data){      //Creating and adding node to the end of the list
    if(isEmpty()){
        createList(data);
    }else{
        Node* pNode = new Node;         
        pNode->data = data;             
        last->next = pNode;             //Makes the added node itself next of the last node
        pNode->next = NULL;             
        last = pNode;                   //And makes the added node itself last node so list doesn't lost ending point
        len++;
    } 
}

void LinkedList::push(int data){        //Creating and adding node to the beginning of the list
    if(isEmpty()){
        createList(data);
    }else{
        Node* pNode = new Node;
        pNode->data = data;
        pNode->next = first;            //Makes the first node itself next to the added node
        first = pNode;                  //And changes the starting point to the added node so list doesn't lost starting point
        len++;
    }
}

void LinkedList::insert(int index, int data){ //To insert data anywhere on the list
    Node* pNode = new Node;
    pNode->data = data;

    if(index == 1){                           //Insert at the beginning
            push(data);
        }
    try{
        len++;
        if(index > len){                      //Controls if the index entered by user is above the lenght of the list
            throw "Enter a valid index\n";    //If it is throws an error  
        }
        else{
            Node* bNode = findNode(index - 1);  //This finds the previous node so created node can be added after the previous node
            pNode->next = bNode->next;          //Makes the changes 
            bNode->next = pNode;
        }
    }
    catch(const char* exp){
            std::cout << "Index Error: " << exp;    //Error catching
    }
}

void LinkedList::deleteData(int data){     //Deletes the entered data
    Node* temp = NULL;                     //To keep track of the points I made temp and prev
    Node* prev = NULL;
    if(first->data == data){               //If data is in the first node delete the first node
        temp = first;
        first = first->next;               //Used temp to doesn't lose the first pointer itself
        delete temp;
    }else{
        temp = first->next;                //Starting point for variables
        prev = first;
        while(temp != NULL){
            if(temp->data == data){
                prev->next = temp->next;
                delete temp;               //When find the data make its previous to follow its next node to not lose the list's link
                break;                     //Then delete the node
            }
            prev = prev->next;
            temp = temp->next;
        }
    }
    len--;                                 //Don't forget the decrease the lenght of the list
}

void LinkedList::deleteIndex(int index){  //Same with the deleteData function but this deletes with respect to its index point
    Node* temp = NULL;
    Node* prev = NULL;                    //Same variables to keep track of points
    if(index == 1){
        temp = first;
        first = first->next;
        delete temp;
    }else{
        temp = first->next;
        prev = first;
        int count = 2;                    //Just added a count variable to keep track of the point in the list
        while(temp != NULL && count < index){   //Made it equal the zero because temp is in the point 2 at that time
            prev = temp;
            temp = temp->next;                  //Everytime node continues increase count as well
            count++;
        }
        prev->next = temp->next;
        delete temp;                            //When found make the same trick. Don't lose link and delete the unlinked node
    }
    len--;
}

void LinkedList::traverse(){
    Node* temp = first;
    int count = 1;                              //Just loops through list and make them printed on the screen
    while(temp != NULL){                        //Used count to make a fancy printing
        std::cout << count << ".Node: " << temp->data << std::endl;
        count++;
        temp=temp->next;
    }
}

int main(){
    //Example (Created a fibonacci series and deleted the wrong data)
    LinkedList A;
    A.append(52);
    A.append(3);
    A.push(2);
    A.push(1);
    A.insert(4, 5);
    A.append(8);
    A.append(13);
    A.traverse();
    A.deleteData(52);
    A.traverse();
    return 0;
}