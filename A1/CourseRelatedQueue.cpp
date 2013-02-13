#include "CourseRelatedQueue.h"

using namespace std;

CourseRelatedQueue::CourseRelatedQueue() : head(0) { }


//Deallocate All Memory
CourseRelatedQueue::~CourseRelatedQueue()
{


}

//Adds an item to back of Queue, make sure to check for all cases (empty list)
void CourseRelatedQueue::pushBack(CourseRelated *newRC)
{

  Node* tempNode = new Node;
  tempNode->data = newRC;
  tempNode -> next = 0;

  if(head == 0){
    head = tempNode;
    return;
  }

  Node *currNode = head;
  while(currNode -> next != 0)
  {
    currNode = currNode -> next;
  }

  currNode -> next = tempNode;

}

//Removes first item from Queue, make sure to deallocate all memory
void CourseRelatedQueue::popFront()
{
  Node* tempNode = head;
  head = head -> next;
  delete tempNode;

}

//Returns a pointer to the first Node
CourseRelated* CourseRelatedQueue::front()
{
  return head -> data;
}

//Checks to see if the Linked List is empty... ie Check to see if head is NULL
bool CourseRelatedQueue::empty()
{
  return head == 0;
}
