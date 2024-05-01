#include "tpch.h"
#include "Layer.h"

namespace Thrylos
{
    /**
     * \class Layer
     *
     * \brief Represents a generic layer in an application.
     *
     * A layer is a modular component that can be added to an application's
     * layer stack. Layers can handle various events and update their state
     * accordingly. They can also be attached and detached dynamically during
     * runtime.
     */
    Layer::Layer(const std::string& name)
        : m_DebugName(name)
    {
    }

    /**
     * \brief Destructor for the Layer class.
     *
     * This destructor is responsible for cleaning up any resources used by the Layer.
     */
    Layer::~Layer()
    {
    }
}
