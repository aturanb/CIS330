#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"

struct CCipher::CipherCheshire{
	string cipher_alpha;
};
// -------------------------------------------------------
// Caesar Cipher implementation

CCipher::CCipher(){ }

CCipher::CCipher(int rot)
{	//Check if rot smaller than zero
	if(rot < 0){
		cerr << "Error: Caesar cipher is less than 0" << endl;
		exit(EXIT_FAILURE);
	}
	rotate_string(smile->cipher_alpha, rot);
}

CCipher::~CCipher(){ }

// -------------------------------------------------------


// Rotates the input string in_str by rot positions
void rotate_string(string& in_str, int rot)
{
    for(int i = 0; i < (rot % 26); i++){
    	for(unsigned int j = 1; j < in_str.size(); j++){
		swap(in_str[j-1], in_str[j]);
	}
	//cout << in_str << endl;
    }
}
