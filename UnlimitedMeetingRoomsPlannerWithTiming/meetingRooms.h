typedef struct meetingRoom
{
  unsigned int remainingTime;
  unsigned int totalTime;
} meetingRoom;

typedef struct meetingTiming
{
  unsigned int startTime;
  unsigned int endTime;
} meetingTiming;

void allocateRoomToUsers(meetingRoom* meetingRooms, unsigned int numberOfRooms, meetingTiming* meetingTimes, unsigned int numberOfMeetings);
unsigned int getNumberOfRoomsUsed(meetingRoom* meetingRooms, unsigned int numberOfRooms);
unsigned int getTotalTimeOfRoomBookedTheLongest(meetingRoom* meetingRooms, unsigned int numberOfRooms);
