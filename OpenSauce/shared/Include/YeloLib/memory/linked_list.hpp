/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#pragma once

namespace Yelo
{
	// Use as a base class only
	template<typename T>
	class LinkedListNode
	{
		T* m_next;
		T* m_prev;

	protected:
		void ClearNodeData()
		{
			m_next = NULL;
			m_prev = NULL;
		}

	public:
		T* GetNext() const { return m_next; }
		T* GetPrevious() const { return m_prev; }

		void SetNext(T* next) { m_next = next; }
		void SetPrevious(T* previous) { m_prev = previous; }
	};

	template<typename TNode>
	class LinkedListIterator
	{
		TNode*& m_list_head;
		TNode* m_current_node;

	public:
		TNode* Current() { return m_current_node; }

		bool MoveNext()
		{
			if(m_current_node && !m_current_node->GetNext())
				return false;
			else if(m_current_node && m_current_node->GetNext())
				m_current_node = m_current_node->GetNext();
			else
				m_current_node = m_list_head;
			return m_current_node != NULL;
		}

		bool MovePrevious()
		{
			if(!m_current_node)
				return false;

			if(m_current_node->GetPrevious())
			{
				m_current_node = m_current_node->GetPrevious();
				return true;
			}
			else
				return false;
		}

		void Reset() { m_current_node = NULL; }

		LinkedListIterator(TNode*& list_head) : m_list_head(list_head), m_current_node(NULL)
		{ }
	};

	// TNode's are LinkedListNode's

	template<typename TNode>
	size_t GetListLength(TNode*& list_head)
	{
		size_t count = 0;
		for(const TNode* cur = CAST_PTR(TNode*, list_head); cur != NULL; cur = CAST_PTR(TNode*, cur->GetNext()), count++)
			;

		return count;
	}

	template<typename TNode>
	void DeleteLinkedList(TNode*& list_head)
	{
		ASSERT(list_head != NULL, "attepting to delete a linked list with a NULL list head");

		for(TNode* cur = CAST_PTR(TNode*, list_head->GetNext()); cur != NULL; )
		{
			TNode* next = CAST_PTR(TNode*, cur->GetNext());
			delete cur;
			cur = next;
		}

		delete list_head;
		list_head = NULL;
	}

	template<typename TNode>
	void AppendLinkedListNode(TNode*& list_head, TNode* object)
	{
		if(list_head == NULL)
		{
			list_head = object;
			return;
		}

		TNode* cur, * next;
		for(cur = list_head, next = CAST_PTR(TNode*, cur->GetNext()); next != NULL; cur = next, next = CAST_PTR(TNode*, cur->GetNext()))
			;

		cur->SetNext(object);
		object->SetPrevious(cur);
	}

	template<typename TNode>
	void RemoveLinkedListNode(TNode*& list_head, const TNode* object)
	{
		ASSERT(list_head != NULL, "attepting to remove from a linked list with a NULL list head");

		TNode* next = CAST_PTR(TNode*, object->GetNext());
		TNode* prev = CAST_PTR(TNode*, object->GetPrevious());

		if(list_head == object)
		{
			if(next != NULL)
				next->SetPrevious(NULL);
			list_head = next;
			return;
		}

		if(prev != NULL) prev->SetNext(next);
		if(next != NULL) next->SetPrevious(prev);
	}

	template<typename TNode>
	void InsertAfterLinkedListNode(TNode* previous, TNode* object)
	{
		TNode* next = previous->GetNext();

		previous->SetNext(object);
		object->SetPrevious(previous);

		object->SetNext(next);
		if(next != NULL)
			next->SetPrevious(object);
	}

	template<typename TNode>
	TNode* GetNodeByIndex(TNode*& list_head, int32 index)
	{
		int32 i = 0;

		TNode* cur, * next;
		for(cur = list_head; cur != NULL && (next = CAST_PTR(TNode*, cur->GetNext())) != NULL && i < index; cur = next, i++)
			;

		if(i != index)
			return NULL;

		return cur;
	}
};