#include "meetingRooms.h"

static unsigned int globalTime;

void initGlobalTime(void)
{
  globalTime = 0;
}

void incrementGlobalTime(void)
{
  globalTime++;
}

unsigned int getGlobalTime(void)
{
  return globalTime;
}

void sortMeetingRoomsWithRemainingTime(meetingRoom* meetingRooms, unsigned int numberOfRooms)
{
  // Brut force
  for (int i = 0; (i < numberOfRooms) && (meetingRooms[i].totalTime > 0); i++)
  {
    for (int j = i + 1; (j < numberOfRooms) && (meetingRooms[j].totalTime > 0); j++)
    {
      if (meetingRooms[i].remainingTime > meetingRooms[j].remainingTime)
      {
        meetingRoom temp = meetingRooms[i];
        meetingRooms[i]  = meetingRooms[j];
        meetingRooms[j]  = temp;
      }
    }
  }
}

void decrementRemainingTime(meetingRoom* meetingRooms, unsigned int numberOfRooms)
{
  for (int i = 0; i < numberOfRooms; i++)
  {
    if (meetingRooms[i].remainingTime > 0)
    {
      meetingRooms[i].remainingTime--;
    }
  }
}

void scheduleNewMeeting(meetingRoom* meetingRoom, meetingTiming* meetingTime)
{
  unsigned int meetingDuration = meetingTime->endTime - meetingTime->startTime;
  meetingRoom->remainingTime   = meetingDuration;
  meetingRoom->totalTime      += meetingDuration;
}

meetingRoom* findAvailableRoom(meetingRoom* meetingRooms, unsigned int numberOfRooms)
{
  meetingRoom* ptr = nullptr;

  for (int i = 0; (i < numberOfRooms) && (ptr == nullptr); i++)
  {
    if (meetingRooms[i].remainingTime == 0)
    {
      ptr = &meetingRooms[i];
    }
  }

  return ptr;
}

void allocateRoomToUsers(meetingRoom* meetingRooms, unsigned int numberOfRooms, meetingTiming* meetingTimes, unsigned int numberOfMeetings)
{
  unsigned int meetingIndex = 0;
  unsigned int globalTime;

  initGlobalTime();

  while (meetingIndex < numberOfMeetings)
  {
    globalTime = getGlobalTime();

    // check if meeting should be scheduled
    while (meetingTimes[meetingIndex].startTime == globalTime)
    {
      meetingRoom* availableMeetingRoom = findAvailableRoom(meetingRooms, numberOfRooms);

      if (availableMeetingRoom != nullptr)
      {
        scheduleNewMeeting(availableMeetingRoom, &meetingTimes[meetingIndex]);
        meetingIndex++;
      }
    }
    sortMeetingRoomsWithRemainingTime(meetingRooms, numberOfRooms);
    
    incrementGlobalTime();
    decrementRemainingTime(meetingRooms, numberOfRooms);
  }
}

unsigned int getNumberOfRoomsUsed(meetingRoom* meetingRooms, unsigned int numberOfRooms)
{
  unsigned int numOfRoomsUsed = 0;

  while ((numOfRoomsUsed < numberOfRooms) && (meetingRooms[numOfRoomsUsed].totalTime > 0))
  {
    numOfRoomsUsed++;
  }

  return numOfRoomsUsed;
}

unsigned int getTotalTimeOfRoomBookedTheLongest(meetingRoom* meetingRooms, unsigned int numberOfRooms)
{
  unsigned int totalTime = 0;

  for (int i = 0; i < numberOfRooms; i++)
  {
    if (meetingRooms[i].totalTime > totalTime)
    {
      totalTime = meetingRooms[i].totalTime;
    }
  }

  return totalTime;
}
