#ifndef RCIPHER_H_ 
#define RCIPHER_H_
#include "ccipher.h"

using namespace std;

/* A class that implements a
   ROT13 cipher class. It 
   inherts class CCipher */
class RCipher : public Cipher
{
	public:
		RCipher();
		~RCipher();
};
#endif

