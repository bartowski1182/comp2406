

Queue::Queue() : head(0) {}

Queue::~Queue(){}

void Queue::pushBack(Application* newApp)
{
	Node* tempNode = new Node;
	tempNode->data = newApp;

	if(head == 0){
		head = tempNode;
		return;
	}

	tail->next = tempNode;
	tail = tempNode;
}

void Queue::popFront()
{
	head = head->next;
}

Application* Queue::front()
{
	return head->data;
}

bool Queue::empty()
{
	return head == 0;
}

