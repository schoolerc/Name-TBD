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
		KeyDown,
		KeyUp,
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

	enum Key
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

		MouseButton GetMouseButton();
		std::vector<ModifierKeys> GetModifierKeys();
		int GetX();
		int GetY();

	private:
		MouseButton mouse_button;
		std::vector<ModifierKeys> modifier_keys;
		int x;
		int y;
	};

	class KeyEvent : public Event
	{
	public:
		KeyEvent(EventType, Key, std::vector<ModifierKeys>);
		~KeyEvent();

		Key GetKey();
		std::vector<ModifierKeys> GetModifierKeys();

	private:
		Key key;
		std::vector<ModifierKeys> modifier_keys;
	};

	class UpdateEvent : public Event
	{
	public:
		UpdateEvent(double delta);
		~UpdateEvent();

		double GetDelta();
	private:
		double delta;
	};
}