#pragma once
#include "vector2.hpp"
#include <vector>
#include <iostream>
#include "GLFW.h"
#include "input.h"

namespace Charps {
	class TexturedModel;

	/**
	 * Manages the game window itself.
	 */
	class Window {
	private:
		/**
		 * The private variable that is referenced by the getter and setter.
		 */
		Vector2<unsigned int> _size, _pos;
		
		/**
		 * The private variable that is referenced by the getter and setter.
		 */
		std::string _title;
	public:
		/**
		 * The constructor for the window.
		 * @param width The width of the new window.
		 * @param height The height of the new window.
		 * @param title The title of the window.
		 */
		Window(const unsigned int width, const unsigned int height, std::string title);

		/**
		 * The input manager of the window.
		 */
		Input input;

		/**
		 * Initializes (in a non-literal sense) the window.
		 */
		void init();

		/**
		 * Update the window. Should run every frame.
		 */
		void update();
		/**
		 * Render to the window. Should run every frame.
		 */
		void render();

		void renderModel(const TexturedModel& texturedModel);

		/**
		 * The GLFW window struct.
		 */
		GLFWwindow* windowGLFW;
		
		/**
		 * The colour of the window.
		 */
		float color[3] = {0, 0, 0};

		// GETTERS AND SETTERS

		/**
		 * Window size setter.
		 */
		void setSize(const Vector2<unsigned int>& v);
		/**
		 * Window size getter.
		 */
		Vector2<unsigned int> getSize();

		/**
		 * Window position setter.
		 */
		void setPosition(const Vector2<unsigned int>& v);
		/**
		 * Window position getter.
		 */
		Vector2<unsigned int> getPosition();

		/**
		 * Window title setter.
		 */
		void setTitle(const std::string v);
		/**
		 * Window title getter.
		 */
		std::string getTitle();
	};
}
