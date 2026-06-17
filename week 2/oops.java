QUES OOPS
   1.Playable.java
  package music;
public interface Playable {
    void play();
}
2.Veena.java
  package music.string;

import music.Playable;

public class Veena implements Playable {

    @Override
    public void play() {
        System.out.println("Playing Veena");
    }
}
3.Saxophone.java
  package music.wind;

import music.Playable;

public class Saxophone implements Playable {

    @Override
    public void play() {
        System.out.println("Playing Saxophone");
    }
}
4. Test.java
  package live;

import music.Playable;
import music.string.Veena;
import music.wind.Saxophone;

public class Test {

    public static void main(String[] args) {

        // a. Create an instance of Veena and call play()
        Veena veena = new Veena();
        veena.play();

        // b. Create an instance of Saxophone and call play()
        Saxophone saxophone = new Saxophone();
        saxophone.play();

        // c. Using Playable reference
        Playable p;

        p = new Veena();
        p.play();

        p = new Saxophone();
        p.play();
    }
}
