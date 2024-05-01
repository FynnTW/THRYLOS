#include "tpch.h"
#include "LayerStack.h"

namespace Thrylos
{
    /**
     * @class LayerStack
     * @brief Represents a stack of layers.
     *
     * The LayerStack class is responsible for managing a stack of layers and overlays in a game or application.
     * It allows pushing and popping layers and overlays, as well as iterating over them.
     */
    LayerStack::LayerStack()
    {
        m_LayerInsert = m_Layers.begin();
    }

    /**
     * @brief Destructor for the LayerStack class.
     *
     * This method is responsible for freeing the memory allocated for each layer in the stack.
     * It iterates over the layers vector and deletes each layer pointer.
     */
    LayerStack::~LayerStack()
    {
        for (const Layer* layer : m_Layers)
            delete layer;
    }

    /**
     * @brief Pushes a layer onto the layer stack.
     *
     * The PushLayer method adds a layer to the layer stack. The layer is inserted before the layer iterator and becomes the new top layer. This method is used to manage the layers in a
     * game or application.
     *
     * @param layer A pointer to the layer to be pushed onto the layer stack.
     */
    void LayerStack::PushLayer(Layer* layer)
    {
        m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
    }

    /**
     * @brief Pushes an overlay onto the layer stack.
     *
     * This method adds the specified overlay to the top of the layer stack. Overlays are
     * layers that are rendered on top of the other layers in the stack.
     *
     * @param overlay A pointer to the overlay layer to be added to the stack.
     */
    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    /**
     * @brief Removes the specified layer from the LayerStack.
     *
     * This function removes the specified layer from the LayerStack. It searches for the layer in the internal
     * list of layers and, if found, erases it. It also decrements the m_LayerInsert iterator by 1.
     *
     * @param layer The layer to be removed from the LayerStack.
     */
    void LayerStack::PopLayer(const Layer* layer)
    {
        if (const auto it = std::ranges::find(m_Layers, layer); it != m_Layers.end())
        {
            m_Layers.erase(it);
            --m_LayerInsert;
        }
    }

    /**
     * @brief Removes the specified overlay from the layer stack.
     *
     * This method removes the specified overlay from the layer stack if it exists. If the overlay is found in the stack, it is erased from the stack.
     *
     * @param overlay The pointer to the overlay layer to be removed.
     */
    void LayerStack::PopOverlay(Layer* overlay)
    {
        if (const auto it = std::ranges::find(m_Layers, overlay); it != m_Layers.end())
            m_Layers.erase(it);
    }
}
