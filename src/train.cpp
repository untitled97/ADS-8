// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() :first(nullptr), countOp(0) {}
void Train::addCage(bool light) {
    Cage* cage = new Cage;
    cage->light = light;
    if (first == nullptr) {
        first = cage;
        first->next = nullptr;
        first->prev = nullptr;
    } else if (first->prev == nullptr) {
        first->prev = cage;
        first->next = cage;
        cage->prev = first;
        cage->next = first;
    } else {
        first->prev->next = cage;
        cage->prev = first->prev;
        first->prev = cage;
        cage->next = first;
    }
}

int Train::getLength() {
    Cage* ptr = first;
    first->light = true;
    uint64_t counter = 1;
    ptr = ptr->next;
    countOp++;
    while (ptr) {
        if (ptr->light) {
            ptr->light = false;
            for (int i = 0; i < counter; i++) {
                ptr = ptr->prev;
                countOp++;
            }
            if (!ptr->light) {
                return counter;
            } else {
                counter = 1;
                ptr = ptr->next;
                countOp++;
            }
        } else {
            ptr = ptr->next;
            counter++;
            countOp++;
        }
    }
    return 0;
}
int Train::getOpCount() {
    return countOp;
}
