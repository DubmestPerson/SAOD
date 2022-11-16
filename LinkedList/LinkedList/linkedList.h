#pragma once
#include <iostream>
using namespace std;
// Вариант 7:
// 7. Два дополнительных служебных узла (в начале и в конце по одному).
template <typename T>
class LinkedListElement {
private:
    T data;
    LinkedListElement* prev = NULL;
    LinkedListElement* next = NULL;

public:
    LinkedListElement(T data) {
        this->data = data;
    };
    LinkedListElement(T data, LinkedListElement* prev) {
        this->data = data;
        this->prev = prev;
    };
    LinkedListElement(T data, LinkedListElement* prev,
        LinkedListElement* next) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    };

    void set_next(LinkedListElement* next) {
        this->next = next;
    }
    void set_prev(LinkedListElement* prev) {
        this->prev = prev;
    }

    LinkedListElement* get_next() {
        return next;
    }
    LinkedListElement* get_prev() {
        return prev;
    }

    void set_data(T data) {
        this->data = data;
    }
    T get_data() {
        return data;
    }

    T& get_data_ref() {
        return data;
    }
};

template <typename T>
class LinkedListIterator {
private:
    LinkedListElement<T>* current = NULL;

public:
    LinkedListIterator(LinkedListElement<T>* elem) {
        current = elem;
    }

    LinkedListIterator& operator++() {
        current = current->get_next();
        return *this;
    }

    bool operator!=(LinkedListIterator iterator) {
        return current != iterator.current;
    }

    T& operator*() {
        return current->get_data_ref();
    }
};

template <typename T>
class LinkedList {
private:
    LinkedListElement<T>* first = NULL;
    LinkedListElement<T>* last = NULL;

    LinkedListElement<T>* find_by_index(unsigned int index) const {
        LinkedListElement<T>* x = first->get_next();
        int i = 0;
        while (x != last) {
            if (i == index)
                return x;

            x = x->get_next();
            i++;
        }

        throw runtime_error("index out of range");
    }

    void actually_remove(LinkedListElement<T>* x) {
        if (!x)
            throw runtime_error("NULL is not possible to remove");
        if (x == first || x == last)
            throw runtime_error(
                "You can't remove special elements");

        auto p = x->get_prev();
        auto n = x->get_next();

        if (p)
            p->set_next(n);
        if (n)
            n->set_prev(p);

        delete x;
    }

    // next - это элемент, перед которым мы хотим добавить
    // x - новый элемент, который мы хотим добавить
    void actually_add_before(LinkedListElement<T>* x,
        LinkedListElement<T>* next) {
        if (!next)
            throw runtime_error("You can't add before NULL");
        if (next == first)
            throw runtime_error(
                "unreachable. You can't add before special element");

        auto p = next->get_prev();

        x->set_next(next);
        x->set_prev(p);

        next->set_prev(x);

        p->set_next(x);
    }

public:
    LinkedList() {
        LinkedListElement<T>* e1 = new LinkedListElement<T>('Strt');
        LinkedListElement<T>* e2 = new LinkedListElement<T>('End');
        first = e1;
        last = e2;

        first->set_next(last);
        last->set_prev(first);
    };
    ~LinkedList() {
        clear();
        delete first;
        delete last;
    };

    void clear() {
        LinkedListElement<T>* x = first->get_next();
        while (x != last) {
            auto tx = x;
            x = x->get_next();
            delete tx;
        }

        first->set_next(last);
        last->set_prev(first);
    }

    void push_front(T data) {
        LinkedListElement<T>* elem = new LinkedListElement<T>(data);

        actually_add_before(elem, first->get_next());
    }
    void push_back(T data) {
        LinkedListElement<T>* elem = new LinkedListElement<T>(data);

        actually_add_before(elem, last);
    }
    void insert(size_t index, T data) {
        if (index == 0) {
            push_front(data);
            return;
        }

        auto target = find_by_index(index);

        auto elem = new LinkedListElement<T>(data);
        actually_add_before(elem, target);
    }

    void pop_front() {
        actually_remove(first->get_next());
    }
    void pop_back() {
        actually_remove(last->get_prev());
    }
    void remove_at(size_t index) {
        auto x = find_by_index(index);

        actually_remove(x);
    }

    size_t size() const {
        LinkedListElement<T>* elem = first->get_next();
        unsigned int count = 0;
        while (elem != last) {
            count += 1;

            elem = elem->get_next();
        }

        return count;
    }


    LinkedListIterator<T> begin() {
        return LinkedListIterator<T>(first->get_next());
    }
    LinkedListIterator<T> end() {
        return LinkedListIterator<T>(last);
    }

    bool empty() const {
        return first->get_next() == last;
    }

    T front() const {
        if (empty())
            throw runtime_error("list is empty");

        return first->get_next()->get_data();
    }
    T back() const {
        if (empty())
            throw runtime_error("list is empty");

        return last->get_prev()->get_data();
    }

    // для записи данных по индексу
    T& operator[](const size_t index) {
        auto x = find_by_index(index);

        return x->get_data_ref();
    }

    // для чтения данных по индексу
    T const& operator[](const size_t index) const {
        auto x = find_by_index(index);

        return x->get_data_ref();
    }
};

