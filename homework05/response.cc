/*
  Implementation of methods for classes Response, AngryResponse, HappyResponse
*/
#include <iostream>
#include <string>
#include <algorithm>

#include "response.h"

using namespace std;

/*
  Implementation of Word class
  Don't worry too hard about these implementations.
  If you'd like to learn more about STL see: 
    https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
*/
string Word::upper()
{
  string result(theWord);
  transform(result.begin(), result.end(), result.begin(), ::toupper);
  return result;
}

string Word::lower()
{
  string result(theWord);
  transform(result.begin(), result.end(), result.begin(), ::tolower);
  return result;
}

/*
  Implementation of Response methods
*/
bool Response::checkAndRespond(const string& inWord, ostream& toWhere)
{
    // This method should check if the current object's keyword is in the input message (inWord) 
    if (inWord.find(keyword.upper()) != string::npos){
	// Send the proper response to the toWhere output streaa
    	respond(toWhere);
	return true;
    }
    return false;
}

void Response::respond(ostream& toWhere)
{
    // This method should 'insert' "I am neither angry nor happy: " followed by
    // the object's response word to the toWhere output stream, along with
    // a newline at the end
    toWhere << "I am neither angry nor happy: " << response << endl;
}


void AngryResponse::respond(ostream& toWhere)
{
    // Implement the 'respond' member function for the AngryResponse class so that
    // the angry rseponse "I am angry: " followed by the object's response word 
    // is inserted to the toWhere output stream, along with a newline at the end
     toWhere << "I am angry: " << response << endl;
}

void HappyResponse::respond(ostream& toWhere)
{
   // Implement the 'respond' member function for the HappyResponse class so that
   // the happy rseponse "I am happy: " followed b y the object's response word 
   // is inserted to the toWhere output stream, along with a newline at the end
     toWhere << "I am happy: " << response << endl;
}
