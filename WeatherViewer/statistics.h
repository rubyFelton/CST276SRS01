#ifndef WEATHER_VIEWER_STATISTICS_H
#define WEATHER_VIEWER_STATISTICS_H

#include <ostream>
#include <chrono>
#include "abstractViewer.h"

namespace WeatherStation 
{
    class Station;
}

namespace WeatherViewer
{
    class Statistics : public AbstractViewer
    {
        friend std::ostream& operator<<(std::ostream& os, Statistics & statistics);
		WeatherStation::Temperature temp_;
		WeatherStation::Humidity humidity_;
		WeatherStation::Pressure pressure_;

    private:
        std::chrono::system_clock::time_point const begin_{ std::chrono::system_clock::now() };

    public:
        explicit Statistics();
		void Update() override;
        WeatherStation::Station const& getStation() const;
        WeatherStation::Station & getStation();
        std::chrono::system_clock::time_point getBegin() const;
    };
}

#endif // WEATHER_VIEWER_STATISTICS_H
