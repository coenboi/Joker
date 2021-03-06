#include <iostream>
#include <bapi.h>
#include <string>
#include "..\src\client\vfx\graphics.h"
#include "..\src\client\sys\modules.h"
#include "..\src\client\sys\dashboard.h"
#include "..\src\client\util\class\frontObj.h"
#include "..\src\client\cred\access.h"

//Local Declarations
/*--------------------------------------------------------------------------------------------------------*/

void loginAttempt(unsigned short attempt);

//Core definitions
/*--------------------------------------------------------------------------------------------------------*/
void bimdl::login() {
	unsigned short input;
	bivfx::loginMenu();
	std::cin >> input;
	switch (input){
	case 1: {
		loginAttempt(4);
	}
		break;
	case 2: std::cout << "This functionality is in development. Check back later." << std::endl;
		break;
	case 3: std::cout << "This functionality is in development. Check back later." << std::endl;
		break;
	case 4: {
		std::cout << "\t\t\t Please enter your Enrollment Number or College ID" << std::endl;
	}
		break;
	case 5: std::cout << "This functionality is in development. Check back later." << std::endl;
		break;
	case 6: std::cout << "This functionality is in development. Check back later." << std::endl;
		break;
	case 0:
		break;
	default: std::cout << "Incorrect Input. Program will now terminate. Error Code: F101" << std::endl;
		break;
	}
}

void bimdl::create() {

}

void bimdl::contact() {

}

//Local Definitions
/*--------------------------------------------------------------------------------------------------------*/
void loginAttempt(unsigned short attempt) {	//COMPLETE
	std::system("cls");
	if (attempt >= 0 && attempt < 5) {
		std::cout << "\t\t\t\t\t    Attempts remaining: 0" << attempt + 1 << std::endl;
		std::cout << "\n\t\t\t       Please enter your Network ID (e.g: NET1234567890)" << std::endl;
		std::cout << "\t\t\t       Network ID: ";
		std::string net;
		std::cin >> net;
		std::cout << "\n\t\t\t       Please enter your Username and Password" << std::endl;
		std::cout << "\t\t\t       Username: ";
		std::string username;
		std::cin >> username;
		if (BAPI::USER::is_present(access_token, net, username, BAPI::ADM)) {
			std::cout << "\t\t\t       Password: ";
			std::string salt;
			std::cin >> salt;
			if (BAPI::USER::authorize_login(access_token, net, username, salt, BAPI::ADM) != "-1") {
				std::string token = BAPI::USER::authorize_login(access_token, net, username, salt, BAPI::ADM);
				std::string attr = BAPI::USER::get(access_token, "low69coenfuse", "BID001", net, "BID008");
				short log;
				log = dashboard_adm(attr, token);
			}
			else {
				std::cout << "\n\t\t\t       Given Username or Password is incorrect. Retry? [Y/N]" << std::endl;
				char choice = 'N';
				std::cin >> choice;
				if (choice == 'Y' || choice == 'y')
					loginAttempt(--attempt);
				else bivfx::close();
				exit(0);
			}
		}
		std::cout << "User not found in the given network. Retry? [Y/N]" << std::endl;
		char choice = 'N';
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y')
			loginAttempt(--attempt);
		else bivfx::close();
	}
	std::cout << "Too many incorrect inputs. System will now terminate." << std::endl;
}
