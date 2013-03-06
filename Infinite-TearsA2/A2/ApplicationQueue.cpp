#include "ApplicationQueue.h"

using namespace std;

ApplicationQueue::ApplicationQueue() : head(0) { }


//Deallocate All Memory
ApplicationQueue::~ApplicationQueue()
{


}

ApplicationQueue::Node* ApplicationQueue::getHead(){
  return head;
}


//Adds an item to back of Queue, make sure to check for all cases (empty list)
void ApplicationQueue::pushBack(Application *newApp)
{

  Node* tempNode = new Node;
  tempNode->data = newApp;
  tempNode -> next = 0;

  if(head == 0){
    head = tempNode;
    return;
  }

  Node *currNode = head;

  //Should not cause seg fault because head is not equal to 0
  while(currNode -> next != 0)
  {
    currNode = currNode -> next;
  }

  currNode -> next = tempNode;

}

//Removes first item from Queue, make sure to deallocate all memory
bool ApplicationQueue::popFront()
{
  if (head != 0)
  {
    Node* tempNode = head;
    head = head -> next;
    if(tempNode != 0)
      delete tempNode -> data;
    delete tempNode;
    return true;
  }
  else
    return false;


}

//Returns a pointer to the first Node
Application* ApplicationQueue::front()
{
  return head -> data;
}

//Checks to see if the Linked List is empty... ie Check to see if head is NULL
bool ApplicationQueue::empty()
{
  return head == 0;
}
