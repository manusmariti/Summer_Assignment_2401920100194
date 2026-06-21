Compartment.java
  abstract class Compartment {
    public abstract String notice();
}
FirstClass.java
  class FirstClass extends Compartment {
    @Override
    public String notice() {
        return "First Class Compartment";
    }
}
Ladies.java
  class Ladies extends Compartment {
    @Override
    public String notice() {
        return "Ladies Compartment";
    }
}
General.java
  class General extends Compartment {
    @Override
    public String notice() {
        return "General Compartment";
    }
}
Luggage.java
  class Luggage extends Compartment {
    @Override
    public String notice() {
        return "Luggage Compartment";
    }
}
TestCompartment.java
  import java.util.Random;

public class TestCompartment {
    public static void main(String[] args) {

        Compartment[] compartments = new Compartment[10];
        Random rand = new Random();

        for (int i = 0; i < compartments.length; i++) {

            int choice = rand.nextInt(4) + 1; // Random number 1 to 4

            switch (choice) {
                case 1:
                    compartments[i] = new FirstClass();
                    break;

                case 2:
                    compartments[i] = new Ladies();
                    break;

                case 3:
                    compartments[i] = new General();
                    break;

                case 4:
                    compartments[i] = new Luggage();
                    break;
            }
        }

        System.out.println("Railway Compartments:");

        for (int i = 0; i < compartments.length; i++) {
            System.out.println("Compartment " + (i + 1) + ": "
                    + compartments[i].notice());
        }
    }
}
