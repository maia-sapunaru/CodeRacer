//
// Created by Maia Sapunaru on 23.05.2025.
//

#ifndef OVERHEATED_H
#define OVERHEATED_H
#include<stdexcept>


class Overheated : public std::runtime_error {
public:
    Overheated(const std::string& smt) : std::runtime_error(smt) {}
};



#endif //OVERHEATED_H
