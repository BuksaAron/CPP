#include "Directory.h"
#include <iostream>
#include <algorithm>

Directory::Directory(const std::string& name)
    : FileSystemItem(name, 0) {}

Directory::Directory(const Directory& other)
    : FileSystemItem(other.name, other.size) {
    for (auto child : other.children) {
        children.push_back(child->clone());
    }
}

Directory& Directory::operator=(const Directory& other) {
    if (this != &other) {
        for (auto child : children) {
            delete child;
        }
        children.clear();

        name = other.name;
        size = other.size;

        for (auto child : other.children) {
            children.push_back(child->clone());
        }
    }
    return *this;
}

Directory::~Directory() {
    for (auto item : children) {
        delete item;
    }
    children.clear();
}

void Directory::add(FileSystemItem* item) {
    children.push_back(item);
}

void Directory::remove(const std::string& name) {
    auto it = std::remove_if(children.begin(), children.end(),
        [&](FileSystemItem* item) { return item->getName() == name; });

    for (auto i = it; i != children.end(); ++i)
        delete *i;

    children.erase(it, children.end());
}

FileSystemItem* Directory::find(const std::string& name) {
    for (auto item : children) {
        if (item->getName() == name)
            return item;
    }
    return nullptr;
}

long Directory::getSize() const {
    long total = 0;
    for (auto item : children)
        total += item->getSize();
    return total;
}

void Directory::display(int depth) const {
    std::cout << std::string(depth * 2, ' ') << "[" << name << "]" << std::endl;
    for (auto item : children)
        item->display(depth + 1);
}

FileSystemItem* Directory::clone() const {
    return new Directory(*this);
}

Directory& Directory::operator+=(FileSystemItem* item) {
    add(item);
    return *this;
}

Directory& Directory::operator-=(const std::string& name) {
    remove(name);
    return *this;
}
