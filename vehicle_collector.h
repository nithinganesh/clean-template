#include <limits>

enum measurement
{
    motor_temperature,
    battery_pc,
    battery_temperature,
    max_count
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
    float measurements[max_count];
};
 
inventory telematics_to_inventory(const telematics& received_telematics);
