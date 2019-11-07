#pragma once

#include <nrr/core/global.hpp>

namespace nrr::core
{
	struct Vehicle
	{
		Vec2f position;
		Vec2f velocity;
		float angle;	//! Normalized in range [0;360[

		float radius;
		float mass;
		float friction;
	};
}