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
	uint64_t counter = 0;
	while (ptr) {
		ptr = ptr->next;
		if (!ptr->light) {
			ptr->light = true;
			counter++;
			countOp++;
		}
		else {
			ptr->light = false;
			while (counter != 0) {
				ptr = ptr->prev;
				countOp++;
				counter--;
			}
			countOp++;
			if (ptr->light == false)
				return counter;
			else
				counter = 1;
		}
	}
}

int Train::getOpCount() {
	return countOp;
}
