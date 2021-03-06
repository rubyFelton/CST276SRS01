// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
//implimentation fo GOF Observer pattern

class Observer {

	public: virtual void Update() = 0;

};

class Subject {
	std::vector<std::reference_wrapper<Observer> > observers;

	public : void  Attach(Observer& subscriber) { //registers an observer/subscriber
		observers.push_back(subscriber);
	}

public:
	void Detach(Observer& subscriber)
	{
		//unregisters an observer/subscriber
		observers.erase(std::remove_if(
			                observers.begin(), 
							observers.end(), 
							[&subscriber](Observer const& value)
			                {
				                auto const result{&value == &subscriber}; // same address
				                return result;
			                }), 
					observers.end());
	}
	
	public: void Notify() { //notifies all observers when the state changes
		for (auto& o: observers) {

			o.get().Update();
		}
	}

};

class ConcreteSubject : public Subject{
	bool subjectState{ false };

	public : bool GetState() {
		return subjectState;
	}

	public: void SetState(bool newState) {
		subjectState = newState;
	}

};

class ConcreteObserver : public Observer{
	ConcreteSubject subject;
	bool observerState = subject.GetState();

	public: void Update() {
		observerState = subject.GetState();
	}

};

int main()
{
    return 0;
}

