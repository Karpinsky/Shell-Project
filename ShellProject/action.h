#pragma once

#include <iostream>
#include <vector>
#include "event.h"

template<class Container>
class Action
{
public:
	// Define function pointer with 0 parameters and void return type.
	typedef void(Container::*void_delegate)();

	Action();
	virtual ~Action();

	void AddAction(Container* invoker, void_delegate action);
	void Invoke();

	Action<Container> operator+=(Event<Container>* actionEvent);
	Action<Container> operator()();

protected:
	std::vector<Event<Container>*> events_;
};

template<class Container>
inline Action<Container>::Action()
{
}

template<class Container>
inline Action<Container>::~Action()
{
	for (Event<Container>* actionEvent : this->events_)
	{
		delete actionEvent;
	}
}

template<class Container>
inline void Action<Container>::AddAction(Container* invoker, void_delegate action)
{
	this->events_.push_back(new Event<Container>(invoker, action));
}

template<class Container>
inline void Action<Container>::Invoke()
{
	for (Event<Container>* actionEvent : this->events_)
	{
		((actionEvent->invoker_)->*(actionEvent->invokable_))();
	}
}

template<class Container>
inline Action<Container> Action<Container>::operator+=(Event<Container>* actionEvent)
{
	this->events_.push_back(actionEvent);
	return *this;
}

template<class Container>
inline Action<Container> Action<Container>::operator()()
{
	this->Invoke();
	return *this;
}
