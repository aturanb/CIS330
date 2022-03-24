#ifndef KCIPHER_H_
#define KCIPHER_H_
#include "cipher.h"
#include "ccipher.h"

using namespace std;

const unsigned int MAX_LENGTH = 100;

/* A class that implements a
   Running key cipher class. It 
   inherts class Cipher */
class KCipher : public Cipher
{
	protected:
		struct KCipherCheshire;
		KCipherCheshire *mysmile;
	public:
		KCipher();
		KCipher(string page);
		virtual void add_key(string new_page);
		virtual void set_id(unsigned int num);
		~KCipher();
		virtual string encrypt(string raw);
		virtual string decrypt(string enc);
};

string remove_space(string s);

#endif

