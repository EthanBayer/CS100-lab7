#include <gtest/gtest.h>
#include "headers/addsubpowtests.hpp"
#include "headers/MultDivFailTests.hpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}