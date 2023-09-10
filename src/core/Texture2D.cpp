#include "Texture2D.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


namespace core
{
	Texture2D::Texture2D(const std::string& file_path, const GLuint texture_block)
	{
		this->width = 0;
		this->height = 0;
		this->texture_block = texture_block;


		glGenTextures(1, &object_id);
		glActiveTexture(GL_TEXTURE0 + this->texture_block);
		glBindTexture(GL_TEXTURE_2D, object_id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);

		GLubyte* data = stbi_load(file_path.c_str(), &width, &height, nullptr, 4);

		if (!data)
		{
			throw std::runtime_error("Failed to load texture");
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}


	Texture2D::~Texture2D()
	{
		destroy();
	}


	void Texture2D::bind() const
	{
		glActiveTexture(GL_TEXTURE0 + this->texture_block);
		glBindTexture(GL_TEXTURE_2D, object_id);
	}


	void Texture2D::unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}


	void Texture2D::destroy()
	{
		if (is_destroyed())
		{
			return;
		}

		GLObject::destroy();

		glDeleteTextures(1, &object_id);
	}
}
