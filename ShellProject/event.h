#pragma once

template<class Container>
struct Event
{
	// Define function pointer with 0 parameters and void return type.
	typedef void(Container::*void_delegate)();

	Event(Container* invoker, void_delegate invokable);
	virtual ~Event();

	Container* invoker_;
	void_delegate invokable_;
};

template<class Container>
inline Event<Container>::Event(Container* invoker, void_delegate invokable)
{
	this->invoker_ = invoker;
	this->invokable_ = invokable;
}

template<class Container>
inline Event<Container>::~Event()
{
	delete this->invoker_;
}
