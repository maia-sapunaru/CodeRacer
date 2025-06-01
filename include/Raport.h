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
    Raport();
    ~Raport();
    void add(T* t);
    T* get() const;
    void showOrder() const;
    bool empty() const;
    void removeTop();

};

template <typename T>
Raport<T>::Raport() : pq([](T* a, T* b) {
    return a->getScore() < b->getScore();
}) {}

template <typename T>
Raport<T>::~Raport() {

}


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
    while (!copy.empty()) {
      T* t = copy.top();
      std::cout << pos << ". " << *t << std::endl;
      copy.pop();
      pos++;
    }
}

template <typename T>
bool Raport<T>::empty() const {
    return pq.empty();
}

template<typename T>
void Raport<T>::removeTop() {
    if (!pq.empty()) pq.pop();
}


#endif //RAPORT_H
