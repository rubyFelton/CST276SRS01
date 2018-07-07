#pragma once
#include<algorithm>
#include "../WeatherViewer/abstractViewer.h"

class AbstractStation
{
	std::vector<std::reference_wrapper<WeatherViewer::AbstractViewer> > observers;


public:
	void  Attach(WeatherViewer::AbstractViewer& subscriber) { //registers an observer/subscriber
		observers.push_back(subscriber);
	}

	void Detach(WeatherViewer::AbstractViewer& subscriber)
	{
		//unregisters an observer/subscriber
		observers.erase(std::remove_if(
			observers.begin(),
			observers.end(),
			[&subscriber](WeatherViewer::AbstractViewer const& value)
		{
			auto const result{ &value == &subscriber }; // same address
			return result;
		}),
			observers.end());
	}

	void Notify() { //notifies all observers when the state changes
		for (auto& o : observers) {

			o.get().Update();
		}
	}
};
