#include "Event.h"

namespace game {

	Event::Event(EventType t):type(t)
	{
	}


	Event::~Event()
	{
	}

	ResizeEvent::ResizeEvent(int width, int height) : Event(EventType::Resize), width(width), height(height)
	{
	}

	ResizeEvent::~ResizeEvent()
	{
	}

	int ResizeEvent::GetWidth()
	{
		return width;
	}

	int ResizeEvent::GetHeight()
	{
		return height;
	}

	MouseEvent::MouseEvent(EventType type, MouseButton mouse_button, std::vector<ModifierKeys> modifier_keys, int x, int y) :
		Event(type),
		mouse_button(mouse_button),
		modifier_keys(modifier_keys),
		x(x),
		y(y)
	{
	}

	MouseEvent::~MouseEvent()
	{
	}

	MouseButton MouseEvent::GetMouseButton()
	{
		return mouse_button;
	}

	std::vector<ModifierKeys> MouseEvent::GetModifierKeys()
	{
		return modifier_keys;
	}

	int MouseEvent::GetX()
	{
		return x;
	}

	int MouseEvent::GetY()
	{
		return y;
	}

	KeyEvent::KeyEvent(EventType type, Key k, std::vector<ModifierKeys> modifiers) : Event(type), key(k), modifier_keys(modifiers)
	{
	}

	KeyEvent::~KeyEvent()
	{
	}

	Key KeyEvent::GetKey()
	{
		return key;
	}

	std::vector<ModifierKeys> KeyEvent::GetModifierKeys()
	{
		return modifier_keys;
	}

	UpdateEvent::UpdateEvent(double delta) :Event(EventType::Update), delta(delta)
	{
	}

	UpdateEvent::~UpdateEvent()
	{
	}

	double UpdateEvent::GetDelta()
	{
		return delta;
	}
}