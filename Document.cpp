#include "Document.h"


Document::Document(int set_id, int set_license_limit, std::string set_name) : 
id(set_id), license_limit(set_license_limit), current_patrons(0), name(set_name){}


void Document::returnDocument(int patronID){
    if(patrons.count(patronID)){
        patrons.erase(patronID); 
        current_patrons--; 
    }
    else std::cout << "ERROR: cannot return document (from document class) "; 
}


bool Document::borrowDocument(int patronID){
    if(license_limit <= current_patrons)
        return 0; 
    else{
        patrons.insert(patronID);
        current_patrons++; 
        return 1; 
    }
}