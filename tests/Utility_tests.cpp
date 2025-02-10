/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-16
 */

/* ===== Includes ===== */
#include <gtest/gtest.h>
extern "C" {
    #include "Utility.h"
}

/* ===== Tests ===== */

// Simple button pressed twice.
TEST(Utility, JoypadChanges1)
{
    // Reset joypad state
    JoypadChanges(0);

    // First press is recorded and returned
    EXPECT_EQ(JoypadChanges(J_UP), J_UP);

    // Hold is ignored
    EXPECT_EQ(JoypadChanges(J_UP), 0);

    // Release is recorded
    EXPECT_EQ(JoypadChanges(0), 0);

    // Second press is recorded and returned
    EXPECT_EQ(JoypadChanges(J_UP), J_UP);
}

// A and B buttons pressed simultaneously
TEST(Utility, JoypadChanges2)
{
    // Reset joypad state
    JoypadChanges(0);

    EXPECT_EQ(JoypadChanges(J_A), J_A);
    EXPECT_EQ(JoypadChanges(J_A | J_B), J_B);
    EXPECT_EQ(JoypadChanges(J_B), 0);
    EXPECT_EQ(JoypadChanges(J_A), J_A);
}
