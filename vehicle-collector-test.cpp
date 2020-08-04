#include <gtest/gtest.h>
#include <cmath>
#include "vehicle_collector.h"

TEST(COLLECT,when_vehicle_sends_measurment_it_is_validated_and_stored_against_vehicle_id){

    telematics test_data{1,measurement::battery_temperature,40};
    auto fetched_inventory = telematics_to_inventory(test_data);
    
    ASSERT_TRUE(std::isnan(fetched_inventory.measurements[measurement::motor_temperature]));
    ASSERT_TRUE(std::isnan(fetched_inventory.measurements[measurement::battery_pc]));
    ASSERT_NEAR(fetched_inventory.measurements[measurement::battery_temperature],40,0.001);

    test_data={1,measurement::motor_temperature,12.45};
    ASSERT_NEAR(fetched_inventory.measurements[measurement::motor_temperature],12.45,0.001);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}