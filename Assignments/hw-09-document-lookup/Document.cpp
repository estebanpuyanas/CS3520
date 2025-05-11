#include "Document.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



string tolower(const string & str) 
{
  string result; 
  for(string::const_iterator it = str.begin(); it != str.end(); ++it)
  {
    result += static_cast<char>(std::tolower(*it));

  }
  return result;
}

bool read_document(const DocumentName & documentName, Document & document) 
{
    ifstream file(("doc/" + documentName + ".txt").c_str());
    if (!file) { return false; }

    document.words.clear(); // Clear the words vector
    string line;
    while (getline(file, line)) 
    {
        // Ignore lines starting with '#'
        if (!line.empty() && line[0] == '#') {
            continue;
        }

        istringstream iss(line);
        string word;
        while (iss >> word) 
        {
            document.words.push_back(tolower(word)); // Add lowercase words to the vector
        }
    }
    return true;
}

void read_documents(const std::vector<DocumentName> & documentNames, std::vector<Document> & documents) 
{
  documents.clear(); // Clear the documents vector before adding new documents

  for (std::vector<DocumentName>::const_iterator it = documentNames.begin(); it != documentNames.end(); ++it) 
  {
      Document document;
      document.documentName = *it; // Set the document name

      // Attempt to read the document
      if (read_document(*it, document)) 
      {
          documents.push_back(document); // Add the document to the vector if successfully read
      }
  }
}

void display_document(const Document & document) 
{
    cout << "document: " << document.documentName << endl;
    for (vector<Word>::const_iterator it = document.words.begin(); it != document.words.end(); ++it) 
    {
        cout << "word: " << *it << endl;
    }
}