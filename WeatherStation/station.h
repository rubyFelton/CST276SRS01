#ifndef WEATHER_STATION_STATION_H  __declspec(dllexport)
#define WEATHER_STATION_STATION_H
#else
#define WEATHER_STATION_STATION_H __declspec(dllimport)
#endif

#include <vector>
#include <chrono>
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"
#include "record.h"
#include "abstractStation.h"

namespace WeatherStation
{
    class Station : public AbstractStation
    {
    private:
        std::vector<WeatherStation::Record> history_{};

        //WeatherViewer::Current weather_viewer_current_;       // TODO: Remove this ConcreteObserver.
        //WeatherViewer::Statistics weather_viewer_statistics_; // TODO: Remove this ConcreteObserver.

    public:
        Station() noexcept;

		std::vector<std::reference_wrapper<WeatherViewer::AbstractViewer> > observers;


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
