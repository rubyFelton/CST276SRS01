#include "stdafx.h"
#include <iomanip>
#include "current.h"
#include "abstractViewer.h"
#include "theWeatherStation.h"

namespace WeatherViewer
{
    std::ostream& operator<<(std::ostream& os, WeatherViewer::Current const& current)
    {
        auto const& station{ current.getStation() };

        auto const temperature{ station.getTemperature() };
        auto const humidity{ station.getHumidity() };
        auto const pressure{ station.getPressure() };

        os <<
            std::setw(3) << temperature.get() << "°C, " <<
            std::setw(3) << humidity.get()    << "%, "  <<
            std::setw(4) << pressure.get()    << " in. Hg";

        return os;
    }

    Current::Current()
    {
		getStation().Attach(*this);
    }

    WeatherStation::Station const& Current::getStation() const
    {
		return TheWeatherStation::getWeatherStation();
	}   
	
	WeatherStation::Station & Current::getStation()
    {
		return TheWeatherStation::getWeatherStation();
	}

}
