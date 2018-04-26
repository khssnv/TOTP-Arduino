// OpenAuthentication Time-based One-time Password Algorithm (RFC 6238)
// Arduino Library
//
// Luca Dentella (http://www.lucadentella.it)
// Changed 26 april 2018 by Alisher Khassanov <a.khssnv@gmail.com> to let it work on Libelium Waspmote

#include "Waspmote.h" // Libelium implements <Arduino.h> for Waspmote in <Waspmote.h>

#ifndef _TOTP_H
#define _TOTP_H


class TOTP {

	public:
	
		TOTP(uint8_t* hmacKey, int keyLength);
		TOTP(uint8_t* hmacKey, int keyLength, int timeStep);
		char* getCode(long timeStamp);
		char* getCodeFromSteps(long steps);
	
	private:

		uint8_t* _hmacKey;
		int _keyLength;
		int _timeStep;
		uint8_t _byteArray[8];
		uint8_t* _hash;
		int _offset;
		long _truncatedHash;
		char _code[7];
};

#endif
