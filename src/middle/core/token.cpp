#include "..\src\middle\token.h"
#include <map>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <iostream>

#define HIGH 1
#define LOW 0;

// CAUTION: CHANGING THE FOLLOWING VALUE WITHOUT MAKING NECESSARY CHANGES CAN CAUSE SYSTEM CRASH. Proceed with caution
// DOCUMENTATION INCOMPLETE
const bool MODE = LOW;				// PERFORMANCE SWITCH

std::string alphabets[] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z", };
std::string numbers[] = { "0","1","2","3","4","5","6","7","8","9" };
std::string special[] = { "~","!","@","#","$","%","^","&","*","(",")","_","+","-",">","<" };
std::string pool[] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","0","1","2","3","4","5","6","7","8","9","~","!","@","#","$","%","^","&","*","(",")","_","+","-",">","<" };

Token::Token() {	// COMPLETE (CURRENTLY USING LOW MEMORY VERSION)
	// Explicitly generating one pseudo access code that would always be the same.
	// This has been done because the program generates a new access_token on every execution.

	if (MODE) // Set the value to non-zero to activate this HIGH MEMORY part of code
	{
		m_access["6969"] = "Gx%kVRN+E^QX3m7Ux4D?y^coenJu2Nfk4S5?TUFETD69FC?4B5L5NW9pnbg$U&D+";
	}
	else // Set the if() value to zero to activate this LOW MEMORY part of the code
	{
		m_access["6"] = "Gx%kVRN+E^QX3m7Ux4D?y^coenJu2Nfk4S5?TUFETD69FC?4B5L5NW9pnbg$U&D+";
	}

	// Filling the Token object with a pool of access and session strings.
	fill();
}

Token::~Token() {

}

void Token::fill() {	// COMPLETE
	/*
	// Fill map data types. When data storage is changed, the following initializations would be obsolete.
	// To add a new key,value salt pair. Add pair in the following format:
	// {"aabc","YOUR 10 BIT CODE HERE"}, "aabc" is current end index. Not constant
	// eg: to add code "123456780" you'll write, {"aabc","1234567890"}

	m_session = {
		{"aaaa","8W#N_im$90"},{"aaab","7-WtrvR05w"},{"aaac","bjF^W4Rtht"},{"aaad","6+VsquQ94v"},{"aaae","Bsa!4UV@dm"},{"aaaf","L@Ke#gH9Ns"},{"aaag","AMEvRv^6SP"},{"aaah","#ZyVyfj7LQ"},{"aaai","Q%3yBQn9DV"},{"aaaj","2umn+=FSb3"},
		{"aaak","7V!M-hn#89"},{"aaal","&SC^J*v4?j"},{"aaam","4BAeeN8-Qa"},{"aaan","&SFWSMwH6P"},{"aaao","rPe5Vp%nyw"},{"aaap","yHjC-vT5Fp"},{"aaaq","8*Hy2qx8+g"},{"aaar","s_r%9mGC29"},{"aaas","fh4x+A_A4D"},{"aaat","WkZ-$_h!9t"},
		{"aaau","r8=VLnUU+A"},{"aaav","snCvaN*8+n"},{"aaaw","C$_uHugm9P"},{"aaax","eRjjf3$3M%"},{"aaay","tRg7T_^5rW"},{"aaaz","w3+P9NeNxp"},{"aaba","rWtRfY@W5C"},{"aabb","j?4v*J)MsC"},{"aabc","ZNB47fnsdf"},{"aabd","HCs2*5#$^_"},
	};

	// To add a new key,value salt pair. Add pair in the following format:
	// {"ac","YOUR 64 BIT CODE HERE"}, "ac" is current end index. Not constant
	// eg: to add code "123456780" you'll write, {"ac","1234567890123456789012345678901234567890123456789012345678901234"}
	m_access = {
		{ "aa","Gx%kVRN+E^QX3m7Ux4D?y^coenJu2Nfk4S5?TUFETD69FC?4B5L5NW9pnbg$U&D+", }, {"ab","_=ARJvy&$$ECuNaeS?zqY^URG-coens2!zRF4vjC84cUFwDQ9jbbShPuU-*W96L#"}
	};
	*/

	//Generating random <key> and <value> for m_session of length 4 and 10 respectively.

	if (MODE)
	{
		int alphalength = sizeof(alphabets) / sizeof(alphabets[0]);
		int pool_len = sizeof(pool) / sizeof(pool[0]);
		std::string key, session_val, access_val;
		srand((unsigned)time(0));
		for (int i = 0; i < alphalength; i++) {
			for (int j = 0; j < alphalength; j++) {
				for (int k = 0; k < alphalength; k++) {
					for (int l = 0; l < alphalength; l++) {
						//This should create keys from 'aaaa' to 'zzzz'
						key = key + alphabets[i] + alphabets[j] + alphabets[k] + alphabets[l];

						/* Generating session_val from random values of pool[]
						*  First we take size of pool array and store it in variable (here, pool_len)
						*  Using the random seed function
						*  Since session code is 10bit long, we'll fetch 10 random values from pool as:
						*  pool[(rand() % pool_len)], and concatenate in session_val variable.
						*/
						session_val = session_val + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)];

						/* Generating access_val from random values of pool[]
						* First we take size of pool size and store it in variable (here, pool_len)
						* Using the random seed function
						* Since access code is 64 bit long, we'll fetch 64 random values from pool as:
						* pool[(rand() % pool_len)], and concatenate in access_val variable.
						*/
						access_val = access_val + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)];

						// Filling the m_session and m_access maps with generated strings.
						m_session[key] = session_val;
						m_access[key] = access_val;

						key = session_val = access_val = "";	// Emptying the variables after one iteration.

					}
				}
			}
		}
	}
	else { // Set the if() value to zero to activate this LOW MEMORY part of the code
		int alphalength = sizeof(alphabets) / sizeof(alphabets[0]);
		int pool_len = sizeof(pool) / sizeof(pool[0]);
		std::string key, session_val, access_val;
		srand((unsigned)time(0));
		for (int i = 0; i < alphalength; i++) {
			key = alphabets[i];
			session_val = session_val + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)];
			access_val = access_val + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)] + pool[(rand() % pool_len)];
			m_session[key] = session_val;
			m_access[key] = access_val;
			key = session_val = access_val = "";
		}
	}
}

bool Token::checkAccess(std::string input) {	// COMPLETE
	// input.length() = length of the string
	// input.substr(0,2) = first two character of string
	// input.substr(length - 2, length) = last two character of string
	// std::string strip = input.substr(2, (input.length() - 4)) = string excluding first two and last two characters

	if (MODE)
	{
		std::string index = input.substr(0, 2) + input.substr(input.length() - 2, input.length());
		std::string strip = input.substr(2, (input.length() - 4));
		if (m_access.at(index) == strip)
			return true;
		return false;
	}
	else {
		std::string index = input.substr(0, 1);
		std::string strip = input.substr(1, (input.length() - 1));
		if (m_access.at(index) == strip)
			return true;
		return false;
	}
}

bool Token::checkSession(std::string input) {	// COMPLETE
	// input.length() = length of the string
	// input.substr(0,2) = first two character of string
	// input.substr(length - 2, length) = last two character of string
	// std::string strip = input.substr(2, (input.length() - 4)) = string excluding first two and last two characters

	if (MODE)
	{
		std::string index = input.substr(0, 2) + input.substr(input.length() - 2, input.length());
		std::string strip = input.substr(2, (input.length() - 4));
		if (m_session.at(index) == strip)
			return true;
		return false;
	}
	else {
		std::string index = input.substr(0, 1);
		std::string strip = input.substr(1, (input.length() - 1));
		if (m_session.at(index) == strip)
			return true;
		return false;
	}
}

std::string Token::giveAccess() {	// COMPLETE
	if (MODE)
	{
		const unsigned short length = sizeof(alphabets) / sizeof(alphabets[0]);
		std::string index;
		srand((unsigned)time(0));
		index = index + alphabets[(rand() % length)] + alphabets[(rand() % length)] + alphabets[(rand() % length)] + alphabets[(rand() % length)];
		return index.substr(0, 2) + m_access.at(index) + index.substr(index.length() - 2, index.length());
	}
	else {
		const unsigned short length = sizeof(alphabets) / sizeof(alphabets[0]);
		std::string index;
		srand((unsigned)time(0));
		index = index + alphabets[(rand() % length)];
		return index + m_access.at(index);
	}
}

std::string Token::giveSession() {	// COMPLETE
	if (MODE)
	{
		const unsigned short length = sizeof(alphabets) / sizeof(alphabets[0]);
		std::string index, session_code;
		srand((unsigned)time(0));
		index = index + alphabets[(rand() % length)] + alphabets[(rand() % length)] + alphabets[(rand() % length)] + alphabets[(rand() % length)];
		session_code = index.substr(0, 2) + m_session.at(index) + index.substr(index.length() - 2, index.length());
		return session_code;
	}
	else {
		const unsigned short length = sizeof(alphabets) / sizeof(alphabets[0]);
		std::string index, session_code;
		srand((unsigned)time(0));
		index = index + alphabets[(rand() % length)];
		session_code = index + m_session.at(index);
		return session_code;
	}
}

void Token::log() {	// COMPLETE
	std::map<std::string, std::string>::iterator pos;
	for (pos = m_access.begin(); pos != m_access.end(); ++pos) {
		std::cout << "{ " << pos->first << " , " << pos->second << " }" << std::endl;
		std::cout << std::endl;
	}
	for (pos = m_session.begin(); pos != m_session.end(); ++pos) {
		std::cout << "{ " << pos->first << " , " << pos->second << " }" << std::endl;
		}
}
