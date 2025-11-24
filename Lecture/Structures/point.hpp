struct Point {

    int x;
    int y;

    Point midpoint(Point const &other){

        Point mid;
        mid.x = (x + other.x) / 2; 
        mid.y = (y + other.y) / 2; 

        return mid;
    }

    

    
};


