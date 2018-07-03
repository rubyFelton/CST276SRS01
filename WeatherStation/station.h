#ifndef WEATHER_STATION_STATION_H
#define WEATHER_STATION_STATION_H

#include <vector>
#include <chrono>
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"
#include "record.h"

namespace WeatherStation
{
    class Station // TODO: Make this a ConcreteSubject by adding inheritance from subjest class you write.
    {
    private:
        std::vector<WeatherStation::Record> history_{};

        //WeatherViewer::Current weather_viewer_current_;       // TODO: Remove this ConcreteObserver.
        //WeatherViewer::Statistics weather_viewer_statistics_; // TODO: Remove this ConcreteObserver.

    public:
        Station() noexcept;
		//replace with collect of weatherviewers and attach to the subject
        //WeatherViewer::Statistics getWeatherViewerStatistics() const;
        //WeatherViewer::Current getWeatherViewerCurrent() const;

        Temperature getTemperature() const;
        Humidity getHumidity() const;
        Pressure getPressure() const;

        Temperature getMeanTemperature(std::chrono::system_clock::time_point const t0, std::chrono::system_clock::time_point const t1) const;
        Humidity getMeanHumidity(std::chrono::system_clock::time_point const t0, std::chrono::system_clock::time_point const t1) const;
        Pressure getMeanPressure(std::chrono::system_clock::time_point const t0, std::chrono::system_clock::time_point const t1) const;

        void measure();
    };
}

#endif // WEATHER_STATION_STATION_H
