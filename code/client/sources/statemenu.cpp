#include "statemenu.hpp"

#include "global.hpp"

#include <mme/core/statemanager.hpp>

namespace nrr::client
{
	StateMenu::StateMenu()
	{

	}

	bool StateMenu::clear()
	{
		//throw std::logic_error("The method or operation is not implemented.");
		return true;
	}

	void StateMenu::draw(const float dt, const float interp)
	{
		//throw std::logic_error("The method or operation is not implemented.");
	}

	bool StateMenu::initialize()
	{
		//throw std::logic_error("The method or operation is not implemented.");
		return true;
	}

	void StateMenu::onClose()
	{
		//throw std::logic_error("The method or operation is not implemented.");
	}

	void StateMenu::onWindowResized()
	{
		//throw std::logic_error("The method or operation is not implemented.");
	}

	void StateMenu::tick(float dt)
	{
		if (checkStateChange())
		{
			return;
		}
	}
}