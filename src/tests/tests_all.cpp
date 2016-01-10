#include <gtest/gtest.h>
#include <iostream>

// It's necessary if you want to debug the program
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
