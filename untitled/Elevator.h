//
// Created by 孙文礼 on 2021/4/27.
//
#include "Person.h"
#include "iostream"
#include "queue"
#ifndef ELEVATOR_ELEVATOR_H
#define ELEVATOR_ELEVATOR_H


class Elevator {
private:
    std::queue<Person> people[fNum]; //电梯的按钮  电梯里面的人下电梯是不会被阻碍的
    int place; //plce number  电梯在第几层
    bool direction;
    int maxW;
public:
    Elevator();
    void press(int, Person);//有一个人按下了按钮
    void moveup();
    void move();
    void movedown();
    void leave(int);//  int目的地是这个楼层的人都下楼了
    int getW();
    void display();
    bool getdirection();
    void setdirection(bool);
    void changedirection();
    int getplace();
    int getmaxW();
    std::queue<Person> &getpeople(int );
};


#endif //ELEVATOR_ELEVATOR_H
