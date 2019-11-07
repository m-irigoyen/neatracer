#pragma once

#include <string>

namespace nrr::client
{
	extern const std::string cStateMenu;
	extern const std::string cStateStartup;
	extern const std::string cStateGame;

	extern const std::string cButtonStateMenu;
	extern const std::string cButtonStateGame;

	// UI stuff
	extern const std::string cButtonLMB;
	extern const std::string cButtonRMB;


	bool checkStateChange();
}
