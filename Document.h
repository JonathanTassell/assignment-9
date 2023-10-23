#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "Patron.h"

class Document{
    private:
        //documents data
        int id;
        int license_limit; 
        int current_patrons; 

        //documents name
        std::string name; 

        //unordered set to store the patrons currently borrowing document
        std::unordered_set<int> patrons;

    public:
        //   ||CONSTRUCTOR|| sets values of document 
        Document(int set_id, int set_license_limit, std::string set_name); 

        //   ||RETURN DOCUMENT|| returns document by removing patrons id from set, prints error if patron does not exist
        void returnDocument(int patronID);
        
        //   ||BORROW DOCUMENT|| if patron exists and the current patrons doesn't exceed the limit, then let patron borrow
        bool borrowDocument(int patronID); 
}; 

#endif