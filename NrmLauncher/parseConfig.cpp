#include "parseConfig.h"
#include <windows.h>

void parseConfig(Config& config) {
	std::wfstream fileConfig;

	fileConfig.open("launcher.cfg", std::ios::in);

	std::wstring tempStr;

	bool windowName = false;
	
	if (fileConfig.is_open()) {
		while (getline(fileConfig, tempStr)) {
			if (tempStr.find(L"WindowName:") != -1) {
				windowName = true;
				continue;
			}
			if (windowName)
				config.m_name = tempStr;

			break;
		}
	}

	fileConfig.close();
}