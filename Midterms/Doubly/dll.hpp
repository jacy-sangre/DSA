class Doubly{
    public:
    virtual void print() = 0;
    virtual int add(int n) = 0;
    virtual void addHead(int n) = 0;
    virtual void addTail(int n) = 0;
    virtual int removeFirst() = 0;
    virtual int removeLast() = 0;
    virtual int remove(int n) = 0;
    virtual int removeAll(int n) = 0;
    virtual void addAt(int n, int pos) = 0;
    virtual int removeAt(int pos) = 0;
    virtual void reverse() = 0;
    virtual int get(int pos) = 0;

};