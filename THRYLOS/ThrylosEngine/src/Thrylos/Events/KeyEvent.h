#pragma once

#include "Event.h"
#include <sstream>

#include "KeyCodes.h"

namespace Thrylos {

#pragma region KeyEvent
	/**
	 * \brief KeyEvent is an event that is triggered when a key is pressed or released.
	 * You don't create this class directly, instead you create KeyPressedEvent or KeyReleasedEvent.
	 */
	class THRYLOS_API KeyEvent : public Event
	{
	public:
		/**
		 * \brief Get the key code of the key that was pressed or released
		 * \return the key code of the key that was pressed or released
		 */
		int GetKeyCode() const { return m_KeyCode; }

		/**
		 * Event categories of the KeyEvent
		 */
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		/**
		 * \brief Constructor for the KeyEvent
		 * \param keycode Key code of the key that was pressed or released
		 */
		explicit KeyEvent(const int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};
#pragma endregion KeyEvent
	
#pragma region KeyPressedEvent
	/**
	 * \brief KeyPressedEvent is an event that is triggered when a key is pressed.
	 */
	class THRYLOS_API KeyPressedEvent : public KeyEvent
	{
	public:
		/**
		 * \brief Constructor for the KeyPressedEvent
		 * \param keycode Key code of the key that was pressed
		 * \param repeatCount the number of times the key was pressed
		 */
		KeyPressedEvent(const int keycode, const int repeatCount)
			: KeyEvent(glfwToWindowsKeyCode(keycode)), m_RepeatCount(repeatCount) {}

		/**
		 * \brief Get the number of times the key was pressed
		 * \return the number of times the key was pressed
		 */
		int GetRepeatCount() const { return m_RepeatCount; }

		/**
		 * \brief Convert the KeyPressedEvent to a string
		 * \return the KeyPressedEvent as a string
		 */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		/**
		 * Event type of the KeyPressedEvent event
		 */
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};
#pragma endregion KeyPressedEvent

#pragma region KeyReleasedEvent
	/**
	 * \brief KeyReleasedEvent is an event that is triggered when a key is released.
	 */
	class THRYLOS_API KeyReleasedEvent : public KeyEvent
	{
	public:
		/**
		 * \brief Constructor for the KeyReleasedEvent
		 * \param keycode Key code of the key that was released
		 */
		explicit KeyReleasedEvent(const int keycode)
			: KeyEvent(glfwToWindowsKeyCode(keycode)) {}
		
		/**
		 * \brief Convert the KeyReleasedEvent to a string
		 * \return the KeyReleasedEvent as a string
		 */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
		
		/**
		 * Event type of the KeyReleased event
		 */
		EVENT_CLASS_TYPE(KeyReleased)
	};
#pragma endregion KeyReleasedEvent

}
