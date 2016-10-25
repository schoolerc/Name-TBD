#pragma once
namespace game {
	class Event
	{
	public:
		Event();
		~Event();

		enum Type
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


		virtual Type Type() = 0;
	};

	class ResizeEvent : public Event
	{
	public:
		ResizeEvent(int width, int height);
		~ResizeEvent();

		virtual enum Type Type() { return Event::Resize; }

		int GetWidth();
		int GetHeight();

	private:
		int width;
		int height;
	};

	class MouseEvent : public Event
	{
	public:

		enum MouseButton
		{

		};

		MouseEvent(enum Type, MouseButton, int x, int y);
		~MouseEvent();

	private:
		enum Type type;
		MouseButton mouse_button;
		int x;
		int y;
	};

}