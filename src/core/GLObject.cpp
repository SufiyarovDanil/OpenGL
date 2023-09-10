#include "GLObject.h"


namespace core
{
	GLObject::GLObject()
	{
		this->object_id = 0;
		this->b_is_destroyed = false;
	}


	void GLObject::bind() const
	{
		// pass
	}


	void GLObject::unbind() const
	{
		// pass
	}


	void GLObject::destroy()
	{
		this->b_is_destroyed = true;
	}
}
