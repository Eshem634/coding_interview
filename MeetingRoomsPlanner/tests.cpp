#include < iostream >
#include "meetingRooms.h"


using namespace std;

void testCaseFewUsers(void)
{
  const unsigned int totalNumberUsers = 10;
  const unsigned int totalNumberRooms = 3;

  unsigned int testSetFewUsers[totalNumberUsers] = { 20, 10, 15, 5, 30, 60, 120, 15, 10, 5 };

  meetingRoom meetingRooms[totalNumberRooms] = { 0 };

  // Function call
  allocateMeetingRoomToUsers(testSetFewUsers, totalNumberUsers, meetingRooms, totalNumberRooms);

  // Results
  unsigned int results[totalNumberRooms] = { 75, 75, 140 };

  for (int i = 0; i < totalNumberRooms; i++)
  {
    if (meetingRooms[i].m_totalTime != results[i])
    {
      cout << "test failed for idx " << i << " current = " << meetingRooms[i].m_totalTime << " and expected = " << results[i] << endl;
    }
    else
    {
      cout << "passed for idx " << i << endl;
    }
  }
}


void testCaseManyUsers(void)
{
  const unsigned int totalNumberUsers = 40;
  const unsigned int totalNumberRooms = 6;

  unsigned int testSetFewUsers[totalNumberUsers] =
  { 20, 10, 15, 5, 30, 60, 120, 15, 10, 5, 20, 10, 15, 5, 30, 60, 120, 15, 10, 5, 20, 10, 15, 5, 30, 60, 120, 15, 10, 5, 20, 10, 15, 5, 30, 60, 120, 15, 10, 5 };

  meetingRoom meetingRooms[totalNumberRooms] = { 0 };

  // Function call
  allocateMeetingRoomToUsers(testSetFewUsers, totalNumberUsers, meetingRooms, totalNumberRooms);

  // Results
  unsigned int results[totalNumberRooms] = { 165, 165, 170, 195, 205, 260 };

  for (int i = 0; i < totalNumberRooms; i++)
  {
    if (meetingRooms[i].m_totalTime != results[i])
    {
      cout << "test failed for idx " << i << " current = " << meetingRooms[i].m_totalTime << " and expected = " << results[i] << endl;
    }
    else
    {
      cout << "passed for idx " << i << endl;
    }
  }
}



int main(int argc, char* argv[])
{
  cout << "Test case: 10 users and 3 meeting rooms" << endl;
  testCaseFewUsers();

  cout << "Test case: 40 users and 6 meeting rooms" << endl;
  testCaseManyUsers();
}