#include <iostream>
#include <gtest/gtest.h>
#include <commands/command_factory.hpp>

TEST(basicTests, whenHelpPassedThenResIsNotNullptr)
{
    auto res = command_factory::construct("help");
    EXPECT_NE(res, nullptr);
}

TEST(basicTests, whenExitPassedThenResIsNotNullptr)
{
    auto res = command_factory::construct("exit");
    EXPECT_NE(res, nullptr);
}

TEST(basicTests, whenRotatePassedThenResIsNotNullptr)
{
    auto res = command_factory::construct("rotate");
    EXPECT_NE(res, nullptr);
}

TEST(basicTests, whenSplitPassedThenResIsNotNullptr)
{
    auto res = command_factory::construct("split");
    EXPECT_NE(res, nullptr);
}

TEST(basicTests, whenGreyScalePassedThenResIsNotNullptr)
{
    auto res = command_factory::construct("greyscale");
    EXPECT_NE(res, nullptr);
}

TEST(basicTests, whenLoadBmpPassedThenResIsNotNullptr)
{
    auto res = command_factory::construct("load_bmp");
    EXPECT_NE(res, nullptr);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}