#include <gtest/gtest.h>
#include "vehicle_collector.h"

TEST(COLLECT,when_vehicle_sends_measurment_it_is_validated_and_stored_against_vehicle_id){

    telematics test_data{1,measurement::battery_temperature,40};
    auto fetched_inventory = telematics_to_inventory(test_data);
    
    ASSERT_TRUE(std::isnan(fetched_inventory.motor_temperature));
    ASSERT_EQUAL(fetched_inventory.battery_temperature,40);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}