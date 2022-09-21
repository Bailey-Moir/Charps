#include "gameobject.h"

using namespace Charps;

std::vector<Component*> Component::allComponents = std::vector<Component*>();

Component::Component(GameObject& gameObject, const std::type_info& id) : gameObject(gameObject), id(id) {
	gameObject.addComponent(this);
	allComponents.push_back(this);
}

void Component::update() {}
