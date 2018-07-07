#pragma once
#include "../WeatherStation/temperature.h"
#include "../WeatherStation/station.h"

class TheWeatherStation
{
private:
	TheWeatherStation(){}
	//

public:
	static WeatherStation::Station& getWeatherStation()
	{
		static WeatherStation::Station weather_station;
		return weather_station;
	}
};

