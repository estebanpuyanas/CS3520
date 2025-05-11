#include "Document.hpp"
#include "Lookup.hpp"
#include <string>
#include <iostream>
using namespace std;

// TODO: change these as needed
//const DocumentName docname = "primes_small";
//onst int iterations = 1000;
const DocumentName docname = "primes_large";
const int iterations = 1;

void use_vector(const Document &doc) 
{
    for (int ii = 0; ii < iterations; ++ii) 
    {
        VectorCollection collection;

        // Add the document to the vector collection
        add_document(doc, collection);

        // Search for a word that is not in the collection
        Results results = lookup_word("nonexistentword", collection);

        // Optional: Print the results (comment out for performance testing)
        // cout << "Vector results size: " << results.size() << endl;
    }
}

void use_list(const Document &doc) 
{
    for (int ii = 0; ii < iterations; ++ii) 
    {
        ListCollection collection;

        // Add the document to the list collection
        add_document(doc, collection);

        // Search for a word that is not in the collection
        Results results = lookup_word("nonexistentword", collection);

        // Optional: Print the results (comment out for performance testing)
        // cout << "List results size: " << results.size() << endl;
    }
}

void use_map(const Document &doc) 
{
    for (int ii = 0; ii < iterations; ++ii) 
    {
        MapCollection collection;

        // Add the document to the map collection
        add_document(doc, collection);

        // Search for a word that is not in the collection
        Results results = lookup_word("nonexistentword", collection);

        // Optional: Print the results (comment out for performance testing)
        // cout << "Map results size: " << results.size() << endl;
    }
}

int main() 
{
    Document document;

    // Read the document from the file
    if (!read_document(docname, document)) 
    {
        cerr << "Failed to read document: " << docname << endl;
        return 1;
    }

    // Run the performance tests
    use_vector(document);
    use_list(document);
    use_map(document);

    return 0;
}