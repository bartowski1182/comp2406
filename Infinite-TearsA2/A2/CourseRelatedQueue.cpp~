#include "CourseRelatedQueue.h"

using namespace std;

CourseRelatedQueue::CourseRelatedQueue() : head(0) { }


//Deallocate All Memory
CourseRelatedQueue::~CourseRelatedQueue()
{


}

std::string CourseRelatedQueue::stringOut(){
  if(head == 0)
    return "";

  Node* currNode = head;

  string tempString = currNode->data->print();

  currNode=currNode->next;

  while(currNode != 0){
    tempString = tempString + "$" + currNode->data->print();
    currNode = currNode->next;
  }

  return tempString;
    
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
bool CourseRelatedQueue::popFront()
{
  if(head != 0)
  {
    Node* tempNode = head;
    head = head -> next;
    if (tempNode != 0)
      delete tempNode -> data;
    delete tempNode;
    return true;
  }
  else
    return false;

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
