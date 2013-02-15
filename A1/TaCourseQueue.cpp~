#include "TaCourseQueue.h"

using namespace std;

TaCourseQueue::TaCourseQueue() : head(0) { }


//Deallocate All Memory
TaCourseQueue::~TaCourseQueue()
{


}

//Adds an item to back of Queue, make sure to check for all cases (empty list)
void TaCourseQueue::pushBack(TaCourse *newTC)
{

  Node* tempNode = new Node;
  tempNode->data = newTC;
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

std::string TaCourseQueue::stringOut(){
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

//Removes first item from Queue, make sure to deallocate all memory
bool TaCourseQueue::popFront()
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
TaCourseQueue* TaCourseQueue::front()
{
  return head -> data;
}

//Checks to see if the Linked List is empty... ie Check to see if head is NULL
bool TaCourseQueue::empty()
{
  return head == 0;
}
