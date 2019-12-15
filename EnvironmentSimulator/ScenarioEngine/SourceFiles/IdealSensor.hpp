/*
 * esmini - Environment Simulator Minimalistic
 * https://github.com/esmini/esmini
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) partners of Simulation Scenarios
 * https://sites.google.com/view/simulationscenarios
 */

#pragma once

#include "ScenarioEngine.hpp"

namespace scenarioengine
{
	typedef struct
	{
		double x;
		double y;
		double z;
		double h;
		double p;
		double r;
	} SensorPosition;

	class BaseSensor
	{
	public:
		typedef enum
		{
			SENSOR_TYPE_UNDEFINED,
			SENSOR_TYPE_OBJECT,
		} Type;

		Type type_;
		SensorPosition pos_;  // Position, relative host object

		BaseSensor(BaseSensor::Type type, double pos_x, double pos_y);

		virtual void Update()
		{
			LOG("Virtual, should be overridden");
		};
	};

	class ObjectSensor : public BaseSensor
	{
	public:

		double near_;         // Near limit field of view, from position of sensor
		double near_sq_;      // Near squared - for performance purpose
		double far_;          // Far limit field of view, from position of sensor
		double far_sq_;       // Far squared - for performance purpose
		double fovH_;         // Horizontal field of view, in degrees
		double fovV_;         // Vertical field of view, in degrees
		int maxObj_;          // Maximum length of object list
					         
		Object *host_;        // Entity to which the sensor is attached
		int *objList_;        // List of identified objects
		int nObj_;            // Size of object list, i.e. number of identified objects

		ObjectSensor(Entities *entities, Object *refobj, double pos_x, double pos_y, double near, double far, double fovH, int maxObj);
		ObjectSensor::~ObjectSensor();
		void Update();

	private:

		Entities *entities_;   // Reference to the global collection of objects within the scenario

	};

}
