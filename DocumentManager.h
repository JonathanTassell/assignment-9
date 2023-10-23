#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include "Document.h"

class DocumentManager{
    private: 
        //Unordered maps and set
    
        std::unordered_map<int, Document*> documentManager;
        std::unordered_map<std::string, int> document_names; 
        std::unordered_set<int> patron_list; 

    public:     

        //   ||ADD DOCUMENT|| adds new document to unordered map with given data
        void addDocument(std::string name, int id, int license_limit);

        //   ||ADD PATRON|| adds patron to patron_list
        void addPatron(int patronID);

        //   ||RETURN DOCUMENT|| returns a specific users document given its docid (document id)
        void returnDocument(int docid, int patronID);




        //   ||SEARCH DOCUMENT BY NAME|| returns docid if name is in the document collection or 0 if the name is not in the collection
        int search(std::string name); 


        //   ||BORROW DOCUMENT|| returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)
        bool borrowDocument(int docid, int patronID); //make sure to check whether patron exists (note)
       


        //testing functions(s)
        std::unordered_map<int, Document*> returnManager(){
            return documentManager; 
        }

}; 

#endif 