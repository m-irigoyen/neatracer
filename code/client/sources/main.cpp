#include "global.hpp"

#include "stategame.hpp"
#include "statemenu.hpp"

#include <mme/core/application.hpp>
#include <mme/core/inputprocessor.hpp>
#include <mme/core/statemanager.hpp>

#include <SFML/Window/Keyboard.hpp>

#include <iostream>
#include <string>
#include <unordered_map>

namespace
{
	void setDefaultInputContexts()
	{
		mme::core::InputProcessor::instance().setDefaultContextsFunction([](std::vector<mme::core::InputProcessor::InputContext>& contexts)
		{
			mme::core::InputProcessor::InputContext context;

			// State change buttons
			context.keyToButton.insert(std::make_pair(sf::Keyboard::F1, nrr::client::cButtonStateMenu));	
			context.keyToButton.insert(std::make_pair(sf::Keyboard::F2, nrr::client::cButtonStateGame));	

			// Mouse controls
			context.mouseButtonToButton.insert(std::make_pair(sf::Mouse::Left, nrr::client::cButtonLMB));
			context.mouseButtonToButton.insert(std::make_pair(sf::Mouse::Right, nrr::client::cButtonRMB));

			// Gameplay stuff

			contexts.push_back(context);
		});
	}

	void setStates()
	{
		std::unordered_map<std::string, mme::core::AbstractState*> states;
		states.insert(std::make_pair(nrr::client::cStateMenu, new nrr::client::StateMenu()));
		states.insert(std::make_pair(nrr::client::cStateMenu, new nrr::client::StateGame()));
		mme::core::StateManager::instance().init(states, nrr::client::cStateMenu);
	}
}

int main()
{
	setDefaultInputContexts();
	setStates();

	mme::core::Application& app = mme::core::Application::instance();
	app.init("NeatRacer Client", mme::Vec2i(1024, 780), mme::Vec2i(800, 600));

	app.run();

	return 0;
}
