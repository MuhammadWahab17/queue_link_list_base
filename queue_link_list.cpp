//
//  main.cpp
//  queue_link_list
//
//  Created by Ch Muhammad Wahab on 14/11/2020.
//  Copyright © 2020 Ch Muhammad Wahab. All rights reserved.
//

#include <iostream>
#include<iostream>
using namespace std;
template<typename T>
struct node {
    T data;
    node<T>* next;
};
template<typename T>
class queue {
    node<T>* rear_idx;
    node<T>* front_idx;
public:
    queue() {
        rear_idx = front_idx = NULL;
    }
    ~queue() {
        make_empty();
    }
    bool empty() const {
        return rear_idx == NULL;
    }
    void push(const T& val) {
        if (full())
            throw("Queue Overflow!");
        node<T>* temp;
        temp = new node<T>;
        temp->data = val;
        temp->next = NULL;
        if (empty()) {
            rear_idx = temp;
            front_idx = rear_idx;
        }
        else {
            rear_idx->next = temp;
            rear_idx = temp;
        }
    }
    void pop() {
        if (empty())
            throw("Queue Underflow!");
        node<T>* temp;
        temp = front_idx;
        front_idx = front_idx->next;
        delete temp;
        if (front_idx == NULL)
            rear_idx = NULL;
    }
    T front() const {
        if (empty())
            throw("Queue is empty!");
        return front_idx->data;
    }
    bool full() const {
        node<T>* temp;
        temp = new node<T>;
        if (temp == NULL)
            return true;
        else {
            delete temp;
            return false;
        }
    }
    void make_empty() {
        while (!empty())
            pop();
    }
    void operator=(const queue<T>& s) {
        make_empty();
        node<T>* temp;
        temp = s.front_idx;
        while (temp != NULL) {
            push(temp->data);
            temp = temp->next;
        }
    }
    queue(const queue<T>& s) {
        rear_idx = front_idx = NULL;
        operator=(s);
    }
};
bool element_check(queue<int> a,queue<int> b){
    int c1,c2;
    c1=c2=0;
    while(!a.empty()){
        a.pop();  c1++;
    }
    while(!b.empty()){
        b.pop();  c2++;
    }
    return c1==c2;
}
int main(int argc, const char * argv[]) {
    queue<int> q1,q2;
    for (int i=0; i<5; i++) {
        q1.push(i+5);
    }
    q2=q1;    //Assignment operator
    cout<<"Queue_1:\n";
    while (!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    queue<int> q3=q2;   //copy constructor
    cout<<"\nQueue_2:\n";
    while (!q2.empty()) {
        cout<<q2.front()<<" ";
        q2.pop();
    }
    cout<<"\nQueue_3:\n";
    while (!q3.empty()) {
        cout<<q3.front()<<" ";
        q3.pop();
    }
    //now q1,q2,q3 all are empty we will push some element and check the number of elements in both are or not
    for (int i=0; i<5; i++) {
        q1.push(i+5);
        q2.push(i+8);
    }
    if(element_check(q1, q2))
        cout<<"\nNumber of elements in Q1 and Q2 are same\n";
    else
        cout<<"\nNumber of elements in Q1 and Q2 are not same\n";
}
