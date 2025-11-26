//
// Created by buksa on 11/12/2025.
//

#include "FileSystemItem.h"

FileSystemItem::FileSystemItem(const string &name, long size): name(name), size(size) {}

string FileSystemItem::getName() {
    return name;
}

bool FileSystemItem::operator<(const FileSystemItem &other) const {
    return name < other.name;
}

std::ostream & operator<<(std::ostream &os, const FileSystemItem &item) {
    item.display();
    return os;
}
