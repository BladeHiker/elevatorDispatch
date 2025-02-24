//
// Created by 孙文礼 on 2021/4/27.
//

#include "Dispatch.h"
void Dispatch::press(int index1, int index2, Person person) {
    elevators[index1].press(index2, person);
}

void Dispatch::pressup(int index, Person person) {
    peopleup[index].push(person);
}

void Dispatch::pressdown(int index, Person person) {
    peopledown[index].push(person);
}

void Dispatch::display() {
    std::cout << "people up" << std::endl;
    for (int i = 0; i < fNum; i++) {
        for (int j = 0; j < peopleup[i].size(); j++) {
            std::cout << i << " " << peopleup[i].front().getW() << std::endl;
            peopleup[i].push(peopleup[i].front());
            peopleup[i].pop();
        }
    }
    std::cout << std::endl;
    std::cout << "people down" << std::endl;
    for (int i = 0; i < fNum; i++) {
        for (int j = 0; j < peopledown[i].size(); j++) {
            std::cout << i << " " << peopledown[i].front().getW() << std::endl;
            peopledown[i].push(peopledown[i].front());
            peopledown[i].pop();
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < eNum; i++) {
        std::cout << "num:" << i << std::endl;
        elevators[i].display();
    }
}

Elevator &Dispatch::getelevator(int index) {
    return this->elevators[index];
}

std::queue<Person> &Dispatch::getpeopleup(int index) {
    return this->peopleup[index];
}

std::queue<Person> &Dispatch::getpeopledown(int index) {
    return this->peopledown[index];
}

void Dispatch::leave(int index1, int index2) {
    this->elevators[index1].leave(index2);
}