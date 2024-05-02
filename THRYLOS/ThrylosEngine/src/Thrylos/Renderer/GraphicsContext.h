#pragma once

namespace Thrylos
{
    class GraphicsContext
    {
    public:
        /**
         * @brief Initializes the graphics context.
         *
         * This method is purely virtual and must be implemented by the derived classes.
         * It is responsible for initializing the graphics context, including any necessary libraries or APIs.
         */
        virtual void Init() = 0;

        /**
         * @brief Performs the buffer swap for the graphics context.
         *
         * This method is purely virtual and must be implemented by the derived classes.
         * It is responsible for swapping the front and back buffers of the graphics context,
         * effectively displaying the rendered frame on the window.
         */
        virtual void SwapBuffers() = 0;
    };
    
}
