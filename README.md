# CST276SRS01
Weather Station Observer


Project Name(s):  

    - Observer  
    - WeatherStation  
    - WeatherViewer  


Purposes:  

    - Learn to implement the cannonical GoF Observer Design Pattern.  
    - Learn to create a .dll  
    - Learn to apply the Observer pattern to existing code.  
    - Learn to provide an API and documentation to another programmer.  
    - Learn to provide citation for patterns.  


Specification:  

    - Create an empty Visual Studio solution named CST276SRS01.  
    - Delete the CST276SRS01 project from your solution and repository.  

    - Create a console project named Observer.  
    - Implement the Observer pattern from the GoF as shown in the UML Class Diagram (p294)  
    - Don't forget: Pattern citation is required for all projects, including this one.  

    - Create a .dll project named WeatherStation.  
    - Implement the WeatherStation namespace code in the WeatherStation.dll project.  
    - Find all the "TODO"s and follow the instructions given to get you started converting the code to use the Observer pattern.  
    - Create an API document for your .dll interface.  

    - Obtain the WeatherStation.dll and API document from your previous partner and give your WeatherStation.dll and API document to your next partner.  

    - Create a console project named WeatherViewer.  
    - Implement the WeatherViewer namespace code in the WeatherViewer project.  
    - Test your WeatherViewer with the WeatherStation.dll and API documentation provided from your previous partner.  

    - See the main.cpp example for a starting place to create your WeatherViewer.  
    - Unlike the main.cpp, your WeatherViewer should only report changes to the weather.  

    - As always, write a report for your project in the REPORT.md file.  

    - Be sure to follow all course guidelines, especially submission of main.cpp, REPORT.md, and README.md files.  

concrete subject
inherits from abstract subject
weather station 

concrete observer
inherits from abstract observer
statistics 
current

abstract observer
viewer

abstract subject
subject 
###
