1.Test.java
  interface Test {
    int square(int n);
}
Arithmetic.java
  class Arithmetic implements Test {

    @Override
    public int square(int n) {
        return n * n;
    }
}
ToTestInt.java
  import java.util.Scanner;

public class ToTestInt {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = sc.nextInt();

        Arithmetic obj = new Arithmetic();

        System.out.println("Square = " + obj.square(num));

        sc.close();
    }
}
2.OUTER AND INNER CLASS
  class Outer {

    void display() {
        System.out.println("Display method of Outer class");
    }

    class Inner {

        void display() {
            System.out.println("Display method of Inner class");
        }
    }
}

public class Main {
    public static void main(String[] args) {

        Outer obj1 = new Outer();
        obj1.display();

        Outer.Inner obj2 = obj1.new Inner();
        obj2.display();
    }
}
3.POINT CLASS
  class Point {

    private int x;
    private int y;

    // Default constructor
    public Point() {
        x = 0;
        y = 0;
    }

    // Parameterized constructor
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void display() {
        System.out.println("Point = (" + x + ", " + y + ")");
    }

    public static void main(String[] args) {

        Point p1 = new Point();
        p1.display();

        Point p2 = new Point(10, 20);
        p2.display();

        p2.setX(30);
        p2.setY(40);
        p2.display();

        p2.setXY(50, 60);
        p2.display();
    }
}
4.Box and Box3D (Inheritance)
  class Box {

    double length;
    double breadth;

    Box(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    double area() {
        return length * breadth;
    }
}

class Box3D extends Box {

    double height;

    Box3D(double length, double breadth, double height) {
        super(length, breadth);
        this.height = height;
    }

    double volume() {
        return length * breadth * height;
    }
}

public class Main {
    public static void main(String[] args) {

        Box box = new Box(10, 5);
        System.out.println("Area = " + box.area());

        Box3D box3d = new Box3D(10, 5, 4);

        System.out.println("Area = " + box3d.area());
        System.out.println("Volume = " + box3d.volume());
    }
}
