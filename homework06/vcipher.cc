#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"
#include "vcipher.h"


// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

struct VCipher::CipherCheshire{ string cipher_alpha; };

VCipher::VCipher(){
	smile->cipher_alpha = "";
	for(unsigned int i = 0; i < MAX_LENGTH; i++){ smile->cipher_alpha.push_back('a'); } 
}
VCipher::VCipher(string cipher_keyword){
	//Check for for blank spaces
	int found = -1;
	found = cipher_keyword.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
        if(found != -1){
		cerr << "Error: not a valid Vigenere key word" << endl;
		exit(EXIT_FAILURE);
	}
		
	unsigned int mod = cipher_keyword.size();
	smile->cipher_alpha = "";
	for(unsigned int i = 0; i < MAX_LENGTH; i++){ smile->cipher_alpha.push_back(cipher_keyword[i % mod]); } 
}

VCipher::~VCipher(){}

