#include <iostream>
#include <cstdlib>
#include <string>

template<typename T>
class Stack{
public:
    int top = -1;
    T arr[1000];
    bool push(T data);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
};

template<typename T>
bool Stack<T>::isEmpty(){
    return top < 0;
}

template<typename T>
bool Stack<T>::isFull(){
    return top == 1000;
}

template<typename T>
bool Stack<T>::push(T data){
    if(isFull()){
        std::cout << "Stack Overflow\n";
        return false;
    }else{
        arr[++top] = data;
        std::cout << data << " pushed to Stack\n";
        return true;
    }

}

template<typename T>
T Stack<T>::pop(){
    if(isEmpty()){
        std::cout << "Stack Underflow\n";
        return -1;
    }else{
        return arr[top--];
    }
}

template<typename T>
T Stack<T>::peek(){
    if(isEmpty()){
        std::cout << "Stack Underflow\n";
        return -1;
    }else{
        return arr[top];
    }
}


int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
  
// The main function to convert infix expression 
//to postfix expression 
void infixToPostfix(std::string s) 
{ 
    Stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    std::string ns; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
        ns+=s[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == '(') 
          
        st.push('('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ')') 
        { 
            while(st.peek() != 'N' && st.peek() != '(') 
            { 
                char c = st.peek(); 
                st.pop(); 
               ns += c; 
            } 
            if(st.peek() == '(') 
            { 
                char c = st.peek(); 
                st.pop(); 
            } 
        } 
          
        //If an operator is scanned 
        else{ 
            while(st.peek() != 'N' && prec(s[i]) <= prec(st.peek())) 
            { 
                char c = st.peek(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(s[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(st.peek() != 'N') 
    { 
        char c = st.peek(); 
        st.pop(); 
        ns += c; 
    } 
      
    std::cout << ns << std::endl; 
  
} 


int main(){

    std::string exp = "a+b*(c^d-e)^(f+g*h)-i"; 
    infixToPostfix(exp);

    return 0;
}