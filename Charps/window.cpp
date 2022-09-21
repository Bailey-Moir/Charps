#include "window.h"
#include "spriterenderer.h"

using namespace Charps;

Window::Window(const unsigned int width, const unsigned int height, const std::string title) : input(Input(*this)), time(Time()) {
	this->_title = title;

	if (!glfwInit()) exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	windowGLFW = glfwCreateWindow(width, height, _title.c_str(), 0, 0);
	if (windowGLFW == 0) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(windowGLFW);
	monitor = glfwGetPrimaryMonitor();

	GLint err = glewInit();
	if (err != 0) {
		printf("ERROR: %s", glewGetErrorString(err));
		throw std::exception("Unable to initialize GLEW");
	}

	const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);
	if (videoMode == 0) throw new std::exception("Failed to get video mode");
	glfwSetWindowPos(windowGLFW, (videoMode->width - width) / 2, (videoMode->height - height) / 2);
	glfwMakeContextCurrent(windowGLFW);

	//createCapabilities(); //Adds the ability to render to the window
	glEnable(GL_DEPTH_TEST);

	//glfwSetWindowUserPointer(windowGLFW, this);

	glfwSetErrorCallback([](int code, const char* description) { std::cout << "ERROR(" << code << "): " << description << "." << std::endl; });
	glfwSetWindowSizeCallback(windowGLFW, [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); });

	std::vector<int> hKeys = {
		GLFW_KEY_A, GLFW_KEY_D,
		GLFW_KEY_LEFT, GLFW_KEY_RIGHT
	};
	input.addAxis(Input::Axis("horizontal", hKeys));

	std::vector<int> vKeys = {
		GLFW_KEY_S, GLFW_KEY_W,
		GLFW_KEY_DOWN, GLFW_KEY_UP
	};
	input.addAxis(Input::Axis("vertical", vKeys));

	glfwShowWindow(windowGLFW);
	glfwSwapInterval(1);
}

void Window::update() {
	time.update();
	glfwPollEvents(); //Gets all the callbacks connected to the window.
	for (auto component = Component::allComponents.begin(); component != Component::allComponents.end(); ++component) {
		if (*component == nullptr) Component::allComponents.erase(component);
		(*component)->update();
	}
}

void Window::render() {
	glClearColor(color[0], color[1], color[2], 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Or bit

	for (auto sr : SpriteRenderer::renderers) sr->render();

	glfwSwapBuffers(windowGLFW);
}

void Window::setTitle(const std::string v) {
	_title = v;
}
std::string Window::getTitle() {
	return _title;
}