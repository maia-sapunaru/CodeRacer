//
// Created by Maia Sapunaru on 23.05.2025.
//

#ifndef RAPORT_H
#define RAPORT_H
#include<iostream>
#include<queue>
#include<vector>
#include<functional>

template <typename T>
class Raport {
    std::priority_queue<T*, std::vector<T*>, std::function<bool(T*, T*) >>  pq;

public:
    Raport(std::function<bool(T*, T*) > comp);
    void add(T* t);
    T* get() const;
    void showOrder() const;
};

template <typename T>
Raport<T>::Raport(std::function<bool(T*, T*) > comp) : pq(comp) {}

template <typename T>
void Raport<T>::add(T* t) {
  pq.push(t);
}

template <typename T>
T* Raport<T>::get() const {
  return pq.top();
}

template <typename T>
void Raport<T>::showOrder() const {
    std::priority_queue<T*, std::vector<T*>, std::function<bool(T*, T*) >> copy = pq;
    int pos = 1;
    while (!pq.empty()) {
      T* t = copy.top();
      std::cout << pos++ << ". " << *t << std::endl;
      copy.pop();
      pos++;
    }
}

#endif //RAPORT_H
