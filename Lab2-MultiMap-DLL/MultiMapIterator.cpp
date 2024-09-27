#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
    currentElem = col.headList;
}

TElem MultiMapIterator::getCurrent() const{
    if (!valid()) {
        throw exception();
    }
    return currentElem->elem;
}

bool MultiMapIterator::valid() const {
    return currentElem != nullptr;
}

void MultiMapIterator::next() {
    if (!valid()) {
        throw exception();
    }
    currentElem = currentElem->nextAddr;
}

void MultiMapIterator::first() {
    currentElem = col.headList;
}

