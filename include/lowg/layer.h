#pragma once

#include <vector>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "renderer2d.h"
#include "shader.h"
#include "renderable2d.h"

namespace lowg {
	class Layer
	{
	protected:
		Renderer2D* renderer;
		std::vector<Renderable2D*> renderables;
		Shader* shader;
		glm::mat4 projectionMatrix;
	public:
		Layer();
		Layer(Renderer2D* renderer, Shader* shader, glm::mat4 projectionMatrix);
	public:
		virtual ~Layer();
		virtual void add(Renderable2D* renderable);
		virtual void remove(void *ptr);
		virtual void removeByIndex(unsigned int index);
		virtual void render();
		std::vector<Renderable2D*> getRenderables() { return renderables; }
	};
}
