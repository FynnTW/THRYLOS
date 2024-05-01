#pragma once

#include "Thrylos/Core.h"
#include "Layer.h"

#include <vector>


namespace Thrylos
{
    typedef std::vector<Layer*> StackLayers ;
    class THRYLOS_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(const Layer* layer);
        void PopOverlay(Layer* overlay);

        StackLayers GetLayers() { return m_Layers; }
        StackLayers::iterator begin() { return m_Layers.begin(); }
        StackLayers::iterator end() { return m_Layers.end(); }
    private:
        StackLayers m_Layers;
        StackLayers::iterator m_LayerInsert;
    };
    
}

