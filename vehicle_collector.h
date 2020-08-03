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

static inventory inventory_data[] =
                    {{1,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN()},
                     {2,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN()},
                     {3,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN()}   };


inventory *fetch_inventory_reference(int vehicle_id)
{
    for (auto &vehicle_details: inventory_data)
    {
        if(vehicle_details.vehicle_id == vehicle_id)
            return &vehicle_details;
    }
    return nullptr;
}

void update_battery_temperature( inventory *details, float new_value)
{
    details->battery_temperature = new_value;
}

void update_motor_temperature( inventory *details, float new_value)
{
    details->motor_temperature = new_value;
}

void update_battery_pc( inventory *details, float new_value)
{clTabCtrl
    details->battery_pc = new_value;
}

inventory telematics_to_inventory(const telematics& received_telematics)
{
    auto fetched_inventory_details = fetch_inventory_reference(received_telematics.vehicle_id);
    switch(received_telematics.type)
    {
        case measurement::battery_pc:
            update_battery_pc(fetched_inventory_details,received_telematics.value);
            break;
        case measurement::battery_temperature:
            update_battery_temperature(fetched_inventory_details,received_telematics.value);
            break;
        case measurement::motor_temperature:
            update_motor_temperature(fetched_inventory_details,received_telematics.value);
            break;
    }
    return *fetched_inventory_details;
}
