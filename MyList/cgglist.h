#pragma once

namespace cgg 
{
    template<typename T>
    class List
    {
    public:
        List();
        ~List();

        void push_back(T &a);   // ������β������Ԫ��
        void push_front(T &a);  // ������ͷ������Ԫ��
        void pop_back();        // �Ƴ�β����Ԫ��
        void pop_front();       // �Ƴ�ͷ����Ԫ��

        T& front(); // ����ͷ��Ԫ��
        T& back();  // ����β��Ԫ��

        bool empty()
        {
            return this->head == nullptr;
        }

    private:
        struct Node
        {
            T *data;
            Node *next;
            Node *previ;
            Node() :next(nullptr), previ(nullptr) {}
            ~Node()
            {
                if (data != nullptr)
                {
                    delete data;
                    data = nullptr;
                }
            }
        };
        Node    *head;  // ����ͷָ�룬ָ���һ��Ԫ��
        Node    *tail;  // ����βָ�룬ָ�����һ��Ԫ��

    };

    template<typename T>
    List<T>::List():head(nullptr),tail(nullptr)
    {
    }

    template<typename T>
    List<T>::~List()
    {
        auto p = head;
        while (p != nullptr)
        {
            auto q = p;
            p = p->next;
            delete q;
        }
        this->head = nullptr;
        this->tail = nullptr;
    }

    template<typename T>
    void List<T>::push_front(T &a)
    {
        Node *p = new Node;
        p->data = new T(a);

        if (this->head == nullptr)
        {
            this->head = p;
            this->tail = p;
        }
        else
        {
            this->head->previ = p;
            p->next = this->head;
            this->head = p;
        }
    }

    template<typename T>
    void List<T>::push_back(T &a)
    {
        Node *p = new Node;
        p->data = new T(a);

        if (this->head == nullptr)
        {
            this->head = p;
            this->tail = p;
        }
        else
        {
            p->previ = this->tail;
            this->tail->next = p;
            this->tail = p;
        }
    }

    template<typename T>
    void List<T>::pop_front()
    {
        if (this->head == nullptr)
        {
            return;
        }

        Node *p = this->head;
        this->head = this->head->next;
        if (this->tail == p)
        {
            this->tail = nullptr;
        }
        delete p;

        if (this->head)
        {
            this->head->previ = nullptr;
        }
    }

    template<typename T>
    void List<T>::pop_back()
    {
        if (this->tail == nullptr)
        {
            return;
        }

        Node *p = this->tail;
        this->tail = this->tail->previ;
        if (this->head == p)
        {
            this->head = nullptr;
        }
        delete p;

        if (this->tail)
        {
            this->tail->next = nullptr;
        }
    }

    template<typename T>
    T& List<T>::front()
    {
        return *(this->head->data);
    }

    template<typename T>
    T& List<T>::back()
    {
        return *(this->tail->data);
    }
}
