#include "stdafx.h"
#include <iomanip>
#include "../WeatherStation/station.h"
#include "statistics.h"
#include "theWeatherStation.h"

namespace WeatherViewer
{
    std::ostream& operator<<(std::ostream& os, WeatherViewer::Statistics & statistics)
    {
        auto & station{ statistics.getStation() };

        auto & begin{ statistics.getBegin() };
        auto & now{ std::chrono::system_clock::now() };

        auto const meanTemperature{ station.getMeanTemperature(begin, now) };
        auto const meanHumidity{ station.getMeanHumidity(begin, now) };
        auto const meanPressure{ station.getMeanPressure(begin, now) };

        os <<
            std::setw(3) << meanTemperature.get() << "°C, " <<
            std::setw(3) << meanHumidity.get()    << "%, "  <<
            std::setw(4) << meanPressure.get()    << " in. Hg";

        return os;
    }

    Statistics::Statistics()
	{
		temp_ = getStation().getPressure();;
		humidity_ = getStation().getPressure();;
		pressure_ = getStation().getPressure();
		getStation().Attach(*this);
    }

	void Statistics::Update()
	{
		auto lastRecord = getStation().getLastRecord();
		temp_ = lastRecord.getTemperature();
		humidity_ = lastRecord.getHumidity();
		pressure_ = lastRecord.getPressure();
	}

	WeatherStation::Station & Statistics::getStation()
    {
        return TheWeatherStation::getWeatherStation();
    }   
	
	WeatherStation::Station const& Statistics::getStation() const
    {
        return TheWeatherStation::getWeatherStation();
    }

    std::chrono::system_clock::time_point Statistics::getBegin() const
    {
        return begin_;
    }
}
