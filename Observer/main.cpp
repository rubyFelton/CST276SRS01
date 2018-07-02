// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

class Observer {

	public: void Update() {

	}

};

class Subject {
	std::vector<std::reference_wrapper<Observer*> > observerList;

	public : void  Attach(Observer* subscriber) { //registers an observer/subscriber
		observerList.push_back(subscriber);
	}

	public: void Detach(Observer* subscriber) { //unregisters an observer/subscriber
		//observerList.erase(std::remove(observerList.begin(), observerList.end(), subscriber), observerList.end);
	}
	
	public: void Notify() { //notifies all observers when the state changes
		for (int i = 0; i < observerList.size(); i++) {

			//observerList[i]->update();
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

	public: ConcreteSubject Update() {

	}

};

int main()
{
    return 0;
}

