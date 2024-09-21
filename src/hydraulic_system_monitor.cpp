// hydraulic_system_monitor.cpp
#include <string>

class HydraulicSystemMonitor {
public:
    HydraulicSystemMonitor() 
        : hydraulic_oil_temperature("Unknown"), 
          hydraulic_oil_tank_fill_level("Unknown"), 
          hydraulic_oil_pressure("Unknown") {}

    // Setters
    void setHydraulicOilTemperature(const std::string& temperature) {
        hydraulic_oil_temperature = temperature;
    }

    void setHydraulicOilTankFillLevel(const std::string& fill_level) {
        hydraulic_oil_tank_fill_level = fill_level;
    }

    void setHydraulicOilPressure(const std::string& pressure) {
        hydraulic_oil_pressure = pressure;
    }

    // Getters
    std::string getHydraulicOilTemperature() const {
        return hydraulic_oil_temperature;
    }

    std::string getHydraulicOilTankFillLevel() const {
        return hydraulic_oil_tank_fill_level;
    }

    std::string getHydraulicOilPressure() const {
        return hydraulic_oil_pressure;
    }

private:
    std::string hydraulic_oil_temperature;
    std::string hydraulic_oil_tank_fill_level;
    std::string hydraulic_oil_pressure;
};
