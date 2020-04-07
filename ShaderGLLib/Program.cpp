#include "Program.h"
#include <stdexcept>
#include <iostream>

namespace sgl {

	Program::Program()
	{
		program_id_ = glCreateProgram();
		if (program_id_ <= 0)
		{
			throw std::runtime_error("Could not have a program that is <= 0");
		}
	}

	Program::~Program()
	{
		glDeleteProgram(program_id_);
	}

	void Program::AddShader(const Shader& shader)
	{
		glAttachShader(program_id_, shader.GetId());
		attached_shaders_.push_back(shader.GetId());
	}

	void Program::LinkShader()
	{
		glLinkProgram(program_id_);
		for (const auto& id : attached_shaders_)
		{
			glDetachShader(program_id_, id);
		}
	}

	void Program::Use() const
	{
		glUseProgram(program_id_);
	}

	void Program::UniformBool(const std::string& name, bool value) const
	{
		glUniform1i(GetMemoizeUniformLocation(name), (int)value);
	}

	void Program::UniformInt(const std::string& name, int value) const
	{
		glUniform1i(GetMemoizeUniformLocation(name), value);
	}

	void Program::UniformFloat(const std::string& name, float value) const
	{
		glUniform1f(GetMemoizeUniformLocation(name), value);
	}

	void Program::UniformVector2(
		const std::string& name, 
		const glm::vec2& vec2) const
	{
#pragma message ("You have to complete this code!")

		glUniform2f(
			glGetUniformLocation(program_id_, name.c_str()), vec2.x, vec2.y);

	}

	void Program::UniformVector3(
		const std::string& name, 
		const glm::vec3& vec3) const
	{
#pragma message ("You have to complete this code!")

		glUniform3f(
			glGetUniformLocation(program_id_, name.c_str()),
			vec3.x,
			vec3.y,
			vec3.z);
	}

	void Program::UniformVector4(
		const std::string& name, 
		const glm::vec4& vec4) const
	{

		glUniform4f(
			glGetUniformLocation(program_id_, name.c_str()),
			vec4.x,
			vec4.y,
			vec4.z,
			vec4.w);
	}

	void Program::UniformMatrix(
		const std::string& name, 
		const glm::mat4& mat,
		const bool transpose /*= false*/) const
	{
		glUniformMatrix4fv(
			glGetUniformLocation(GetMemoizeUniformLocation(name), name.c_str()),
			1,
			transpose ? GL_TRUE : GL_FALSE,
			&mat[0][0]);
	}

	const int Program::GetMemoizeUniformLocation(const std::string& name) const
	{
		auto it = memoize_map_.find(name);
		if (it == memoize_map_.end())
		{
			memoize_map_[name] = 
				glGetUniformLocation(program_id_, name.c_str());
		}
		return memoize_map_[name];
	}

	std::shared_ptr<sgl::Program> CreateSimpleProgram(
		const glm::mat4& projection /*= glm::mat4(1.0f)*/, 
		const glm::mat4& view /*= glm::mat4(1.0f)*/,
		const glm::mat4& model /*= glm::mat4(1.0f)*/)
	{
#pragma message ("You have to complete this code!")

		auto program_ = std::make_shared<Program>();
		
		Shader vertex_shader(ShaderType::VERTEX_SHADER);
		if (!vertex_shader.LoadFromFile("../Asset/SimpleVertex.glsl"))
		{
			std::cout << "can't read vertex sahder" << std::endl;
			exit(-1);
		}
		
		program_->AddShader(vertex_shader);

		Shader fragement_shader(ShaderType::FRAGMENT_SHADER);
		if (!fragement_shader.LoadFromFile("../Asset/SimpleFragment.glsl"))
		{
			std::cout << "can't read vertex sahder" << std::endl;
			exit(-1);
		}
		program_->AddShader(fragement_shader);

		program_->LinkShader();
		program_->Use();

		return nullptr;
	}

	std::shared_ptr<sgl::Program> CreateCubeMapProgram(
		const glm::mat4& projection /*= glm::mat4(1.0f)*/,
		const glm::mat4& view /*= glm::mat4(1.0f)*/,
		const glm::mat4& model /*= glm::mat4(1.0f)*/)
	{
#pragma message ("You have to complete this code!")
		return nullptr;
	}

	std::shared_ptr<sgl::Program> CreatePBRProgram(
		const glm::mat4& projection /*= glm::mat4(1.0f)*/,
		const glm::mat4& view /*= glm::mat4(1.0f)*/,
		const glm::mat4& model /*= glm::mat4(1.0f)*/)
	{
#pragma message ("You have to complete this code!")
		return nullptr;
	}

} // End namespace sgl.
