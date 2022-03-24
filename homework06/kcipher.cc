#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "kcipher.h"

/* Helper function definitions
 */
//
// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

struct KCipher::CipherCheshire{ string cipher_alpha; };

struct KCipher::KCipherCheshire{ vector<string> pages; };

KCipher::KCipher(){
	mysmile = new KCipherCheshire;
	smile->cipher_alpha = "";
	for(unsigned int i = 0; i < MAX_LENGTH; i++){ smile->cipher_alpha.push_back('a'); }

}

KCipher::KCipher(string page){
	
	//Check if page empty
	if(page.empty()){ 
		cerr << "Invalid Running key: " << page << endl;
		exit(EXIT_FAILURE);
	}
	mysmile = new KCipherCheshire;
	mysmile->pages.push_back(page);
	smile->cipher_alpha = mysmile->pages[0];

}

KCipher::~KCipher(){ delete mysmile; }

void KCipher::add_key(string page){ 
	
	//Check if page empty
	if(page.empty()){  
		cerr << "Invalid Running key: " << page << endl; 
		exit(EXIT_FAILURE); }
        
	//Check if page contains special characters
	int found = -1;
        found = page.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ");	
	if(found != -1){
		cerr << "Invalid Running key: " << page << endl;
		exit(EXIT_FAILURE); }
	
	mysmile->pages.push_back(page); 

}

void KCipher::set_id(unsigned int num){ 

	//Check if set page number bigger than pages
	if(mysmile->pages.size() < num){
		cerr << "Warning: invalid id: " << num << endl;
		exit(EXIT_FAILURE); }

	smile->cipher_alpha = mysmile->pages[num]; 
}

string KCipher::encrypt(string raw)
{
	//Create Tableau
	char tab[26][26];
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for(int i = 0; i < 26; i++){
		if(i!=0){rotate_string(alphabet, 1);}
		for(int j = 0; j < 26; j++){ tab[i][j] = alphabet[j]; }	
	}
 
	string retStr;
	int cipher_ctr = 0;
	smile->cipher_alpha = remove_space(smile->cipher_alpha);
	
	//Traverse raw input
	for(unsigned int i = 0; i < raw.size(); i++){
		bool lower_case = true;
		//Space
		if(raw[i] == ' '){ retStr.push_back(' '); }
		else{
			//Find position of the encryption column
			unsigned int col_pos = find_pos("abcdefghijklmnopqrstuvwxyz", LOWER_CASE(smile->cipher_alpha[cipher_ctr]));
			
			//Find position of the encryption row
			unsigned int row_pos = 0;
			for(unsigned int j = 0; j < 26; j++){
				if(tab[j][0] == LOWER_CASE(raw[i])){ 
					row_pos = j; 
					if(isupper(raw[i])){ lower_case = false; }
				}
			}
			//Add the encrypted letter to retStr and retain the case
			if(lower_case){ retStr.push_back(tab[row_pos][col_pos]); }
			else{ retStr.push_back(UPPER_CASE(tab[row_pos][col_pos])); }
			cipher_ctr++;
		}
	}
	return retStr; 
}

string KCipher::decrypt(string enc){

	//Create Tableau
	char tab[26][26];
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for(int i = 0; i < 26; i++){
		if(i!=0){ rotate_string(alphabet, 1); }
		for(int j = 0; j < 26; j++){ tab[i][j] = alphabet[j]; }	
	}

	string retStr;
	int cipher_ctr = 0;
	smile->cipher_alpha = remove_space(smile->cipher_alpha);
	
	//Traverse encoded input
	for(unsigned int i = 0; i < enc.size(); i++){
		bool lower_case = true;
		//Space
		if(enc[i] == ' '){ retStr.push_back(' '); }
		else{
			//Find where the encryption column is
			unsigned int col_pos = find_pos("abcdefghijklmnopqrstuvwxyz", LOWER_CASE(smile->cipher_alpha[cipher_ctr]));
			
			//Traverse through encryption column and find the row of encrypted letter
			unsigned int row_pos = 0;
			for(unsigned int j = 0; j < 26; j++){
				if(tab[j][col_pos] == LOWER_CASE(enc[i])){ 
					row_pos = j; 
					if(isupper(enc[i])){ lower_case = false; }
				}
			}
		 	
			//Add the first column of the row_pos of tableau to retStr
			if(lower_case){ retStr.push_back(tab[row_pos][0]); }
			else{ retStr.push_back(UPPER_CASE(tab[row_pos][0])); }
			cipher_ctr++;
		}
	}
	return retStr;
}

/* 
  Helper function definitions 
*/

string remove_space(string s){
	
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	return s;
	

}

