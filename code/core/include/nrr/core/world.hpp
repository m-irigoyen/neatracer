#pragma once

#include <nrr/core/vehicle.hpp>

namespace nrr::core
{
	struct World
	{
		std::vector<Vehicle> vehicles;
		std::vector<Polygon> obstacles;
	};
}