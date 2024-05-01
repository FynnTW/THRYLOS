﻿#pragma once

#include "Thrylos/Core.h"
#include "Thrylos/Events/Event.h"

namespace Thrylos
{
    class THRYLOS_API Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        const std::string& GetName() const { return m_DebugName; }
    private:
        std::string m_DebugName;
    };
}

