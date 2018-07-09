#pragma once

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

