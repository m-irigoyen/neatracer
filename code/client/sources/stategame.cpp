#include "stategame.hpp"

#include "global.hpp"

#include <mme/core/statemanager.hpp>

namespace nrr::client
{
	StateGame::StateGame()
	{

	}

	bool StateGame::clear()
	{
		//throw std::logic_error("The method or operation is not implemented.");
		return true;
	}

	void StateGame::draw(const float dt, const float interp)
	{
		//throw std::logic_error("The method or operation is not implemented.");
	}

	bool StateGame::initialize()
	{
		//throw std::logic_error("The method or operation is not implemented.");
		return true;
	}

	void StateGame::onClose()
	{
		//throw std::logic_error("The method or operation is not implemented.");
	}

	void StateGame::onWindowResized()
	{
		//throw std::logic_error("The method or operation is not implemented.");
	}

	void StateGame::tick(float dt)
	{
		if (checkStateChange())
		{
			return;
		}
	}
}