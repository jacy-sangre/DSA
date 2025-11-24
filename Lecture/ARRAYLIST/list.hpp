// LIST ADT

class List {
    public:
    virtual void add(int n) = 0;
    virtual void print() = 0;
    virtual void remove(int) = 0;
    virtual void addFirst(int) = 0;
    virtual void addLast(int) = 0;
    virtual void addAt(int, int) = 0;
    virtual void flip() = 0;
    virtual int removeAll(int) = 0;
    
};