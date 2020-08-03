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


inventory telematics_to_inventory(const telematics& received_telematics);
