#pragma once
//#include "Object.hpp"
#include "Entities.hpp"
#include "Init.hpp"
#include "Story.hpp"
#include "pugixml.hpp"

#include <iostream>
#include <string>
#include <vector>

class ScenarioReader
{
public:
	ScenarioReader();
	void loadXmlFile(const char* path);

	// ParameterDeclaration
	void parseParameterDeclaration();

	// Enitites
	void parseEntities(Entities &entities);
	void parseOSCVehicle(OSCVehicle &vehicle, pugi::xml_node vehicleNode);
	void parseOSCBoundingBox(OSCBoundingBox &boundingBox, pugi::xml_node boundingBoxNode);
	void parseOSCAxle(OSCAxle &axle, pugi::xml_node axleNode);
	void parseOSCDriver(OSCDriver &driver, pugi::xml_node driverNode);
	void parseOSCPersonDescription(OSCPersonDescription &personDescription, pugi::xml_node descriptionNode);

	// Storyboard - Init
	void parseInit(Init &init);
	void parseOSCPrivateAction(OSCPrivateAction &action, pugi::xml_node actionNode);
	void parseOSCPosition(OSCPosition &position, pugi::xml_node positionNode);

	// Storyboard - Story
	void parseOSCCondition(OSCCondition &condition, pugi::xml_node conditionNode);
	void parseOSCConditionGroup(OSCConditionGroup &conditionGroup, pugi::xml_node conditionGroupNode);
	void parseStory(std::vector<Story> &storyVector);
	void parseOSCManeuver(OSCManeuver &maneuver, pugi::xml_node maneuverNode);

	// Help functions
	std::string getParameter(std::string name);
	void addParameter(std::string name, std::string value);

private:
	pugi::xml_document doc;
	OSCParameterDeclaration parameterDeclaration;
	int objectCnt;
};

