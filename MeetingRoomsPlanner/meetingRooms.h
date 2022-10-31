#pragma once

typedef struct meetingRoom
{
  unsigned int m_remainingTime;
  unsigned int m_totalTime;
} meetingRoom;

void allocateMeetingRoomToUsers(unsigned int* userList, unsigned int userListSize, meetingRoom* meetingRooms, unsigned int meetingRoomsSize);

