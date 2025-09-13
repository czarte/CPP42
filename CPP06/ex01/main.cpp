//
// Created by Vojtěch Parkán on 13.09.2025.
//

#include "Serializer.h"
#include "Data.h"
#include <iostream>

int main() {
    // Create a Data object using the parameterized constructor
    Data* originalData = new Data(42, "Test Data", 19.99);

    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << originalData << std::endl;
    std::cout << "Value: " << originalData->value << std::endl;
    std::cout << "Name: " << originalData->name << std::endl;
    std::cout << "Price: " << originalData->price << std::endl;
    std::cout << std::endl;

    // Serialize the Data pointer
    uintptr_t serialized = Serializer::serialize(originalData);
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << "Serialized value (hex): 0x" << std::hex << serialized << std::dec << std::endl;
    std::cout << std::endl;

    // Deserialize back to Data pointer
    Data* deserializedData = Serializer::deserialize(serialized);

    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Address: " << deserializedData << std::endl;
    std::cout << "Value: " << deserializedData->value << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;
    std::cout << "Price: " << deserializedData->price << std::endl;
    std::cout << std::endl;

    // Verify that the addresses are the same
    if (originalData == deserializedData) {
        std::cout << "SUCCESS: Original and deserialized pointers are identical!" << std::endl;
    } else {
        std::cout << "FAILURE: Original and deserialized pointers are different!" << std::endl;
    }

    // Clean up
    delete originalData;

    return 0;
}
