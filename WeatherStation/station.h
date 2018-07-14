#pragma once

#include <vector>
#include <chrono>
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"
#include "record.h"
#include "abstractStation.h"
#include "weatherStationDLL.h"
#include "../WeatherViewer/statistics.h"
#include "../WeatherViewer/current.h"

namespace WeatherStation
{
    class WEATHERSTATION_API Station : public AbstractStation
    {
    private:
        std::vector<std::reference_wrapper<WeatherStation::Record> > history_{};

    public:
        Station() noexcept;
		WeatherViewer::Current getWeatherViewerCurrent() const;
		WeatherViewer::Statistics getWeatherViewerStatistics() const;

	    std::vector<std::reference_wrapper<WeatherViewer::AbstractViewer> > observers;

        Temperature getTemperature();
        Humidity getHumidity();
        Pressure getPressure();

        Temperature getMeanTemperature(std::chrono::system_clock::time_point const t0, std::chrono::system_clock::time_point const t1);
        Humidity getMeanHumidity(std::chrono::system_clock::time_point const t0, std::chrono::system_clock::time_point const t1);
        Pressure getMeanPressure(std::chrono::system_clock::time_point const t0, std::chrono::system_clock::time_point const t1);
		Record getLastRecord();

        void measure();
    };
}
