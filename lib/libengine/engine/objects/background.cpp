#include "engine/objects/background.hpp"

#include "engine/models/background_model.hpp"
#include "engine/models/model_factory.hpp"
#include "engine/shaders/backgroundshader.hpp"
#include "engine/shaders/shaderregistry.hpp"

#include <glm/glm.hpp>

Background::Background() : Object{nullptr, "Rectangle"} {
    m_model = ModelFactory::make<BackgroundModel>(*this);
    m_model->setPreRenderLogic([](const ShaderRegistry& shaderContainer) {
        shaderContainer.get<BackgroundShader>().use();
    });
}