#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
    headList = nullptr;
    tailList = nullptr;
    totalPairs = 0;
}


void MultiMap::add(TKey c, TValue v) {
    TElem newElem = std::make_pair(c, v);
    Node * newNode = new Node(newElem);
    
    newNode->nextAddr = headList;
    newNode->prevAddr = nullptr;
    if (headList != nullptr) {
            headList->prevAddr = newNode; // Update the old head's prevAddr
    }
    headList = newNode;
    if (tailList == nullptr) {
         tailList = newNode; // Update tail if list was empty
    }
    totalPairs++;
}


bool MultiMap::remove(TKey c, TValue v) {
    if (headList == nullptr) {
        return false;
    }
    Node * nomad = headList;
    while (nomad != nullptr && (nomad->elem.first != c || nomad->elem.second != v)) {
        nomad = nomad->nextAddr;
    }
    if (nomad == nullptr) {
        return false;
    }
    //if heads
    if (headList != nullptr && nomad->prevAddr == nullptr) {
        headList = headList->nextAddr;
        if (headList != nullptr) {
            headList->prevAddr = nullptr;
        }
    }
    //else if tails
    else if (tailList != nullptr && nomad->nextAddr == nullptr) {
        tailList = nomad->prevAddr;
        if (tailList != nullptr) {
            tailList->nextAddr = nullptr;
        }
    }
    else {
        if (nomad->nextAddr != nullptr) {
            nomad->nextAddr->prevAddr = nomad->prevAddr;
        }
        
        if (nomad->prevAddr != nullptr) {
            nomad->prevAddr->nextAddr = nomad->nextAddr;
        }
    }
    //else in between
    delete nomad;
    totalPairs--;
	return  true;
}


vector<TValue> MultiMap::search(TKey c) const {
    Node * nomadNode = headList;
    vector<TValue> result; //creates an array called Result[] of tval types inside
    
    while (nomadNode != nullptr) {
        if (nomadNode->elem.first == c) {
            result.push_back(nomadNode->elem.second);
        }
        nomadNode = nomadNode->nextAddr;
    }
	return result;
}


int MultiMap::size() const {
    return totalPairs;
}


bool MultiMap::isEmpty() const {
	return totalPairs == 0;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
    while (headList != nullptr) {
        Node * temp = headList;
        headList = headList->nextAddr;
        delete temp;
    }
}
