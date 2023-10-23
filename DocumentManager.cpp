#include "DocumentManager.h"


void DocumentManager::addDocument(std::string name, int id, int license_limit){
    
    //create new document with given details
    Document* new_document = new Document (id, license_limit, name); 

    //put new document into unordered map with id as its key
    documentManager.insert(std::make_pair(id, new_document)); 

    //adds documents name into unordered set for search
    document_names.insert(std::make_pair(name, id)); 
}


void DocumentManager::addPatron(int patronID){
    patron_list.insert(patronID); 
 }


void DocumentManager::returnDocument(int docid, int patronID){
    
    //if documents id exists, then return the document
    //The 2nd returnDocument is within Document.cpp and checks if patron has borrowed the document
    if(documentManager.count(docid)){
        documentManager.find(docid)->second->returnDocument(patronID); 
    }
    else std::cout << "ERROR: cannot return document"; 
}


int DocumentManager::search(std::string name){ 
    //if documents name exists, return docs ID
    if(document_names.count(name)){
        return document_names.find(name)->second; 
    }
    else return 0; 
}


 bool DocumentManager::borrowDocument(int docid, int patronID){
    //if document exists and patron exists, borrow document.
    //else, return 0
    if(documentManager.count(docid) > 0 && patron_list.count(patronID) > 0){
        Document* document = documentManager.find(docid)->second; 
        return document->borrowDocument(patronID); 
    }
    else return 0; 
 }