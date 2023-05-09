#include<iostream>
#include<chrono>

#define MAX_SIZE 1000000

using namespace std;
using namespace std::chrono;

class Node{
public:
    int data;
    Node* next;
};

class StackArray{
    int top;
    int arr[MAX_SIZE];
public:
    StackArray(){
        top = -1;
    }
    bool isEmpty(){
        return (top == -1);
    }
    bool isFull(){
        return (top == MAX_SIZE-1);
    }
    void push(int value){
        if(isFull()){
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }
    void display(){
        if(isEmpty()){
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for(int i=top;i>=0;i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class StackLinkedList{
    Node* top;
public:
    StackLinkedList(){
        top = NULL;
    }
    bool isEmpty(){
        return (top == NULL);
    }
    void push(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack underflow!" << endl;
            return -1;
        }
        Node* temp = top;
        top = top->next;
        int value = temp->data;
        delete temp;
        return value;
    }
    void display(){
        if(isEmpty()){
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node* temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    StackArray stackArray;
    StackLinkedList stackLinkedList;
    auto start1 = high_resolution_clock::now();
    stackArray.push(8);
    stackArray.push(10);
    stackArray.push(5);
    stackArray.push(11);
    stackArray.push(15);
    stackArray.push(23);
    stackArray.push(6);
    stackArray.push(18);
    stackArray.push(20);
    stackArray.push(17);
    stackArray.display();
    for(int i=0;i<5;i++)
        stackArray.pop();
    stackArray.display();
    stackArray.push(4);
    stackArray.push(30);
    stackArray.push(3);
    stackArray.push(1);
    stackArray.display();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Execution time for Stack using Array: " << duration1.count() << " microseconds" << endl;
    auto start2 = high_resolution_clock::now();
    stackLinkedList.push(8);
    stackLinkedList.push(10);
    stackLinkedList.push(5);
    stackLinkedList.push(11);
    stackLinkedList.push(15);
    stackLinkedList.push(23);
    stackLinkedList.push(6);
    stackLinkedList.push(18);
    stackLinkedList.push(20);
    stackLinkedList.push(17);
    stackLinkedList.display();
    for(int i=0;i<5;i++)
        stackLinkedList.pop();
    stackLinkedList.display();
    stackLinkedList.push(4);
    stackLinkedList.push(30);
    stackLinkedList.push(3);
    stackLinkedList.push(1);
    stackLinkedList.display();
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Execution time for Stack using Linked List: " << duration2.count() << " microseconds" << endl;
    return 0;
}
   
