#include "global.hpp"

#include <mme/core/inputmanager.hpp>
#include <mme/core/statemanager.hpp>

namespace nrr::client
{
	const std::string cStateMenu = "StateMenu";
	const std::string cStateGame = "StateGame";

	const std::string cButtonStateMenu = "DebugButtonStateMenu";
	const std::string cButtonStateGame = "DebugButtonStateGame";

	const std::string cButtonLMB = "ButtonLMB";
	const std::string cButtonRMB = "ButtonRMB";		

	bool checkStateChange()
	{
		if (mme::core::InputManager::instance().getButton(cButtonStateMenu, 0).justPressed)
		{
			mme::core::StateManager::instance().setState(cStateMenu);
			return true;
		}
		else if (mme::core::InputManager::instance().getButton(cButtonStateGame, 0).justPressed)
		{
			mme::core::StateManager::instance().setState(cStateGame);
			return true;
		}
		return false;
	}
}