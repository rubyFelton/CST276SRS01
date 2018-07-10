#ifndef WEATHER_VIEWER_CURRENT_H
#define WEATHER_VIEWER_CURRENT_H

#include <ostream>
#include "abstractViewer.h"
#include "../WeatherStation/station.h"

namespace WeatherViewer
{
    class Current : public AbstractViewer
    {
        friend std::ostream& operator<<(std::ostream& os, Current const& current);
		WeatherStation::Temperature temp_;
		WeatherStation::Humidity humidity_;
		WeatherStation::Pressure pressure_;

		//needs temp humidity and pressure
    private:

    public:
        explicit Current();
		void Update();
        WeatherStation::Station const& getStation() const;
        WeatherStation::Station & getStation();
    };
}

#endif // WEATHER_VIEWER_CURRENT_H
