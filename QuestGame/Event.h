#pragma once
#include <vector>

namespace game {
	
	enum class EventType
	{
		Resize,
		MouseButtonPress,
		MouseButtonRelease,
		MouseMove,
		MouseDoubleClick,
		KeyPress,
		KeyRelease,
		Update,
		Render
	};

	enum MouseButton
	{
		Left,
		Middle,
		Right
	};

	enum ModifierKeys
	{

	};

	enum Keys
	{

	};

	class Event
	{
	public:
		Event(EventType type);
		~Event();


		EventType Type() { return type; }
	private:
		EventType type;
	};

	class ResizeEvent : public Event
	{
	public:
		ResizeEvent(int width, int height);
		~ResizeEvent();

		int GetWidth();
		int GetHeight();

	private:
		int width;
		int height;
	};

	class MouseEvent : public Event
	{
	public:
		MouseEvent(EventType, MouseButton, std::vector<ModifierKeys>, int x, int y);
		~MouseEvent();

	private:
		MouseButton mouse_button;
		std::vector<ModifierKeys> modifier_keys;
		int x;
		int y;
	};

	class KeyEvent : public Event
	{
	public:
		KeyEvent(EventType, Keys, std::vector<ModifierKeys>);
		~KeyEvent();

	private:
		Keys key;
		std::vector<ModifierKeys> modifier_keys;
	};
}