#include <iostream>
#include <gtest/gtest.h>
#include "../inc/commands/impl/command_exit.hpp"

TEST(ff, exitWhenExitCommandPassed)
{
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}