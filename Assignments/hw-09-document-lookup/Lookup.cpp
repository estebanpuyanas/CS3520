#include "Lookup.hpp"
using namespace std;


// Helper function to manually sort a vector of strings in ascending order
void manual_sort(Results &results) 
{
    for (size_t i = 0; i < results.size(); ++i) 
    {
        for (size_t j = i + 1; j < results.size(); ++j) 
        {
            if (results[j] < results[i]) 
            {
                // Swap the elements
                DocumentName temp = results[i];
                results[i] = results[j];
                results[j] = temp;
            }
        }
    }
}

// Add a document to the vector collection
void add_document(const Document &doc, VectorCollection &collection) 
{
    for (vector<Word>::const_iterator wordIt = doc.words.begin(); wordIt != doc.words.end(); ++wordIt) 
    {
        bool found = false;

        // Search for the word in the collection
        for (VectorCollection::iterator entryIt = collection.begin(); entryIt != collection.end(); ++entryIt)
         {
            if (entryIt->word == *wordIt) 
            {
                // Word found, add the document name to the set
                entryIt->documentNames.insert(doc.documentName);
                found = true;
                break;
            }
        }

        // If the word is not found, create a new entry
        if (!found) 
        {
            Entry newEntry;
            newEntry.word = *wordIt;
            newEntry.documentNames.insert(doc.documentName);
            collection.push_back(newEntry);
        }
    }
}

// Lookup a word in the vector collection
Results lookup_word(const Word &word, const VectorCollection &collection) 
{
    Results ret;

    // Convert the input word to lowercase
    Word lowerWord = tolower(word);

    for (VectorCollection::const_iterator entryIt = collection.begin(); entryIt != collection.end(); ++entryIt) 
    {
        if (entryIt->word == lowerWord) 
        {
            // Add all document names to the results
            for (set<DocumentName>::const_iterator docIt = entryIt->documentNames.begin(); docIt != entryIt->documentNames.end(); ++docIt) {
                ret.push_back(*docIt);
            }
            break;
        }
    }

    // Ensure results are sorted
    manual_sort(ret);
    return ret;
}

// Add a document to the list collection
void add_document(const Document &doc, ListCollection &collection) 
{
    for (vector<Word>::const_iterator wordIt = doc.words.begin(); wordIt != doc.words.end(); ++wordIt) 
    {
        bool found = false;

        // Search for the word in the collection
        for (ListCollection::iterator entryIt = collection.begin(); entryIt != collection.end(); ++entryIt) 
        {
            if (entryIt->word == *wordIt) 
            {
                // Word found, add the document name to the set
                entryIt->documentNames.insert(doc.documentName);
                found = true;
                break;
            }
        }

        // If the word is not found, create a new entry
        if (!found) 
        {
            Entry newEntry;
            newEntry.word = *wordIt;
            newEntry.documentNames.insert(doc.documentName);
            collection.push_back(newEntry);
        }
    }
}

// Lookup a word in the list collection
Results lookup_word(const Word &word, const ListCollection &collection) 
{
    Results ret;

    // Convert the input word to lowercase
    Word lowerWord = tolower(word);

    for (ListCollection::const_iterator entryIt = collection.begin(); entryIt != collection.end(); ++entryIt) 
    {
        if (entryIt->word == lowerWord) 
        {
            // Add all document names to the results
            for (set<DocumentName>::const_iterator docIt = entryIt->documentNames.begin(); docIt != entryIt->documentNames.end(); ++docIt) 
            {
                ret.push_back(*docIt);
            }
            break;
        }
    }

    // Ensure results are sorted
    manual_sort(ret);
    return ret;
}

// Add a document to the map collection
void add_document(const Document &doc, MapCollection &collection) 
{
    for (vector<Word>::const_iterator wordIt = doc.words.begin(); wordIt != doc.words.end(); ++wordIt) 
    {
        // Check if the word already exists in the map
        MapCollection::iterator entryIt = collection.find(*wordIt);
        if (entryIt != collection.end()) 
        {
            // Word found, add the document name to the set
            entryIt->second.documentNames.insert(doc.documentName);
        } else 
        {
            // Word not found, create a new entry
            Entry newEntry;
            newEntry.word = *wordIt;
            newEntry.documentNames.insert(doc.documentName);
            collection[*wordIt] = newEntry;
        }
    }
}

// Lookup a word in the map collection
Results lookup_word(const Word &word, const MapCollection &collection) 
{
    Results ret;

    // Convert the input word to lowercase
    Word lowerWord = tolower(word);

    // Find the word in the map
    MapCollection::const_iterator entryIt = collection.find(lowerWord);
    if (entryIt != collection.end()) 
    {
        // Add all document names to the results
        for (set<DocumentName>::const_iterator docIt = entryIt->second.documentNames.begin(); docIt != entryIt->second.documentNames.end(); ++docIt) 
        {
            ret.push_back(*docIt);
        }
    }

    // Ensure results are sorted
    manual_sort(ret);
    return ret;
}