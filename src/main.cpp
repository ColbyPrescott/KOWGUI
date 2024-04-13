/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       crprescott2026                                            */
/*    Created:      4/12/2024, 4:34:09 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

vex::brain Brain;

int main() {
    Brain.Screen.print("Hewwo UwU");

        while(1) {
            
            // Allow other tasks to run
            this_thread::sleep_for(10);
        }
}
