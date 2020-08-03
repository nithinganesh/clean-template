#include <limits>

enum class measurement
{
    motor_temperature,
    battery_pc,
    battery_temperature
};

struct telematics
{
    int vehicle_id;
    measurement type;
    float value;
};

struct inventory
{
    int vehicle_id;
    float motor_temperature;
    float battery_pc;
    float battery_temperature;
};

static inventory inventory_details[] =
                    {{1,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN()},
                     {2,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN()},
                     {3,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN()}   };


inventory *fetch_inventory_reference(int vehicle_id)
{
    for (auto vehicle_details: inventory_details)
    {
        if(vehicle_details.vehicle_id == vehicle_id)
            return &vehicle_details;
    }
    return nullptr;
}

inventory telematics_to_inventory(const telematics& received_telematics)
{
    //auto inventory_details = fetch_inventory_reference(received_telematics.vehicle_id);   
    return inventory_details[0];
}
