#pragma once
#include <string>

namespace Charps {
	/**
	 * General shader class.
	 */
	class Shader {
	private:
		/**
		 * The shader's GL program ID.
		 */
		const unsigned int id;
		/**
		 * The vertex shader's GL program ID.
		 */
		const unsigned int vertexID;
		/**
		 * The fragment shader's GL program ID.
		 */
		const unsigned int fragmentID;

	public:
		/**
		 * Constructor.
		 * @param vertexFile The locaiton of the file that the vertex shader is in.
		 * @param fragmentFile The location of the file that the fragment shader is in.
		 */
		Shader(const char* vertexFile, const char* fragmentFile);
		/**
		 * Deconstructor that undoes affected memory.
		 */
		~Shader();

		/**
		 * Starts using the shader.
		 */
		void start();
		/**
		 * Stops using the shader.
		 */
		void stop();

		const int getID();
	protected:
		/**
		 * Binds all shader layout attributes used in the vertex shader.
		 */
		void bindAttributes();
	private:
		/**
		 * Binds a shader layout attribute.
		 */
		void bindAttribute(int attrib, const char* name);
		/**
		 * Creates a shader from a file.
		 * @param file The location of the shader file.
		 * @param type The type of shader, e.g. GL_FRAGMENT_SHADER.
		 * @return the GL ID of the shader.
		 */
		unsigned int loadShader(std::string file, unsigned int type);
	};
}