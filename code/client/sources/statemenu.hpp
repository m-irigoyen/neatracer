#pragma once

#include <mme/core/abstractstate.hpp>

namespace nrr::client
{
	class StateMenu : public mme::core::AbstractState
	{

	public:
		StateMenu();

		bool clear() override;
		void draw(const float dt, const float interp) override;
		bool initialize() override;
		void onClose() override;
		void onWindowResized() override;
		void tick(float dt) override;
	};
}