#include "WorkExpQueue.h"

using namespace std;

WorkExpQueue::WorkExpQueue() : head(0) { }


//Deallocate All Memory
WorkExpQueue::~WorkExpQueue()
{


}

//Adds an item to back of Queue, make sure to check for all cases (empty list)
void WorkExpQueue::pushBack(WorkExp *newWE)
{

  Node* tempNode = new Node;
  tempNode->data = newWE;
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

WorkExpQueue::Node* WorkExpQueue::getHead(){
  return head;
}

std::string WorkExpQueue::stringOut(){
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
bool WorkExpQueue::popFront()
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
WorkExp* WorkExpQueue::front()
{
  return head -> data;
}

//Checks to see if the Linked List is empty... ie Check to see if head is NULL
bool WorkExpQueue::empty()
{
  return head == 0;
}
