#ifndef _LIST_H 
#define _LIST_H
typedef float Element; 


class List {

public: 
List();
List( const List & ); // reuse add
~List();
void add( const Element );
void remove( const Element );
void view() const;


private: 
struct Node;
typedef Node * NodePtr;
struct Node {
Element element;
NodePtr next;
};
NodePtr front;
};
#endif // Guard – end

