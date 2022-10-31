#include <iostream>
#include "meetingRooms.h"

using namespace std;

void testMeetingRoomsSmallSet(void)
{
  const unsigned int numberOfRooms = 4;
  const unsigned int numberOfMeetings = 4;
  meetingRoom meetingRooms[numberOfRooms] = { 0 };
  meetingTiming meetingTimes[numberOfMeetings] = {
    {0,  15},
    {0,   5},
    {2,  10},
    {8,  20}
  };

  allocateRoomToUsers(meetingRooms, numberOfRooms, meetingTimes, numberOfMeetings);

  // How many rooms do we need?
  unsigned int numOfRoomsUsed = getNumberOfRoomsUsed(meetingRooms, numberOfRooms);
  unsigned int expectedNumOfRoomsUsed = 3;

  if (numOfRoomsUsed == expectedNumOfRoomsUsed)
  {
    cout << "passed" << endl;
  }
  else
  {
    cout << "failed" << endl;
  }


  // How long was booked the room which was booked the longest?
  unsigned int totalTime = getTotalTimeOfRoomBookedTheLongest(meetingRooms, numberOfRooms);
  unsigned int expectedTotalTime = 17;

  if (totalTime == expectedTotalTime)
  {
    cout << "passed" << endl;
  }
  else
  {
    cout << "failed" << endl;
  }
}

void testMeetingRooms(void)
{
  const unsigned int numberOfRooms = 10;
  const unsigned int numberOfMeetings = 10;
  meetingRoom meetingRooms[numberOfRooms] = { 0 };
  meetingTiming meetingTimes[numberOfMeetings] = {
    {0,  15},
    {0,   5},
    {2,  10},
    {8,  20},
    {15, 30},
    {15, 45},
    {20, 45},
    {30, 50},
    {35, 45},
    {40, 60}
  };

  allocateRoomToUsers(meetingRooms, numberOfRooms, meetingTimes, numberOfMeetings);

  // How many rooms do we need?
  unsigned int numOfRoomsUsed = getNumberOfRoomsUsed(meetingRooms, numberOfRooms);
  unsigned int expectedNumOfRoomsUsed = 5;

  if (numOfRoomsUsed == expectedNumOfRoomsUsed)
  {
    cout << "passed" << endl;
  }
  else
  {
    cout << "failed" << endl;
  }


  // How long was booked the room which was booked the longest?
  unsigned int totalTime = getTotalTimeOfRoomBookedTheLongest(meetingRooms, numberOfRooms);
  unsigned int expectedTotalTime = 45;

  if (totalTime == expectedTotalTime)
  {
    cout << "passed" << endl;
  }
  else
  {
    cout << "failed" << endl;
  }
}

int main(int argc, char* arv[])
{
  cout << "testMeetingRoomsSmallSet" << endl;
  testMeetingRoomsSmallSet();

  cout << "testMeetingRooms" << endl;
  testMeetingRooms();
}
