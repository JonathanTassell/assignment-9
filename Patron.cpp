#include "Patron.h"

Patron::Patron(int new_id) : id(new_id){}

int Patron::getID(){
    return this->id; 
}