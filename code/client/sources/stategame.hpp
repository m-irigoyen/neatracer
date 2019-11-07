#pragma once

#include <mme/core/abstractstate.hpp>

namespace nrr::client
{
	class StateGame : public mme::core::AbstractState
	{

	public:
		StateGame();

		bool clear() override;
		void draw(const float dt, const float interp) override;
		bool initialize() override;
		void onClose() override;
		void onWindowResized() override;
		void tick(float dt) override;
	};
}