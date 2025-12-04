/*
I wanted extra practice utilizing linked lists before my DSA1 Final for December 5, 2025

*/
#include <iostream>
#include <fstream>
#include <string>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    
public:
    Node* getHead()  { return head; }
    
    DoublyLinkedList() : head(nullptr) {
        Node* firstNode = nullptr;
        Node* node50 = nullptr;
        
        for (int i = 0; i < 100; i++) {
            Node* newNode = new Node(i);
            
            if (i == 50) {
                node50 = newNode;
            }
            
            if (firstNode == nullptr) {
                firstNode = newNode;
                firstNode->next = firstNode;
                firstNode->prev = firstNode;
            } else {
                Node* tail = firstNode->prev;
                newNode->next = firstNode;
                newNode->prev = tail;
                tail->next = newNode;
                firstNode->prev = newNode;
            }
        }
        
        head = node50;
    }
    
    ~DoublyLinkedList() {
        if (head == nullptr) return;
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }

};

int main(){

    std::ifstream inputFile("../input.txt");
    std::string currentLine;
    DoublyLinkedList LL;
    int count = 0;
    Node* currentNum = LL.getHead();
    while(std::getline(inputFile, currentLine)){
        bool dialDirection = currentLine.at(0) == 'L' ? 0 : 1;//False left, True right
        int rotations = std::stoi(currentLine.substr(1));

        count += rotations /100;
        rotations %= 100;

        if  (dialDirection){//Rotate Right
            for (int i = 0; i < rotations; i++){
                currentNum = currentNum->next;
                if (currentNum->data == 0) count ++;
            }
        }else{
            for (int i = 0; i < rotations; i++){
                currentNum = currentNum->prev;
                if (currentNum->data == 0) count++;
            }
        }
        std::cout << "Rotating: " << currentLine << std::endl;
        std::cout << "CurrentNum = " << currentNum->data<< std::endl;
    }
    std::cout << "------------------------" << std::endl;
    std::cout << "The count is: "<< count << std::endl;
    return 0;
}