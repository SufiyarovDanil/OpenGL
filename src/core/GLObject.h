#pragma once

#include <GL/glew.h>


namespace core
{
	class GLObject
	{

	private:

		GLboolean b_is_destroyed;

	protected:

		GLuint object_id;

	public:

		GLObject();

		inline GLuint get_id() const { return object_id; }

		inline GLboolean is_destroyed() const { return b_is_destroyed; }

		virtual void bind() const;

		virtual void unbind() const;

		virtual void destroy();

	};
}
