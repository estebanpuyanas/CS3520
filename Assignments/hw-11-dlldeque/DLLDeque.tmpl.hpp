// iterator functions

template<typename T>
DLLDeque<T>::iterator::iterator(IterPtr n)
{
  m_node = n;
}

template<typename T>
DLLDeque<T>::iterator::iterator(const iterator & it)
{
  m_node = it.m_node;
}

template<typename T>
typename DLLDeque<T>::iterator &
DLLDeque<T>::iterator::operator++()
{
  if (m_node) {
    m_node = m_node->next;
  }
  return *this;
}

template<typename T>
typename DLLDeque<T>::iterator
DLLDeque<T>::iterator::operator++(int)
{
  iterator temp(*this);
  ++(*this);
  return temp;
}

template<typename T>
T &
DLLDeque<T>::iterator::operator*()
{
  return m_node->item;
}

template<typename T>
bool
DLLDeque<T>::iterator::operator==(const iterator & it)
{
  return m_node == it.m_node;
}

template<typename T>
bool
DLLDeque<T>::iterator::operator!=(const iterator & it)
{
  return m_node != it.m_node;
}



// deque functions

template<typename T>
void
DLLDeque<T>::push_front(const T & t)
{
  auto newNode = std::make_shared<Node>();
  newNode->item = t;
  newNode->next = m_head;
  newNode->prev.reset();
  if (m_head) {
    m_head->prev = newNode;
  } else {
    m_tail = newNode;
  }
  m_head = newNode;
}

template<typename T>
void
DLLDeque<T>::push_back(const T & t)
{
  auto newNode = std::make_shared<Node>();
  newNode->item = t;
  newNode->next.reset();
  newNode->prev = m_tail;
  if (m_tail) {
    m_tail->next = newNode;
  } else {
    m_head = newNode;
  }
  m_tail = newNode;
}

template<typename T>
void
DLLDeque<T>::pop_front()
{
  if (!m_head) {
    return;
  }
  auto oldHead = m_head;
  m_head = oldHead->next;
  if (m_head) {
    m_head->prev.reset();
  } else {
    m_tail.reset();
  }
}

template<typename T>
void
DLLDeque<T>::pop_back()
{
  if (!m_tail) {
    return;
  }
  auto oldTail = m_tail;
  m_tail = oldTail->prev.lock();
  if (m_tail) {
    m_tail->next.reset();
  } else {
    m_head.reset();
  }
}

template<typename T>
typename DLLDeque<T>::iterator
DLLDeque<T>::begin()
{
  return iterator(m_head);
}

template<typename T>
typename DLLDeque<T>::iterator
DLLDeque<T>::end()
{
  return iterator(nullptr);
}
