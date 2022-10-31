#include <iostream>
#include "MeetingRoomsPlanner.h"

using namespace std;


void testWithFewUsers(void)
{
  const unsigned int totalNumberOfUsers = 10;
  unsigned int timeToBeBooked[totalNumberOfUsers] = {10, 30, 45, 20, 65, 34, 22, 43, 98, 5};

  allocateMeetingRoomsToUsers(timeToBeBooked, totalNumberOfUsers);

  unsigned int expectedMaxBookingTime = 105;
  unsigned int maxBookingTime = getMaxBookingTimeForRoom();
  bool isPassed = (maxBookingTime == expectedMaxBookingTime) ? true : false;
  cout << "max booking time - passed: " << isPassed << endl;
}

int main(int argc, char* argv[])
{
  cout << "Test case: few users" << endl;
  testWithFewUsers();
}
