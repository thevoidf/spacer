#pragma once

#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include "renderer2d.h"
#include "texture.h"

namespace lowg {

	struct VertexData {
		glm::vec3 vertex;
		glm::vec2 uv;
		float tid;
		glm::vec4 color;
	};

	class Renderable2D
	{
	public:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
		glm::vec2 size;
		glm::vec4 color;
		float angle;
	protected:
		std::vector<glm::vec2> uvs;
		Texture* texture;
	protected:
		Renderable2D() { init(); }
	public:
		Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color)
			: position(position), size(size), color(color) { init(); }
		virtual ~Renderable2D() { }

		virtual void submit(Renderer2D* renderer) const
		{
			renderer->submit(this);
		}

		inline const glm::vec2& getSize() const { return size; }
		inline const glm::vec4& getColor() const { return color; }
		inline const std::vector<glm::vec2>& getUV() const { return uvs; }
		inline const unsigned int getTID() const { return texture ? texture->getID() : 0; }
	private:
		void init()
		{
			uvs.push_back(glm::vec2(0.0f, 0.0f));
			uvs.push_back(glm::vec2(0.0f, 1.0f));
			uvs.push_back(glm::vec2(1.0f, 1.0f));
			uvs.push_back(glm::vec2(1.0f, 0.0f));
			texture = nullptr;

			rotation = glm::vec3(0.0f, 0.0f, 1.0f);
			scale = glm::vec3(1.0f, 1.0f, 1.0f);
			angle = 0.0f;
		}
	};
}
