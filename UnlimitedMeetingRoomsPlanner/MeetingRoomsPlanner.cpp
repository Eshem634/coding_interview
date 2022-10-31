#include "MeetingRoomsPlanner.h"

static meetingRoom meetingRooms[totalNumberOfRooms];

void decrementRemainingTime(void)
{
  for (int i = 0; (i < totalNumberOfRooms) && (meetingRooms[i].totalBookedTime != 0); i++)
  {
    if (meetingRooms[i].remainingTime > 0)
    {
      if (meetingRooms[i].remainingTime >= 10)
      {
        meetingRooms[i].remainingTime -= 10;
      }
      else
      {
        meetingRooms[i].remainingTime = 0;
      }
    }
  }
}

meetingRoom* findAvailableRoom(void)
{
  meetingRoom* return_ptr = nullptr;
  int i = 0;

  while ((i < totalNumberOfRooms) && (return_ptr == nullptr))
  {
    if (meetingRooms[i].remainingTime == 0)
    {
      return_ptr = &meetingRooms[i];
    }
    i++;
  }

  return return_ptr;
}

void bookRoomForUser(unsigned int* timeToBeBooked, meetingRoom* availableRoom)
{
  availableRoom->remainingTime    = *timeToBeBooked;
  availableRoom->totalBookedTime += *timeToBeBooked;
}

void sortRoomsWithIncreasingRemainingTime(void)
{
  // brut force
  for (int i = 0; i < totalNumberOfRooms; i++)
  {
    for (int j = i + 1; j < totalNumberOfRooms; j++)
    {
      if ((meetingRooms[i].totalBookedTime != 0) &&
          (meetingRooms[j].totalBookedTime != 0) &&
          (meetingRooms[i].remainingTime > meetingRooms[j].remainingTime))
      {
        meetingRoom tmpRoom = meetingRooms[i];
        meetingRooms[i] = meetingRooms[j];
        meetingRooms[j] = tmpRoom;
      }
    }
  }
  // todo: optimize with merge sort - move 1st room
}

void allocateMeetingRoomsToUsers(unsigned int* timeToBeBooked, unsigned int totalNumberOfUsers)
{
  unsigned int userIndex = 0;
  meetingRoom* ptrfreeRoom;

  // All users should use a room
  while (userIndex < totalNumberOfUsers)
  {
    ptrfreeRoom = findAvailableRoom();
    if (nullptr != ptrfreeRoom)
    {
      bookRoomForUser(&timeToBeBooked[userIndex], ptrfreeRoom);
      userIndex++;
      sortRoomsWithIncreasingRemainingTime();
    }
    decrementRemainingTime();
  }
}

unsigned int getMaxBookingTimeForRoom(void)
{
  unsigned int maxBookingTime = 0;

  for (int i = 0; (i < totalNumberOfRooms) && (meetingRooms[i].totalBookedTime != 0); i++)
  {
    if (maxBookingTime < meetingRooms[i].totalBookedTime)
    {
      maxBookingTime = meetingRooms[i].totalBookedTime;
    }
  }
  return maxBookingTime;
}
