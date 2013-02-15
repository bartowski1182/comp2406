#include "CourseQueue.h"

using namespace std;

CourseQueue::CourseQueue() : head(0) { }


//Deallocate All Memory
CourseQueue::~CourseQueue()
{


}

//Adds an item to back of Queue, make sure to check for all cases (empty list)
void CourseQueue::pushBack(Course *newC)
{

  Node* tempNode = new Node;
  tempNode->data = newC;
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
bool CourseQueue::popFront()
{
  if(head != 0)
  {
    Node* tempNode = head;
    head = head -> next;
    delete tempNode -> data;
    delete tempNode;
    return true;
  }
  else
    return false;

}

//Returns a pointer to the first Node
Course* CourseQueue::front()
{
  return head -> data;
}

//Checks to see if the Linked List is empty... ie Check to see if head is NULL
bool CourseQueue::empty()
{
  return head == 0;
}
