#include "vehicle_collector.h"

static inventory inventory_data[] =
                    {{1,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN()},
                     {2,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN()},
                     {3,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN()}   };


static inventory *fetch_inventory_reference(const int vehicle_id)
{
    for (auto &vehicle_details: inventory_data)
    {
        if(vehicle_details.vehicle_id == vehicle_id)
            return &vehicle_details;
    }
    return nullptr;
}

static void update_measurement_value( float &data, const float &new_value)
{
    data = new_value;
}

inventory telematics_to_inventory(const telematics& received_telematics)
{
    auto fetched_inventory_details = fetch_inventory_reference(received_telematics.vehicle_id);
    
    for( auto type = static_cast<std::size_t>(measurement::motor_temperature) ; 
                type< static_cast<std::size_t>(measurement::max_count);  type++)
    {
        if( type == static_cast<std::size_t>(received_telematics.type))
        {
            update_measurement_value(fetched_inventory_details->measurements[type],received_telematics.value);
        }
    }

    // Return a copy 
    return *fetched_inventory_details;
}