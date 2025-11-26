//
// Created by buksa on 11/12/2025.
//

#include "File.h"
#include <iostream>

File::File(const std::string& name, long size)
    : FileSystemItem(name, size) {}

File::File(const File& other)
    : FileSystemItem(other.name, other.size) {}

File& File::operator=(const File& other) {
    if (this != &other) {
        name = other.name;
        size = other.size;
    }
    return *this;
}

long File::getSize() const {
    return size;
}

void File::display(int depth) const {
    std::cout << std::string(depth * 2, ' ') << name << " (" << size << " bajt)" << std::endl;
}

FileSystemItem* File::clone() const {
    return new File(*this);
}