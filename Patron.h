#ifndef PATRON_H
#define PATRON_H

#include <string> 
#include <unordered_map> 
#include <iostream> 
#include <unordered_set>

class Patron{
    private:
        int id;

    public:
        //   ||CONSTRUCTOR|| creates new patron with given id
        Patron(int new_id); 

        //   ||getID|| returns patrons id
        int getID(); 
};

#endif