#pragma once
#include "..\src\client\util\json\JSON.h"
#include <string>

short dashboard_adm(std::string, std::string);
short dashboard_stu(JSON_stu, std::string);
short dashboard_emp(JSON_emp, std::string);
short dashboard_sup(JSON_sup, std::string);
short dashboard_mod(JSON_mod, std::string);
short dashboard_guest(JSON_guest, std::string);
