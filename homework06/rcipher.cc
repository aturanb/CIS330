#include <string>
#include <iostream>
#include "rcipher.h"

// -------------------------------------------------------
// ROT13 Cipher implementation
// -------------------------------------------------------
struct RCipher::CipherCheshire{
	string cipher_alpha;
};

RCipher::RCipher()
{
	smile->cipher_alpha = "nopqrstuvwxyzabcdefghijklm";
}
RCipher::~RCipher()
{
	
}


