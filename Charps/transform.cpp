#include "gameobject.h"
#include "window.h"

using namespace Charps;
using namespace std;

Transform::Transform(GameObject& gameObject) : Component(gameObject, typeid(Transform)) {
	size = Vector2<double>(1);
}

void Transform::translate(const Vector2<double> delta) {
	position += delta * gameObject.window.time.deltaTime;
}

void Transform::update() {}