#pragma once

#ifdef WEATHERSTATION_EXPORTS
#define WEATHERSTATION_API __declspec(dllexport)
#else
#define WEATHERSTATION_API __declspec(dllimport)
#endif
