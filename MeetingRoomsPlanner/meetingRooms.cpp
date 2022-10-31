#include "meetingRooms.h"
#include <string.h>

void decrementRemainingTime(meetingRoom* meetingRooms, unsigned int meetingRoomsSize)
{
  for (int i = 0; i < meetingRoomsSize; i++)
  {
    if (meetingRooms[i].m_remainingTime > 0)
    {
      meetingRooms[i].m_remainingTime--;
    }
  }
}

bool isRoomAvailable(meetingRoom* meetingRoom)
{
  return (meetingRoom->m_remainingTime == 0) ? true : false;
}

void bookRoomForUser(unsigned int* bookingDuration, meetingRoom* meetingRoom)
{
  meetingRoom->m_remainingTime = *bookingDuration;
  meetingRoom->m_totalTime    += *bookingDuration;
}

void sortRoomsWithIncreasingRemainingTime(meetingRoom* meetingRooms, unsigned int meetingRoomsSize)
{
  for (int i = 0; i < meetingRoomsSize; i++)
  {
    for (int j = i + 1; j < meetingRoomsSize; j++)
    {
      if (meetingRooms[i].m_remainingTime > meetingRooms[j].m_remainingTime)
      {
        meetingRoom temp = meetingRooms[i];
        meetingRooms[i] = meetingRooms[j];
        meetingRooms[j] = temp;
      }
    }
  }
}

void allocateMeetingRoomToUsers(unsigned int* bookingDuration, unsigned int totalNumberOfUsers, meetingRoom* meetingRooms, unsigned int totalNumberOfRooms)
{
  unsigned int userIndex = 0;

  while (userIndex < totalNumberOfUsers)
  {
    while ((isRoomAvailable(&meetingRooms[0])) && (userIndex < totalNumberOfUsers))
    {      
      bookRoomForUser(&bookingDuration[userIndex], &meetingRooms[0]);
      userIndex++;
      sortRoomsWithIncreasingRemainingTime(meetingRooms, totalNumberOfRooms);
    }
    
    decrementRemainingTime(meetingRooms, totalNumberOfRooms);
  }
}