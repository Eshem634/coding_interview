
typedef struct meetingRoom
{
  unsigned int remainingTime;
  unsigned int totalBookedTime;
}meetingRoom;

const unsigned int totalNumberOfRooms = 10;

void allocateMeetingRoomsToUsers(unsigned int * timeToBeBookedForUsers, unsigned int totalNumberOfUsers);
unsigned int getMaxBookingTimeForRoom(void);
